#include "comobject.h"


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
ComObject::ComObject(QString name, QString baud, QString parity, QString stopbit, QObject *parent) :
    QObject(parent)
{
    //1、初始化串口线程
    QThread *com_thread = new QThread;
    com = new ComDriver(name, baud, parity, stopbit);
    com->moveToThread(com_thread);
    com_thread->start();

    //连接信号
    connect(this, SIGNAL(DownLoad_sig(int,int,int,const QString,int)),
            com, SLOT(DownLoad_slt(int,int,int,const QString,int)));
    connect(this, SIGNAL(SendMsg_sig(char*)),
            com, SLOT(SendMsg_slt(char*)));
    connect(com, SIGNAL(ResProgress_sig(int, QString)),
            this, SLOT(ResProgress_slt(int, QString)));

}

void ComObject::DownLoad(const int type, const int cmd, const int addr, const QString filename, int flag)
{
    emit DownLoad_sig(type, cmd, addr, filename, flag);
}

void ComObject::SendMsg(char* data)
{
    emit SendMsg_sig(data);
}

void ComObject::ResProgress_slt(int pos, QString msg)
{
    emit ResProgress_sig(pos, msg);
}



ComDriver::ComDriver(QString name, QString baud, QString parity, QString stopbit, QObject *parent) :
    QObject(parent)
{

    //打开窗口
    m_com = new QSerialPort();
    SetSerialPara(name, baud, parity, stopbit);
    connect(m_com,SIGNAL(readyRead()),this,SLOT(ReceiveMsg()));
    qDebug()<<"SerialPort is open";


    m_sendTimer = new QTimer(this);
    connect(m_sendTimer, SIGNAL(timeout()), this, SLOT(SendMsg()));
}

void ComDriver::SetSerialPara(QString name, QString baud, QString parity, QString stopbit)
{
    if (m_com->isOpen()){
        m_com->close();
    }
    m_com->setPortName(name);
    if (!m_com->open(QIODevice::ReadWrite)){
        return;
    }
    if (baud == "9600")
        m_com->setBaudRate(QSerialPort::Baud9600);
    else
        m_com->setBaudRate(QSerialPort::Baud115200);
    m_com->setDataBits(QSerialPort::Data8);
    if (parity == "None")
        m_com->setParity(QSerialPort::NoParity);
    else if (parity == "Even")
        m_com->setParity(QSerialPort::EvenParity);
    else if (parity == "Odd")
        m_com->setParity(QSerialPort::OddParity);
    if (stopbit == "1")
        m_com->setStopBits(QSerialPort::OneStop);
    else if (stopbit == "1.5")
        m_com->setStopBits(QSerialPort::OneAndHalfStop);
    else if (stopbit == "2")
        m_com->setStopBits(QSerialPort::TwoStop);

    m_com->setFlowControl(QSerialPort::NoFlowControl);

    qDebug()<<"parity:"<<m_com->parity();
}
/**
* 函数说明：CRC校验
*
* @param:需要校验的数据，长度
*
* @return:校验码
**/
unsigned int ComDriver::CRC16Check(uchar *pchMsg, ushort wDataLen)
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
/**
* 函数说明：CRC校验
*
* @param:需要校验的数据，长度
*
* @return:校验码
**/
unsigned int ComDriver::CRC16Check_CCITT(uchar *pchMsg, uint wDataLen)
{
    /*这里注意len一定要定义为uint，要不然长度不够*/
    int crc = 0xFFFF;
    for (uint j = 0; j < wDataLen; j++) {
        crc = ((crc >> 8) | (crc << 8)) & 0xffff;
        crc ^= (pchMsg[j] & 0xff);// byte to int, trunc sign
        crc ^= ((crc & 0xff) >> 4);
        crc ^= (crc << 12) & 0xffff;
        crc ^= ((crc & 0xFF) << 5) & 0xffff;
    }
    crc &= 0xffff;
    return crc;

}
bool ComDriver::SendMsgDownLoad(const int cmd, const int addr, const uchar *data, const int len, const int flag)
{
    int i=0, send_len=0, data_len=0;
    QByteArray send_buf;
    send_buf.resize(len+6);
    send_buf[0] = 0x01;
    send_buf[1] = 0xa0;
    send_buf[2] = cmd;
    send_buf[3] = (addr >> 16) & 0xff;
    send_buf[4] = (addr >> 8) & 0xff;
    send_buf[5] = (addr >> 0) & 0xff;
    if (data != NULL && flag == 0){
        data_len = 256;
    }else{
        data_len = len;
    }

    for(i=0;i<data_len;i++) {
        send_buf[i+6] = data[i];
    }
    //添加CRC
    unsigned short CRC = CRC16Check((unsigned char *)send_buf.data(), send_buf.count());

    send_buf.append((CRC >> 8) & 0xff);
    send_buf.append((CRC >> 0) & 0xff);

    send_len = m_com->write(send_buf);
    if (send_len>0){
        send_count += send_len;
        cur_pos = cur_pos + send_len - 6 - 2;
        for(i=0;i<data_len;i++) {
            m_dataAll.append(data[i]);
        }
        qDebug()<<"Send success!";
        return true;
    }else{
        qDebug()<<"Send failed!";
        return false;
    }

}

bool ComDriver::FetchData(uchar *data, int *len, int start_pos)
{
    int value = 0;
    bool ok = false;
    int i = 0, pos = 0;
    //判断是否已经取完txt数据
    if (start_pos >= file_byte_count){
        return false;
    }
    while (1){
        if (dtype == 0){        //压缩图片
            pos = (start_pos+i)/2;
            if (pos >= dataStr.count())
                break;
            //qDebug()<<pos<<start_pos<<i<<dataStr[pos];
            if (dataStr[pos].indexOf("0x")>-1 || dataStr[pos].indexOf("0X")>-1){
                value = dataStr[pos].toInt(&ok, 16);
            }else{
                value = dataStr[pos].toInt(&ok, 10);
            }
            data[i++] =(uchar)((value >> 0) & 0xff);
            data[i++] = (uchar)((value >> 8) & 0xff);
        }else if (dtype == 1){  //无压缩
            pos = start_pos + i;
            if (pos >= dataStr.count())
                break;
            //qDebug()<<pos<<start_pos<<i<<dataStr[pos];
            if (dataStr[pos].indexOf("0x")>-1 || dataStr[pos].indexOf("0X")>-1){
                value = dataStr[pos].toInt(&ok, 16);
            }else{
                value = dataStr[pos].toInt(&ok, 10);
            }
            data[i++] =(uchar)((value >> 0) & 0xff);
        }else if ((dtype == 2) | (dtype == 4) |
                  (dtype == 5) | (dtype == 6) |
                  (dtype == 9)){   //字库
            pos = start_pos + i;
            if (pos >= dataStr.count())
                break;
            data[i++] = (uchar)(dataStr[pos].toInt() & 0xff);
            //qDebug()<<pos<<start_pos<<data[i-1];

        }else if((dtype == 3) | (dtype == 10)){       //菜单文件
            if (dtype == 10){
                if (m_charList.isEmpty()){
                    emit ResProgress_sig(ERROR_FILE);
                    return false;
                }
            }
            pos = (start_pos + i) / 128;
            if (pos >= dataStr.count())
                break;
            //qDebug()<<pos<<start_pos<<i<<dataStr[pos];
            char *szU8 = new char[128];
            memset(szU8, 0, 128);
            int ret = QStringToMultBytes(dataStr[pos], szU8, len);
            if (ret == -1) return true;
            memcpy((uchar *)(data+i*sizeof(uchar)), (uchar *)(szU8), 128);
            i += 128;

        }else if((dtype == 11) | (dtype == 12)){  //字体数组
            pos = start_pos + i;
            if (pos >= dataStr.count())
                break;
            data[i++] = (uchar)(dataStr[pos].toInt(&ok, 16) & 0xff);
        }else if(dtype == 13){  //测试
            pos = start_pos + i;
            if (pos >= dataStr.count())
                break;
            if (dataStr[pos].indexOf("0x")>-1 || dataStr[pos].indexOf("0X")>-1){
                data[i++] = dataStr[pos].toInt(&ok, 16);
            }else{
                data[i++] = dataStr[pos].toInt(&ok, 10);
            }
        }
        if (i>=256)
            break;
    }
    *len = i;
    if (i > 256){
        qDebug()<<"123";
    }
    return true;
}

bool ComDriver::OpenFile(int type, QString name)
{
    if (dtype == 8){
        QFile f1(name);
        if(!f1.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            emit ResProgress_sig(ERROR_FILE);
            return false;
        }
        QTextStream input(&f1);
        m_charList = input.readAll();
        emit ResProgress_sig(100);
        f1.close();
        return false;
    }

    if (dataStr.isEmpty()){
        QStringList strList;
        //打开数据filename
        if (dtype == 7) return true;

        int pData;
        if (dtype == 11){   //字体数组，生成数据放入dataStr中待用
            pData = CHAR32_FIRST_ADD_SDRAM;
            for (int i=0;i<FONT_CHAR_LENGTH;i++){
                dataStr.append("0x10");
                dataStr.append("0x10");
                dataStr.append("0x02");
                dataStr.append("0x00");
                dataStr.append(QString::number((pData >>  0)&0xff, 16));
                dataStr.append(QString::number((pData >>  8)&0xff, 16));
                dataStr.append(QString::number((pData >> 16)&0xff, 16));
                dataStr.append(QString::number((pData >> 24)&0xff, 16));
                pData += 66;
            }
            for (int i=0;i<FONT_HZ_LENGTH;i++){
                dataStr.append("0x20");
                dataStr.append("0x20");
                dataStr.append("0x04");
                dataStr.append("0x00");
                dataStr.append(QString::number((pData >>  0)&0xff, 16));
                dataStr.append(QString::number((pData >>  8)&0xff, 16));
                dataStr.append(QString::number((pData >> 16)&0xff, 16));
                dataStr.append(QString::number((pData >> 24)&0xff, 16));
                pData += 132;
            }

            file_byte_count = dataStr.count();
            return true;
        }else if (dtype == 12){
            pData= CHAR16_FIRST_ADD_SDRAM;
            for (int i=0;i<FONT_CHAR_LENGTH;i++){
                dataStr.append("0x08");
                dataStr.append("0x08");
                dataStr.append("0x01");
                dataStr.append("0x00");
                dataStr.append(QString::number((pData >>  0)&0xff, 16));
                dataStr.append(QString::number((pData >>  8)&0xff, 16));
                dataStr.append(QString::number((pData >> 16)&0xff, 16));
                dataStr.append(QString::number((pData >> 24)&0xff, 16));
                pData += 16;
            }
            for (int i=0;i<FONT_HZ_LENGTH;i++){
                dataStr.append("0x10");
                dataStr.append("0x10");
                dataStr.append("0x02");
                dataStr.append("0x00");
                dataStr.append(QString::number((pData >>  0)&0xff, 16));
                dataStr.append(QString::number((pData >>  8)&0xff, 16));
                dataStr.append(QString::number((pData >> 16)&0xff, 16));
                dataStr.append(QString::number((pData >> 24)&0xff, 16));
                pData += 32;
            }
        }else if (dtype == 13){
            dataStr.append("200");
            dataStr.append("0");    //x0=200
            dataStr.append("100");
            dataStr.append("0");    //y0=100
            dataStr.append("80");
            dataStr.append("0");    //xsize=80
            dataStr.append("50");
            dataStr.append("0");    //ysize=50
            dataStr.append("0x70");
            dataStr.append("0x01");    //Id=0x170
            dataStr.append("2");
            dataStr.append("0");    //Flag=1<<1

            dataStr.append("0");
            dataStr.append("0");
            dataStr.append("0");
            dataStr.append("0");    //color=0x

            dataStr.append("0xe5");
            dataStr.append("0x85");
            dataStr.append("0x98");    //\0
            dataStr.append("0xe4");    //\xE8\x8F\x9C\xE5\x8D\x95
            dataStr.append("0xbe");
            dataStr.append("0x8c");

            file_byte_count = dataStr.count();
            return true;
        }


        QFile f(name);
        if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            emit ResProgress_sig(ERROR_FILE);
            return false;
        }
        QTextStream txtInput(&f);
        QString tmpStr = txtInput.readAll();
        if (tmpStr.isEmpty()){
            emit ResProgress_sig(ERROR_FILE);
            return false;
        }
        if ((dtype ==0) | (dtype == 1)){   //压缩和无压缩图片的文件处理
            QRegExp rx1("static GUI_CONST_STORAGE.+\n([.\n]+)GUI_CONST_STORAGE");
            rx1.setMinimal(true);
            int pos = 0;

            QString datatmpStr;
            while ((pos = rx1.indexIn(tmpStr, pos)) != -1){
                datatmpStr.push_back(rx1.capturedTexts().at(0));
                pos += rx1.matchedLength();
            }
            //根据文本内容判断选择压缩方式是否正确
            int idx = datatmpStr.indexOf("0x");

            if (dtype == 0){        //下载无压缩，文本中没有注释
                if ((datatmpStr[idx+6] != ',') || (datatmpStr[idx+4] == ',')){
                    emit ResProgress_sig(ERROR_PICTYPE0);
                    return false;
                }
            }else if (dtype == 1){  //下载压缩图片，文本中有注释，需要去掉注释
                if ((datatmpStr[idx+6] == ',') || (datatmpStr[idx+4] != ',')){
                    emit ResProgress_sig(ERROR_PICTYPE1);
                    return false;
                }

                strList = datatmpStr.split("\n");
                for (int i=0;i<strList.count();i++){
                    strList[i] = strList[i].mid(strList[i].indexOf("*/")+2);
                }
                datatmpStr = strList.join("\n");
            }

            pos = 0;
            QString tmp;
            QRegExp rx(tr("((0[xX])?[0-9a-fA-F]{1,4},)"));
            while ((pos = rx.indexIn(datatmpStr, pos)) != -1){
                tmp = rx.capturedTexts().at(0);
                tmp.replace(",","");
                dataStr.push_back(tmp);
                pos += rx.matchedLength();
            }
            if (dtype == 0){
                file_byte_count = dataStr.count() * 2;
            }else{
                file_byte_count = dataStr.count();
            }
        }else if ((dtype == 2) | (dtype == 4) | (dtype == 5) | (dtype == 6) | (dtype == 9)){
            //如果下载的是宋体16，则截取.c文件中的中文字库部分下载
            if (dtype == 4){ //宋体16中文字库
                tmpStr = tmpStr.mid(tmpStr.indexOf("/* Start of unicode area <CJK Unified Ideographs> */"));
            }else if (dtype == 5){ //宋体16英文字库
                tmpStr = tmpStr.left(tmpStr.indexOf("/* Start of unicode area <CJK Unified Ideographs> */"));
            }else if (dtype == 6){   //俄文字库
                tmpStr = tmpStr.mid(tmpStr.indexOf("/* Start of unicode area <Cyrillic> */"));
            }
            strList = tmpStr.split("\n");
            if (dtype == 9){ //汉字全字库
                //如果下载的是自定义字体，则需要重排序
                QStringList defStrList;
                QString sun;
                int iun;
                bool ok;
                int j;
                for(j=0; j<strList.count();j++){
                    //这里需要记录每个字符的原始unicode和所在行号
                    int pos = strList[j].indexOf("[");
                    if (pos > 0){
                        if (strList[j].indexOf("CharInfo") > 0){
                            break;
                        }
                        sun = strList[j].mid(pos-4, 4);
                        iun = sun.toInt(&ok, 16);
                        if (ok){
                             //这里行号为key，因为qmap是按照key的大小顺序存储，方便后续处理
                            m_charUnicode.insert(j, iun);
                        }else{
                            qDebug()<<strList[j];
                        }
                    }
                }
                m_charUnicode.insert(j, 0);
                QList<int> numKeys = m_charUnicode.keys();
                for (int j=0;j<m_charList.count();j++){
                    int unc = m_charList[j].unicode();
                    int num = m_charUnicode.key(unc, -1);   //根据value查找key
                    if (num < 0) break;
                    int idx = numKeys.indexOf(num);
                    if (idx < 0) break;
                    qDebug()<<unc<<num<<idx;
                    for(int k=num;k<numKeys[idx+1];k++){
                        defStrList.append(strList[k]);
                    }
                }
                strList = defStrList;
                //写入文件
                QFile fw("defFont.txt");
                if(!fw.open(QIODevice::WriteOnly | QIODevice::Text))
                {
                    return false;
                }
                QTextStream output(&fw);
                for(int i=0;i<strList.count();i++){
                    output << strList[i] << "\n";
                }
                fw.close();
            }
            QStringList lineData;
            bool status;
            for(int j=0; j<strList.count();j++){
                status = FontFileLineCal(strList[j], &lineData);
                if (status){
                    dataStr += lineData;
                }
            }

            file_byte_count = dataStr.count();
        }else if ((dtype == 3) | (dtype == 10)){      //菜单文件的处理:一行128字节
            dataStr = tmpStr.split("\n");
            while(dataStr[dataStr.count()-1].isEmpty()){
                dataStr.removeLast();
            }
            file_byte_count = dataStr.count() * 128;
        }
        f.close();

    }

    return true;
}

int ComDriver::QStringToMultBytes(QString str, char *szUn, int *slen)
{
    int i = 0;
    QByteArray data;
    QByteArray bdata;
    const QChar *q = NULL;
    QChar qtmp;
    int num;
    q = str.unicode();

    int len = str.count();
    if (len > 42){      //128/3
        len = 42;
        emit ResProgress_sig(ERROR_FONTSIZE);
    }
    for(i=0;i<len;i++)
    {
        //https://blog.csdn.net/chary8088/article/details/21226375
        //第一步：先转unicode
        QString Dstr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        if (dtype == 10){   //全汉字字库的菜单
            if (Dstr.indexOf(str.at(i)) >= 0){  //如果为数字或者字母，则用原始的unicode码
                qtmp = str.at(i);
                num = qtmp.unicode();
            }else{
                num = CHAR_START_UNICODE + m_charList.indexOf(str.at(i));
            }
        }else{
            if (m_charList.indexOf(str.at(i)) < 0){
                s_cmd = 0;
                emit ResProgress_sig(ERROR_NOFINDCHAR, str.at(i));
                return -1;
            }
            qtmp =(QChar)*q++;
            num= qtmp.unicode();
        }
        quint8 hi = (quint8)(num >> 8);
        quint8 lo = (quint8)(num);
        data.append (hi);

        data.append (lo);
        //第二步：unicode转3字节码
        szUn[i*3+0] = 0xe0 | ((num >> 12) & 0xf);
        szUn[i*3+1] = 0x80 | ((num >> 6) & 0x3f);
        szUn[i*3+2] = 0x80 | ((num >> 0) & 0x3f);
//        bdata.append(0xe0 | ((num >> 12) & 0xf));    //剩下4bit
//        bdata.append(0x80 | ((num >> 6) & 0x3f));    //中间6bit
//        bdata.append(0x80 | ((num >> 0) & 0x3f));    //低6bit
    }
    *slen = 3*len;
//    *slen = bdata.count();
//    qDebug()<<"Unicode :"<<QString("%1").arg(data.toHex().data());
//    qDebug()<<"3 Bytes:"<<QString("%1").arg(bdata.toHex().data());
    return 1;
}
bool ComDriver::FontFileLineCal(QString line, QStringList *data)
{
    QStringList tmpData;
    int tmp = 0;

    //先判断是否为字体行
    if ((!line.startsWith("  _")) && (!line.startsWith("  X"))){
        return false;
    }
    line = line.replace(" ", ""); //去掉空格
    QStringList lineList = line.split(",");
    //如果最后一个为空字符串，移除
    while(lineList[lineList.count()-1].isEmpty()){
        lineList.removeLast();
    }
    for (int j=0; j<lineList.count();j++){
        tmp = 0;
        for (int i=0;i<lineList[j].count();i++){
            if (lineList[j][i] == 'X'){
                tmp = tmp + (1<<(7-i));
            }
        }
        tmpData.append(QString("%1").arg(tmp & 0xff));
    }

    *data = tmpData;
    return true;
}


void ComDriver::SendMsg()
{
    s_cmd = 0x5d;
    SendMsgDownLoad(s_cmd, m_address, NULL, 0);

//    QString str = "АБВГЁ";
//    int len;
//    char *szU8 = new char[128];
//    memset(szU8, 0, 128);
//    QStringTo3Bytes(str, szU8, &len);
//    SendMsgDownLoad(0x11, addr, (uchar *)szU8, len, 1);
}



void ComDriver::DownLoad_slt(const int type, const int cmd, const int addr, const QString filename, int flag)
{
    if (flag == CANCEL_OK){
        s_cmd = 0xff;
        m_sendTimer->stop();
        emit ResProgress_sig(CANCEL_OK);
        return;
    }else if (flag == SERIAL_SET){
        QStringList para = filename.split("+");
        SetSerialPara(para[0], para[1], para[2], para[3]);
        return;
    }
    m_serialType = FLASH_DOWNLOAD;
    //清理历史变量
    cur_pos = 0;
    send_count = 0;
    receive_count = 0;
    dataStr = QStringList();
    m_dataAll.clear();
    m_charUnicode.clear();

    //检查串口是否打开
    if (!m_com->isOpen()){
        emit ResProgress_sig(ERROR_OPEN);
    }
    //参数合法性检查
    if ((addr < 0) || ((uint)addr > 0x80000000)){
        emit ResProgress_sig(ERROR_ADDR);
    }
    dtype = type;

    bool status = OpenFile(type, filename);
    if (!status){
        return;
    }

    //定位

    m_cmd = cmd;
    m_flag = flag;

    m_address = addr;
    m_filename = filename;

    SendMsg();
    m_sendTimer->start(500);
}

void ComDriver::ReceiveMsg()
{
    m_sendTimer->stop();
    //1、读取并处理串口缓冲区数据
    bool status = false;
    uchar data[512];

    int len = 0;
    bool f_status = false;
    if ((dtype == 2) | (dtype == 4) | (dtype == 5) | (dtype == 6) | (dtype == 9)){
        memset(data, 0xff, 512);
    }else{
        memset(data, 0, 512);
    }

    QByteArray seial_buff = m_com->readAll();
    if(!seial_buff.isEmpty())
    {
        if (m_serialType == FLASH_DECODE){
            QString out = QString(seial_buff);
            qDebug()<<"Recive:"<<out;
            if (out.indexOf("1020")>-1){
                emit ResProgress_sig(DECODE_OK);
                m_serialType = -1;
            }else if (out.indexOf("19")>-1){
                emit ResProgress_sig(DECODE_CRP2);
                m_serialType = -1;
            }
            return;
        }

        //这里一定要做包的完整性校验，否则会因为硬件差异，一个包分两次传输
        m_ReceiveBuf.append(seial_buff);

        int r_cnt = m_ReceiveBuf.count();
        qDebug()<<"Recive:"<<m_ReceiveBuf.toHex().data();
        if (r_cnt < 8){
            return;
        }
        //CRC校验，如果不通过----
        receive_count += 8;
        unsigned char r_cmd = (unsigned char)m_ReceiveBuf[1];
        //删除本次处理完的包
        m_ReceiveBuf.remove(0, 8);

        switch (r_cmd) {
        case 0x18:
            qDebug()<<"CRC error!";
            break;
        case 0x19:
            status = true;
            qDebug()<<"Store error!";
            break;
        case 0x20:
            qDebug()<<"Length error!";
            break;
        case 0x21:
            qDebug()<<"CRC Length error!";
            break;
        case 0x22:
            qDebug()<<"Address error!";
            break;
        case 0xa0:
            status = true;
            qDebug()<<"Receive sucess!";
            break;
        default:

            qDebug()<<r_cmd<<"Noknow error!";
            break;
        }

        switch (s_cmd) {
        case 0x5d:  //定位
            if (status){
                qDebug()<<"Set start address success!";
                if (m_cmd == 0x0){  //如果输入的擦除大小为0，则直接跳过擦除
                    s_cmd = 0x5b;
                    SendMsgDownLoad(s_cmd, m_address, NULL, 0);
                }else{
                    s_cmd = m_cmd;
                    SendMsgDownLoad(s_cmd, m_address, NULL, 0);
                }

            }else{
                m_sendTimer->start(500);
                s_cmd = 0x5d;
                SendMsgDownLoad(s_cmd, m_address, NULL, 0);
            }
            break;
        case 0x57:      //4k
        case 0x58:      //8k
        case 0x59:      //16k
        case 0x5c:      //20k
        case 0x5a:      //1M
        case 0x5f:      //252k
            if (status){
                qDebug()<<"Erase success!";
                if (dtype == 7) {
                    emit ResProgress_sig(100);
                    return;
                }
                OpenFile(dtype, m_filename);
                f_status = FetchData(data, &len, cur_pos);
                if (!f_status){
                    emit ResProgress_sig(ERROR_FILE);
                    return;
                }
                if (s_cmd == 0) return;
                s_cmd = 0x5b;
                SendMsgDownLoad(s_cmd, m_address, data, len);
            }else{
                s_cmd = 0x5d;   //如果擦除失败，则重新定位擦除
                SendMsgDownLoad(s_cmd, m_address, NULL, 0);
            }

            break;
        case 0x5b:
            if (status){
                int percent = (cur_pos*100)/file_byte_count;
                emit ResProgress_sig(percent);

                qDebug()<<cur_pos<<"Down part success!";
                f_status = FetchData(data, &len, cur_pos);
                if (f_status){
                    s_cmd = 0x5b;
                    SendMsgDownLoad(s_cmd, m_address, data, len);
                }else{
                    uchar *strAll = NULL;
                    strAll = (uchar *)m_dataAll.data();
                    uint CRC_CCITT = CRC16Check_CCITT(strAll, m_dataAll.count());
                    qDebug()<<cur_pos<<send_count<<receive_count<<CRC_CCITT;
                    data[0] = (cur_pos >> 0) & 0xff;
                    data[1] = (CRC_CCITT >> 8) & 0xff;
                    data[2] = (CRC_CCITT >> 0) & 0xff;
                    s_cmd = 0x60;
                    SendMsgDownLoad(s_cmd, (cur_pos>>8), data, 3, 1);
                }

            }else{
                f_status = FetchData(data, &len, cur_pos);
                s_cmd = 0x5b;
                SendMsgDownLoad(s_cmd, m_address, data, len);
            }
            break;
        case 0x60:
            if (status){
                qDebug()<<"Download finshed!";
            }else{

            }
            break;
        case 0xff:

        default:
            break;
        }
    }
}

void ComDriver::SendMsg_slt(char* data)
{
    if (!m_com->isOpen()){
        return;
    }
    m_serialType = FLASH_DECODE;
    m_com->write(data);
    qDebug()<<"Send:"<<QString(data);
    while (!m_com->waitForBytesWritten(1000));

}

