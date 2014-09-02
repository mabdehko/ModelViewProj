#include "dialogplot.h"
#include "ui_dialogplot.h"
#include <QtWidgets>
#include <QDesktopServices>

DialogPlot::DialogPlot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPlot)
{
    ui->setupUi(this);
    //model = new QStandardItemModel();
}

DialogPlot::~DialogPlot()
{
    delete ui;
}

void  DialogPlot::setModel(QStandardItemModel *mdl){
    this->model = mdl;
}

void DialogPlot::generatePlot(){
    int size = model->rowCount();

    QVector<double> x(size), y(size);

    double minx = 0;
    double maxx = 0;
    double miny = 0;
    double maxy = 0;

    for (int row = 1; row < model->rowCount(); ++row) {

        QModelIndex sliceIndex = model->index(row,0);
        double valuex = model->data(sliceIndex).toDouble();
        sliceIndex = model->index(row,1);
        double valuey = model->data(sliceIndex).toDouble();
        x[row-1] = valuex;
        if(valuex < minx){minx = valuex;}
        if(valuex > maxx){maxx = valuex;}
        y[row-1] = valuey;
        if(valuey < miny){miny = valuey;}
        if(valuey > maxy){maxy = valuey;}
    }

    ui->plot->plotLayout()->insertRow(0); // inserts an empty row above the default axis rect
    ui->plot->plotLayout()->addElement(0, 0, new QCPPlotTitle(ui->plot, "Energy Levels (keV) vs. Count"));
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x,y);
    ui->plot->xAxis->setRange(minx,maxx);
    ui->plot->yAxis->setRange(miny,maxy);
}

void DialogPlot::on_pushButton_clicked()
{
    //ui->plot->savePdf("plotEnergy.pdf");
    //ui->plot->savePdf("Energy.pdf",true,0,0,"minesense","Energy Plot");
    ui->plot->savePng("plotEnergy.png",0,0,1,-1);
    QDesktopServices::openUrl(QUrl("plotEnergy.png", QUrl::TolerantMode));
}
