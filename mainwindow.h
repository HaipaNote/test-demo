#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

#include <QTextEdit>
#include <QString>
#include <QPushButton>
#include <QMap>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);


    QLabel* label_pwd ;
    QTextEdit* pwdTextEdit;
    QTextEdit* userTextEdit;
    QLabel* label_user;
    QPushButton *btn_login;
    QPushButton * btn_register;
    QMap<QString,QString>map;

    //Ìø×ªµ½widdget´°¿Ú
    void  onLoginButtonClicked();
    void  registerButtonClicked();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
