﻿#include "comobject.h"


const unsigned char gCrcHigh[256]=
{
    0X00, 0XC1, 0X81, 0X40, 0X01, 0XC0, 0X80, 0X41, 0X01, 0XC0,
    0X80, 0X41, 0X00, 0XC1, 0X81, 0X40, 0X01, 0XC0, 0X80, 0X41,
    0X00, 0XC1, 0X81, 0X40, 0X00, 0XC1, 0X81, 0X40, 0X01, 0XC0,
    0X80, 0X41, 0X01, 0XC0, 0X80, 0X41, 0X00, 0XC1, 0X81, 0X40,
    0X00, 0XC1, 0X81, 0X40, 0X01, 0XC0, 0X80, 0X41, 0X00, 0XC1,
    0X81, 0X40, 0X01, 0XC0, 0X80, 0X41, 0X01, 0XC0, 0X80, 0X41,
    0X00, 0XC1, 0X81, 0X40, 0X01, 0XC0, 0X80, 0X41, 0X00, 0XC1,
    0X81, 0X40, 0X00, 0XC1, 0X81, 0X40, 0X01, 0XC0, 0X80, 0X41,
    0X00, 0XC1, 0X81, 0X40, 0X01, 0XC0, 0X80, 0X41, 0X01, 0XC0,
    0X80, 0X41, 0X00, 0XC1, 0X81, 0X40, 0X00, 0XC1, 0X81, 0X40,
    0X01, 0XC0, 0X80, 0X41, 0X01, 0XC0, 0X80, 0X41, 0X00, 0XC1,
    0X81, 0X40, 0X01, 0XC0, 0X80, 0X41, 0X00, 0XC1, 0X81, 0X40,
    0X00, 0XC1, 0X81, 0X40, 0X01, 0XC0, 0X80, 0X41, 0X01, 0XC0,
    0X80, 0X41, 0X00, 0XC1, 0X81, 0X40, 0X00, 0XC1, 0X81, 0X40,
    0X01, 0XC0, 0X80, 0X41, 0X00, 0XC1, 0X81, 0X40, 0X01, 0XC0,
    0X80, 0X41, 0X01, 0XC0, 0X80, 0X41, 0X00, 0XC1, 0X81, 0X40,
    0X00, 0XC1, 0X81, 0X40, 0X01, 0XC0, 0X80, 0X41, 0X01, 0XC0,
    0X80, 0X41, 0X00, 0XC1, 0X81, 0X40, 0X01, 0XC0, 0X80, 0X41,
    0X00, 0XC1, 0X81, 0X40, 0X00, 0XC1, 0X81, 0X40, 0X01, 0XC0,
    0X80, 0X41, 0X00, 0XC1, 0X81, 0X40, 0X01, 0XC0, 0X80, 0X41,
    0X01, 0XC0, 0X80, 0X41, 0X00, 0XC1, 0X81, 0X40, 0X01, 0XC0,
    0X80, 0X41, 0X00, 0XC1, 0X81, 0X40, 0X00, 0XC1, 0X81, 0X40,
    0X01, 0XC0, 0X80, 0X41, 0X01, 0XC0, 0X80, 0X41, 0X00, 0XC1,
    0X81, 0X40, 0X00, 0XC1, 0X81, 0X40, 0X01, 0XC0, 0X80, 0X41,
    0X00, 0XC1, 0X81, 0X40, 0X01, 0XC0, 0X80, 0X41, 0X01, 0XC0,
    0X80, 0X41, 0X00, 0XC1, 0X81, 0X40
};

const unsigned char gCrcLow[256]=
{
    0X00, 0XC0, 0XC1, 0X01, 0XC3, 0X03, 0X02, 0XC2, 0XC6, 0X06,
    0X07, 0XC7, 0X05, 0XC5, 0XC4, 0X04, 0XCC, 0X0C, 0X0D, 0XCD,
    0X0F, 0XCF, 0XCE, 0X0E, 0X0A, 0XCA, 0XCB, 0X0B, 0XC9, 0X09,
    0X08, 0XC8, 0XD8, 0X18, 0X19, 0XD9, 0X1B, 0XDB, 0XDA, 0X1A,
    0X1E, 0XDE, 0XDF, 0X1F, 0XDD, 0X1D, 0X1C, 0XDC, 0X14, 0XD4,
    0XD5, 0X15, 0XD7, 0X17, 0X16, 0XD6, 0XD2, 0X12, 0X13, 0XD3,
    0X11, 0XD1, 0XD0, 0X10, 0XF0, 0X30, 0X31, 0XF1, 0X33, 0XF3,
    0XF2, 0X32, 0X36, 0XF6, 0XF7, 0X37, 0XF5, 0X35, 0X34, 0XF4,
    0X3C, 0XFC, 0XFD, 0X3D, 0XFF, 0X3F, 0X3E, 0XFE, 0XFA, 0X3A,
    0X3B, 0XFB, 0X39, 0XF9, 0XF8, 0X38, 0X28, 0XE8, 0XE9, 0X29,
    0XEB, 0X2B, 0X2A, 0XEA, 0XEE, 0X2E, 0X2F, 0XEF, 0X2D, 0XED,
    0XEC, 0X2C, 0XE4, 0X24, 0X25, 0XE5, 0X27, 0XE7, 0XE6, 0X26,
    0X22, 0XE2, 0XE3, 0X23, 0XE1, 0X21, 0X20, 0XE0, 0XA0, 0X60,
    0X61, 0XA1, 0X63, 0XA3, 0XA2, 0X62, 0X66, 0XA6, 0XA7, 0X67,
    0XA5, 0X65, 0X64, 0XA4, 0X6C, 0XAC, 0XAD, 0X6D, 0XAF, 0X6F,
    0X6E, 0XAE, 0XAA, 0X6A, 0X6B, 0XAB, 0X69, 0XA9, 0XA8, 0X68,
    0X78, 0XB8, 0XB9, 0X79, 0XBB, 0X7B, 0X7A, 0XBA, 0XBE, 0X7E,
    0X7F, 0XBF, 0X7D, 0XBD, 0XBC, 0X7C, 0XB4, 0X74, 0X75, 0XB5,
    0X77, 0XB7, 0XB6, 0X76, 0X72, 0XB2, 0XB3, 0X73, 0XB1, 0X71,
    0X70, 0XB0, 0X50, 0X90, 0X91, 0X51, 0X93, 0X53, 0X52, 0X92,
    0X96, 0X56, 0X57, 0X97, 0X55, 0X95, 0X94, 0X54, 0X9C, 0X5C,
    0X5D, 0X9D, 0X5F, 0X9F, 0X9E, 0X5E, 0X5A, 0X9A, 0X9B, 0X5B,
    0X99, 0X59, 0X58, 0X98, 0X88, 0X48, 0X49, 0X89, 0X4B, 0X8B,
    0X8A, 0X4A, 0X4E, 0X8E, 0X8F, 0X4F, 0X8D, 0X4D, 0X4C, 0X8C,
    0X44, 0X84, 0X85, 0X45, 0X87, 0X47, 0X46, 0X86, 0X82, 0X42,
    0X43, 0X83, 0X41, 0X81, 0X80, 0X40
};


ComObject::ComObject(QObject *parent) :
    QObject(parent)
{
    //1、初始化串口线程
    QThread *com_thread = new QThread;
    ComDriver *com = new ComDriver();
    com->moveToThread(com_thread);
    com_thread->start();

    //连接信号
    connect(this, SIGNAL(SendMsg(QByteArray)), com, SLOT(SendMsg(QByteArray)));
    connect(com, SIGNAL(ResponseMsg(QByteArray)), this, SLOT(ResponseMsg(QByteArray)));

    m_preCmd = 0;
    m_finsh = false;


}
/**
* 函数说明：CRC校验
*
* @param:需要校验的数据，长度
*
* @return:校验码
**/
unsigned int ComObject::CRC16Check(uchar *pchMsg, short wDataLen)
{
    unsigned int aTemp,   aNum;

    uchar gCrcH = 0xff;
    uchar gCrcL = 0xff;
    for (aNum=0; aNum<wDataLen;aNum++)
    {
       aTemp =  gCrcH ^ pchMsg[aNum];
       gCrcH = gCrcL ^ gCrcHigh[aTemp];
       gCrcL = gCrcLow[aTemp];
    }
    return (gCrcH<<8)|gCrcL;
}

void ComObject::ResponseMsg(QByteArray dataVar)
{
    int cmd = dataVar[1];
    switch (cmd) {
    case 0x18:
        qDebug()<<"CRC error!";
        break;
    case 0x20:
        qDebug()<<"Length error!";
        break;
    case 0x22:
        qDebug()<<"Address error!";
        break;
    default:
        if (m_preCmd == cmd){
            qDebug()<<"Sucess!";
            m_finsh = true;
        }else{
            qDebug()<<"Noknow error!";
            m_finsh = false;
        }
        break;
    }
}
void ComObject::send(uchar *dataVar, int len)
{
    int i;
    QByteArray byArr;
    byArr.resize(len);
    for(i=0;i<len;i++) {
        byArr[i]=dataVar[i];
    }

    //添加CRC
    unsigned short CRC = CRC16Check(dataVar, len);
    byArr[i+0] = (CRC >> 8) & 0xff;
    byArr[i+1] = (CRC >> 0) & 0xff;
    emit SendMsg(byArr);
    m_preCmd = byArr[1];
}

ComDriver::ComDriver(QObject *parent) :
    QObject(parent)
{

    //打开窗口
    m_com = new QSerialPort();
    m_com->setPortName("COM1");
    if (!m_com->open(QIODevice::ReadWrite)){
        return;
    }
    m_com->setBaudRate(QSerialPort::Baud9600);
    m_com->setDataBits(QSerialPort::Data8);
    m_com->setParity(QSerialPort::NoParity);
    m_com->setStopBits(QSerialPort::OneStop);
    m_com->setFlowControl(QSerialPort::NoFlowControl);

}

/**
* 函数说明：发送数据函数
*
* @param:待发送的数据
*
* @return:是否成功
* **/
bool ComDriver::SendMsg(QByteArray dataVar)
{
    bool status;
    status = m_com->write(dataVar);
    if(status<0)
        return false;

    status = ReceiveMsg();
}
/**
* 函数说明：接收数据函数
*
* @param:
*
* @return:接收到的数据是否有效
* **/
bool ComDriver::ReceiveMsg()
{
    bool receive_status = false;

    while (m_com->waitForReadyRead(WAIT_TIME))
    {
        //1、读取并处理串口缓冲区数据
        QByteArray seial_buff = m_com->readAll();
        emit ResponseMsg(seial_buff);
    }

    return receive_status;

}
