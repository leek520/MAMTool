
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


    void modify_global(QString name);
    void modify_hexfile(QString name);
    void modify_zhanhao(QString name);
    void modify_vfactor(QString name);
    void modify_startup(bool jiemi);

    bool deleteDir(const QString &dirName);
private:
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


    QString m_code_path;
    QString m_hex_name;
    QString m_dir_name;
    QString m_project_path;
    int m_hexFileTime;
    QListWidget *m_loglist;

    QPushButton *m_modfiy_build;
    QPushButton *m_compress_clear;
    bool m_jiemi;
};

#endif // MAINWINDOW_H
