#ifndef COMOBJECT_H
#define COMOBJECT_H

#include <QObject>
#include <QThread>
#include <QDateTime>
#include <QtSerialPort/QtSerialPort>

#include "windows.h"

#define ERROR_OPEN      -1
#define ERROR_ADDR      -2
#define ERROR_FILE      -3
class ComDriver : public QObject
{
    Q_OBJECT
public:
    ComDriver(QString name, int baud, QObject *parent = 0);

private:
    //CRC-16校验
    unsigned int CRC16Check(uchar *pchMsg, short wDataLen);
    unsigned int CRC16Check_CCITT(uchar *pchMsg, short wDataLen);
    bool SendMsg(const int cmd, const int addr, const uchar *data, const int len, const int flag=0);
    bool FetchData(uchar *data, int *len, int stat_pos);
    bool OpenFile(QString name);
    int QStringToMultiByte(QString str, char *szU8, int *u8Len);
    int QStringToUnicode(QString str, char *szUn, int *slen);
private slots:
    void DownLoad_slt(const int type, const int cmd, const int addr, const QString filename, int flag=0);
    void ReceiveMsg();
signals:
    void ResProgress_sig(int pos);
private:
    int s_cmd;
    int m_cmd;
    int m_flag;
    int dtype;
    int m_address;
    QString m_filename;
    QStringList dataStr;
    int cur_pos;
    int com_status;
    int file_byte_count;
    int send_count;
    int receive_count;
    QSerialPort *m_com;
    QByteArray m_dataAll;
};


class ComObject : public QObject
{
    Q_OBJECT
public:
    ComObject(QString name, int baud, QObject *parent = 0);

    void DownLoad(const int type, const int cmd, const int addr, const QString filename, int flag=0);

signals:
    void DownLoad_sig(const int type, const int cmd, const int addr, const QString filename, int flag=0);
    void ResProgress_sig(int pos);
private slots:
    void ResProgress_slt(int pos);
};
#endif // COMOBJECT_H
