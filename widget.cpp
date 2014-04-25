#include "widget.h"
#include "ui_widget.h"
#include <time.h>
#include <stdlib.h>
#include <graph_widget.h>

#define FRAME_RATE 60

const int max = 4*FRAME_RATE;
const int min_x = 2*FRAME_RATE;
const int min_y = 1.5*FRAME_RATE;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //Устанавливаем ui и инициализируем окружение
    ui->setupUi(this);
    scene = new QGraphicsScene(QRect(10, 10, 331, 271),ui->graphicsView);
    timer = new QTimer();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    srand(time(NULL));
    timer->setInterval(1000/FRAME_RATE);
    qwt_install(ui->qwtwidg);

   //соединяем кнопки с функциями
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(check_button()));
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(calc()));
    QObject::connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(reset()));
    QObject::connect(ui->pushButton_2,SIGNAL(clicked()),scene,SLOT(update()));

}

Widget::~Widget()
{
    delete scene;
    delete timer;
    //delete d_plot;
    //delete curve;
    delete ui;
}

void Widget::start()
{
    if(vec.isEmpty())
    {
     QColor *col;
     for(int i=0; i<100;i++)
     {
       int speedx=min_x+rand()%(max-min_y);
       int speedy=min_y+rand()%(max-min_y);
         if(speedx%2)
           speedx*=-1;
         if(speedy%2)
            speedy*=-1;
         if(rand()%2)
             col = new QColor(Qt::black);
         else
             col = new QColor(Qt::red);

         molecula *dot = new molecula(rand()%331-3,rand()%271-3,*col,speedx,speedy);

         vec.push_back(dot);
         QObject::connect(timer,SIGNAL(timeout()),vec.back(),SLOT(changePos()));
         scene->addItem(vec.back());
         delete(col);
     }
         timer->start();

    }
    else
    {
        draw_graph(ui->spinBox->value(),m);
        timer->start();
    }

}
void Widget::stop()
{
    timer->stop();
}
void Widget::check_button()
{
    if(ui->pushButton->text()=="Старт")
    {
        ui->pushButton->setText("Cтоп");
        start();
    }
    else
     {
        ui->pushButton->setText("Старт");
        stop();
     }
}
void Widget::reset()
{
    if(ui->pushButton->text()!="Стоп")
        ui->pushButton->setText("Старт");
    scene->clear();
    timer->stop();
    vec.clear();
}
void Widget::calc()
{
    double Vver=sqrt(2*k*ui->spinBox->value()/m);
     ui->label_11->setText(QString::number(Vver));

     double Vkv = sqrt(3*k*ui->spinBox->value()/m);
     ui->label_10->setText(QString::number(Vkv));

}

