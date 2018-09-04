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
    resize(500,450);
    QTabWidget *w = new QTabWidget();
    setCentralWidget(w);
    QWidget *main0 = new QWidget(this);
    QWidget *main1 = new QWidget(this);
    QWidget *main2 = new QWidget(this);

    w->addTab(main0, "程序修改");
    w->addTab(main1, "密码计算");
    w->addTab(main2, "flash下载");

    QVBoxLayout *vbox = new QVBoxLayout();
    main0->setLayout(vbox);

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
    m_copy = new QPushButton("4拷贝hex");
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
    m_cb_ckCode->setChecked(true);
    m_cb_password->setChecked(true);

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


    //算密码页面设计
    m_comfact = new QComboBox;
    m_comfact->addItem("台盛");
    m_comfact->addItem("鑫磊");


    m_tippass = new QLineEdit;
    m_tippass->setPlaceholderText("提示码");
    m_dynpass = new QLabel("密码：");
    m_dynpass->setFixedWidth(100);
    QHBoxLayout *passbox = new QHBoxLayout(main1);
    passbox->addWidget(m_comfact);
    passbox->addWidget(m_tippass);
    passbox->addWidget(m_dynpass);

    connect(m_tippass, SIGNAL(editingFinished()), this, SLOT(cal_pass()));



    //flash下载页面

    QGridLayout *tgbox = new QGridLayout(main2);
    m_table = new QTableWidget();

    m_table->setColumnCount(4);
    m_table->setColumnWidth(0, 90);
    m_table->setColumnWidth(1, 150);
    m_table->setColumnWidth(2, 60);
    m_table->horizontalHeader()->setStretchLastSection(true);//关键
    m_table->setHorizontalHeaderLabels(QStringList()<<"操作"<<"起始地址"<<"擦除大小"<<"文件"<<"状态");

    m_exportcfg = new QPushButton("保存配置");
    m_exportcfg->setFixedHeight(40);
    m_inportcfg = new QPushButton("载入配置");
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
    tgbox->addWidget(m_exportcfg,1,0,1,1);
    tgbox->addWidget(m_inportcfg,1,1,1,1);
    tgbox->addWidget(m_insert,1,2,1,1);
    tgbox->addWidget(m_delete,1,3,1,1);
    tgbox->addWidget(m_downtable,1,4,1,1);

    m_com_obj = NULL;
    m_ComPort = "COM1";
    m_baudRate = 115200;
    m_flashType<<"无压缩图片"<<"压缩图片"<<"宋体32字库"<<"菜单";
    m_flashAddr<<"Run(300000)"<<"User(30a000)"
                <<"Fact(346000)"<<"Calc(314000)"
                <<"Block(31e000)"<<"Hard(30f000)"
                <<"Maint(328000)"<<"Vsd(34b000)"
                <<"Touch(341000)"<<"TimePress(337000)"
                <<"RunStop(33c000)"<<"Fault(323000)"
                <<"MVSD(305000)"<<"FVSD(32d000)"
                <<"Fact(346000)"<<"Calc(314000)"
                <<"Data(319000)"<<"SetVSD(3c0000)"
                <<"Mode(378000)"<<"Return(332000)"
                <<"First(100000)"<<"32CharLib(000000)"
                <<"Stop(200000)"<<"Load1(23f000)"
                <<"Load2(27e000)"<<"Unld1(2bd000)"
                <<"Unld2(37d000)"<<"Fan1(36e000)"
                <<"Fan2(373000)";
    m_flashSize<<"4K"<<"8K"<<"16K"<<"20K"<<"252K"<<"1M";

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
    m_srcPath->setText(dir);
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
            if (strAll[i].contains("if\(\*pstr1 > 2000 \) \*pstr1 = 2000;"))
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
    on_m_clear_clicked();
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
    m_cfgDialog->resize(300,150);
    QGridLayout *gridbox = new QGridLayout(m_cfgDialog);

    m_tableCfg = new QTableWidget(3,1);
    m_tableCfg->setToolTip("双击更改程序默认位置！");
    QTableWidgetItem *item = new QTableWidgetItem(m_winRARCfg);
    m_tableCfg->setItem(0, 0, item);
    item = new QTableWidgetItem(m_keilCfg);
    m_tableCfg->setItem(1, 0, item);
    item = new QTableWidgetItem(m_checkCfg);
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
            QMessageBox::information(this, "提示", "Check路径错误！");
            QTimer::singleShot(100,this, SLOT(on_actioncfg_triggered()));
            return;
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
    QComboBox *baud = new QComboBox();
    baud->addItems(QStringList()<<"9600"<<"115200");
    QPushButton *ok = new QPushButton("Ok");
    QPushButton *cancel = new QPushButton("Cancel");
    connect(ok, SIGNAL(clicked()), m_comDialog, SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), m_comDialog, SLOT(reject()));

    gridbox->addWidget(com, 0, 0);
    gridbox->addWidget(baud, 0, 1);
    gridbox->addWidget(ok, 1, 0);
    gridbox->addWidget(cancel, 1, 1);
    int resutl = m_comDialog->exec();
    if (resutl == QDialog::Accepted)
    {
        m_ComPort = com->currentText();
        m_baudRate = baud->currentText().toInt();
        qDebug() << "You Choose Ok";
    }
    else
    {
        qDebug() << "You Choose Cancel";
    }


}

void MainWindow::cal_pass()
{
    int num = m_comfact->currentIndex();
    unsigned short CalCode, dynpass;
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
    default:
        break;
    }

    m_dynpass->setText(QString("密码：%1").arg(dynpass));
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

    QComboBox *item0 = new QComboBox();
    item0->addItems(m_flashType);
    item0->setCurrentIndex(1);
    //connect(item0, SIGNAL(currentIndexChanged(int)), this, SLOT(SetStartAddress(int)));
    QComboBox *item1 = new QComboBox();
    item1->addItems(m_flashAddr);
    item1->setEditable(true);
    //connect(item1, SIGNAL(currentIndexChanged(int)), this, SLOT(SetEraseSize(int)));
    QComboBox *item2 = new QComboBox();
    item2->addItems(m_flashSize);
    item2->setCurrentIndex(3);

    QTableWidgetItem *item3 = new QTableWidgetItem("C:/Users/leek/Desktop/data.ini"/*"D:\\2-Work\\0-Day_work\\leek\\xinlei_two\\first.c"*/);

    item3->setToolTip(item3->text());

    m_table->setCellWidget(cur_num, 0, item0);
    m_table->setCellWidget(cur_num, 1, item1);
    m_table->setCellWidget(cur_num, 2, item2);
    m_table->setItem(cur_num, 3, item3);

}

void MainWindow::on_delete_clicked()
{
    int cur_num = m_table->currentRow();
    if (cur_num>=0)
        m_table->removeRow(cur_num);
}

void MainWindow::on_downtable_clicked()
{
    if (m_com_obj == NULL){
        m_com_obj = new ComObject(m_ComPort, m_baudRate);
        connect(m_com_obj, SIGNAL(ResProgress_sig(int)),
                this, SLOT(ResProgress_slt(int)));
    }

    int row_cnt = m_table->rowCount();
    if (row_cnt<=0){
        return;
    }

    pStatusBar->show();
    m_progresstext->setText(QString("%1/%2").arg(1).arg(row_cnt));
    pProgressBar->setFormat(QString("%1%").arg(0));
    pProgressBar->setValue(0);
    down_row(0);
}

void MainWindow::ResProgress_slt(int pos)
{
    if (pos == -1){
        pStatusBar->hide();
        QMessageBox::information(this, "提示", "串口打开失败，请检查！");
        return;
    }
    pProgressBar->setFormat(QString("%1%").arg(pos));
    pProgressBar->setValue(pos);

    int row_cnt = m_table->rowCount();
    int cur_num = m_progresstext->text().split("/")[0].toInt();
    if (pos==100){
        cur_num++;
        if (cur_num > row_cnt){
            QMessageBox::information(this, "提示", "下载完成！");
        }else{
            m_progresstext->setText(QString("%1/%2").arg(cur_num).arg(row_cnt));
            down_row(cur_num-1);
        }
    }
}

void MainWindow::SetFilePath(QTableWidgetItem *item)
{
    int row = item->row();
    int col = item->column();
    if (col != 3)
        return;
    QString file_dir = QFileDialog::getOpenFileName(this, tr("选择文件"), "");
    item->setText(file_dir);
    item->setToolTip(file_dir);
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
                }
                index = m_flashAddr.indexOf(dataList[2]);
                if (index > -1){
                    address->setCurrentIndex(index);
                }
                index = m_flashSize.indexOf(dataList[3]);
                if (index > -1){
                    size->setCurrentIndex(index);
                }
            }
            m_table->item(dataList[0].toInt(), 3)->setText(dataList[4]);
        }

    }

    file.close();
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
    //图片位置
    QString filename = m_table->item(row, 3)->text();

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
    default:
        cmd = 0x58;
        break;
    }
    m_com_obj->DownLoad(type, cmd, address, filename, 0);
}







