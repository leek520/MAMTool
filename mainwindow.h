
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QCoreApplication>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QCheckBox>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QDebug>
#include <QProcess>
#include <QFileDialog>
#include <QListWidget>
#include <QMessageBox>
#include <QMenuBar>
#include <QComboBox>
#include <QTablewidget>
#include <QHeaderView>
#include <QProgressBar>
#include <QStatusBar>
#include <QDialogButtonBox>
#include <QDomDocument>
#include <QAxObject>

#include "comobject.h"

#define DIR_WINRAR      "C:\\Program Files\\WinRAR\\WinRAR.exe"
#define DIR_CHECK       "C:\\Users\\Administrator\\Desktop\\ChangeName.exe"
#define DIR_KEIL        "C:\\Keil_v5\\UV4\\UV4.exe"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setUi();
    void SetMenu();
    int build_check();

private slots:
    void on_m_start_clicked();
    void on_m_check_clicked();
    void on_m_copy_clicked();
    void on_m_compress_clicked();
    void on_m_clear_clicked();
    void on_btn_clicked();
    void on_m_build_clicked();
    void on_m_download_clicked();

    void on_build2_clicked();
    void on_clear2_clicked();


    void on_m_chooseBtn_clicked();
    void on_m_chooseoutBtn_clicked();
    void on_m_createBtn_clicked();



    void modify_global(QString name);
    void modify_hexfile(QString name);
    void modify_zhanhao(QString name);
    void modify_vfactor(QString name);
    void modify_startup(bool jiemi);

    bool deleteDir(const QString &dirName);

    void on_actioncfg_triggered();
    void on_actioncom_triggered();


    void cal_pass();

    void on_insert_clicked();
    void on_delete_clicked();
    void on_downtable_clicked();
    void ResProgress_slt(int pos);

    void SetFilePath(QTableWidgetItem* item);
    void SetStartAddress(int index);
    void SetEraseSize(int index);

    void on_exportcfg_clicked();
    void on_inportcfg_clicked();

    void on_flashdeconde_clicked();
private:
    void down_row(int row);
private:
    QPushButton *m_chooseBtn;
    QPushButton *m_chooseoutBtn;
    QPushButton *m_createBtn;
    QLineEdit *m_srcPathx;
    QLineEdit *m_outPath;
    QLineEdit *m_colNum;

    QGridLayout *m_gbox;
    QList<QComboBox *> m_comboxlist;


    QLineEdit *m_srcPath;
    QLineEdit *m_name;
    QLineEdit *m_data;
    QLineEdit *m_ckCode;
    QLineEdit *m_company;
    QLineEdit *m_password;

    QCheckBox *m_cb_data;
    QCheckBox *m_cb_ckCode;
    QCheckBox *m_cb_password;


    QCheckBox *m_cb_vsd;
    QCheckBox *m_cb_vfactor;
    QCheckBox *m_cb_jiemi;

    QPushButton *m_start;
    QPushButton *m_build;
    QPushButton *m_download;
    QPushButton *m_copy;
    QPushButton *m_check;
    QPushButton *m_compress;
    QPushButton *m_clear;
    QComboBox *m_deviceType;

    QString m_code_path;
    QString m_hex_name;
    QString m_dir_name;
    QString m_project_path;
    int m_hexFileTime;
    bool m_isCode;
    QListWidget *m_loglist;

    QPushButton *m_modfiy_build;
    QPushButton *m_compress_clear;
    bool m_jiemi;
    QString m_winRARCfg;
    QString m_keilCfg;
    QString m_checkCfg;
    QTableWidget *m_tableCfg;

    QComboBox *m_comfact;
    QLineEdit *m_tippass;
    QLabel *m_dynpass;

    QTableWidget *m_table;
    QPushButton *m_exportcfg;
    QPushButton *m_inportcfg;
    QPushButton *m_insert;
    QPushButton *m_delete;
    QPushButton *m_downtable;


    QStringList m_flashType;
    QStringList m_flashAddr;
    QStringList m_flashSize;

    QString m_ComPort;
    QString m_baudRate;
    QString m_Parity;
    QString m_Stopbit;
    ComObject *m_com_obj;
    QStatusBar *pStatusBar;
    QProgressBar * pProgressBar;
    QLabel *m_progresstext;

    QDialog *m_cfgDialog;
    QDialog *m_comDialog;
};

#endif // MAINWINDOW_H
