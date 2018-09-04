#ifndef COMOBJECT_H
#define COMOBJECT_H

#include <QObject>
#include <QThread>
#include <QDateTime>
#include <QtSerialPort/QtSerialPort>

#include "windows.h"
#define WAIT_TIME 1000
class ComDriver : public QObject
{
    Q_OBJECT
public:
    ComDriver(QString name, int baud, QObject *parent = 0);

private:
    //CRC-16校验
    unsigned int CRC16Check(uchar *pchMsg, short wDataLen);
    bool SendMsg(const int cmd, const int addr, const uchar *data, const int len);
    bool FetchData(uchar *data, int *len, int stat_pos);
    bool OpenFile(QString name);
    int QStringToMultiByte(QString str, char *szU8, int *u8Len);
    int QStringToUnicode(QString str, char *szUn, int *slen);
private slots:
    void DownLoad_slt(const int type, const int cmd, const int addr, const QString filename, int flag);
    void ReceiveMsg();
signals:
    void ResProgress_sig(int pos);
private:
    int s_cmd;
    int m_cmd;
    int dtype;
    int m_address;
    QString m_filename;
    QStringList dataStr;
    int cur_pos;
    int com_status;
    int file_count;
    int send_count;
    int receive_count;
    QSerialPort *m_com;
};


class ComObject : public QObject
{
    Q_OBJECT
public:
    ComObject(QString name, int baud, QObject *parent = 0);

    void DownLoad(const int type, const int cmd, const int addr, const QString filename, int flag);

signals:
    void DownLoad_sig(const int type, const int cmd, const int addr, const QString filename, int flag);
    void ResProgress_sig(int pos);
private slots:
    void ResProgress_slt(int pos);
};
#endif // COMOBJECT_H
