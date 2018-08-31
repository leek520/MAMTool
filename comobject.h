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
    explicit ComDriver(QObject *parent = 0);

private:



signals:
    void ResponseMsg(QByteArray dataVar);
private slots:
    //发送数据包函数
    bool SendMsg(QByteArray dataVar);
    //接收数据包函数
    bool ReceiveMsg();
private:
    QSerialPort *m_com;
};

class ComObject : public QObject
{
    Q_OBJECT
public:
    explicit ComObject(QObject *parent = 0);

    void send(uchar *dataVar, int len);
private:
    //CRC-16校验
    unsigned int CRC16Check(uchar *pchMsg, short wDataLen);
signals:
    void SendMsg(QByteArray dataVar);

private slots:
    void ResponseMsg(QByteArray dataVar);
private:
    int m_preCmd;
    bool m_finsh;
};
#endif // COMOBJECT_H
