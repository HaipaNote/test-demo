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
    this->setWindowTitle(QString::fromLocal8Bit("首页"));



    //账户文本：
    label_user = new QLabel(this);
    label_user->setText(QString::fromLocal8Bit("账  户："));
    label_user->setGeometry(100, 170, 150, 90);
    //账户编辑框：
    userTextEdit = new QTextEdit(this);
    userTextEdit->setGeometry(170, 200, 200, 30);
    userTextEdit->setAcceptRichText(false);


    //密码文本：
    label_pwd = new QLabel(this);
    label_pwd->setText(QString::fromLocal8Bit("密   码："));
    label_pwd->setGeometry(100, 270, 150, 90);
    //密码编辑框：
    pwdTextEdit = new QTextEdit(this);
    pwdTextEdit->setGeometry(170, 300, 200, 30);
    pwdTextEdit->setAcceptRichText(false);



    //创建按钮
    //注册
    btn_register=new QPushButton(QString::fromLocal8Bit("注册"),this);
    btn_register->resize(90,40);
    btn_register->move(600,120);
    //检测登录信息是否正确，完成登录
    connect(btn_register,&QPushButton::clicked,this,&MainWindow::registerButtonClicked);

    //登录
    btn_login=new QPushButton(QString::fromLocal8Bit("登录"),this);
    btn_login->resize(90,40);
    btn_login->move(600,200);
    // 获取用户名和密码

     //检测登录信息是否正确，完成登录
     connect(btn_login,&QPushButton::clicked,this,&MainWindow::onLoginButtonClicked);

    //清除
    QPushButton *btn_clear=new QPushButton(QString::fromLocal8Bit("清除"),this);
    btn_clear->resize(90,40);
    btn_clear->move(600,280);
    //清除功能
    connect(btn_clear,&QPushButton::clicked,this,[=](){
        pwdTextEdit->clear();
        userTextEdit->clear();
    });
    //退出
    QPushButton *btn_exit=new QPushButton(QString::fromLocal8Bit("退出"),this);
    btn_exit->resize(90,40);
    btn_exit->move(600,360);
    //退出功能
    connect(btn_exit,&QPushButton::clicked,this,[&](){
        close();
    });

}
//注册
void MainWindow::registerButtonClicked()
{
    QString username = userTextEdit->toPlainText();
    QString password = pwdTextEdit->toPlainText();
    map.insert(username,password);

    if(map.size()){
        QMessageBox::information(this, QString::fromLocal8Bit("welcome！！！"), QString::fromLocal8Bit("注册成功，欢迎登录"));
    }
    userTextEdit->clear();
    pwdTextEdit->clear();


    //测试
}


//登录
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
