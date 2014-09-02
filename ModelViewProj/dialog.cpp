#include "dialog.h"
#include "ui_dialog.h"
#include "dialogplot.h"
#include <QtCore>
#include <QTGui>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    ui->tableView->setModel(model);


    QFile file(":/CSVFiles/mvcdata.csv");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        while (!file.atEnd()){
            QString line = file.readLine();
            QStringList strings = line.split(",");

            QStandardItem *item = new QStandardItem(strings.value(0));
            standardItemList.append(item);
            QStandardItem *item2 = new QStandardItem(strings.value(1));
            standardItemList.append(item2);
            model->appendRow(standardItemList);
            standardItemList.clear();
            strings.clear();

            /*
            QModelIndex tempQRecord = model->indexFromItem()
          new QRecord();
            tempQRecord.setValue("City",strings.value(1));
            tempQRecord.setValue("Region",strings.value(2));
            model->insertRecord(-1,tempQRecord);
            */
        }
        file.close();
    }

    //DialogPlot dialogplot;

    //dialogplot.setModal(true);
   // dialogplot.setModal(model);

      /*for(int row = 0; row < 4; ++row){
        for(int col = 0; col <2; ++col){
            QModelIndex index = model->index(row,col, QModelIndex());
            model->setData(index,0);

        }
    }*/


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    //Add
    int row = model->rowCount();
    model->insertRows(row,1);

    QModelIndex index = model->index(row,0,QModelIndex());

    ui->tableView->setCurrentIndex(index);
    ui->tableView->edit(index);
}


void Dialog::on_pushButton_2_clicked()
{
    //Delete
    int row = ui->tableView->currentIndex().row();
    if(row!=0){
        model->removeRow(row);
    }
        // model->removeRows(ui->tableView()->currentIndex().row(),1,QModelIndex());
}

void Dialog::on_pushButton_3_clicked()
{
    //Insert
    int row = ui->tableView->currentIndex().row();
    if(row!=0){
        model->insertRows(row,1);
        QModelIndex index = model->index(row,0, QModelIndex());

         ui->tableView->setCurrentIndex(index);
            ui->tableView->edit(index);
    }

}

void Dialog::on_pushButton_4_clicked()
{
    //Plot
    DialogPlot dialogplot;

    dialogplot.setModal(true);
    dialogplot.setModel(model);
    dialogplot.generatePlot();

    //dialogplot.setModal(model);
    dialogplot.exec();

}

void Dialog::on_pushButton_5_clicked()
{
   //save

    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save file as"), "", "*.csv")+".csv";

    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text))
        return;

    QTextStream stream(&file);

        QStringList pieces;




     for (int row = 0; row < model->rowCount(QModelIndex()); ++row) {
       QStringList pieces;

       pieces.append(model->data(model->index(row, 0, QModelIndex()),
                                 Qt::DisplayRole).toString().simplified());
       pieces.append(model->data(model->index(row, 1, QModelIndex()),
                                 Qt::DisplayRole).toString().simplified());

       stream << pieces.join(',') << "\n";//<< "\n";
    }

    file.close();
    QMessageBox::information(this,"Saved","Saved!");
}

void Dialog::on_pushButton_6_clicked()
{
    //load

    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose a data file"), "", "*.csv");


    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
        return;

    QTextStream stream(&file);
    QString line;

    model->removeRows(0, model->rowCount(QModelIndex()), QModelIndex());

    int row = 0;
    do {
        line = stream.readLine();
        if (!line.isEmpty()) {
            model->insertRows(row, 1, QModelIndex());

            QStringList pieces = line.split(",", QString::SkipEmptyParts);
            model->setData(model->index(row, 0, QModelIndex()),
                           pieces.value(0));
            model->setData(model->index(row, 1, QModelIndex()),
                           pieces.value(1));
            row++;
        }
    } while (!line.isEmpty());

    file.close();
    QMessageBox::information(this,"Loaded","Data Load Complete!");


}
