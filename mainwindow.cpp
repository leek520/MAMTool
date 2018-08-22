#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setUi();
}

MainWindow::~MainWindow()
{

}

void MainWindow::setUi()
{
    resize(500,400);
    QWidget *main = new QWidget(this);
    setCentralWidget(main);

    QVBoxLayout *vbox = new QVBoxLayout();
    main->setLayout(vbox);

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


    gbox->addWidget(m_name,0,1);
    gbox->addWidget(m_data,1,1);
    gbox->addWidget(m_ckCode,2,1);
    gbox->addWidget(m_password,3,1);
    gbox->addWidget(m_cb_vfactor,4,1);


    QHBoxLayout *hbox_btn = new QHBoxLayout();
    m_start = new QPushButton("1执行");
    m_copy = new QPushButton("2拷贝hex");
    m_check = new QPushButton("3检查");
    m_compress = new QPushButton("4打包");
    m_clear = new QPushButton("5清理");

    hbox_btn->addWidget(m_start);
    hbox_btn->addWidget(m_copy);
    hbox_btn->addWidget(m_check);
    hbox_btn->addWidget(m_compress);
    hbox_btn->addWidget(m_clear);


    m_loglist = new QListWidget;
    QHBoxLayout *hbox_set = new QHBoxLayout();
    hbox_set->addWidget(groupbox);
    hbox_set->addWidget(m_loglist);
    hbox_set->setStretch(0,3);
    hbox_set->setStretch(1,2);

    vbox->addLayout(hbox);
    vbox->addLayout(hbox_set);
    vbox->addLayout(hbox_btn);


    m_cb_data->setChecked(true);
    m_cb_ckCode->setChecked(true);
    m_cb_password->setChecked(true);

    connect(m_start, SIGNAL(clicked(bool)), this, SLOT(on_m_start_clicked()));
    connect(m_check, SIGNAL(clicked(bool)), this, SLOT(on_m_check_clicked()));
    connect(m_copy, SIGNAL(clicked(bool)), this, SLOT(on_m_copy_clicked()));
    connect(m_compress, SIGNAL(clicked(bool)), this, SLOT(on_m_compress_clicked()));
    connect(m_clear, SIGNAL(clicked(bool)), this, SLOT(on_m_clear_clicked()));
    connect(btn, SIGNAL(clicked(bool)), this, SLOT(on_btn_clicked()));
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

    m_loglist->addItem("1.删除原hex.");
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
            m_loglist->addItem("2.开始解压.");
            QString code_packet = dir.absolutePath()+"\/"+filename;
            QString extract_cmd = QString("WinRaR.exe x -ibck -y -o+ %1 %2")
                            .arg(code_packet)
                            .arg(dir.absolutePath());
            qDebug() <<extract_cmd;
            QProcess pro(0);
            pro.execute(extract_cmd);
            m_loglist->addItem("3.解压完成.");
            dir.remove(code_packet);
            m_loglist->addItem("4.删除原压缩包.");
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
            m_loglist->addItem("5.程序修改完成，请重新编译.");
        }

    }



}

void MainWindow::on_m_check_clicked()
{
    QFileInfo check_tool("C:\\Users\\Administrator\\Desktop\\ChangeName.exe");
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
    QString packet_cmd = QString("WinRaR.exe a -ep1 -r -ibck -o+ %1 %2")
                    .arg(code_dir+".rar")
                    .arg(code_dir);
    qDebug() <<packet_cmd;
    QProcess pro(0);
    pro.execute(packet_cmd);
    m_loglist->addItem("7.打包完成.");
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
    QDir dir(m_code_path + "\\" + m_dir_name + "\\Output\\LPC1788_TengHua_LPC1788_KEIL_CMSIS\\Release_FLASH\\Obj");
    foreach(QFileInfo fileitem ,dir.entryInfoList())
    {

        if (fileitem.fileName().endsWith("hex") && fileitem.fileName().startsWith(m_hex_name))
        {
            if (QFile::copy(fileitem.filePath(), m_code_path+"\\"+fileitem.fileName()))
            {
                m_loglist->addItem("6.hex文件已拷贝到指定目录.");
            }
            qDebug()<<fileitem.filePath()<<m_code_path+"\\"+fileitem.fileName();
            return;
        }

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
                m_loglist->addItem("站号修改完成.");
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
                m_loglist->addItem("电压系数修改完成.");
            }

            in << strAll[i]<<"\n";
        }

        file.close();
    }
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





