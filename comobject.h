#ifndef COMOBJECT_H
#define COMOBJECT_H

#include <QObject>
#include <QThread>
#include <QDateTime>
#include <QtSerialPort/QtSerialPort>


#define WAIT_TIME 5000
class ComDriver : public QObject
{
    Q_OBJECT
public:
    ComDriver(QObject *parent = 0);

private:
    //CRC-16校验
    unsigned int CRC16Check(uchar *pchMsg, short wDataLen);
    bool ComOneManual(const int cmd, const int addr, const uchar *data, const int len);

private slots:
    void DownLoad_slt(const int cmd, const int addr, const QString filename, int flag);

private:
    QSerialPort *m_com;
};


class ComObject : public QObject
{
    Q_OBJECT
public:
    ComObject(QObject *parent = 0);

    void DownLoad(const int cmd, const int addr, const QString filename, int flag);

signals:
    void DownLoad_sig(const int cmd, const int addr, const QString filename, int flag);

private:
};
#endif // COMOBJECT_H
