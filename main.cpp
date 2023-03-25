#include "mainscence.h"
#include <QResource>
#include <QApplication>
#include "config.h"
#include "start.h"
#include"mainscence2.h"
#include"mainscence3.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

     //MainScence ww;
     //ww.show();
   Start w;
    w.show();
    //MainScence3 w;
    //w.show();
    return a.exec();
}
