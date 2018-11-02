#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setUi();
    SetMenu();
}

MainWindow::~MainWindow()
{

}

void MainWindow::setUi()
{
    setWindowIcon(QIcon(":/mamtool.ico"));
    resize(600,450);
    QTabWidget *w = new QTabWidget();
    setCentralWidget(w);
    QWidget *main0 = new QWidget();
    QWidget *main1 = new QWidget(this);
    QWidget *main2 = new QWidget(this);
    QWidget *main3 = new QWidget(this);

#if TEST_USER
    w->addTab(main0, "程序修改");  
#endif
    w->addTab(main1, "处理菜单");
    w->addTab(main2, "Flash下载");
    w->addTab(main3, "其它工具");


    QVBoxLayout *vbox = new QVBoxLayout(main0);

    QHBoxLayout *hbox = new QHBoxLayout();
    QString currentPath = QDir::currentPath();
    //QString currentPath = QString("D:\\2-Work\\0-Day_work\\tmp\\M6080A_E22A_BZ_180705");
    m_srcPath = new QLineEdit(currentPath);
    QPushButton *btn = new QPushButton("路径");
    hbox->addWidget(new QLabel("路径："));
    hbox->addWidget(m_srcPath);
    hbox->addWidget(btn);
    hbox->setStretch(0,1);
    hbox->setStretch(1,5);
    hbox->setStretch(2,1);


    QGroupBox *groupbox = new QGroupBox();
    groupbox->setTitle("修改项");
    groupbox->setAlignment(Qt::AlignCenter);
    QGridLayout *gbox = new QGridLayout();
    groupbox->setLayout(gbox);
    m_cb_data = new QCheckBox("日期：");
    m_cb_ckCode = new QCheckBox("CK码：");
    m_cb_password = new QCheckBox("密码：");
    m_cb_vsd = new QCheckBox("站号");

    m_cb_vfactor = new QCheckBox("电压系数");

    m_cb_jiemi = new QCheckBox("解密");
    m_name = new QLineEdit();


    QString currentDate = QDate::currentDate().toString("yyyyMMdd");
    m_data = new QLineEdit(currentDate.mid(2));
    m_ckCode = new QLineEdit();
    m_company = new QLineEdit;
    m_password = new QLineEdit;

    gbox->addWidget(new QLabel("软件名："),0,0);
    gbox->addWidget(m_cb_data,1,0);
    gbox->addWidget(m_cb_ckCode,2,0);
    gbox->addWidget(m_cb_password,3,0);

    gbox->addWidget(m_cb_vsd,4,0);


    gbox->addWidget(m_name,0,1,1,2);
    gbox->addWidget(m_data,1,1,1,2);
    gbox->addWidget(m_ckCode,2,1,1,2);
    gbox->addWidget(m_password,3,1,1,2);
    gbox->addWidget(m_cb_vfactor,4,1);
    gbox->addWidget(m_cb_jiemi,4,2);


    QVBoxLayout *vbox_btn = new QVBoxLayout();
    m_start = new QPushButton("1执行");
    m_build = new QPushButton("2编译");
    m_download = new QPushButton("3下载");
    m_copy = new QPushButton("4拷hex");
    m_check = new QPushButton("5检查");
    m_compress = new QPushButton("6打包");
    m_clear = new QPushButton("7清理");

    vbox_btn->addWidget(m_start);
    vbox_btn->addWidget(m_build);
    vbox_btn->addWidget(m_download);
    vbox_btn->addWidget(m_copy);
    vbox_btn->addWidget(m_check);
    vbox_btn->addWidget(m_compress);
    vbox_btn->addWidget(m_clear);

    QHBoxLayout *hbox_btn1 = new QHBoxLayout();
    m_modfiy_build = new QPushButton("修改程序-编译工程");
    m_modfiy_build->setFixedHeight(50);
    m_compress_clear = new QPushButton("打包程序-清理目录");
    m_compress_clear->setFixedHeight(50);
    hbox_btn1->addWidget(m_modfiy_build);
    hbox_btn1->addWidget(m_compress_clear);

    m_loglist = new QListWidget;
    QHBoxLayout *hbox_set = new QHBoxLayout();
    hbox_set->addWidget(groupbox);
    hbox_set->addWidget(m_loglist);
    hbox_set->addLayout(vbox_btn);
    hbox_set->setStretch(0,5);
    hbox_set->setStretch(1,3);
    hbox_set->setStretch(2,1);

    vbox->addLayout(hbox);
    vbox->addLayout(hbox_set);
    vbox->addLayout(hbox_btn1);


    m_cb_data->setChecked(true);
    //m_cb_ckCode->setChecked(true);
    //m_cb_password->setChecked(true);

    connect(m_start, SIGNAL(clicked(bool)), this, SLOT(on_m_start_clicked()));
    connect(m_build, SIGNAL(clicked(bool)), this, SLOT(on_m_build_clicked()));
    connect(m_download, SIGNAL(clicked(bool)), this, SLOT(on_m_download_clicked()));
    connect(m_check, SIGNAL(clicked(bool)), this, SLOT(on_m_check_clicked()));
    connect(m_copy, SIGNAL(clicked(bool)), this, SLOT(on_m_copy_clicked()));
    connect(m_compress, SIGNAL(clicked(bool)), this, SLOT(on_m_compress_clicked()));
    connect(m_clear, SIGNAL(clicked(bool)), this, SLOT(on_m_clear_clicked()));
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(on_btn_clicked()));

    connect(m_modfiy_build, SIGNAL(clicked(bool)), this, SLOT(on_build2_clicked()));
    connect(m_compress_clear, SIGNAL(clicked(bool)), this, SLOT(on_clear2_clicked()));

    m_winRARCfg = DIR_WINRAR;
    m_keilCfg = DIR_KEIL;
    m_checkCfg = DIR_CHECK;


    //处理菜单表格
    QVBoxLayout *excel_vbox = new QVBoxLayout(main1);
    QHBoxLayout *excel_hbox = new QHBoxLayout();
    QString currentPathx = QDir::currentPath();
    //QString currentPath = "D:\\2-Work\\leek.project\\mam_tools\\xlsx\\菜单_6070BZ_E22.xls";
    m_srcPathx = new QLineEdit(currentPathx);
    m_chooseBtn = new QPushButton("选择");
    excel_hbox->addWidget(new QLabel("表格路径："));
    excel_hbox->addWidget(m_srcPathx);
    excel_hbox->addWidget(m_chooseBtn);
    excel_hbox->setStretch(0,1);
    excel_hbox->setStretch(1,5);
    excel_hbox->setStretch(2,1);

    QHBoxLayout *excel_hbox1 = new QHBoxLayout();
    QString outPath = QDir::currentPath();

    m_outPath = new QLineEdit(outPath);
    m_chooseoutBtn = new QPushButton("选择");
    excel_hbox1->addWidget(new QLabel("输出路径："));
    excel_hbox1->addWidget(m_outPath);
    excel_hbox1->addWidget(m_chooseoutBtn);
    excel_hbox1->setStretch(0,1);
    excel_hbox1->setStretch(1,5);
    excel_hbox1->setStretch(2,1);

    m_colNum = new QLineEdit("1");
    m_createBtn = new QPushButton("确定");
    m_createBtn->setToolTip(tr("顺序：简体中文->英文->西班牙文->繁体中文->法文->德文"));
    QHBoxLayout *hbox_btn = new QHBoxLayout();
    hbox_btn->addWidget(new QLabel("语言数量："));
    hbox_btn->addWidget(m_colNum);
    hbox_btn->addWidget(m_createBtn);
    hbox_btn->setStretch(0,1);
    hbox_btn->setStretch(1,5);
    hbox_btn->setStretch(2,1);


    excel_vbox->addLayout(excel_hbox);
    excel_vbox->addLayout(excel_hbox1);    
    excel_vbox->addLayout(hbox_btn);

    connect(m_chooseBtn, SIGNAL(clicked(bool)), this, SLOT(on_m_chooseBtn_clicked()));
    connect(m_chooseoutBtn, SIGNAL(clicked(bool)), this, SLOT(on_m_chooseoutBtn_clicked()));
    connect(m_createBtn, SIGNAL(clicked(bool)), this, SLOT(on_m_createBtn_clicked()));

    //flash下载页面

    QGridLayout *tgbox = new QGridLayout(main2);
    m_table = new QTableWidget();

    m_table->setColumnCount(4);
    m_table->setColumnWidth(0, 110);
    m_table->setColumnWidth(1, 150);
    m_table->setColumnWidth(2, 60);
    m_table->horizontalHeader()->setStretchLastSection(true);//关键
    m_table->setHorizontalHeaderLabels(QStringList()<<"操作"<<"起始地址"<<"擦除大小"<<"文件"<<"状态");

    m_exportcfg = new QPushButton("导出配置");
    m_exportcfg->setFixedHeight(40);
    m_inportcfg = new QPushButton("导入配置");
    m_inportcfg->setFixedHeight(40);
    m_insert = new QPushButton("添加");
    m_insert->setFixedHeight(40);
    m_delete = new QPushButton("删除");
    m_delete->setFixedHeight(40);
    m_downtable = new QPushButton("下载");
    m_downtable->setFixedHeight(40);
    connect(m_exportcfg, SIGNAL(clicked(bool)), this, SLOT(on_exportcfg_clicked()));
    connect(m_inportcfg, SIGNAL(clicked(bool)), this, SLOT(on_inportcfg_clicked()));
    connect(m_insert, SIGNAL(clicked(bool)), this, SLOT(on_insert_clicked()));
    connect(m_delete, SIGNAL(clicked(bool)), this, SLOT(on_delete_clicked()));
    connect(m_downtable, SIGNAL(clicked(bool)), this, SLOT(on_downtable_clicked()));
    connect(m_table, SIGNAL(itemDoubleClicked(QTableWidgetItem*)),
            this, SLOT(SetFilePath(QTableWidgetItem*)));


    tgbox->addWidget(m_table,0,0,1,5);
    tgbox->addWidget(m_exportcfg,1,1,1,1);
    tgbox->addWidget(m_inportcfg,1,0,1,1);
    tgbox->addWidget(m_insert,1,2,1,1);
    tgbox->addWidget(m_delete,1,3,1,1);
    tgbox->addWidget(m_downtable,1,4,1,1);


    m_com_obj = NULL;
    m_ComPort = "COM1";
    m_baudRate = "9600";
    m_Parity = "Even";
    m_Stopbit = "1";
    m_flashType<<"无压缩图片"<<"压缩图片"
               <<"宋体32字库"<<"菜单"
               <<"汉字16字库"<<"英文16字库"
               <<"其他字库"<<"擦除Flash"
               <<"全字符文本"<<"全汉字字库"
               <<"菜单(全汉字)"
               <<"字体32数组"<<"字体16数组"
               <<"测试";
    m_flashAddr<<"CharLib(000000)"<<"FirstPic(100000)"
                <<"ZHChar16(420000)"<<"ENChar16(45f000)"

                <<"Run(300000)"<<"User(30a000)"
                <<"Fact(346000)"<<"Calc(314000)"
                <<"Block(31e000)"<<"Hard(30f000)"
                <<"Maint(328000)"<<"Vsd(34b000)"
                <<"Touch(341000)"<<"TimePress(337000)"
                <<"RunStop(33c000)"<<"Fault(323000)"
                <<"MVSD(305000)"<<"FVSD(32d000)"
                <<"Data(319000)"<<"SetVSD(3c0000)"
                <<"Mode(378000)"<<"Return(332000)"

                <<"Stop(200000)"
                <<"Load1(23f000)"<<"Load2(27e000)"
                <<"Unld1(2bd000)"<<"Unld2(37d000)"
                <<"Fan1(36e000)"<<"Fan2(373000)"

                <<"TipRun(350000)"<<"TipPress(355000)"
                <<"TipPown(35a000)"<<"TipRemote(35f000)"
                <<"TipBlock(364000)"<<"TipModbus(369000)";

    m_flashSize<<"4K"<<"8K"<<"16K"<<"20K"<<"252K"<<"1M"<<"0K";

    pStatusBar = new QStatusBar();
    pStatusBar->hide();
    setStatusBar(pStatusBar);
    pProgressBar = new QProgressBar();
    pProgressBar->setAlignment(Qt::AlignCenter);
    pProgressBar->setRange(0,100);

    QLabel *pLabel = new QLabel();
    m_progresstext = new QLabel();
    pLabel->setText("请稍候...");

    pStatusBar->addWidget(pLabel);//添加到状态栏的左边
    pStatusBar->addWidget(pProgressBar);
    pStatusBar->addWidget(m_progresstext);//添加到状态栏的左边

    m_SerialChange = false;


    //其他功能页面
    QVBoxLayout *otherbox = new QVBoxLayout(main3);
    otherbox->setMargin(10);
    //算密码页面设计
    QGroupBox *passwd = new QGroupBox();
    passwd->setTitle("计算密码");
    otherbox->addWidget(passwd);

    m_comfact = new QComboBox();
    m_comfact->addItem("台盛");
    m_comfact->addItem("鑫磊");
    m_comfact->addItem("太原大汇-动态用户密码");
    m_comfact->addItem("太原大汇-动态厂家密码");
    m_comfact->addItem("武汉格高(交换13,+1357)");
    m_comfact->addItem("博士汉德(2a 3b d+8 4c)");
    m_comfact->addItem("英纳贝特(3a 2b 5+d 7c)");

    m_comfact->setFixedHeight(40);

    m_tippass = new QLineEdit;
    m_tippass->setPlaceholderText("提示码");
    m_dynpass = new QLabel("密码：");
    m_dynpass->setStyleSheet("border:1px solid blue;");
    m_dynpass->setFixedWidth(100);
    QHBoxLayout *passbox = new QHBoxLayout(passwd);
    passbox->addWidget(m_comfact);
    passbox->addWidget(m_tippass);
    passbox->addWidget(m_dynpass);

    connect(m_tippass, SIGNAL(returnPressed()),
            this, SLOT(cal_pass()));

    //芯片解密
    QGroupBox *devicedecode = new QGroupBox();
    devicedecode->setTitle("芯片解密");
    otherbox->addWidget(devicedecode);
    QPushButton *flashDecode = new QPushButton("解密");
    m_deviceType = new QComboBox();
    m_deviceType->addItems(QStringList()<<"LPC1788"<<"LPC845");
    QGridLayout *fdbox = new QGridLayout(devicedecode);
    fdbox->addWidget(m_deviceType, 0, 0);
    fdbox->addWidget(flashDecode, 0, 1);
    connect(flashDecode, SIGNAL(clicked()), this, SLOT(on_flashdeconde_clicked()));


    //UNICODE
    QGroupBox *charCoder = new QGroupBox();
    QGridLayout *codeBox = new QGridLayout(charCoder);
    charCoder->setTitle("字符<->Unicode");
    otherbox->addWidget(charCoder);
    m_charEdit = new QLineEdit;
    m_unicodeEdit = new QLineEdit;
    m_byte3Edit = new QLineEdit;
    codeBox->addWidget(new QLabel("字符:"),0,0,1,1);
    codeBox->addWidget(m_charEdit,0,1,1,4);
    codeBox->addWidget(new QLabel("Unicode:"),1,0,1,1);
    codeBox->addWidget(m_unicodeEdit,1,1,1,4);
    codeBox->addWidget(new QLabel("3字节码:"),2,0,1,1);
    codeBox->addWidget(m_byte3Edit,2,1,1,4);
    connect(m_charEdit, SIGNAL(returnPressed()),
            this, SLOT(charConvertCoder()));
    connect(m_unicodeEdit, SIGNAL(returnPressed()),
            this, SLOT(charConvertCoder()));
    connect(m_byte3Edit, SIGNAL(returnPressed()),
            this, SLOT(charConvertCoder()));
    //改6090程序ready页面设计
    QGroupBox *M90Ready = new QGroupBox();
    M90Ready->setTitle("软件批量升级");
    otherbox->addWidget(M90Ready);
    QGridLayout *M90box = new QGridLayout(M90Ready);
    M90path = new QLineEdit();
    QPushButton *M90Choose = new QPushButton("选择路径");
    QPushButton *M90Uncomp = new QPushButton("批量解压");
    QPushButton *M90Compile = new QPushButton("批量编译");

    QPushButton *M90Change = new QPushButton("批量修改");
    QPushButton *M90Compress = new QPushButton("批量打包");

    QPushButton *M90Modify = new QPushButton("批量解压并修改");


    M90box->addWidget(M90path, 0, 0, 1, 2);
    M90box->addWidget(M90Choose, 1, 0, 1, 1);

    M90box->addWidget(M90Uncomp, 2, 0, 1, 1);
    M90box->addWidget(M90Change, 2, 1, 1, 1);

    M90box->addWidget(M90Compile, 3, 0, 1, 1);
    M90box->addWidget(M90Compress, 3, 1, 1, 1);

//    M90box->addWidget(M90Modify, 4, 0, 1, 1);

    connect(M90Choose, SIGNAL(clicked()), this, SLOT(on_M90Choose_clicked()));


    connect(M90Uncomp, SIGNAL(clicked()), this, SLOT(on_M90Uncomp_clicked()));
    connect(M90Compile, SIGNAL(clicked()), this, SLOT(on_M90Compile_clicked()));

    connect(M90Change, SIGNAL(clicked()), this, SLOT(on_M90Change_clicked()));
    connect(M90Compress, SIGNAL(clicked()), this, SLOT(on_M90Compress_clicked()));

//    connect(M90Modify, SIGNAL(clicked()), this, SLOT(on_M90Modfiy_clicked()));

    otherbox->addStretch();
}
void MainWindow::cal_pass()
{
    int num = m_comfact->currentIndex();
    unsigned short CalCode = 0, dynpass = 0;
    unsigned short temp,temp1,temp2,temp3,temp4;
    unsigned short result1,result2,result3,result4;
    CalCode = m_tippass->text().toInt();
    temp1=CalCode%10;	//D
    temp2=CalCode%100/10;//C
    temp3=CalCode%1000/100; //B
    temp4=CalCode/1000;	//A

    switch (num) {
    case 0:     //台盛

        result4 = (temp4 * 26)%10;//A
        result3 = (temp3 * 27)%10;//B
        result2 = (temp2 * 28)%10;//C
        result1 = (temp1 * 14)%10;//D

        temp = result1;
        result1 = result4;
        result4 = temp;

        result4 = (result4+2)%10;//A
        result3 = (result3+7)%10;//B
        result2 = (result2+9)%10;//C
        result1 = (result1+3)%10;//D

        temp = result1;
        result1 = result4;
        result4 = temp;

        result4 = (result4+temp4)%10;//A
        result3 = (result3+temp3)%10;//B
        result2 = (result2+temp2)%10;//C
        result1 = (result1+temp1)%10;//D

        dynpass = result1+result2*10+result3*100+result4*1000;
        break;
    case 1:     //鑫磊

        temp3 = temp3*9+1;
        temp2 = temp2*8+1;

        temp4= temp3%10; //
        temp3/=10; //
        temp1=temp2/10;
        temp2%=10; //

        dynpass = temp1+temp2*10+temp3*100+temp4*1000;
        break;
    case 2:
        temp1= (temp1+7)%10;
        temp2= (temp2+5)%10;
        temp3= (temp3+0)%10;
        temp4= (temp4+8)%10;

        dynpass = temp3+temp1*10+temp4*100+temp2*1000;

        break;
    case 3:
        temp1= (temp1+4)%10;
        temp2= (temp2+8)%10;
        temp3= (temp3+1)%10;
        temp4= (temp4+2)%10;

        dynpass = temp3+temp4*10+temp1*100+temp2*1000;

        break;
    case 4:
        temp1 += 7;	//D
        temp2 += 1;	//C
        temp3 += 3; //B
        temp4 += 5;	//A

        temp4%=10; //E
        temp3%=10; //F
        temp2%=10; //G
        temp1%=10; //H
        dynpass = temp1+temp4*10+temp3*100+temp2*1000;

        break;
    case 5:
        temp4*=2; //A
        temp3*=3; //B
        temp2*=4; //C
        temp1+=8; //D


        //
        temp4%=10; //E
        temp3%=10; //F
        temp2%=10; //G
        temp1%=10; //H
        dynpass = temp2+temp1*10+temp3*100+temp4*1000;
        break;
    case 6:
        temp4*=3;//a
        temp3*=2;//b
        temp2*=7;//c
        temp1+=5;//d

 //
       temp4%=10; //E a
       temp3%=10; //F b
       temp2%=10; //G c
       temp1%=10; //H d
        dynpass = temp2+temp1*10+temp3*100+temp4*1000;
        break;
    default:
        if (temp3 > 7)
          temp3 = 0;
        else
          temp3 = temp3 + 1;

        if (temp1 > 6)
          temp1 = 0;
        else
          temp1 = temp1 + 2;

        temp4%=10; //E
        temp3%=10; //F
        temp2%=10; //G
        temp1%=10; //H
        dynpass = temp1+temp4*10+temp3*100+temp2*1000;
        break;
    }

    m_dynpass->setText(QString("密码：%1").arg(dynpass));
}

void MainWindow::charConvertCoder()
{
    QByteArray data, bdata;
    QString charTmp, unicodeTmp, byte3Tmp;
    int num;
    QString charStr = m_charEdit->text();
    QString unicodeStr = m_unicodeEdit->text();
    QString byte3Str = m_byte3Edit->text();
    if (sender() == m_charEdit){
        for(int i=0;i<charStr.count();i++){
            //转unicode
            num= charStr.at(i).unicode();
            quint8 hi = (quint8)(num >> 8);
            quint8 lo = (quint8)(num);
            data.append (hi);
            data.append (lo);
            //转3字节码
            bdata.append(0xe0 | ((num >> 12) & 0xf));    //剩下4bit
            bdata.append(0x80 | ((num >> 6) & 0x3f));    //中间6bit
            bdata.append(0x80 | ((num >> 0) & 0x3f));    //低6bit    
        }
        unicodeTmp = data.toHex().data();
        byte3Tmp = bdata.toHex().data();


        unicodeTmp = unicodeTmp.toUpper();
        unicodeStr.clear();
        for(int i=0;i<unicodeTmp.count();i=i+4){
            unicodeStr.append(QString("%1 ").arg(unicodeTmp.mid(i, 4)));
        }
        byte3Tmp = byte3Tmp.toUpper();
        byte3Str.clear();
        for(int i=0;i<byte3Tmp.count();i=i+2){
            byte3Str.append(QString("\\x%1").arg(byte3Tmp.mid(i, 2)));
        }

    }else if (sender() == m_unicodeEdit){
        unicodeTmp = unicodeStr;
        unicodeTmp.replace(" ", "");    //去空格
        unicodeTmp.replace("0x", "");    //去0x
        unicodeTmp.replace("0X", "");    //去0X
        int count=unicodeTmp.count();
        int len=count/4;
        bool ok;
        int temp[count];
        QChar qchar[len];
        for(int i=0;i<count;i+=4){
            temp[i]=unicodeTmp.mid(i,4).toInt(&ok,16);//每四位转化为16进制整型
            qchar[i/4]=temp[i];

            //转3字节码
            bdata.append(0xe0 | ((temp[i] >> 12) & 0xf));    //剩下4bit
            bdata.append(0x80 | ((temp[i] >> 6) & 0x3f));    //中间6bit
            bdata.append(0x80 | ((temp[i] >> 0) & 0x3f));    //低6bit
        }
        QString str0(qchar, len);
        charStr = str0;
        byte3Tmp = bdata.toHex().data();

        byte3Str.clear();
        byte3Tmp = byte3Tmp.toUpper();
        for(int i=0;i<byte3Tmp.count();i=i+2){
            byte3Str.append(QString("\\x%1").arg(byte3Tmp.mid(i, 2)));
        }
    }else if (sender() == m_byte3Edit){

    }

    m_charEdit->setText(charStr);
    m_unicodeEdit->setText(unicodeStr);
    m_byte3Edit->setText(byte3Str);
}
void MainWindow::SetMenu()
{
    QAction *actioncfg = new QAction("路径设置", this);
    QAction *actioncom = new QAction("串口设置", this);
    connect(actioncom, SIGNAL(triggered()), this, SLOT(on_actioncom_triggered()));
    connect(actioncfg, SIGNAL(triggered()), this, SLOT(on_actioncfg_triggered()));
    QMenu *configMenu = this->menuBar()->addMenu("配置");
    configMenu->addAction(actioncfg);
    configMenu->addAction(actioncom);

}

void MainWindow::on_m_start_clicked()
{
    QString soft_name;
    QString new_path;
    QString src_path = m_srcPath->text();
    QDir dir(src_path);
    if(!dir.exists())
    {
        return;
    }

    m_loglist->clear();
    //1.修改目录名称
    QString hex_name = m_name->text();
    soft_name = hex_name.left(hex_name.lastIndexOf("_")+1);
    m_hex_name = soft_name + m_data->text();

    new_path = src_path.left(src_path.lastIndexOf("/")+1) + m_hex_name;
    m_code_path = new_path;


    if (m_cb_data->isChecked())
    {
        dir.rename(src_path, new_path);
        dir.setPath(new_path);
    }

    m_loglist->addItem(QString("%1.%2").arg(m_loglist->count()).arg("删除原hex."));
    foreach(QString filename ,dir.entryList())
    {
        qDebug() << filename;
        //2.删除hex文件
        if (filename.endsWith("hex"))
        {
            dir.remove(filename);
        }
        //3.解压软件包，并删除压缩包
        if (filename.endsWith("rar") || filename.endsWith("zip"))
        {
            qApp->processEvents();
            m_loglist->addItem(QString("%1.%2").arg(m_loglist->count()).arg("开始解压."));
            QString code_packet = dir.absolutePath()+"\/"+filename;
            QString extract_cmd = QString("\"%1\" x -ibck -y -o+ \"%2\" \"%3\"")
                            .arg(m_winRARCfg)
                            .arg(code_packet)
                            .arg(dir.absolutePath());
            qDebug() <<extract_cmd;
            QProcess pro(0);
            pro.execute(extract_cmd);
            m_loglist->addItem(QString("%1.%2").arg(m_loglist->count()).arg("解压完成."));
            qApp->processEvents();
            dir.remove(code_packet);
            m_loglist->addItem(QString("%1.%2").arg(m_loglist->count()).arg("删除原压缩包."));
        }

    }

    QDir dir_new(new_path);
    foreach(QFileInfo fileitem ,dir_new.entryInfoList())
    {
        qDebug()<<fileitem.fileName();
        if (fileitem.fileName().startsWith("M") && fileitem.isDir())
        {
            m_dir_name = fileitem.fileName();
            //4.修改程序
            modify_global(fileitem.fileName());
            //5.修改输出的hex文件名
            modify_hexfile(fileitem.fileName());
            //5.修改站号
            modify_zhanhao(fileitem.fileName());
            //5.修改电压系数
            modify_vfactor(fileitem.fileName());
            //6.修改加解密
            if (m_cb_jiemi->isChecked()){
                modify_startup(true);
            }else{
                modify_startup(false);
            }
            m_loglist->addItem(QString("%1.%2").arg(m_loglist->count()).arg("程序修改完成."));
            qApp->processEvents();
            //记录程序修改时间
            m_hexFileTime = QDateTime::currentDateTime().toTime_t();

            //on_m_build_clicked();
        }

    }



}

void MainWindow::on_m_check_clicked()
{
    QFileInfo check_tool(m_checkCfg);
    qDebug()<<check_tool.absolutePath()<<m_code_path+"\\"+check_tool.fileName();
    QFile::copy(check_tool.filePath(), m_code_path+"\\"+check_tool.fileName());

    QDir::setCurrent(m_code_path);
    QString open_cmd = m_code_path+"\/"+check_tool.fileName();
    QProcess pro(0);
    pro.execute(open_cmd);
}

void MainWindow::on_m_compress_clicked()
{
    //先判断HEX文件是否加密，如果没加密，不能打包
    QString hex_file = m_code_path+"/"+m_hex_name+".hex";
    QFile file(hex_file);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
        m_isCode = false;
        return;
    }
    int i=0;
    while(!file.atEnd()) {
        QByteArray line = file.readLine();
        QString str(line);
        i++;
        if ((i==49) && (str.indexOf("FFFFFFFF")>-1)){
            qDebug()<< str;
            m_isCode = false;
            QMessageBox::warning(this, tr("提示"),tr("程序未加密！"));
            file.close();
            return;
        }
        if (i>49){
            break;
        }
    }
    file.close();
    m_isCode = true;
    QString code_dir = m_code_path+"\/"+m_dir_name;
    QString packet_cmd = QString("\"%1\" a -ep1 -r -ibck -o+ \"%2\" \"%3\"")
                    .arg(m_winRARCfg)
                    .arg(code_dir+".rar")
                    .arg(code_dir);
    qDebug() <<packet_cmd;


    QProcess pro(0);
    pro.execute(packet_cmd);

    m_loglist->addItem(QString("%1.%2").arg(m_loglist->count()).arg("打包完成."));
}

void MainWindow::on_m_clear_clicked()
{
    QDir dir(m_code_path);
    QString code_dir = m_code_path+"\/"+m_dir_name;

    dir.remove("ChangeName.exe");
    deleteDir(code_dir);

    m_loglist->clear();
}

void MainWindow::on_m_copy_clicked()
{
    //搜索编译日期之后的HEX文件，为编译完成的
    if(build_check()){

    }else{
        QMessageBox::warning(this, "提示", "编译错误，请检查！");
    }
}

void MainWindow::on_btn_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "D:\\2-Work\\0-Day_work", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (dir.isEmpty()) return;
    m_srcPath->setText(dir);
    QString name = dir.mid(dir.lastIndexOf("/") + 1);
    if (name.startsWith("M6090")
        || name.startsWith("M6080")
        || name.startsWith("M6070")
        || name.startsWith("M6060")){
        name.remove(1,2);
    }
    m_name->setText(name);
}

void MainWindow::modify_global(QString name)
{
    QStringList strAll;
    QFile file(m_code_path + "\\" + name + "\\LCD\\LCD_Global.h");
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        strAll.append(line);
    }

    file.resize(0);
    in.reset();

    int idx=0;
    for (int i=0;i<strAll.count();i++)
    {

        if (i<50)
        {
            //(1)日期
            if (m_cb_data->isChecked())
            {

                if (strAll[i].contains("#define SOFT_NAME"))
                {
                    qDebug()<<strAll[i];
                    idx = strAll[i].indexOf("\"");
                    if (!m_hex_name.isEmpty())
                        strAll[i] = QString("%1%2\"").arg(strAll[i].left(idx+1)).arg(m_hex_name);
                    qDebug()<<strAll[i];
                }
            }
            //(2)CK
            if (m_cb_ckCode->isChecked())
            {
                if (strAll[i].contains("#define SOFT_VER"))
                {
                    qDebug()<<strAll[i];
                    idx = strAll[i].lastIndexOf("\"");
                    QString ck_code = m_ckCode->text();
                    ck_code.trimmed();
                    ck_code.replace("\n","");
                    ck_code.replace("、","");
                    ck_code.replace("/","");
                    if (ck_code.count() == 10)
                        ck_code.insert(2,"0");
                    if (!ck_code.isEmpty())
                        strAll[i] = QString("%1%2\"").arg(strAll[i].left(idx-11)).arg(ck_code);
                    qDebug()<<strAll[i];
                }
            }
            //(3)密码
            if (m_cb_password->isChecked())
            {
                if (strAll[i].contains("#define FACT_PASS") ||
                    strAll[i].contains("#define SETVF_PASS") ||
                    strAll[i].contains("#define HARD_PASS") ||
                    strAll[i].contains("#define HAOCAI_PASS"))
                {
                    qDebug()<<strAll[i];
                    QString passwd = m_password->text();
                    if (passwd.mid(0,1) == "0")
                    {
                        passwd = passwd.mid(1);
                        if (passwd.mid(1,2) == "0")
                        {
                            passwd = passwd.mid(2);
                        }
                    }
                    if (!passwd.isEmpty())
                        strAll[i].replace(QRegExp("(\\d+)"),passwd);
                    qDebug()<<strAll[i];
                }
            }
        }
        in << strAll[i]<<"\n";
    }

    file.close();
}

void MainWindow::modify_hexfile(QString name)
{

    QDir dir(m_code_path + "\\" + name);
    foreach(QString fileitem ,dir.entryList())
    {
        if (fileitem.endsWith("uvproj"))
        {
            QStringList strAll;
            QFile file(m_code_path + "\\" + name + "\\" + fileitem);
            if(!file.open(QIODevice::ReadWrite))
            {
                qDebug()<<"Can't open the file!"<<endl;
            }
            QTextStream in(&file);
            while(!in.atEnd())
            {
                QString line = in.readLine();
                strAll.append(line);
            }

            file.resize(0);
            in.reset();


            QRegExp rx("<OutputName>.+</OutputName>");
            for (int i=0;i<strAll.count();i++)
            {
                if (strAll[i].contains(rx))
                {
                    qDebug()<<"<OutputName>"+m_hex_name+"</OutputName>)";
                    strAll[i].replace(rx, "<OutputName>"+m_hex_name+"</OutputName>");
                }

                in << strAll[i]<<"\n";
            }

            file.close();
        }

    }
}

void MainWindow::modify_zhanhao(QString name)
{
    //站号
    if (m_cb_vsd->isChecked())
    {
        QStringList strAll;
        QString path = m_code_path + "\\" + name + "\\Drive\\paraLim.c";
        qDebug()<<path;
        QFile file(path);
        if(!file.open(QIODevice::ReadWrite))
        {
            qDebug()<<"Can't open the file!"<<endl;
        }
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            strAll.append(line);
        }

        file.resize(0);
        in.reset();

        QRegExp rx(",.+,");
        rx.setMinimal(true);        //非贪婪模式
        for (int i=0;i<strAll.count();i++)
        {
            if (strAll[i].contains("FactParaType_Str.gFanVsdAdd"))
            {
                qDebug()<<strAll[i];
                strAll[i].replace(rx, ",1,");
                qDebug()<<strAll[i];
                m_loglist->addItem(QString("%1.%2").arg(m_loglist->count()).arg("站号修改完成."));
            }

            in << strAll[i]<<"\n";
        }

        file.close();
    }
}

void MainWindow::modify_vfactor(QString name)
{
    //电压系数
    if (m_cb_vfactor->isChecked())
    {
        QStringList strAll;
        QString path = m_code_path + "\\" + name + "\\Drive\\paraLim.c";
        qDebug()<<path;
        QFile file(path);
        if(!file.open(QIODevice::ReadWrite))
        {
            qDebug()<<"Can't open the file!"<<endl;
        }
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            strAll.append(line);
        }

        file.resize(0);
        in.reset();

        for (int i=0;i<strAll.count();i++)
        {
            if (strAll[i].contains("if ( *pstr1 > 2000 ) *pstr1 = 2000;"))
            {
                qDebug()<<strAll[i];
                strAll[i].replace("2000", "4000");
                qDebug()<<strAll[i];
                m_loglist->addItem(QString("%1.%2").arg(m_loglist->count()).arg("电压系数修改完成."));
            }

            in << strAll[i]<<"\n";
        }

        file.close();
    }
}

void MainWindow::modify_startup(bool jiemi)
{
    QStringList strAll;
    QString path = m_code_path + "/" + m_dir_name + "/System/HW/DeviceSupport/startup_LPC177x_8x_Keil.s";
    if (!QFile::exists(path)){
        return;
    }
    qDebug()<<path;
    QFile file(path);
    if(!file.open(QIODevice::ReadWrite))
    {
        qDebug()<<"Can't open the file!"<<endl;

    }
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        strAll.append(line);
    }

    file.resize(0);
    in.reset();

    for (int i=0;i<strAll.count();i++)
    {
        if (strAll[i].contains("CRP_Key         DCD    0xFFFFFFFF"))
        {
            qDebug()<<strAll[i];
            if (jiemi){
                strAll[i] = "CRP_Key         DCD    0xFFFFFFFF";
            }else{
                strAll[i] = ";CRP_Key         DCD    0xFFFFFFFF";
            }
            qDebug()<<strAll[i];
        }
        if (strAll[i].contains("CRP_Key         DCD    0x87654321"))
        {
            qDebug()<<strAll[i];
            if (jiemi){
                strAll[i] = ";CRP_Key         DCD    0x87654321";
            }else{
                strAll[i] = "CRP_Key         DCD    0x87654321";
            }
            qDebug()<<strAll[i];
        }
        in << strAll[i]<<"\n";
    }

    file.close();
}

void MainWindow::modify_UPDATA(QString name)
{
        QStringList strAll;
        QString path = m_code_path + "\\" + name + "\\System\\Main.c";
        qDebug()<<path;
        QFile file(path);
        if(!file.open(QIODevice::ReadWrite))
        {
            qDebug()<<"Can't open the file!"<<endl;
        }
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            strAll.append(line);
        }

        file.resize(0);
        in.reset();


        int readyflag = 0;
        QString readyTmpStr = "";
        //6090改ready
        QString projectDir = m_srcPath->text();
        if ((projectDir.startsWith("M90")) || (projectDir.startsWith("M6090"))) {

            for (int i=0;i<strAll.count();i++)
            {
                if (strAll[i].indexOf("ExecutMulOutput(uint16_t pdata)") > -1){
                    readyflag = 1;
                }
                if ((readyflag == 1) && (strAll[i].indexOf("case 4:") > -1)){
                    readyflag = 2;
                }
                if (readyflag == 2){
                    if ((strAll[i].indexOf("case 5:") > -1)){
                       readyflag = 3;
                    }else{
                        readyTmpStr += strAll[i] + "\n";
                    }
                }
                if (readyflag == 3){
                    readyflag = 0;
                    qDebug() << readyTmpStr;
                    QString str = readyTmpStr;
                    if(str.remove(QRegExp("\\s")) == "case4://readyif(gRunFlag1.Sys_OnokF){gRunMutex2.MulOutIOStateF=1;}else{gRunMutex2.MulOutIOStateF=0;}break;"){

                        readyTmpStr =  "        case 4:  //ready\n"\
                                       "            if(gRunFlag1.Sys_FaultF||gRunFlag1.Sys_EmergcF)\n" \
                                       "            {\n" \
                                       "                gRunMutex2.MulOutIOStateF = 0;\n" \
                                       "            }\n" \
                                       "            else\n" \
                                       "            {\n" \
                                       "                gRunMutex2.MulOutIOStateF = 1;\n" \
                                       "            }\n" \
                                       "            break;\n";

                    }else{
                        QMessageBox::warning(this, tr("提示"), tr("ready区域不匹配！"));
                    }
                    in << readyTmpStr;
                    in << "        case 5: //far\n";
                }else if (readyflag != 2){
                    in << strAll[i]<<"\n";
                }
            }
        }
        //判断是否打开了工频风机
        readyflag = 0;
        for (int i=strAll.count()-1;i>0;i--)
        {
            if (strAll[i].indexOf("main(void)") > -1){
                readyflag = 1;
            }
            if (readyflag == 1){
                if (strAll[i].indexOf("OldMainPoll_ISR3(void)") > -1){
                   readyflag = 2;
                   break;
                }else{
                    readyTmpStr = strAll[i];
                    readyTmpStr = readyTmpStr.remove(QRegExp("\\s"));
                    if (readyTmpStr.startsWith("GpFanControl()")){
                        readyflag = 3;
                        break;
                    }
                }
            }
        }
        //如果状态为3，则需要后续的更改
        if (readyflag == 3){

        }
        file.close();

}

void MainWindow::on_m_build_clicked()
{
    //http://www.keil.com/support/man/docs/uv4/uv4_commandline.htm

    m_loglist->addItem(QString("%1.%2").arg(m_loglist->count()).arg("开始编译..."));
    qApp->processEvents();
    //6.修改加解密
    if (m_cb_jiemi->isChecked()){
        m_jiemi = true;
    }else{       
        m_jiemi = false;
    }
    modify_startup(m_jiemi);

    QString code_path = m_code_path + "/" + m_dir_name;
    //查找目录内工程文件后缀
    //1.1判断路径是否存在
    QDir dir(code_path);
    if(!dir.exists())
    {
        return;
    }
    QFileInfoList InfoList = QDir(code_path).entryInfoList();//获取当前目录所有文件
    QFileInfoList SuffixInfoList;//定义放提取文件的List
    //遍历
    foreach(QFileInfo fileInfo, InfoList )
    {
        if(!fileInfo.isFile()) continue;//不是文件继续，只用于加速，可不加
        //后缀不区分大小写，需要区分直接用“==”
        if(0==fileInfo.suffix().compare("uvproj", Qt::CaseInsensitive))
        {
            SuffixInfoList << fileInfo;//指定后缀，加入列表
        }
    }
    if (InfoList.count()<0){
        return;
    }
    m_hexFileTime = QDateTime::currentDateTime().toTime_t();
    m_project_path = SuffixInfoList[0].absoluteFilePath();
    //QString build_cmd = QString("%1 -j0 -r %2 -o build_log.txt").arg(DIR_KEIL).arg(project_path);
    QString build_cmd = QString("\"%1\" -j0 -b \"%2\"").arg(m_keilCfg).arg(m_project_path);
    //这里的编译选项 -r:rebuild,-b:build
    QProcess pro(0);
    pro.execute(build_cmd);

    m_loglist->addItem(QString("%1.%2").arg(m_loglist->count()).arg("编译完成."));

}

void MainWindow::on_m_download_clicked()
{
    if (!m_jiemi) {
        QMessageBox::warning(this, "提示", "程序已加密，请解密后再下载！");
        return;
    }
    m_loglist->addItem(QString("%1.%2").arg(m_loglist->count()).arg("开始下载..."));
    qApp->processEvents();
    QString down_cmd = QString("\"%1\" -j0 -f \"%2\"").arg(DIR_KEIL).arg(m_project_path);
    QProcess pro(0);
    pro.execute(down_cmd);
    m_loglist->addItem(QString("%1.%2").arg(m_loglist->count()).arg("下载完成."));
}

void MainWindow::on_build2_clicked()
{
    on_m_start_clicked();
    on_m_build_clicked();
    on_m_copy_clicked();
}


void MainWindow::on_clear2_clicked()
{
    on_m_compress_clicked();
    if (!m_isCode)
        return;
    on_m_clear_clicked();
}


void MainWindow::on_m_chooseBtn_clicked()
{
    QString strFile = QFileDialog::getOpenFileName(this,QStringLiteral("选择Excel文件"),"",tr("Exel file(*.xls *.xlsx)"));
    m_srcPathx->setText(strFile);
}

void MainWindow::on_m_chooseoutBtn_clicked()
{
    QString strFile = QFileDialog::getExistingDirectory(this,QStringLiteral("选择输出路径"),"");
    m_outPath->setText(strFile);
}

void MainWindow::on_m_createBtn_clicked()
{
    bool ok;
    QString useCharList;
    QStringList dirlist;
    dirlist<<"简体中文"<<"英文"<<"西班牙文"<<"繁体中文"<<"法文"<<"德文";
    QStringList suflist;
    suflist<<""<<" - ENG"<<" - 西班牙"<<" - 繁体"<<" - 法文"<<" - 德文";
    QStringList namelist;
    namelist<<"用户参数"<<"时间参数"<<"厂家参数"<<"运行参数"<<"预置变频器"
            <<"校准参数"<<"主界面参数及其它"<<"按钮输入输出端子功能"<<"压力温度切换"
            <<"运行状态"<<"故障"<<"预警"<<"硬件";

    int curCol = 0;

    QString strFile = m_srcPathx->text();
    if (!strFile.endsWith(".xls") && !strFile.endsWith(".xlsx"))
    {
        return;
    }

    QString outDir = m_outPath->text();
    QDir pathDir(outDir);
    if (!pathDir.exists())
    {
        return;
    }

    //1、打开excel
    QAxObject excel("Excel.Application"); //加载Excel驱动
    excel.setProperty("Visible", false); //不显示Excel界面，如果为true会看到启动的Excel界面
    QAxObject* pWorkBooks = excel.querySubObject("WorkBooks");
    pWorkBooks->dynamicCall("Open (const QString&)", strFile);//打开指定文
    QAxObject* pWorkBook = excel.querySubObject("ActiveWorkBook");
    QAxObject* pWorkSheets = pWorkBook->querySubObject("Sheets");//获取工作表
    int nSheetCount = pWorkSheets->property("Count").toInt();  //获取工作表的数目

    for (int i=1; i<=nSheetCount; i++){
        QAxObject* pWorkSheet = pWorkBook->querySubObject("Sheets(int)", i);//获取第一张表
        QString name = pWorkSheet->property("Name").toString();
        name = name.trimmed();
        QAxObject *pUsedrange = pWorkSheet->querySubObject("UsedRange");//获取该sheet的使用范围对象
        QAxObject *pRows = pUsedrange->querySubObject("Rows");
        QAxObject *pColumns = pUsedrange->querySubObject("Columns");
        /*获取行数和列数*/
        int intCols = pColumns->property("Count").toInt();
        int intRows = pRows->property("Count").toInt();
        int intColStart = pColumns->property("Column").toInt();
        int intRowStart = pRows->property("Row").toInt();

        curCol = m_colNum->text().toInt(&ok, 10);
        //输入的是数字
        if (ok){
            if (curCol < 0 || curCol > intCols )
            {
                qDebug()<<name<<intColStart<<intCols<<curCol<<"Error col num";
                continue;
            }
            for (int t=0; t<curCol; t++)
            {
                //2、创建txt
                QString path = QString("%1\/%2").arg(outDir).arg(dirlist[t]);
                QDir dir;
                if (!dir.exists(path))
                {
                    dir.mkpath(path);
                }
                //QString filename = QString("%1\/%2\/%3.txt").arg(dir.currentPath()).arg(path).arg(name);
                QString fullname = namelist[i-1] + suflist[t];
                if (fullname.contains("用户参数") && t==1)
                {
                    fullname = "用户参数 -ENG";
                }

                QString filename = QString("%1\/%2.txt").arg(path).arg(fullname);
                QFile file(filename);
                if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
                    return;
                }

                QStringList outstr;
                int space_num = 0, end_line = 0;
                for (int j=intRowStart; j<=intRows; j++){
                    QAxObject *range = pWorkSheet->querySubObject("Cells(int,int)", j, t+2); //获取cell的值
                    QString value = range->dynamicCall("Value2()").toString();

                    qDebug()<<value.toStdString().c_str();

                    //3、插入txt
                    outstr << value;

                    //记录空格行的次数
                    if (value.remove(QRegExp("\\s")) == ""){
                        space_num += 1;
                    }else{
                        space_num = 0;
                    }
                }
                end_line = intRows - intRowStart + 1 - space_num;

                //4、创建txt，并写入文件
                QTextStream out(&file);
                out.setCodec(QTextCodec::codecForName("unicode"));//unicode小端模式
                out.setAutoDetectUnicode(true); //好像没用处
                QChar head = 0xfeff;//unicode文件头 文本里前两个字节为FFFE
                out << head;

                for (int i=0;i<end_line;i++) {
                    out << outstr[i] << "\n";
                    for(int j=0;j<outstr[i].count();j++){
                        if (useCharList.indexOf(outstr[i].at(j)) < 0){
                            useCharList.append(outstr[i].at(j));
                        }
                    }
                }

                file.close();

            }
        }else{
            //输入的是关键字
            int t = 0;
            QString lan = m_colNum->text().trimmed().toLower();
            bool hasValue = false;
            for (t=intColStart; t<=intCols; t++)
            {
                QAxObject *range = pWorkSheet->querySubObject("Cells(int,int)", 1, t); //获取cell的值
                QString value = range->dynamicCall("Value2()").toString();
                value = value.trimmed().toLower();
                qDebug()<<value.toStdString().c_str();
                if (value == lan){
                    hasValue = true;
                    break;
                }
            }
            if (hasValue == false) continue;
            //2、创建txt
            QString path = QString("%1\/%2").arg(outDir).arg(lan);
            QDir dir;
            if (!dir.exists(path))
            {
                dir.mkpath(path);
            }
            QString fullname = namelist[i-1];
            QString filename = QString("%1\/%2.txt").arg(path).arg(fullname);
            QFile file(filename);
            if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
                return;
            }

            QStringList outstr;
            int space_num = 0, end_line = 0;
            for (int j=intRowStart+1; j<=intRows; j++){
                QAxObject *range = pWorkSheet->querySubObject("Cells(int,int)", j, t); //获取cell的值
                QString value = range->dynamicCall("Value2()").toString();

                qDebug()<<value.toStdString().c_str();

                //3、插入txt
                outstr << value;

                //记录空格行的次数
                if (value.remove(QRegExp("\\s")) == ""){
                    space_num += 1;
                }else{
                    space_num = 0;
                }
            }
            end_line = intRows - (intRowStart+1) + 1 - space_num;

            //4、创建txt，并写入文件
            QTextStream out(&file);
            out.setCodec(QTextCodec::codecForName("unicode"));//unicode小端模式
            out.setAutoDetectUnicode(true); //好像没用处
            QChar head = 0xfeff;//unicode文件头 文本里前两个字节为FFFE
            out << head;

            for (int i=0;i<outstr.count();i++) {
                out << outstr[i] << "\n";
                for(int j=0;j<outstr[i].count();j++){
                    if (useCharList.indexOf(outstr[i].at(j)) < 0){
                        useCharList.append(outstr[i].at(j));
                    }
                }
            }

            file.close();
        }

    }
    pWorkBooks->dynamicCall("Close()");

    QMessageBox::information(this, "信息", "已完成！");


    //4、创建txt，并写入文件
    QString path = QString("%1\/%2").arg(outDir).arg("xls_Font32.txt");
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
        return;
    }
    QTextStream out(&file);
    out.setCodec(QTextCodec::codecForName("unicode"));//unicode小端模式
    out.setAutoDetectUnicode(true); //好像没用处
    QChar head = 0xfeff;//unicode文件头 文本里前两个字节为FFFE
    out << head;
    out << useCharList << "\n";

}



int MainWindow::build_check()
{
    QString new_file;
    QDir dir(m_code_path + "\\" + m_dir_name + "\\Output\\LPC1788_TengHua_LPC1788_KEIL_CMSIS\\Release_FLASH\\Obj");
    foreach(QFileInfo fileitem ,dir.entryInfoList())
    {
        int hexFileTime = fileitem.lastModified().toTime_t();

        if (fileitem.fileName().endsWith("hex")
            && fileitem.fileName().startsWith(m_hex_name)
            && (hexFileTime > m_hexFileTime))
        {
            //如果已经存在hex，则先删除
            new_file = m_code_path+"\\"+fileitem.fileName();
            if (QFileInfo::exists(new_file)){
                QFile::remove(new_file);
            }
            if (QFile::copy(fileitem.filePath(), new_file))
            {
                m_loglist->addItem(QString("%1.%2").arg(m_loglist->count()).arg("已拷贝."));

            }
            qDebug()<<fileitem.filePath()<<m_code_path+"\\"+fileitem.fileName();
            return 1;
        }

    }
    return -1;
}
bool MainWindow::deleteDir(const QString &dirName)
 {
     QDir directory(dirName);
     if (!directory.exists())
     {
         return true;
     }


     QString srcPath = QDir::toNativeSeparators(dirName);
     if (!srcPath.endsWith(QDir::separator()))
         srcPath += QDir::separator();


     QStringList fileNames = directory.entryList(QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden);
     bool error = false;
     for (QStringList::size_type i=0; i != fileNames.size(); ++i)
     {
         QString filePath = srcPath + fileNames.at(i);
         QFileInfo fileInfo(filePath);
         if (fileInfo.isFile() || fileInfo.isSymLink())
         {
             QFile::setPermissions(filePath, QFile::WriteOwner);
             if (!QFile::remove(filePath))
             {
                 qDebug() << "remove file" << filePath << " faild!";
                 error = true;
             }
         }
         else if (fileInfo.isDir())
         {
             if (!deleteDir(filePath))
             {
                 error = true;
             }
         }
     }


     if (!directory.rmdir(QDir::toNativeSeparators(directory.path())))
     {
         qDebug() << "remove dir" << directory.path() << " faild!";
         error = true;
     }


     return !error;
}


void MainWindow::on_actioncfg_triggered()
{
    m_cfgDialog = new QDialog();
    m_cfgDialog->setWindowTitle("路径设置");
    m_cfgDialog->resize(500,156);
    QGridLayout *gridbox = new QGridLayout(m_cfgDialog);

    m_tableCfg = new QTableWidget(3,1);
    m_tableCfg->setToolTip("双击更改程序默认位置！");
    QTableWidgetItem *item = new QTableWidgetItem(m_winRARCfg);
    item->setFont(QFont("微软雅黑", 9));
    m_tableCfg->setItem(0, 0, item);
    item = new QTableWidgetItem(m_keilCfg);
    item->setFont(QFont("微软雅黑", 9));
    m_tableCfg->setItem(1, 0, item);
    item = new QTableWidgetItem(m_checkCfg);
    item->setFont(QFont("微软雅黑", 9));
    m_tableCfg->setItem(2, 0, item);

    m_tableCfg->horizontalHeader()->setStretchLastSection(true);//关键
    m_tableCfg->setVerticalHeaderLabels(QStringList()<<"WinRAR路径"<<"Keil路径"<<"Check路径");
    m_tableCfg->horizontalHeader()->hide();


    QPushButton *ok = new QPushButton("Ok");
    QPushButton *cancel = new QPushButton("Cancel");
    connect(ok, SIGNAL(clicked()), m_cfgDialog, SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), m_cfgDialog, SLOT(reject()));

    gridbox->addWidget(m_tableCfg, 0, 0, 1, 2);
    gridbox->addWidget(ok, 1, 0);
    gridbox->addWidget(cancel, 1, 1);
    int resutl = m_cfgDialog->exec();
    if (resutl == QDialog::Accepted)
    {
        m_winRARCfg = m_tableCfg->item(0,0)->text();
        m_keilCfg = m_tableCfg->item(1,0)->text();
        m_checkCfg = m_tableCfg->item(2,0)->text();
        QFileInfo file1(m_winRARCfg);
        if (!file1.exists()){
            QMessageBox::information(this, "提示", "winRAR路径错误！");
            QTimer::singleShot(100,this, SLOT(on_actioncfg_triggered()));
            return;
        }
        QFileInfo file2(m_keilCfg);
        if (!file2.exists()){
            QMessageBox::information(this, "提示", "Keil路径错误！");
            QTimer::singleShot(100,this, SLOT(on_actioncfg_triggered()));
            return;
        }
        QFileInfo file3(m_checkCfg);
        if (!file3.exists()){
//            QMessageBox::information(this, "提示", "Check路径错误！");
//            QTimer::singleShot(100,this, SLOT(on_actioncfg_triggered()));
//            return;
        }
        qDebug() << "You Choose Ok";
    }
    else
    {
        qDebug() << "You Choose Cancel";
    }
}

void MainWindow::on_actioncom_triggered()
{
    m_comDialog = new QDialog();
    m_comDialog->setWindowTitle("通讯设置");
    m_comDialog->resize(200,150);
    QGridLayout *gridbox = new QGridLayout(m_comDialog);

    QComboBox *com = new QComboBox();
    com->addItems(QStringList()<<"COM1"<<"COM2"<<"COM3"<<"COM4"
                                <<"COM5"<<"COM6"<<"COM7"
                                <<"COM8"<<"COM9");
    com->setEditable(true);
    com->setCurrentText(m_ComPort);
    QComboBox *baud = new QComboBox();
    baud->addItems(QStringList()<<"9600"<<"115200");
    baud->setCurrentText(m_baudRate);
    QComboBox *parity = new QComboBox();
    parity->addItems(QStringList()<<"None"<<"Even"<<"Odd");
    parity->setCurrentText(m_Parity);
    QComboBox *stopbit = new QComboBox();
    stopbit->addItems(QStringList()<<"1"<<"1.5"<<"2");
    stopbit->setCurrentText(m_Stopbit);
    QPushButton *ok = new QPushButton("Ok");
    QPushButton *cancel = new QPushButton("Cancel");
    connect(ok, SIGNAL(clicked()), m_comDialog, SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), m_comDialog, SLOT(reject()));

    gridbox->addWidget(com, 0, 0);
    gridbox->addWidget(baud, 0, 1);
    gridbox->addWidget(parity, 1, 0);
    gridbox->addWidget(stopbit, 1, 1);
    gridbox->addWidget(ok, 2, 0);
    gridbox->addWidget(cancel, 2, 1);
    int resutl = m_comDialog->exec();
    if (resutl == QDialog::Accepted)
    {
        if ((com->currentText() != m_ComPort) ||
            (baud->currentText() != m_baudRate) ||
            (parity->currentText() != m_Parity) ||
            (stopbit->currentText() != m_Stopbit)){
            m_SerialChange = true;
        }else{
            m_SerialChange = false;
        }
        m_ComPort = com->currentText();
        m_baudRate = baud->currentText();
        m_Parity = parity->currentText();
        m_Stopbit = stopbit->currentText();
        qDebug() << "You Choose Ok";
    }
    else
    {
        qDebug() << "You Choose Cancel";
    }


}



void MainWindow::on_insert_clicked()
{
    int cur_num = m_table->currentRow();
    if (cur_num<0){
        cur_num = m_table->rowCount();
    }else{
        cur_num = cur_num + 1;
    }

    m_table->insertRow(cur_num);

/*    m_flashType<<"无压缩图片"<<"压缩图片"
               <<"宋体32字库"<<"菜单"
               <<"汉字16字库"<<"英文16字库"
               <<"其他字库"<<"擦除Flash"
               <<"全汉字文本"<<"全汉字字库"
               <<"菜单(全汉字)"
               <<"字体32数组"<<"字体16数组";
*/
    QStandardItemModel *model = new QStandardItemModel(this);
    QStandardItem *item[m_flashType.count()];
    for (int i=0;i<m_flashType.count();i++){
        item[i] = new QStandardItem(m_flashType[i]);
        model->appendRow(item[i]);
    }
    item[ 8]->setToolTip("选择全汉字txt文件，地址和大小不设置，必须选择txt文件");
    item[ 9]->setToolTip("下载全汉字字库，32和16通用，必须先选择好全汉字txt才可使用");
    item[10]->setToolTip("下载全汉字字库的菜单使用，必须先选择好全汉字txt才可使用");
    item[11]->setToolTip("生成并下载宋体32的字体数组，不必选择文件");
    item[12]->setToolTip("生成并下载宋体16的字体数组，不必选择文件");

    QComboBox *item0 = new QComboBox();
    item0->setModel(model);
    item0->setCurrentIndex(0);
    //connect(item0, SIGNAL(currentIndexChanged(int)), this, SLOT(SetStartAddress(int)));
    QComboBox *item1 = new QComboBox();
    item1->addItems(m_flashAddr);
    item1->setEditable(true);
    //connect(item1, SIGNAL(currentIndexChanged(int)), this, SLOT(SetEraseSize(int)));
    QComboBox *item2 = new QComboBox();
    item2->addItems(m_flashSize);
    item2->setEditable(true);
    item2->setCurrentIndex(3);

    QTableWidgetItem *item3 = new QTableWidgetItem("D:/2-Work/leek.project/mam_tools/mamTools/build-mamTools-Desktop_Qt_5_2_1_MinGW_32bit-Debug/M6080Songti33.c"/*"D:\\2-Work\\0-Day_work\\leek\\xinlei_two\\first.c"*/);
    item3->setToolTip(item3->text());

    m_table->setCellWidget(cur_num, 0, item0);
    m_table->setCellWidget(cur_num, 1, item1);
    m_table->setCellWidget(cur_num, 2, item2);
    m_table->setItem(cur_num, 3, item3);

}

void MainWindow::on_delete_clicked()
{
    QList<QTableWidgetItem*>items=m_table->selectedItems();
    int count=items.count();
    for(int i=0;i<count;i++)
    {
       int row = m_table->row(items.at(i));//获取选中的行
       m_table->removeRow(row);
    }

}

void MainWindow::on_downtable_clicked()
{
    if (m_downtable->text() == "停止"){
        m_com_obj->DownLoad(0,0,0,NULL,CANCEL_OK);
        return;
    }

    if (m_com_obj == NULL){
        m_com_obj = new ComObject(m_ComPort, m_baudRate, m_Parity, m_Stopbit);
        m_SerialChange = false;
        connect(m_com_obj, SIGNAL(ResProgress_sig(int, QString)),
                this, SLOT(ResProgress_slt(int, QString)));
    }else if(m_SerialChange){
        QString para = m_ComPort + "+" + m_baudRate + "+" + m_Parity + "+" + m_Stopbit;
        m_com_obj->DownLoad(0, 0, 0, para, SERIAL_SET);
        m_SerialChange = false;
    }

    int row_cnt = m_table->rowCount();
    if (row_cnt<=0){
        return;
    }
    m_downloadRow.clear();
    //获取选中的行
    QList<QTableWidgetSelectionRange> selectRange=m_table->selectedRanges();
    int count=selectRange.count();
    for(int i=0;i<count;i++)
    {
       if ((selectRange[i].leftColumn() == 0) && (selectRange[i].rightColumn() == 3)){
           for(int j=selectRange[i].topRow();j<=selectRange[i].bottomRow();j++){
               m_downloadRow.append(j);
           }
       }
    }
    //如果用户没有选中整行，则默认下载所有行
    if (m_downloadRow.isEmpty()){
        for(int j=0;j<row_cnt;j++){
            m_downloadRow.append(j);
        }
    }
    pStatusBar->show();
    m_progresstext->setText(QString("%1/%2").arg(1).arg(m_downloadRow.count()));
    pProgressBar->setFormat(QString("%1%").arg(0));
    pProgressBar->setValue(0);
    down_row(m_downloadRow[0]);

    m_downtable->setText("停止");

}

void MainWindow::ResProgress_slt(int pos, QString msg)
{
    switch (pos) {
    case ERROR_OPEN:
        QMessageBox::information(this, "提示", "串口打开失败，请检查！");
        m_com_obj = NULL;
        m_downtable->setText("下载");
        return;
    case ERROR_FILE:
        QMessageBox::information(this, "提示", "文件打开失败，请检查！");
        m_downtable->setText("下载");
        return;
    case ERROR_PICTYPE0:
        QMessageBox::information(this, "提示", "选择的文件为压缩图片格式，请检查！");
        m_downtable->setText("下载");
        return;
    case ERROR_PICTYPE1:
        QMessageBox::information(this, "提示", "选择的文件为无压缩图片格式，请检查！");
        m_downtable->setText("下载");
        return;
    case ERROR_NOFINDCHAR:
        QMessageBox::information(this, "提示", QString("缺少字符:%1！").arg(msg));
        m_downtable->setText("下载");
        return;
    case ERROR_ADDR:
        QMessageBox::information(this, "提示", "擦除地址有误，请检查！");
        m_downtable->setText("下载");
        return;
    case DECODE_OK:
        QMessageBox::information(this, "提示", "芯片已解密！");
        return;
    case CANCEL_OK:
        m_downtable->setText("下载");
        return;
    default:
        break;
    }
    if (pos > 100){
        pos = 100;
    }
    pProgressBar->setFormat(QString("%1%").arg(pos));
    pProgressBar->setValue(pos);

    int row_cnt = m_downloadRow.count();
    int cur_num = m_progresstext->text().split("/")[0].toInt();
    if (pos == 100){
        cur_num++;
        if (cur_num > row_cnt){
            m_downtable->setText("下载");
            pStatusBar->hide();
            QMessageBox::information(this, "提示", "下载完成！");
        }else{
            QThread::sleep(1);      //必须加延时，否则控制器反应不过来
            m_progresstext->setText(QString("%1/%2").arg(cur_num).arg(row_cnt));
            down_row(m_downloadRow[cur_num-1]);
        }
    }
}

void MainWindow::SetFilePath(QTableWidgetItem *item)
{
    int col = item->column();
    if (col != 3)
        return;
    QString file_dir = QFileDialog::getOpenFileName(this, tr("选择文件"), "");
    if (!file_dir.isEmpty()){
        item->setText(file_dir);
        item->setToolTip(file_dir);
    }
}

void MainWindow::SetStartAddress(int index)
{

}

void MainWindow::SetEraseSize(int index)
{

}

void MainWindow::on_exportcfg_clicked()
{
    int rowCnt = m_table->rowCount();
    if (rowCnt<=0){
        return;
    }
    QString saveFileName = QFileDialog::getSaveFileName(this, tr("保存配置文件"), "", "Config(*.ini *.txt);;");
    if(saveFileName.isEmpty() ) return;

    QFile file(saveFileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream txtOutput(&file);
    QString type, address, size, filedir;
    for(int i=0;i<rowCnt;i++){
        type = ((QComboBox *)(m_table->cellWidget(i, 0)))->currentText();
        address = ((QComboBox *)(m_table->cellWidget(i, 1)))->currentText();
        size = ((QComboBox *)(m_table->cellWidget(i, 2)))->currentText();
        filedir = m_table->item(i, 3)->text();
        txtOutput<<i<<"\t"<<type<<"\t"<<address<<"\t"<<size<<"\t"<<filedir<<"\n";
    }
    file.close();

}

void MainWindow::on_inportcfg_clicked()
{
    QString file_dir = QFileDialog::getOpenFileName(this, tr("选择配置文件"), "", "Config(*.ini *.txt);;");
    if(file_dir.isEmpty() ) return;

    QFile file(file_dir);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    m_table->setRowCount(0);
    QTextStream txtInput(&file);
    QString lineStr;
    QComboBox *type, *address, *size;
    QStringList dataList;
    bool ok;
    int i, index;
    while(!txtInput.atEnd()){
        lineStr = txtInput.readLine();
        dataList = lineStr.split("\t");
        if (dataList.count() == 5){
            on_insert_clicked();
            i = dataList[0].toInt(&ok, 10);
            if (ok && i < m_table->rowCount()){
                type = (QComboBox *)(m_table->cellWidget(i, 0));
                address = (QComboBox *)(m_table->cellWidget(i, 1));
                size = (QComboBox *)(m_table->cellWidget(i, 2));
                index = m_flashType.indexOf(dataList[1]);
                if (index > -1){
                    type->setCurrentIndex(index);
                }else{
                    type->setCurrentText(dataList[1]);
                }
                index = m_flashAddr.indexOf(dataList[2]);
                if (index > -1){
                    address->setCurrentIndex(index);
                }else{
                    address->setCurrentText(dataList[2]);
                }
                index = m_flashSize.indexOf(dataList[3]);
                if (index > -1){
                    size->setCurrentIndex(index);
                }else{
                    size->setCurrentText(dataList[3]);
                }
            }
            m_table->item(dataList[0].toInt(), 3)->setText(dataList[4]);
            m_table->item(dataList[0].toInt(), 3)->setToolTip(dataList[4]);
        }

    }

    file.close();
}

void MainWindow::on_flashdeconde_clicked()
{
    if (m_com_obj == NULL){
        m_com_obj = new ComObject(m_ComPort, "9600", "None", "1");
        connect(m_com_obj, SIGNAL(ResProgress_sig(int, QString)),
                this, SLOT(ResProgress_slt(int, QString)));
    }
    for (int i=0;i<2;i++){
        m_com_obj->SendMsg("?");
        QThread::msleep(200);
        m_com_obj->SendMsg("S");
        QThread::msleep(10);
        m_com_obj->SendMsg("y");
        QThread::msleep(10);
        m_com_obj->SendMsg("n");
        QThread::msleep(10);
        m_com_obj->SendMsg("c");
        QThread::msleep(10);
        m_com_obj->SendMsg("h");
        QThread::msleep(10);
        m_com_obj->SendMsg("r");
        QThread::msleep(10);
        m_com_obj->SendMsg("o");
        QThread::msleep(10);
        m_com_obj->SendMsg("n");
        QThread::msleep(10);
        m_com_obj->SendMsg("i");
        QThread::msleep(10);
        m_com_obj->SendMsg("z");
        QThread::msleep(10);
        m_com_obj->SendMsg("e");
        QThread::msleep(10);
        m_com_obj->SendMsg("d");
        QThread::msleep(10);
        m_com_obj->SendMsg("\r\n");
        QThread::msleep(100);
        m_com_obj->SendMsg("A");
        QThread::msleep(10);
        m_com_obj->SendMsg(" ");
        QThread::msleep(10);
        m_com_obj->SendMsg("0");
        QThread::msleep(10);
        m_com_obj->SendMsg("\r\n");
        QThread::msleep(100);
        m_com_obj->SendMsg("A");
        QThread::msleep(10);
        m_com_obj->SendMsg(" ");
        QThread::msleep(10);
        m_com_obj->SendMsg("0");
        QThread::msleep(10);
        m_com_obj->SendMsg("\r\n");
        QThread::msleep(200);
        if (m_deviceType->currentIndex() == 0){
            m_com_obj->SendMsg("U 23130\r\n");  //锁定
            QThread::msleep(100);
            m_com_obj->SendMsg("P 0 29\r\n");   //定位
            QThread::msleep(100);
            m_com_obj->SendMsg("E 0 29\r\n");   //擦除
        }else if(m_deviceType->currentIndex() == 1){
            m_com_obj->SendMsg("U 23130\r\n");  //锁定
            QThread::msleep(100);
            m_com_obj->SendMsg("P 0 63\r\n");   //定位
            QThread::msleep(100);
            m_com_obj->SendMsg("E 0 63\r\n");   //擦除
        }

        QThread::msleep(100);
        m_com_obj->SendMsg("R 764 4\r\n");  //读取加密状态
    }
    return;




    QFile file("LPC1788.bsp");
    if(!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    QString errorStr;
    int errorLine;
    int errorCol;

    QDomDocument sdoc;

    //setContent是将指定的内容指定给QDomDocument解析，
    //第一参数可以是QByteArray或者是文件名等
    if(!sdoc.setContent(&file, true, &errorStr, &errorLine, &errorCol))
    {
        file.close();
        qDebug() << errorStr << "line: " << errorLine << "col: " << errorCol;
        return;
    }
    //读取报警列表

    QString Name, DataFormat, Data, Latency, Active;
    bool ok;
    QDomElement elm;
    QDomElement root = sdoc.documentElement();
    QDomNode r_node = root.firstChild();
    while (!r_node.isNull())
    {
        QDomElement r_elm = r_node.toElement();
        QString name = r_elm.tagName();
        if (name == "Signals"){
            QDomNode s_node = r_elm.firstChild();
            while (!s_node.isNull()){
                QDomElement b_elm = s_node.toElement();
                name = b_elm.tagName();
                if (name == "BSSignal"){
                    QDomNodeList nodelist = s_node.childNodes();
                    elm = nodelist.at(0).toElement();
                    Name = elm.text();
                    elm = nodelist.at(1).toElement();
                    DataFormat = elm.text();            //数据格式
                    elm = nodelist.at(2).toElement();
                    Data = elm.text();
                    elm = nodelist.at(3).toElement();
                    Latency = elm.text();
                    elm = nodelist.at(4).toElement();
                    Active = elm.text();

                    if (Active == "true"){
                        if (DataFormat == "String"){
                            m_com_obj->com->SendMsg_slt(Data.toLocal8Bit().data());

                        }else if (DataFormat == "Hex"){
                            char sdata = Data.toInt(&ok,16);
                            m_com_obj->com->SendMsg_slt(&sdata);
                        }

                        QThread::msleep(Latency.toInt());
                        qDebug()<<QString("Send %1, delay %2").arg(Data).arg(Latency);
                    }
                }
                s_node = s_node.nextSibling();
            }
        }
        r_node = r_node.nextSibling();
    }

    file.close();

}

void MainWindow::on_M90Uncomp_clicked()
{
    QDir rootDir(M90path->text());
    QString projectDir;
    rootDir.setFilter(QDir::Dirs);
    //第一步：遍历当前目录，取出所有文件夹
    foreach(QFileInfo fullDir, rootDir.entryInfoList()){
        if(fullDir.fileName() == "." || fullDir.fileName() == "..")
            continue;
        projectDir = fullDir.absoluteFilePath();
        QDir dir(projectDir);
        foreach(QString filename, dir.entryList())
        {
            if (filename.endsWith("rar") || filename.endsWith("zip"))
            {
                qApp->processEvents();
                QString code_packet = dir.absolutePath()+"\/"+filename;
                QString extract_cmd = QString("\"%1\" x -ibck -y -o+ \"%2\" \"%3\"")
                                .arg(m_winRARCfg)
                                .arg(code_packet)
                                .arg(dir.absolutePath());
                QProcess pro(0);
                pro.execute(extract_cmd);
                qApp->processEvents();
            }
        }
    }
    QMessageBox::information(this, tr("提示"), tr("解压完成！"));
}

void MainWindow::on_M90Choose_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("选择目录"), "D:\\2-Work\\0-Day_work", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!dir.isEmpty())
        M90path->setText(dir);
}

void MainWindow::on_M90Modfiy_clicked()
{


}

void MainWindow::on_M90Compress_clicked()
{
    QDir rootDir(M90path->text());
    QString projectDir;
    rootDir.setFilter(QDir::Dirs);
    //第一步：遍历当前目录，取出所有文件夹
    foreach(QFileInfo fullDir, rootDir.entryInfoList()){
        if(fullDir.fileName() == "." || fullDir.fileName() == "..")
            continue;

        if ((!fullDir.fileName().startsWith("M")) || (!fullDir.isDir())) continue;

        projectDir = fullDir.absoluteFilePath();

        QDir dir(projectDir);
        //删除原有压缩包
        foreach(QString filename, dir.entryList())
        {
            if (filename.endsWith("rar") || filename.endsWith("zip"))
            {
                qApp->processEvents();
                QString code_packet = dir.absolutePath()+"\/"+filename;
                dir.remove(code_packet);
                break;
            }
        }
        //打包文件夹
        foreach(QFileInfo fileitem ,dir.entryInfoList())
        {
            qDebug()<<fileitem.fileName();
            if (fileitem.fileName().startsWith("M") && fileitem.isDir())
            {
                QString code_dir = fileitem.absoluteFilePath();
                QString packet_cmd = QString("\"%1\" a -ep1 -r -ibck -o+ \"%2\" \"%3\"")
                                .arg(m_winRARCfg)
                                .arg(code_dir+".rar")
                                .arg(code_dir);
                qDebug() <<packet_cmd;
                QProcess pro(0);
                pro.execute(packet_cmd);

                deleteDir(code_dir);
            }
        }
    }
    QMessageBox::information(this, tr("提示"), tr("打包清理完成！"));
}

void MainWindow::on_M90Compile_clicked()
{
    QDir rootDir(M90path->text());
    QString projectDir;
    rootDir.setFilter(QDir::Dirs);
    //第一步：遍历当前目录，取出所有文件夹
    foreach(QFileInfo fullDir, rootDir.entryInfoList()){
        if(fullDir.fileName() == "." || fullDir.fileName() == "..")
            continue;

        if ((!fullDir.fileName().startsWith("M")) || (!fullDir.isDir())) continue;
        projectDir = fullDir.absoluteFilePath();
        QDir dir(projectDir);
        foreach(QFileInfo fileitem ,dir.entryInfoList())
        {

            qDebug()<<fileitem.fileName();
            //2.删除hex文件
            if (fileitem.fileName().endsWith("hex"))
            {
                dir.remove(fileitem.fileName());
                break;
            }
        }
        foreach(QFileInfo fileitem ,dir.entryInfoList())
        {
            if (fileitem.fileName().startsWith("M") && fileitem.isDir())
            {
                QString code_path = fileitem.absoluteFilePath();
                //查找目录内工程文件后缀
                //1.1判断路径是否存在
                QDir dir1(code_path);
                if(!dir1.exists())
                {
                    break;
                }
                QFileInfoList InfoList = QDir(code_path).entryInfoList();//获取当前目录所有文件
                QFileInfoList SuffixInfoList;//定义放提取文件的List
                //遍历
                foreach(QFileInfo fileInfo, InfoList )
                {
                    if(!fileInfo.isFile()) continue;//不是文件继续，只用于加速，可不加
                    //后缀不区分大小写，需要区分直接用“==”
                    if(0==fileInfo.suffix().compare("uvproj", Qt::CaseInsensitive))
                    {
                        SuffixInfoList << fileInfo;//指定后缀，加入列表
                        break;
                    }
                }
                if (InfoList.count()<0){
                    break;
                }
                int old_hexFileTime = QDateTime::currentDateTime().toTime_t();
                //QString build_cmd = QString("%1 -j0 -r %2 -o build_log.txt").arg(DIR_KEIL).arg(project_path);
                QString build_cmd = QString("\"%1\" -j0 -b \"%2\"").arg(m_keilCfg).arg(SuffixInfoList[0].absoluteFilePath());
                //这里的编译选项 -r:rebuild,-b:build
                QProcess pro(0);
                pro.execute(build_cmd);

                //拷贝hex出来
                QDir dir2(code_path + "\\Output\\LPC1788_TengHua_LPC1788_KEIL_CMSIS\\Release_FLASH\\Obj");
                foreach(QFileInfo fileitem ,dir2.entryInfoList())
                {
                    int hexFileTime = fileitem.lastModified().toTime_t();

                    if (fileitem.fileName().endsWith("hex")
                        && (hexFileTime > old_hexFileTime))
                    {
                        //如果已经存在hex，则先删除
                        if (QFile::copy(fileitem.filePath(), projectDir+"/"+fileitem.fileName()));


                    }
                }

            }
        }
    }

    QMessageBox::information(this, tr("提示"), tr("编译完成！"));
}

void MainWindow::on_M90Change_clicked()
{
    QDir rootDir(M90path->text());
    QString projectDir;
    rootDir.setFilter(QDir::Dirs);
    //第一步：遍历当前目录，取出所有文件夹
    foreach(QFileInfo fullDir, rootDir.entryInfoList()){
        if(fullDir.fileName() == "." || fullDir.fileName() == "..")
            continue;
        projectDir = fullDir.absoluteFilePath();
        ChangeM90(projectDir);

    }
    QMessageBox::information(this, tr("提示"), tr("修改完成！"));
}

void MainWindow::ChangeM90(QString path)
{
    m_srcPath->setText(path);
    QString name = path.mid(path.lastIndexOf("/") + 1);
    if (name.startsWith("M6090")
        || name.startsWith("M6080")
        || name.startsWith("M6070")
        || name.startsWith("M6060")){
        name.remove(1,2);
    }
    m_name->setText(name);
    QString currentDate = QDate::currentDate().toString("yyyyMMdd");
    m_data->setText(currentDate.mid(2));

    m_cb_data->setChecked(true);
    m_cb_ckCode->setChecked(false);
    m_cb_password->setChecked(false);
    m_cb_vsd->setChecked(false);
    m_cb_vfactor->setChecked(false);
    m_cb_jiemi->setChecked(false);

    //1.修改目录名称
    QString src_path = path;
    QString hex_name = m_name->text();
    QString soft_name = hex_name.left(hex_name.lastIndexOf("_")+1);
    m_hex_name = soft_name + m_data->text();

    QString new_path = src_path.left(src_path.lastIndexOf("/")+1) + m_hex_name;
    m_code_path = new_path;

    QDir dir(src_path);
    if(!dir.exists())
    {
        return;
    }
    if (m_cb_data->isChecked())
    {
        dir.rename(src_path, new_path);
        dir.setPath(new_path);
    }

    QDir dir_new(new_path);
    foreach(QFileInfo fileitem ,dir_new.entryInfoList())
    {
        qDebug()<<fileitem.fileName();
        if (fileitem.fileName().startsWith("M") && fileitem.isDir())
        {
            m_dir_name = fileitem.fileName();
            //4.修改程序
            modify_global(fileitem.fileName());
            //5.修改输出的hex文件名
            modify_hexfile(fileitem.fileName());
//            //6.修改加解密
//            if (m_cb_jiemi->isChecked()){
//                modify_startup(true);
//            }else{
//                modify_startup(false);
//            }
            qApp->processEvents();
        }

    }


}


void MainWindow::down_row(int row)
{
    int cmd;
    //下载类型
    int type = ((QComboBox *)(m_table->cellWidget(row, 0)))->currentIndex();
    //起始地址
    QString addr = ((QComboBox *)(m_table->cellWidget(row, 1)))->currentText();
    addr = addr.mid(addr.indexOf("(")+1, 6);
    bool ok;
    int address = addr.toInt(&ok, 16);
    if ((!ok) | (address < 0) | (address > 0x800000)){
        QMessageBox::warning(this, "错误", QString("第%1行地址错误").arg(row));
        return;
    }
    //擦除大小
    int erase_size = ((QComboBox *)(m_table->cellWidget(row, 2)))->currentIndex();
    switch (erase_size) {
    case 0: //4k
        cmd = 0x57;
        break;
    case 1: //8k
        cmd = 0x58;
        break;
    case 2: //16K
        cmd = 0x59;
        break;
    case 3: //20K
        cmd = 0x5c;
        break;
    case 4: //252k
        cmd = 0x5f;
        break;
    case 5: //1M
        cmd = 0x5a;
        break;
    case 6: //0
        cmd = 0x0;
        break;
    default:
        cmd = 0x58;
        break;
    }
    //图片位置
    QString filename = m_table->item(row, 3)->text();

    m_com_obj->DownLoad(type, cmd, address, filename);
}
