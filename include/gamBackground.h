#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

namespace bgm {

class gamBackground
{
public:
    gamBackground() {};
    ~gamBackground() {};

    int createBackground(int argc, char *argv[]);
};

}