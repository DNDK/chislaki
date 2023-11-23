#include <iostream>
#include <cmath>
#include "approximation.h"
#include <fstream>
#include "qcustomplot.h"
#include <QApplication>
#include <QPushButton>
#include <QPen>
#include <Qt>
#include <QBrush>
#include <QVector>


#define WINDOW_W 800
#define WINDOW_H 600

using namespace std;

int main(int argc, char **argv){
    ifstream datafile = ifstream("data.txt");
    int n;
    datafile >> n;
    double* X = new double[n];
    for(int i = 0; i < n; i++){
        datafile >> X[i];
    }

    double* Y = new double[n];
    for(int i = 0; i < n; i++){
        datafile >> Y[i];
    }

    double* coeffs = approx_wrapped(X, Y, n);

    // for(int i = 0; i < 2; i++){
    //     //cout << coeffs[i] << " ";
    // }   

    double a = exp(coeffs[0]);
    double b = coeffs[1];

    cout << a << " " << b << endl;

    QApplication app(argc, argv);
    
    QCustomPlot* customPlot = new QCustomPlot();
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(Qt::blue));
    customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    
    QVector<double> x(61), y(61);

    for(int i = 0; i < 61; i++){
        x[i] = i;
        y[i] = a*exp(-b*x[i]);
    }

    customPlot->xAxis2->setVisible(true);
    customPlot->xAxis2->setTickLabels(false);
    customPlot->yAxis2->setVisible(true);
    customPlot->yAxis2->setTickLabels(false);

    customPlot->graph(0)->setData(x, y);
    customPlot->graph(0)->rescaleAxes();
    
    customPlot->resize(WINDOW_W, WINDOW_H);

    customPlot->show();
    delete[] X;
    delete[] Y;
    delete[] coeffs;
    return app.exec();
}