cmake_minimum_required(VERSION 3.5)

# 设置项目名称和C++标准
project(AUX LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

# 查找Qt5核心组件
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

# 启用自动处理
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/gamBackground.cc
    ${PROJECT_SOURCE_DIR}/src/main.cc
)

# 添加可执行文件
add_executable(AUX  ${SOURCES})

# 链接Qt库
target_link_libraries(AUX PRIVATE 
    Qt5::Core
    Qt5::Widgets
)