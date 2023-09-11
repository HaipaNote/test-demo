#ifndef ERROR_H
#define ERROR_H

#include <QMainWindow>
#include <QLabel>
class error : public QMainWindow
{
    Q_OBJECT
public:
    explicit error(QWidget *parent = nullptr);
    QLabel* label_err ;
signals:

public slots:
};

#endif // ERROR_H
