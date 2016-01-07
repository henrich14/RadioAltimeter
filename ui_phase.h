/********************************************************************************
** Form generated from reading UI file 'phase.ui'
**
** Created: Thu 19. Sep 10:42:31 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHASE_H
#define UI_PHASE_H

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
#include "qwt_polar_plot.h"

QT_BEGIN_NAMESPACE

class Ui_Phase
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
    QwtPolarPlot *qwtPolarPlot;

    void setupUi(QWidget *Phase)
    {
        if (Phase->objectName().isEmpty())
            Phase->setObjectName(QString::fromUtf8("Phase"));
        Phase->resize(662, 513);
        horizontalLayout_5 = new QHBoxLayout(Phase);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Phase);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        fmLineEdit = new QLineEdit(Phase);
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
        label_2 = new QLabel(Phase);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        f0LineEdit = new QLineEdit(Phase);
        f0LineEdit->setObjectName(QString::fromUtf8("f0LineEdit"));
        sizePolicy.setHeightForWidth(f0LineEdit->sizePolicy().hasHeightForWidth());
        f0LineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(f0LineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(Phase);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        df0LineEdit = new QLineEdit(Phase);
        df0LineEdit->setObjectName(QString::fromUtf8("df0LineEdit"));
        sizePolicy.setHeightForWidth(df0LineEdit->sizePolicy().hasHeightForWidth());
        df0LineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(df0LineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(Phase);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        HdoubleSpinBox = new QDoubleSpinBox(Phase);
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

        execute = new QPushButton(Phase);
        execute->setObjectName(QString::fromUtf8("execute"));

        verticalLayout->addWidget(execute);


        horizontalLayout_5->addLayout(verticalLayout);

        qwtPolarPlot = new QwtPolarPlot(Phase);
        qwtPolarPlot->setObjectName(QString::fromUtf8("qwtPolarPlot"));

        horizontalLayout_5->addWidget(qwtPolarPlot);


        retranslateUi(Phase);

        QMetaObject::connectSlotsByName(Phase);
    } // setupUi

    void retranslateUi(QWidget *Phase)
    {
        Phase->setWindowTitle(QApplication::translate("Phase", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Phase", "fm:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Phase", "f0:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Phase", "df0:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Phase", "H:", 0, QApplication::UnicodeUTF8));
        execute->setText(QApplication::translate("Phase", "Execute", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Phase: public Ui_Phase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHASE_H
