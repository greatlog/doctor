#ifndef BOOMCIRCUITDIALOG_H
#define BOOMCIRCUITDIALOG_H

#include <QDialog>
#include "qcustomplot.h"
#include "qcustomlabel.h"
//#include "faultdiagnosis.h"
#include "clientthread.h"
#include <diagnosis.h>
#include <QVector>
#include <string>
#include "setsensor.h"

#define press_scale 60.0/10.0
#define angle_scale 90.0/5.0

using namespace std;

namespace Ui {
class BoomCircuitDialog;
}

class BoomCircuitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BoomCircuitDialog(QWidget *parent = 0);
    ~BoomCircuitDialog();

    void addGraph(QCustomPlot *customPlot,QString title);
    void setPlot(QCustomPlot *customPlot);
    void setRealtimePlot(QCustomPlot *customPlot);
    void setCustomGraph(QCPGraph *graph);

private slots:
    void getRealtimeData(QString/*char buf2[]*//*int*/);//+
    void updataPlot();//+
    void onRunStopChanged(int run);
    void onUpdatePeriod(QString);

    void on_btnRunBoom_clicked();

    void on_btnHistoryBoom_clicked(/*QDate date*/);

    void displaySensor1(bool);
    void displaySensor2(bool);
    void displaySensor3(bool);
    void displaySensor4(bool);
    void displaySensor5(bool);
    void displaySensor6(bool);
    void displaySensor7(bool);
    void displaySensor8(bool);
    void displaySensor9(bool);
    void displaySensor10(bool);

    void showHistory(QModelIndex index);
    void loopMovie();
    void switchPage(int index);
    void setPlotRange1(int);
    void setPlotRange2(int);
    void setPlotRange3(int);

    void on_btnEvalBoom_clicked();

protected:
//    void mousePressEvent(QMouseEvent *event);

private:
    Ui::BoomCircuitDialog *ui;
    QTimer *dateTimer;
    QVector<double> time_stramp;
    QVector<double> PumpPressure;
    QVector<double> CylinderPressureA;
    QVector<double> CylinderPressureB;
    QVector<double> CylinderAx;
    QVector<double> CylinderAy;
    QVector<double> CylinderAx1;
    QVector<double> CylinderAy1;
    QVector<double> CylinderAx2;
    QVector<double> CylinderAy2;
    QVector<double> ControlVoltage;
    QVector<double> CylinderDisp;
    QVector<double> LeakFlow;

    Diagnosis faultDetector;
    ClientThread *clientThread;
    QThread *fileThread;
    QCalendarWidget *calendar;
    QMovie *movie;
    // 传感器数据绘图区
    SetSensor *sensor1=new SetSensor(this);
    SetSensor *sensor2=new SetSensor(this);
    SetSensor *sensor3=new SetSensor(this);
    SetSensor *sensor4=new SetSensor(this);
    SetSensor *sensor5=new SetSensor(this);
    SetSensor *sensor6=new SetSensor(this);
    SetSensor *sensor7=new SetSensor(this);
    SetSensor *sensor8=new SetSensor(this);
    SetSensor *sensor9=new SetSensor(this);
    SetSensor *sensor10=new SetSensor(this);

    QCustomPlot *figure1;
    QCustomPlot *figure2;
    QCustomPlot *figure3;
    QCustomPlot *figure4;
    QCustomPlot *figure5;
    QCustomPlot *figure6;
    QCustomPlot *figure7;
    QCustomPlot *figure8;
    QCustomPlot *figure9;
    QCustomPlot *figure10;
    QListWidgetItem *figureItem1;// 无杆腔压力P1绘图
    QListWidgetItem *figureItem2;// 有杆腔压力P2绘图
    QListWidgetItem *figureItem3;// 液压缸位移x绘图
    QListWidgetItem *figureItem4;// X轴倾角绘图(动臂)
    QListWidgetItem *figureItem5;// Y轴倾角绘图(动臂)
    QListWidgetItem *figureItem6;// 流量绘图
    QListWidgetItem *figureItem7;// X轴倾角绘图(斗杆)
    QListWidgetItem *figureItem8;// Y轴倾角绘图(斗杆)
    QListWidgetItem *figureItem9;// X轴倾角绘图(铲斗)
    QListWidgetItem *figureItem10;// Y轴倾角绘图(铲斗)

private slots:
    void on_P1Boom_clicked();
    void on_P2Boom_clicked();
};

#endif // BOOMCIRCUITDIALOG_H
