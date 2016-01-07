/********************************************************************************
** Form generated from reading UI file 'doppler.ui'
**
** Created: Wed 13. Nov 16:28:27 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOPPLER_H
#define UI_DOPPLER_H

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

class Ui_Doppler
{
public:
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *fmLineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *f0LineEdit;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *df0LineEdit;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QDoubleSpinBox *HdoubleSpinBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *VlineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *NoI1_lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *NoI2_lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *NoI3_lineEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QLineEdit *NoI4_lineEdit;
    QSpacerItem *verticalSpacer_2;
    QPushButton *execute;
    QVBoxLayout *verticalLayout_5;
    QwtPlot *qwtPlot;
    QwtPlot *qwtPlot_2;
    QwtPlot *qwtPlot_3;
    QwtPlot *qwtPlot_4;

    void setupUi(QWidget *Doppler)
    {
        if (Doppler->objectName().isEmpty())
            Doppler->setObjectName(QString::fromUtf8("Doppler"));
        Doppler->resize(826, 526);
        horizontalLayout_10 = new QHBoxLayout(Doppler);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(Doppler);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        fmLineEdit = new QLineEdit(Doppler);
        fmLineEdit->setObjectName(QString::fromUtf8("fmLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fmLineEdit->sizePolicy().hasHeightForWidth());
        fmLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(fmLineEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_6 = new QLabel(Doppler);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_6->addWidget(label_6);

        f0LineEdit = new QLineEdit(Doppler);
        f0LineEdit->setObjectName(QString::fromUtf8("f0LineEdit"));
        sizePolicy.setHeightForWidth(f0LineEdit->sizePolicy().hasHeightForWidth());
        f0LineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(f0LineEdit);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(Doppler);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        df0LineEdit = new QLineEdit(Doppler);
        df0LineEdit->setObjectName(QString::fromUtf8("df0LineEdit"));
        sizePolicy.setHeightForWidth(df0LineEdit->sizePolicy().hasHeightForWidth());
        df0LineEdit->setSizePolicy(sizePolicy);
        df0LineEdit->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_7->addWidget(df0LineEdit);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_8 = new QLabel(Doppler);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_8->addWidget(label_8);

        HdoubleSpinBox = new QDoubleSpinBox(Doppler);
        HdoubleSpinBox->setObjectName(QString::fromUtf8("HdoubleSpinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(HdoubleSpinBox->sizePolicy().hasHeightForWidth());
        HdoubleSpinBox->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(HdoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Doppler);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        VlineEdit = new QLineEdit(Doppler);
        VlineEdit->setObjectName(QString::fromUtf8("VlineEdit"));
        sizePolicy.setHeightForWidth(VlineEdit->sizePolicy().hasHeightForWidth());
        VlineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(VlineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Doppler);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        NoI1_lineEdit = new QLineEdit(Doppler);
        NoI1_lineEdit->setObjectName(QString::fromUtf8("NoI1_lineEdit"));
        sizePolicy.setHeightForWidth(NoI1_lineEdit->sizePolicy().hasHeightForWidth());
        NoI1_lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(NoI1_lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(Doppler);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        NoI2_lineEdit = new QLineEdit(Doppler);
        NoI2_lineEdit->setObjectName(QString::fromUtf8("NoI2_lineEdit"));
        sizePolicy.setHeightForWidth(NoI2_lineEdit->sizePolicy().hasHeightForWidth());
        NoI2_lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(NoI2_lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(Doppler);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        NoI3_lineEdit = new QLineEdit(Doppler);
        NoI3_lineEdit->setObjectName(QString::fromUtf8("NoI3_lineEdit"));
        sizePolicy.setHeightForWidth(NoI3_lineEdit->sizePolicy().hasHeightForWidth());
        NoI3_lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(NoI3_lineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_9 = new QLabel(Doppler);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_9->addWidget(label_9);

        NoI4_lineEdit = new QLineEdit(Doppler);
        NoI4_lineEdit->setObjectName(QString::fromUtf8("NoI4_lineEdit"));
        sizePolicy.setHeightForWidth(NoI4_lineEdit->sizePolicy().hasHeightForWidth());
        NoI4_lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(NoI4_lineEdit);


        verticalLayout->addLayout(horizontalLayout_9);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        execute = new QPushButton(Doppler);
        execute->setObjectName(QString::fromUtf8("execute"));

        verticalLayout->addWidget(execute);


        horizontalLayout_10->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        qwtPlot = new QwtPlot(Doppler);
        qwtPlot->setObjectName(QString::fromUtf8("qwtPlot"));

        verticalLayout_5->addWidget(qwtPlot);

        qwtPlot_2 = new QwtPlot(Doppler);
        qwtPlot_2->setObjectName(QString::fromUtf8("qwtPlot_2"));

        verticalLayout_5->addWidget(qwtPlot_2);

        qwtPlot_3 = new QwtPlot(Doppler);
        qwtPlot_3->setObjectName(QString::fromUtf8("qwtPlot_3"));

        verticalLayout_5->addWidget(qwtPlot_3);

        qwtPlot_4 = new QwtPlot(Doppler);
        qwtPlot_4->setObjectName(QString::fromUtf8("qwtPlot_4"));

        verticalLayout_5->addWidget(qwtPlot_4);


        horizontalLayout_10->addLayout(verticalLayout_5);


        retranslateUi(Doppler);

        QMetaObject::connectSlotsByName(Doppler);
    } // setupUi

    void retranslateUi(QWidget *Doppler)
    {
        Doppler->setWindowTitle(QApplication::translate("Doppler", "Form", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Doppler", "fm:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Doppler", "f0:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Doppler", "df0:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Doppler", "H:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Doppler", "V:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Doppler", "Num Of Imp1:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Doppler", "Num Of Imp2:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Doppler", "Num Of Imp3:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Doppler", "Num Of Imp4:", 0, QApplication::UnicodeUTF8));
        execute->setText(QApplication::translate("Doppler", "Execute", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Doppler: public Ui_Doppler {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOPPLER_H
