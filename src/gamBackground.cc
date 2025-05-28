#include "gamBackground.h"

namespace bgm {
int gamBackground::createBackground(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Qt5 Example Program");
    window.resize(300, 200);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    QLabel *label = new QLabel("Welcome to Qt5!", &window);
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    QPushButton *button = new QPushButton("Click Me", &window);
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, [label]() {
        label->setText("Button clicked!");
    });

    window.show();

    return app.exec();
}

}
