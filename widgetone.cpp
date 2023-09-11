#include "widgetone.h"
#include "ui_widgetone.h"

#include <QDateTime>
#include <QPushButton>
#include <QPixmap>
#include <QMessageBox>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>

#include <QBarSeries>
#include <QBarSet>
#include <QtCharts>
#include <QPushButton>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QAbstractBarSeries>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QLegend>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtCharts/QBarCategoryAxis>
#include <QtWidgets/QApplication>
#include <QtCharts/QValueAxis>
#include <QVector>
#include <QDebug>

QVector<int>data0;
QVector<int>data1;
QVector<int>data2;
QVector<int>data3;

using namespace QtCharts;

widgetOne::widgetOne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetOne)
{
    ui->setupUi(this);
//    ui->tableView->setRowHeight(8);
    ui->label_21->setText(QString::fromLocal8Bit("PLC��ȡʧ�ܣ�����δ���ӣ�����"));
    for (int i = 0; i < 6; ++i) {
        data0.push_front(0);
        data1.push_front(0);
        data2.push_front(0);
        data3.push_front(0);
    }
    connect(ui->pushButton_19,&QPushButton::clicked,[=](){
        data0.push_front(ui->lineEdit->text().toInt());
        data1.push_front(ui->lineEdit_4->text().toInt());
        data2.push_front(ui->lineEdit_5->text().toInt());
        data3.push_front(ui->lineEdit_8->text().toInt());

        QBarSet *set0 = new QBarSet(QString::fromLocal8Bit("�չ�(min)"));
        QBarSet *set1 = new QBarSet(QString::fromLocal8Bit("UV(min)"));
        QBarSet *set2 = new QBarSet(QString::fromLocal8Bit("�չ�(month)"));
        QBarSet *set3 = new QBarSet(QString::fromLocal8Bit("UV(month)"));

        QVector<int>::iterator it1 = data0.begin();
        QVector<int>::iterator it2 = data1.begin();
        QVector<int>::iterator it3 = data2.begin();
        qDebug()<<it1<<"|"<<it2<<"|"<<it3;
        //if(i)
        for(QVector<int>::iterator it4 = data3.begin();it4<data3.begin()+5;it4++)
        {
            *set0 << *it1<< *(it1+1) << *(it1+2) << *(it1+3) << *(it1+4) << *(it1+5);
            *set1 << *it2<< *(it2+1) << *(it2+2) << *(it2+3) << *(it2+4) << *(it2+5);
            *set2 << *it3<< *(it3+1) << *(it3+2) << *(it3+3) << *(it3+4) << *(it3+5);
            *set3 << *it4<< *(it4+1) << *(it4+2) << *(it4+3) << *(it4+4) << *(it4+5);
            it1++;
            it2++;
            it3++;
        }
    //    *set0 << 5 << 2 << 3 << 4 << 5 << 6;
    //    *set1 << 7 << 0 << 0 << 4 << 0 << 7;
    //    *set2 << 9 << 5 << 8 << 19<< 8 << 5;
    //    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        QChart *c = new QChart();
        c->setTitle(QString::fromLocal8Bit("����UVǿ��"));
        c->addSeries(series);
        //ui->graphicsView->setChart(c);
        c->legend()->setVisible(true);
        c->setAnimationOptions(QChart::SeriesAnimations);
        //ui->graphicsView->setRenderHint(QPainter::Antialiasing);
        c->createDefaultAxes();//����Ĭ�ϵ����������ᣨ���� QBarSet ���õ�ֵ��
        QValueAxis *axisX = new QValueAxis();//�����������ϵ�б���������������Ϊ�ֲ���ʱ����
        QValueAxis *axisY = new QValueAxis();//����X/Y��
        axisX->setRange(0, 6);
        axisY->setRange(0, 15);//����X/Y��ʾ������
        c->setAxisX(axisX);
        c->setAxisY(axisY);//����chart��������
        series->attachAxis(axisX);
        c->legend()->setVisible(true); //����ͼ��Ϊ��ʾ״̬
        c->legend()->setAlignment(Qt::AlignBottom);//����ͼ������ʾλ���ڵײ�

    });



    //��ѡ��ťĬ��ѡ��
    ui->radioButton->setChecked(true);
    //���ñ��
    //���� ����
    ui->tableWidget->setColumnCount(2);
    //���ñ�ͷ
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<QString::fromLocal8Bit("��������")<<QString::fromLocal8Bit("��¼ʱ��"));
    //��������
    ui->tableWidget->setRowCount(5);
    //��������
    //ui->tableWidget->setItem(0,0,new QTableWidgetItem("��ɪ"));
    QStringList nameList;
    nameList<<"lolo"<<"ssss"<<"sasas"<<"sadd"<<"dsa";

    for(int i=0;i<5;i++){
        int col=0;
        //[]:����Խ��ֱ���������򣬳��������at���׳��쳣
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(nameList[i]));
        //ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sexList.at(i)));
        //int תQString
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(18+i)));
    }




    this->setFixedSize(900,600);
    this->setWindowTitle(QString::fromLocal8Bit("mywidget"));


    QDateTime * sys_time = new QDateTime;
    ui->label_15->setText(sys_time->currentDateTime().toString("yyyy.MM.dd \n hh:mm:ss"));
    ui->label_15->move(20,10);

    QMenuBar *menubar=new QMenuBar(ui->groupBox_4);
        QMenu *menu=new QMenu(QString::fromLocal8Bit("����(C)"),this);
        menubar->addMenu(menu);
        QMenu *menu1=new QMenu(QString::fromLocal8Bit("����(A)"),this);
        menubar->addMenu(menu1);
        QAction *act=new QAction(QString::fromLocal8Bit("��Ӵ���"),this);
        menu->addAction(act);
        menu->addSeparator();
        QAction *act1=new QAction(QString::fromLocal8Bit("�򿪴���"),this);
        menu->addAction(act1);
        QAction *act2=new QAction(QString::fromLocal8Bit("�رմ���"),this);
        menu->addAction(act2);
        menu->addSeparator();
        QAction *act3=new QAction(QString::fromLocal8Bit("���洮��"),this);
        menu->addAction(act3);
        QAction *act4=new QAction(QString::fromLocal8Bit("��ȡ����"),this);
        menu->addAction(act4);
        QAction *act5=new QAction(QString::fromLocal8Bit("д�봮��"),this);
        menu->addAction(act5);
        menu->addSeparator();
        QAction *act6=new QAction(QString::fromLocal8Bit("��ȡ���"),this);
        menu->addAction(act6);
        menu->addSeparator();
        QAction *act7=new QAction(QString::fromLocal8Bit("��������"),this);
        menu->addAction(act7);
        QAction *act8=new QAction(QString::fromLocal8Bit("��մ���"),this);
        menu->addAction(act8);
        menu->addSeparator();
        QAction *act9=new QAction("�˳�����",this);
        menu->addAction(act9);
        QAction *act10=new QAction("����Lincom",this);
        menu1->addAction(act10);

        //�ӹ�����
        QToolBar *toolbar=new QToolBar(ui->groupBox_5);
        QAction *ac=new QAction(this);
        ac->setIcon(QIcon(":/img/ok.png"));
        toolbar->addAction(ac);
        QAction *ac1=new QAction(this);
        ac1->setIcon(QIcon(":/img/sr.png"));
        toolbar->addAction(ac1);
        toolbar->addSeparator();

        QAction *ac2=new QAction(this);
        ac2->setIcon(QIcon(":/img/add.png"));
        toolbar->addAction(ac2);
        QAction *ac3=new QAction(this);
        ac3->setIcon(QIcon(":/img/clock.png"));
        toolbar->addAction(ac3);
        QAction *ac4=new QAction(this);
        ac4->setIcon(QIcon(":/img/copy-template.png"));
        toolbar->addAction(ac4);
        QAction *ac5=new QAction(this);
        ac5->setIcon(QIcon(":/img/save.png"));
        toolbar->addAction(ac5);
        QAction *ac6=new QAction(this);
        ac6->setIcon(QIcon(":/img/save.png"));

        toolbar->addAction(ac6);
        toolbar->addSeparator();

        QAction *ac7=new QAction(this);
        ac7->setIcon(QIcon(":/img/mulu.png"));
        toolbar->addAction(ac7);
        QAction *ac8=new QAction(this);
        ac8->setIcon(QIcon(":/img/clear.png"));
        toolbar->addAction(ac8);


        toolbar->addSeparator();
        QAction *ac9=new QAction(this);
        ac9->setIcon(QIcon(":/img/message.png"));
        toolbar->addAction(ac9);

        //����Ĭ����ʾ
        ui->stackedWidget->setCurrentIndex(3);


    //ui->label_21->setText(ui->progressBar->text());
    //ui->progressBar->setStyleSheet("QProgressBar { background-color: #87CEFA; }");

//    ui->lineEdit_9->setText("PLC��ȡʧ�ܣ�����δ����");

}

widgetOne::~widgetOne()
{
    delete ui;
}

void widgetOne::on_pushButton_clicked()
{

}

void widgetOne::on_pushButton_10_clicked()
{
     ui->page_3->show();
     ui->page_4->close();
     ui->page_5->close();
     ui->page_6->close();
     ui->page_7->close();
     ui->page_8->close();
     ui->groupBox_4->close();
     //ui->graphicsView->close();
}

void widgetOne::on_pushButton_11_clicked()
{
    ui->page_4->show();
    ui->page_3->close();
    ui->page_5->show();
    ui->groupBox_4->close();
   // ui->graphicsView->show();
}

void widgetOne::on_pushButton_4_clicked()
{
    ui->page_5->show();
    ui->page_6->close();
    ui->page_7->close();
    ui->page_8->close();
    ui->groupBox_4->close();
    // ui->graphicsView->show();
}

void widgetOne::on_pushButton_5_clicked()
{
    ui->page_8->show();
    ui->page_5->close();
    ui->page_6->close();
    ui->page_7->close();
    ui->groupBox_4->close();
    // ui->graphicsView->show();
}

void widgetOne::on_pushButton_6_clicked()
{
    ui->page_8->close();
    ui->page_5->close();
    ui->page_6->show();
    ui->page_7->close();
    ui->groupBox_4->close();
   //  ui->graphicsView->show();
}

void widgetOne::on_pushButton_7_clicked()
{
    ui->page_8->close();
    ui->page_5->close();
    ui->page_6->close();
    ui->page_7->show();
    ui->groupBox_4->show();
    // ui->graphicsView->show();
}

void widgetOne::on_pushButton_15_clicked()
{
    //�ر�ǰ���������
    int ret=QMessageBox::question(this,QString::fromLocal8Bit("�ر�ȷ��"),QString::fromLocal8Bit("��Ҫ�رմ���"));
   if(ret){
       this->close();
   }

}
