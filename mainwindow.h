
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setUi();
private slots:
    void on_m_start_clicked();
    void on_m_check_clicked();
    void on_m_copy_clicked();
    void on_m_compress_clicked();
    void on_m_clear_clicked();
    void on_btn_clicked();

    void modify_global(QString name);
    void modify_hexfile(QString name);
    void modify_zhanhao(QString name);
    void modify_vfactor(QString name);

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

    QPushButton *m_start;
    QPushButton *m_copy;
    QPushButton *m_check;
    QPushButton *m_compress;
    QPushButton *m_clear;

    QString m_code_path;
    QString m_hex_name;
    QString m_dir_name;

    QListWidget *m_loglist;
};

#endif // MAINWINDOW_H
