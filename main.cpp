#include "JX002.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JX002 w;
    w.show();
  return a.exec();
}
