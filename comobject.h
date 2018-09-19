#ifndef COMOBJECT_H
#define COMOBJECT_H

#include <QObject>
#include <QThread>
#include <QDateTime>
#include <QtSerialPort/QtSerialPort>

#define ERROR_OPEN      -1
#define ERROR_ADDR      -2
#define ERROR_FILE      -3
#define ERROR_FONTSIZE  -4
#define ERROR_PICTYPE0  -5
#define ERROR_PICTYPE1  -6

#define DECODE_OK       -10
#define DECODE_CRP2     -11
#define CANCEL_OK       -15
#define SERIAL_SET      -16
enum{
    FLASH_DOWNLOAD,
    FLASH_DECODE,
};

class ComDriver : public QObject
{
    Q_OBJECT
public:
    ComDriver(QString name, QString baud, QString parity, QString stopbit, QObject *parent = 0);

private:
    void SetSerialPara(QString name, QString baud, QString parity, QString stopbit);
    //CRC-16校验
    unsigned int CRC16Check(uchar *pchMsg, ushort wDataLen);
    unsigned int CRC16Check_CCITT(uchar *pchMsg, uint wDataLen);
    bool SendMsgDownLoad(const int cmd, const int addr, const uchar *data, const int len, const int flag=0);
    bool FetchData(uchar *data, int *len, int stat_pos);
    bool OpenFile(int type, QString name);
    int QStringToMultBytes(QString str, char *szUn, int *slen);

    bool FontFileLineCal(QString line, QStringList *data);
public slots:
    void SendMsg();
    void DownLoad_slt(const int type, const int cmd, const int addr, const QString filename, int flag=0);
    void ReceiveMsg();

    void SendMsg_slt(char* data);
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
    QByteArray m_ReceiveBuf;

    int m_serialType;
    QString m_decodeCmd;

    QTimer *m_sendTimer;
};


class ComObject : public QObject
{
    Q_OBJECT
public:
    ComDriver *com;
    ComObject(QString name, QString baud, QString parity, QString stopbit, QObject *parent = 0);

    void DownLoad(const int type, const int cmd, const int addr, const QString filename, int flag=0);
    void SendMsg(char* data);
signals:
    void DownLoad_sig(const int type, const int cmd, const int addr, const QString filename, int flag=0);
    void ResProgress_sig(int pos);
    void SendMsg_sig(char* data);
private slots:
    void ResProgress_slt(int pos);
};
#endif // COMOBJECT_H
