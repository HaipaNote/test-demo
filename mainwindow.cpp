#include "mainwindow.h"
#include "error.h"
#include "widgetone.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>

#include <QTextEdit>
#include <QString>
#include <QLabel>
#include <QMap>
#include <iostream>
#include <utility>
#include <QCoreApplication>

#include <QMessageBox>
using namespace  std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    this->setFixedSize(800,600);
    this->setWindowTitle(QString::fromLocal8Bit("��ҳ"));



    //�˻��ı���
    label_user = new QLabel(this);
    label_user->setText(QString::fromLocal8Bit("��  ����"));
    label_user->setGeometry(100, 170, 150, 90);
    //�˻��༭��
    userTextEdit = new QTextEdit(this);
    userTextEdit->setGeometry(170, 200, 200, 30);
    userTextEdit->setAcceptRichText(false);


    //�����ı���
    label_pwd = new QLabel(this);
    label_pwd->setText(QString::fromLocal8Bit("��   �룺"));
    label_pwd->setGeometry(100, 270, 150, 90);
    //����༭��
    pwdTextEdit = new QTextEdit(this);
    pwdTextEdit->setGeometry(170, 300, 200, 30);
    pwdTextEdit->setAcceptRichText(false);



    //������ť
    //ע��
    btn_register=new QPushButton(QString::fromLocal8Bit("ע��"),this);
    btn_register->resize(90,40);
    btn_register->move(600,120);
    //����¼��Ϣ�Ƿ���ȷ����ɵ�¼
    connect(btn_register,&QPushButton::clicked,this,&MainWindow::registerButtonClicked);

    //��¼
    btn_login=new QPushButton(QString::fromLocal8Bit("��¼"),this);
    btn_login->resize(90,40);
    btn_login->move(600,200);
    // ��ȡ�û���������

     //����¼��Ϣ�Ƿ���ȷ����ɵ�¼
     connect(btn_login,&QPushButton::clicked,this,&MainWindow::onLoginButtonClicked);

    //���
    QPushButton *btn_clear=new QPushButton(QString::fromLocal8Bit("���"),this);
    btn_clear->resize(90,40);
    btn_clear->move(600,280);
    //�������
    connect(btn_clear,&QPushButton::clicked,this,[=](){
        pwdTextEdit->clear();
        userTextEdit->clear();
    });
    //�˳�
    QPushButton *btn_exit=new QPushButton(QString::fromLocal8Bit("�˳�"),this);
    btn_exit->resize(90,40);
    btn_exit->move(600,360);
    //�˳�����
    connect(btn_exit,&QPushButton::clicked,this,[&](){
        close();
    });

}
//ע��
void MainWindow::registerButtonClicked()
{
    QString username = userTextEdit->toPlainText();
    QString password = pwdTextEdit->toPlainText();
    map.insert(username,password);

    if(map.size()){
        QMessageBox::information(this, QString::fromLocal8Bit("welcome������"), QString::fromLocal8Bit("ע��ɹ�����ӭ��¼"));
    }
    userTextEdit->clear();
    pwdTextEdit->clear();


    //����
}


//��¼
void MainWindow::onLoginButtonClicked()
{
    widgetOne *wid=new widgetOne;
    error *err=new error;

    QString username = userTextEdit->toPlainText();
    QString password = pwdTextEdit->toPlainText();

    QString usern=map.key(username);
    QString pwdn=map.value(usern);

    if(username==usern&&password==pwdn){
        wid->show();
        this->hide();

    }else{
        err->show();
        qDebug()<<"map::username"<<usern<<endl;
        qDebug()<<"map::pwd"<<pwdn<<endl;
    }

    map.clear();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}
