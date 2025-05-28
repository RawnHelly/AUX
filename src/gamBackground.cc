#include "gamBackground.h"

namespace bgm {
int gamBackground::createBackground(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 创建主窗口
    QWidget window;
    window.setWindowTitle("Qt5示例程序");
    window.resize(300, 200);

    // 创建垂直布局
    QVBoxLayout *layout = new QVBoxLayout(&window);

    // 创建标签
    QLabel *label = new QLabel("欢迎使用Qt5!", &window);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    // 创建按钮
    QPushButton *button = new QPushButton("点击我", &window);
    layout->addWidget(button);

    // 连接按钮点击信号到槽函数
    QObject::connect(button, &QPushButton::clicked, [label]() {
        label->setText("按钮已被点击!");
    });

    // 显示窗口
    window.show();

    // 运行应用程序
    return app.exec();
}

}
