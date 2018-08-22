#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置程序中文字的编码方式
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));


    MainWindow w;
    w.show();

    return a.exec();
}
