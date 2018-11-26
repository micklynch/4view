#include <QtGui/QApplication>
#include "mprviewer.h"
#include "imageml.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MPRviewer w;
    w.show();
    return a.exec();

}
