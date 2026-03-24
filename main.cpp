#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    // 创建一个QApplication对象
    QApplication app(argc, argv);
    QWidget window;
    window.resize(320, 240);
    window.setWindowTitle("TestQtUi");
    window.show();
    return app.exec();
}


