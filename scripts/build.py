#!/usr/bin/env python3
import os
import subprocess
import argparse
from pathlib import Path

def build(jobs=4):
    # 获取真正的项目根目录（包含CMakeLists.txt的目录）
    script_dir = Path(__file__).parent.resolve()
    project_dir = script_dir.parent  # 假设脚本在项目下的scripts目录中
    build_dir = project_dir / "build"  # 构建目录放在项目同级
    
    # 验证CMakeLists.txt是否存在
    if not (project_dir / "CMakeLists.txt").exists():
        print(f"错误：在 {project_dir} 中找不到 CMakeLists.txt")
        return 1
    
    # 创建build目录
    if not build_dir.exists():
        build_dir.mkdir()
    
    # CMake配置
    try:
        subprocess.run([
            "cmake",
            f"-B{build_dir}",
            f"-S{project_dir}"
        ], check=True)
        
        # 编译（带-j参数）
        subprocess.run([
            "cmake",
            "--build",
            str(build_dir),
            f"-j{jobs}"
        ], check=True)
        
        print(f"Build Successful!")
        return 0
    except subprocess.CalledProcessError as e:
        print(f"Build Faile: {e}")
        return 1

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='C++build')
    parser.add_argument('-j', '--jobs', type=int, default=4, 
                       help='并行编译线程数 (默认: 4)')
    args = parser.parse_args()
    
    exit(build(args.jobs))