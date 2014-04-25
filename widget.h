#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include <QTimer>
#include "molecula.h"
#include <QGraphicsScene>
#include <QObject>
#include <math.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    void start();
    void stop();


    const double k=1.3806488*pow(10,-23);
    const double m= 6.64*pow(10,-27);


    QTimer *timer;
    QVector<molecula*> vec;
    QGraphicsScene *scene;
private slots:
    void check_button();
    void reset();
    void calc();
};

#endif // WIDGET_H
