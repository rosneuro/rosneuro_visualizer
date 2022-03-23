/********************************************************************************
** Form generated from reading UI file 'neuroviz_timescopeoTDMqH.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef NEUROVIZ_TIMESCOPEOTDMQH_H
#define NEUROVIZ_TIMESCOPEOTDMQH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "rosneuro_visualizer/TemporalPlot.hpp"

QT_BEGIN_NAMESPACE

class Ui_TimeScope
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QComboBox *ScaleValue;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *LowPassCheck;
    QDoubleSpinBox *LowPassValue;
    QCheckBox *HighPassCheck;
    QDoubleSpinBox *HighPassValue;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QComboBox *ReferenceValue;
    QComboBox *ReferenceOpt;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout;
    QComboBox *TimeWindowValue;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QListWidget *ChannelsList;
    TemporalPlot *eegScope;

    void setupUi(QWidget *TimeScope)
    {
        if (TimeScope->objectName().isEmpty())
            TimeScope->setObjectName(QString::fromUtf8("TimeScope"));
        TimeScope->resize(1019, 884);
        gridLayout = new QGridLayout(TimeScope);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(-1, -1, 0, -1);
        groupBox = new QGroupBox(TimeScope);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMaximumSize(QSize(115, 69));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        ScaleValue = new QComboBox(groupBox);
        ScaleValue->addItem(QString());
        ScaleValue->addItem(QString());
        ScaleValue->addItem(QString());
        ScaleValue->addItem(QString());
        ScaleValue->addItem(QString());
        ScaleValue->addItem(QString());
        ScaleValue->addItem(QString());
        ScaleValue->addItem(QString());
        ScaleValue->addItem(QString());
        ScaleValue->addItem(QString());
        ScaleValue->addItem(QString());
        ScaleValue->addItem(QString());
        ScaleValue->addItem(QString());
        ScaleValue->addItem(QString());
        ScaleValue->addItem(QString());
        ScaleValue->setObjectName(QString::fromUtf8("ScaleValue"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ScaleValue->sizePolicy().hasHeightForWidth());
        ScaleValue->setSizePolicy(sizePolicy1);
        ScaleValue->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        verticalLayout_3->addWidget(ScaleValue);


        verticalLayout_10->addWidget(groupBox);

        groupBox_2 = new QGroupBox(TimeScope);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        LowPassCheck = new QCheckBox(groupBox_2);
        LowPassCheck->setObjectName(QString::fromUtf8("LowPassCheck"));

        verticalLayout_4->addWidget(LowPassCheck);

        LowPassValue = new QDoubleSpinBox(groupBox_2);
        LowPassValue->setObjectName(QString::fromUtf8("LowPassValue"));
        LowPassValue->setMaximum(4096.000000000000000);
        LowPassValue->setValue(100.000000000000000);

        verticalLayout_4->addWidget(LowPassValue);

        HighPassCheck = new QCheckBox(groupBox_2);
        HighPassCheck->setObjectName(QString::fromUtf8("HighPassCheck"));

        verticalLayout_4->addWidget(HighPassCheck);

        HighPassValue = new QDoubleSpinBox(groupBox_2);
        HighPassValue->setObjectName(QString::fromUtf8("HighPassValue"));
        HighPassValue->setMaximum(4096.000000000000000);
        HighPassValue->setValue(1.000000000000000);

        verticalLayout_4->addWidget(HighPassValue);


        verticalLayout_10->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(TimeScope);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        ReferenceValue = new QComboBox(groupBox_3);
        ReferenceValue->addItem(QString());
        ReferenceValue->addItem(QString());
        ReferenceValue->addItem(QString());
        ReferenceValue->setObjectName(QString::fromUtf8("ReferenceValue"));
        ReferenceValue->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        verticalLayout_5->addWidget(ReferenceValue);

        ReferenceOpt = new QComboBox(groupBox_3);
        ReferenceOpt->setObjectName(QString::fromUtf8("ReferenceOpt"));
        ReferenceOpt->setEnabled(false);
        ReferenceOpt->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        verticalLayout_5->addWidget(ReferenceOpt);


        verticalLayout_10->addWidget(groupBox_3);

        groupBox_8 = new QGroupBox(TimeScope);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_8->sizePolicy().hasHeightForWidth());
        groupBox_8->setSizePolicy(sizePolicy2);
        groupBox_8->setMinimumSize(QSize(0, 69));
        groupBox_8->setMaximumSize(QSize(119, 16777215));
        verticalLayout = new QVBoxLayout(groupBox_8);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        TimeWindowValue = new QComboBox(groupBox_8);
        TimeWindowValue->addItem(QString());
        TimeWindowValue->addItem(QString());
        TimeWindowValue->addItem(QString());
        TimeWindowValue->addItem(QString());
        TimeWindowValue->addItem(QString());
        TimeWindowValue->addItem(QString());
        TimeWindowValue->setObjectName(QString::fromUtf8("TimeWindowValue"));
        TimeWindowValue->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        verticalLayout->addWidget(TimeWindowValue);


        verticalLayout_10->addWidget(groupBox_8);

        groupBox_4 = new QGroupBox(TimeScope);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy3);
        groupBox_4->setMinimumSize(QSize(0, 0));
        groupBox_4->setMaximumSize(QSize(119, 16777215));
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        ChannelsList = new QListWidget(groupBox_4);
        ChannelsList->setObjectName(QString::fromUtf8("ChannelsList"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(ChannelsList->sizePolicy().hasHeightForWidth());
        ChannelsList->setSizePolicy(sizePolicy4);
        ChannelsList->setMinimumSize(QSize(0, 20));
        ChannelsList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ChannelsList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        ChannelsList->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout_7->addWidget(ChannelsList);


        verticalLayout_10->addWidget(groupBox_4);


        horizontalLayout_2->addLayout(verticalLayout_10);

        eegScope = new TemporalPlot(TimeScope);
        eegScope->setObjectName(QString::fromUtf8("eegScope"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(eegScope->sizePolicy().hasHeightForWidth());
        eegScope->setSizePolicy(sizePolicy5);
        eegScope->setMinimumSize(QSize(0, 0));
        eegScope->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(eegScope);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        retranslateUi(TimeScope);

        ScaleValue->setCurrentIndex(6);
        TimeWindowValue->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(TimeScope);
    } // setupUi

    void retranslateUi(QWidget *TimeScope)
    {
        TimeScope->setWindowTitle(QApplication::translate("TimeScope", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("TimeScope", "Scale", nullptr));
        ScaleValue->setItemText(0, QApplication::translate("TimeScope", "1 uV", nullptr));
        ScaleValue->setItemText(1, QApplication::translate("TimeScope", "2.5 uV", nullptr));
        ScaleValue->setItemText(2, QApplication::translate("TimeScope", "5 uV", nullptr));
        ScaleValue->setItemText(3, QApplication::translate("TimeScope", "10 uV", nullptr));
        ScaleValue->setItemText(4, QApplication::translate("TimeScope", "25 uV", nullptr));
        ScaleValue->setItemText(5, QApplication::translate("TimeScope", "50 uV", nullptr));
        ScaleValue->setItemText(6, QApplication::translate("TimeScope", "100 uV", nullptr));
        ScaleValue->setItemText(7, QApplication::translate("TimeScope", "250 uV", nullptr));
        ScaleValue->setItemText(8, QApplication::translate("TimeScope", "500 uV", nullptr));
        ScaleValue->setItemText(9, QApplication::translate("TimeScope", "1 mV", nullptr));
        ScaleValue->setItemText(10, QApplication::translate("TimeScope", "2.5 mV", nullptr));
        ScaleValue->setItemText(11, QApplication::translate("TimeScope", "5 mV", nullptr));
        ScaleValue->setItemText(12, QApplication::translate("TimeScope", "10 mV", nullptr));
        ScaleValue->setItemText(13, QApplication::translate("TimeScope", "25 mV", nullptr));
        ScaleValue->setItemText(14, QApplication::translate("TimeScope", "50 mV", nullptr));

        groupBox_2->setTitle(QApplication::translate("TimeScope", "Filtering", nullptr));
        LowPassCheck->setText(QApplication::translate("TimeScope", "Low pass", nullptr));
        HighPassCheck->setText(QApplication::translate("TimeScope", "High pass", nullptr));
        groupBox_3->setTitle(QApplication::translate("TimeScope", "Reference", nullptr));
        ReferenceValue->setItemText(0, QApplication::translate("TimeScope", "None", nullptr));
        ReferenceValue->setItemText(1, QApplication::translate("TimeScope", "Average", nullptr));
        ReferenceValue->setItemText(2, QApplication::translate("TimeScope", "Electrode", nullptr));

        groupBox_8->setTitle(QApplication::translate("TimeScope", "Time window:", nullptr));
        TimeWindowValue->setItemText(0, QApplication::translate("TimeScope", "1 s", nullptr));
        TimeWindowValue->setItemText(1, QApplication::translate("TimeScope", "2 s", nullptr));
        TimeWindowValue->setItemText(2, QApplication::translate("TimeScope", "5 s", nullptr));
        TimeWindowValue->setItemText(3, QApplication::translate("TimeScope", "10 s", nullptr));
        TimeWindowValue->setItemText(4, QApplication::translate("TimeScope", "20 s", nullptr));
        TimeWindowValue->setItemText(5, QApplication::translate("TimeScope", "30 s", nullptr));

        groupBox_4->setTitle(QApplication::translate("TimeScope", "Electrodes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeScope: public Ui_TimeScope {};
} // namespace Ui

QT_END_NAMESPACE

#endif // NEUROVIZ_TIMESCOPEOTDMQH_H
