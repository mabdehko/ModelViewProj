/********************************************************************************
** Form generated from reading UI file 'dialogplot.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPLOT_H
#define UI_DIALOGPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_DialogPlot
{
public:
    QCustomPlot *plot;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogPlot)
    {
        if (DialogPlot->objectName().isEmpty())
            DialogPlot->setObjectName(QStringLiteral("DialogPlot"));
        DialogPlot->resize(652, 437);
        plot = new QCustomPlot(DialogPlot);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setGeometry(QRect(20, 20, 611, 371));
        pushButton = new QPushButton(DialogPlot);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(500, 400, 131, 28));

        retranslateUi(DialogPlot);

        QMetaObject::connectSlotsByName(DialogPlot);
    } // setupUi

    void retranslateUi(QDialog *DialogPlot)
    {
        DialogPlot->setWindowTitle(QApplication::translate("DialogPlot", "Dialog", 0));
        pushButton->setText(QApplication::translate("DialogPlot", "Save in PNG Format", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogPlot: public Ui_DialogPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPLOT_H
