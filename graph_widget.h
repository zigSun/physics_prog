#ifndef GRAPH_WIDGET_H
#define GRAPH_WIDGET_H

#include <qwt_plot.h>
#include <qwt_plot_grid.h>
#include <math.h>
#include <qwt_legend.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_picker.h>
#include <qwt_picker_machine.h>

QwtPlot *d_plot;
QwtPlotCurve *curve;
int t;
double m;
const double k=1.3806488*pow(10,-23);

double func(int v)
{
    static double A = (4*M_PI)*pow(m/(2*M_PI*k*t),1.5);
    double res = A * pow(M_E,(-1*m*pow(v,2)/(2*k*t)))*pow(v,2);
    return res;
}

void qwt_install(QWidget *place)
{
   //Устанавливаем виджет площади графика
    d_plot = new QwtPlot(place);
    d_plot->setGeometry(QRect(0,0,place->size().width(),place->size().height()));
    d_plot->setCanvasBackground( Qt::white ); // цвет фона
    // Параметры осей координат
    d_plot->insertLegend( new QwtLegend() );
    d_plot->setAxisScale(QwtPlot::yLeft,0,150,15);
    d_plot->setAxisScale(QwtPlot::xBottom,0,4000,1000);
    //устанавливаем сетку
    QwtPlotGrid *grid = new QwtPlotGrid(); //
    grid->setMajorPen(QPen( Qt::gray, 1 )); // цвет линий и толщина
    grid->attach( d_plot );
    //Определяем кривую графика
    curve = new QwtPlotCurve();
    curve->setPen( Qt::blue, 2 ); // цвет и толщина кривой
    curve->setRenderHint( QwtPlotItem::RenderAntialiased, true ); // сглаживание
}

void draw_graph(int T,double M)
{

    QPolygonF points;
    t=T;
    m=M;
    for(int v=0;v<4000;v++)
    {
        points << QPointF(v,func(v));
    }
    curve->setSamples(points);
    curve->attach(d_plot);
}


#endif // GRAPH_WIDGET_H
