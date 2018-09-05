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
ComObject::ComObject(QString name, int baud, QObject *parent) :
    QObject(parent)
{
    //1、初始化串口线程
    QThread *com_thread = new QThread;
    ComDriver *com = new ComDriver(name, baud);
    com->moveToThread(com_thread);
    com_thread->start();

    //连接信号
    connect(this, SIGNAL(DownLoad_sig(int,int,int,const QString,int)),
            com, SLOT(DownLoad_slt(int,int,int,const QString,int)));

    connect(com, SIGNAL(ResProgress_sig(int)),
            this, SLOT(ResProgress_slt(int)));

}

void ComObject::DownLoad(const int type, const int cmd, const int addr, const QString filename, int flag)
{
    emit DownLoad_sig(type, cmd, addr, filename, flag);
}

void ComObject::ResProgress_slt(int pos)
{
    emit ResProgress_sig(pos);
}



ComDriver::ComDriver(QString name, int baud, QObject *parent) :
    QObject(parent)
{

    //打开窗口
    m_com = new QSerialPort();
    m_com->setPortName(name);
    if (!m_com->open(QIODevice::ReadWrite)){
        return;
    }
    if (baud == 9600)
        m_com->setBaudRate(QSerialPort::Baud9600);
    else
        m_com->setBaudRate(QSerialPort::Baud9600);
    m_com->setDataBits(QSerialPort::Data8);
    m_com->setParity(QSerialPort::NoParity);
    m_com->setStopBits(QSerialPort::OneStop);
    m_com->setFlowControl(QSerialPort::NoFlowControl);
    connect(m_com,SIGNAL(readyRead()),this,SLOT(ReceiveMsg()));
    qDebug()<<"SerialPort is open";
}
/**
* 函数说明：CRC校验
*
* @param:需要校验的数据，长度
*
* @return:校验码
**/
unsigned int ComDriver::CRC16Check(uchar *pchMsg, short wDataLen)
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
unsigned int ComDriver::CRC16Check_CCITT(uchar *pchMsg, short wDataLen)
{
    int crc = 0xFFFF;
    for (int j = 0; j < wDataLen; j++) {
        crc = ((crc >> 8) | (crc << 8)) & 0xffff;
        crc ^= (pchMsg[j] & 0xff);// byte to int, trunc sign
        crc ^= ((crc & 0xff) >> 4);
        crc ^= (crc << 12) & 0xffff;
        crc ^= ((crc & 0xFF) << 5) & 0xffff;
    }
    crc &= 0xffff;
    return crc;

}
bool ComDriver::SendMsg(const int cmd, const int addr, const uchar *data, const int len, const int flag)
{
    int i, send_len, data_len;
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
    int value;
    bool ok;
    int i = 0, pos = 0;
    //判断是否已经取完txt数据
    if (start_pos >= file_byte_count){
        return false;
    }
    while (1){
        if (dtype == 0){
            pos = (start_pos+i)/2;
            if (pos >= dataStr.count())
                break;
            qDebug()<<pos<<start_pos<<i<<dataStr[pos];
            if (dataStr[pos].indexOf("0x")>-1 || dataStr[pos].indexOf("0X")>-1){
                value = dataStr[pos].toInt(&ok, 16);
            }else{
                value = dataStr[pos].toInt(&ok, 10);
            }
            data[i++] =(uchar)((value >> 0) & 0xff);
            data[i++] = (uchar)((value >> 8) & 0xff);
        }else if (dtype == 1){
            pos = start_pos + i;
            if (pos >= dataStr.count())
                break;
            qDebug()<<pos<<start_pos<<i<<dataStr[pos];
            if (dataStr[pos].indexOf("0x")>-1 || dataStr[pos].indexOf("0X")>-1){
                value = dataStr[pos].toInt(&ok, 16);
            }else{
                value = dataStr[pos].toInt(&ok, 10);
            }
            data[i++] =(uchar)((value >> 0) & 0xff);
        }else if(dtype == 3){
            pos = (start_pos + i) / 128;
            if (pos >= dataStr.count())
                break;
            qDebug()<<pos<<start_pos<<i<<dataStr[pos];
            char *szU8 = new char[128];
            memset(szU8, 0, 128);
            QStringToMultiByte(dataStr[pos+0], szU8, len);
            memcpy((uchar *)(data+i*sizeof(uchar)), (uchar *)(szU8), 128);
            i += 128;

        }
        if (i>=256)
            break;
    }
    *len = i;
    return true;
}

bool ComDriver::OpenFile(QString name)
{
    if (dataStr.isEmpty()){
        //打开数据filename
        QFile f(name);
        if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return false;
        }
        QTextStream txtInput(&f);
        QString tmpStr = txtInput.readAll();
        if (dtype ==0 | dtype == 1){   //压缩和无压缩图片的文件处理
            //QFileInfo infile(m_filename);
            //QString name = infile.baseName();       //获取前缀名
            QRegExp rx1("static GUI_CONST_STORAGE.+\n([.\n]+)GUI_CONST_STORAGE");
            rx1.setMinimal(true);
            int pos = 0;

            QString datatmpStr;

            if (dtype == 0){        //下载无压缩，文本中没有注释
                datatmpStr = tmpStr;
            }else if (dtype == 1){  //下载压缩图片，文本中有注释，需要去掉注释
                while ((pos = rx1.indexIn(tmpStr, pos)) != -1){
                    datatmpStr.push_back(rx1.capturedTexts().at(0));
                    pos += rx1.matchedLength();
                }
                QStringList strList = datatmpStr.split("\n");
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
        }else if (dtype == 3){      //菜单文件的处理:一行128字节
            dataStr = tmpStr.split("\n");
            while(dataStr[dataStr.count()-1].isEmpty()){
                dataStr.removeLast();
            }
            file_byte_count = dataStr.count() * 128;
        }
        f.close();

    }
}

int ComDriver::QStringToMultiByte(QString str, char *out, int *len)
{
    char *szU8 = new char[512];
    //memset(szU8, 0, 512);
    // unicode to UTF8
    //wchar_t* wszString = ret;
    //wchar_t* wszString = L"5号端子功能";
    const wchar_t * wszString = reinterpret_cast<const wchar_t *>(str.utf16());
    //预转换，得到所需空间的大小，这次用的函数和上面名字相反
    int u8Len = ::WideCharToMultiByte(CP_UTF8, NULL, wszString, wcslen(wszString), NULL, 0, NULL, NULL);
    //同上，分配空间要给'\0'留个空间
    //UTF8虽然是Unicode的压缩形式，但也是多字节字符串，所以可以以char的形式保存
    //unicode版对应的strlen是wcslen
    ::WideCharToMultiByte(CP_UTF8, NULL, wszString, wcslen(wszString), szU8, u8Len, NULL, NULL);
    //最后加上'\0'
    //szU8[u8Len] = '\0';
    int i=0;
    int j=0;
    while(i < u8Len){
//        if ((szU8[i] == 0x30) | //0
//            (szU8[i] == 0x31) | //1
//            (szU8[i] == 0x32) | //2
//            (szU8[i] == 0x33) | //3
//            (szU8[i] == 0x34) | //4
//            (szU8[i] == 0x35) | //5
//            (szU8[i] == 0x36) | //6
//            (szU8[i] == 0x37) | //7
//            (szU8[i] == 0x38) | //8
//            (szU8[i] == 0x39) | //9
//            (szU8[i] == 0x3a) | //:
//            (szU8[i] == 0x20) | // 空格
//            (szU8[i] == 0x28) | //(
//            (szU8[i] == 0x29) ){//)
        if ((szU8[i] >= 0x20) && (szU8[i] <= 0x3a)){
            out[j++] = 0xe0;
            out[j++] = 0x80;
            out[j++] = szU8[i] - 128;
            i++;
        }else if (((szU8[i] >= 0x61) && (szU8[i] <= 0x7a)) |//a-z
                  ((szU8[i] >= 0x41) && (szU8[i] <= 0x5a))){//A-Z
            out[j++] = 0xe0;
            out[j++] = 0x81;
            out[j++] = szU8[i] - 192;
            i++;
        }else if ((szU8[i] == 0x21) && (szU8[i+1] == 0x03)){//℃
            out[j++] = 0xe2;
            out[j++] = 0x84;
            out[j++] = 0x83;
            i = i + 2;
        }else{
            out[j++] = szU8[i];
            i++;
        }

    }

    *len = j;

}

int ComDriver::QStringToUnicode(QString str, char *szUn, int *slen)
{
    // 这里传来的字符串一定要加tr，main函数里可以加 QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    QString stt = QObject::tr("%1").arg ("5号端子功能");

    QByteArray data;
    const QChar *q;
    QChar qtmp;
    int num;
    q=stt.unicode();
    int len=stt.count();
    for(int i=0;i<len;i++)
    {
        qtmp =(QChar)*q++;
        num= qtmp.unicode();

        quint8 hi = (quint8)(num >> 8);
        quint8 lo = (quint8)(num);
        data.append (hi);
        data.append (lo);
    }

    while(data.count () <8)
    {
        data.append (QByteArray::fromHex ("20"));
    }
    qDebug ()<<"string to unicode :"<<QObject::tr("%1").arg(data.toHex().data ());

}



void ComDriver::DownLoad_slt(const int type, const int cmd, const int addr, const QString filename, int flag)
{
    //清理历史变量
    cur_pos = 0;
    send_count = 0;
    receive_count = 0;
    dataStr = QStringList();
    m_dataAll.clear();

    //检查串口是否打开
    if (!m_com->isOpen()){
        emit ResProgress_sig(ERROR_OPEN);
    }
    //参数合法性检查
    if (addr < 0 || addr > 0x80000000){
        emit ResProgress_sig(ERROR_ADDR);
    }
    OpenFile(filename);

    //定位
    s_cmd = 0x5d;
    m_cmd = cmd;
    m_flag = flag;
    dtype = type;
    m_address = addr;
    m_filename = filename;

    SendMsg(0x5d, addr, NULL, 0);

//    QString str = "Mpa";
//    int len;
//    char *szU8 = new char[128];
//    memset(szU8, 0, 128);
//    QStringToMultiByte(str, szU8, &len);
//    SendMsg(0x11, addr, (uchar *)szU8, len, 1);
}

void ComDriver::ReceiveMsg()
{
    //1、读取并处理串口缓冲区数据
    bool status = false;
    uchar data[512];

    int len;
    bool f_status;
    memset(data, 0, 512);
    QByteArray seial_buff = m_com->readAll();
    if(!seial_buff.isEmpty())
    {
        receive_count += seial_buff.count();
        unsigned char r_cmd = (unsigned char)seial_buff[1];
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
                    SendMsg(s_cmd, m_address, NULL, 0);
                }else{
                    s_cmd = m_cmd;
                    SendMsg(s_cmd, m_address, NULL, 0);
                }

            }else{
                s_cmd = 0x5d;
                SendMsg(s_cmd, m_address, NULL, 0);
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
                OpenFile(m_filename);
                f_status = FetchData(data, &len, cur_pos);
                if (!f_status){
                    emit ResProgress_sig(ERROR_FILE);
                    return;
                }
                s_cmd = 0x5b;
                SendMsg(s_cmd, m_address, data, len);
            }else{
                s_cmd = 0x5d;   //如果擦除失败，则重新定位擦除
                SendMsg(s_cmd, m_address, NULL, 0);
            }

            break;
        case 0x5b:
            if (status){
                emit ResProgress_sig((cur_pos*100)/file_byte_count);

                qDebug()<<"Down part success!";
                f_status = FetchData(data, &len, cur_pos);
                if (f_status){
                    s_cmd = 0x5b;
                    SendMsg(s_cmd, m_address, data, len);
                }else{
                    uchar *strAll;
                    strAll = (uchar *)m_dataAll.data();
                    uint CRC_CCITT = CRC16Check_CCITT(strAll, m_dataAll.count());
                    qDebug()<<cur_pos<<send_count<<receive_count<<CRC_CCITT;
                    data[0] = (cur_pos >> 0) & 0xff;
                    data[1] = (CRC_CCITT >> 8) & 0xff;
                    data[2] = (CRC_CCITT >> 0) & 0xff;
                    s_cmd = 0x60;
                    SendMsg(s_cmd, (cur_pos>>8), data, 3, 1);
                }

            }else{
                f_status = FetchData(data, &len, cur_pos);
                s_cmd = 0x5b;
                SendMsg(s_cmd, m_address, data, len);
            }
            break;
        case 0x60:
            if (status){
                qDebug()<<"Download finshed!";
            }else{

            }
            break;
        default:
            break;
        }
    }
}
