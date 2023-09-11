#ifndef WIDGETONE_H
#define WIDGETONE_H

#include <QWidget>
#include <QPushButton>
#include <map>
#include "ui_widgetone.h"
#include "person.h"
#include <QProgressBar>
#include <QMenuBar>
using namespace  std;
namespace Ui {
class widgetOne;
}

class widgetOne : public QWidget
{
    Q_OBJECT

public:
    explicit widgetOne(QWidget *parent = nullptr);
    ~widgetOne();
    QPushButton * btn_home1;
    QPushButton * btn_home2;
    QPushButton * btn_home3;
    QPushButton * btn_home4;
    QPushButton * btn_home5;
    QPushButton * btn_home6;
    QMenuBar * menu_bar;

     QProgressBar progressBar;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_15_clicked();

private:
    Ui::widgetOne *ui;
};

#endif // WIDGETONE_H
