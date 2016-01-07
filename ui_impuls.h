/********************************************************************************
** Form generated from reading UI file 'impuls.ui'
**
** Created: Fri 8. Nov 13:13:59 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPULS_H
#define UI_IMPULS_H

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

class Ui_Impuls
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
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
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *impulsesForH;
    QPushButton *execute;
    QSpacerItem *horizontalSpacer;
    QwtPlot *qwtPlot_2;
    QwtPlot *qwtPlot;

    void setupUi(QWidget *Impuls)
    {
        if (Impuls->objectName().isEmpty())
            Impuls->setObjectName(QString::fromUtf8("Impuls"));
        Impuls->resize(745, 502);
        verticalLayout_2 = new QVBoxLayout(Impuls);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Impuls);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        fmLineEdit = new QLineEdit(Impuls);
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
        label_2 = new QLabel(Impuls);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        f0LineEdit = new QLineEdit(Impuls);
        f0LineEdit->setObjectName(QString::fromUtf8("f0LineEdit"));
        sizePolicy.setHeightForWidth(f0LineEdit->sizePolicy().hasHeightForWidth());
        f0LineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(f0LineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(Impuls);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        df0LineEdit = new QLineEdit(Impuls);
        df0LineEdit->setObjectName(QString::fromUtf8("df0LineEdit"));
        sizePolicy.setHeightForWidth(df0LineEdit->sizePolicy().hasHeightForWidth());
        df0LineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(df0LineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(Impuls);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        HdoubleSpinBox = new QDoubleSpinBox(Impuls);
        HdoubleSpinBox->setObjectName(QString::fromUtf8("HdoubleSpinBox"));
        sizePolicy.setHeightForWidth(HdoubleSpinBox->sizePolicy().hasHeightForWidth());
        HdoubleSpinBox->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(HdoubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(Impuls);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        impulsesForH = new QLineEdit(Impuls);
        impulsesForH->setObjectName(QString::fromUtf8("impulsesForH"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(5);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(impulsesForH->sizePolicy().hasHeightForWidth());
        impulsesForH->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(impulsesForH);


        verticalLayout->addLayout(horizontalLayout_5);

        execute = new QPushButton(Impuls);
        execute->setObjectName(QString::fromUtf8("execute"));

        verticalLayout->addWidget(execute);


        horizontalLayout_6->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_6);

        qwtPlot_2 = new QwtPlot(Impuls);
        qwtPlot_2->setObjectName(QString::fromUtf8("qwtPlot_2"));

        verticalLayout_2->addWidget(qwtPlot_2);

        qwtPlot = new QwtPlot(Impuls);
        qwtPlot->setObjectName(QString::fromUtf8("qwtPlot"));

        verticalLayout_2->addWidget(qwtPlot);


        retranslateUi(Impuls);

        QMetaObject::connectSlotsByName(Impuls);
    } // setupUi

    void retranslateUi(QWidget *Impuls)
    {
        Impuls->setWindowTitle(QApplication::translate("Impuls", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Impuls", "fm:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Impuls", "f0:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Impuls", "df0:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Impuls", "H:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Impuls", "Num of impulses for H:", 0, QApplication::UnicodeUTF8));
        execute->setText(QApplication::translate("Impuls", "Execute", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Impuls: public Ui_Impuls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPULS_H
