#include "chatpanel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatPanel w;
    w.show();

    return a.exec();
}
