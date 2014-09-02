#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QStandardItemModel>
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

    public:
        explicit Dialog(QWidget *parent = 0);
        ~Dialog();

    private slots:
        void on_pushButton_clicked();

        void on_pushButton_2_clicked();

        void on_pushButton_3_clicked();

        void on_pushButton_4_clicked();

        //void checkString(QString &temp, QChar character = 0);

        void on_pushButton_5_clicked();

        void on_pushButton_6_clicked();

private:
        Ui::Dialog *ui;

        QList<QStringList> csv;
        QStandardItemModel *model;
        QList<QStandardItem*> standardItemList;

};

#endif // DIALOG_H
