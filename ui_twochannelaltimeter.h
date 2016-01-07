/********************************************************************************
** Form generated from reading UI file 'twochannelaltimeter.ui'
**
** Created: Thu 3. Oct 10:40:34 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWOCHANNELALTIMETER_H
#define UI_TWOCHANNELALTIMETER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_TwoChannelAltimeter
{
public:
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *fmLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *f0LineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *df0LineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QDoubleSpinBox *HdoubleSpinBox;
    QSpacerItem *verticalSpacer;
    QPushButton *execute;
    QVBoxLayout *verticalLayout_2;
    QwtPlot *qwtPlot;
    QwtPlot *qwtPlot_2;
    QwtPlot *qwtPlot_3;

    void setupUi(QWidget *TwoChannelAltimeter)
    {
        if (TwoChannelAltimeter->objectName().isEmpty())
            TwoChannelAltimeter->setObjectName(QString::fromUtf8("TwoChannelAltimeter"));
        TwoChannelAltimeter->resize(746, 524);
        horizontalLayout_5 = new QHBoxLayout(TwoChannelAltimeter);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(TwoChannelAltimeter);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        fmLineEdit = new QLineEdit(TwoChannelAltimeter);
        fmLineEdit->setObjectName(QString::fromUtf8("fmLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fmLineEdit->sizePolicy().hasHeightForWidth());
        fmLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(fmLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(TwoChannelAltimeter);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        f0LineEdit = new QLineEdit(TwoChannelAltimeter);
        f0LineEdit->setObjectName(QString::fromUtf8("f0LineEdit"));
        sizePolicy.setHeightForWidth(f0LineEdit->sizePolicy().hasHeightForWidth());
        f0LineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(f0LineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(TwoChannelAltimeter);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        df0LineEdit = new QLineEdit(TwoChannelAltimeter);
        df0LineEdit->setObjectName(QString::fromUtf8("df0LineEdit"));
        sizePolicy.setHeightForWidth(df0LineEdit->sizePolicy().hasHeightForWidth());
        df0LineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(df0LineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(TwoChannelAltimeter);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        HdoubleSpinBox = new QDoubleSpinBox(TwoChannelAltimeter);
        HdoubleSpinBox->setObjectName(QString::fromUtf8("HdoubleSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(HdoubleSpinBox->sizePolicy().hasHeightForWidth());
        HdoubleSpinBox->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(HdoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        execute = new QPushButton(TwoChannelAltimeter);
        execute->setObjectName(QString::fromUtf8("execute"));

        verticalLayout->addWidget(execute);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        qwtPlot = new QwtPlot(TwoChannelAltimeter);
        qwtPlot->setObjectName(QString::fromUtf8("qwtPlot"));

        verticalLayout_2->addWidget(qwtPlot);

        qwtPlot_2 = new QwtPlot(TwoChannelAltimeter);
        qwtPlot_2->setObjectName(QString::fromUtf8("qwtPlot_2"));

        verticalLayout_2->addWidget(qwtPlot_2);

        qwtPlot_3 = new QwtPlot(TwoChannelAltimeter);
        qwtPlot_3->setObjectName(QString::fromUtf8("qwtPlot_3"));

        verticalLayout_2->addWidget(qwtPlot_3);


        horizontalLayout_5->addLayout(verticalLayout_2);


        retranslateUi(TwoChannelAltimeter);

        QMetaObject::connectSlotsByName(TwoChannelAltimeter);
    } // setupUi

    void retranslateUi(QWidget *TwoChannelAltimeter)
    {
        TwoChannelAltimeter->setWindowTitle(QApplication::translate("TwoChannelAltimeter", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TwoChannelAltimeter", "fm:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TwoChannelAltimeter", "f0:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TwoChannelAltimeter", "df0:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TwoChannelAltimeter", "H:", 0, QApplication::UnicodeUTF8));
        execute->setText(QApplication::translate("TwoChannelAltimeter", "Execute", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TwoChannelAltimeter: public Ui_TwoChannelAltimeter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWOCHANNELALTIMETER_H
