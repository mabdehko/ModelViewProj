#ifndef DIALOGPLOT_H
#define DIALOGPLOT_H

#include <QDialog>
#include <QStandardItemModel>
#include <QAbstractItemView>
#include <QModelIndex>

namespace Ui {
class DialogPlot;
}

class DialogPlot : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPlot(QWidget *parent = 0);
    ~DialogPlot();

    void setModel(QStandardItemModel *mdl);
    void generatePlot();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogPlot *ui;
    QStandardItemModel *model;

};

#endif // DIALOGPLOT_H
