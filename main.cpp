#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>


/*************加载qss文件的函数*************/
class CommonHelper
{
public:
    static void setStyle(const QString &style)
    {
        QFile qss(style);
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置程序中文字的编码方式
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

    // 加载QSS样式
    CommonHelper::setStyle(":/style.qss");

    MainWindow w;
    w.show();

    return a.exec();
}
