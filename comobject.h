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
#define ERROR_NOFINDCHAR -7


#define DECODE_OK       -10
#define DECODE_CRP2     -11
#define CANCEL_OK       -15
#define SERIAL_SET      -16

//0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz<>():,.;!+-*=
#define FONT_CHAR_LENGTH   10+26+26+14  //10个数字，26个大写字母，26个小写字母，15个窄符号

//÷≠℃△○●℉Φ的一是...
#define FONT_HZ_LENGTH     8 + 2995   //(宽的符号和汉字)

#define CHAR32_FIRST_ADD_SDRAM 0xa0200000
#define CHAR16_FIRST_ADD_SDRAM 0xa0270000

#define CHAR_START_UNICODE    0x4e00

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
    void ResProgress_sig(int pos, QString msg="");
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

    QString m_charList;
    QMap<int, int> m_charUnicode;


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
    void ResProgress_sig(int pos, QString msg);
    void SendMsg_sig(char* data);
private slots:
    void ResProgress_slt(int pos, QString msg);
};
#endif // COMOBJECT_H
