#include "error.h"

error::error(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("error");
    this->resize(150,100);
    label_err = new QLabel(this);
    label_err->setText(QString::fromLocal8Bit("��������"));
    label_err->setAlignment(Qt::AlignCenter); // �����ı����ж���
}
