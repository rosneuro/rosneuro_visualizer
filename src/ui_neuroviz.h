/********************************************************************************
** Form generated from reading UI file 'neurovizmwHXFt.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef NEUROVIZMWHXFT_H
#define NEUROVIZMWHXFT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NeuroVizPanel
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTabWidget *NeuroTab;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_3;
    QLineEdit *TopicValue;
    QLabel *label;
    QLabel *AcquisitionStatus;
    QPushButton *StopButton;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_4;
    QLabel *NativeRateLabel;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_6;
    QLabel *MessageSeqLabel;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_5;
    QLabel *MessageRateLabel;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout_2;
    QPushButton *InfoButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *NeuroVizPanel)
    {
        if (NeuroVizPanel->objectName().isEmpty())
            NeuroVizPanel->setObjectName(QString::fromUtf8("NeuroVizPanel"));
        NeuroVizPanel->resize(992, 864);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NeuroVizPanel->sizePolicy().hasHeightForWidth());
        NeuroVizPanel->setSizePolicy(sizePolicy);
        NeuroVizPanel->setMinimumSize(QSize(400, 600));
        NeuroVizPanel->setAutoFillBackground(false);
        NeuroVizPanel->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        NeuroVizPanel->setDocumentMode(false);
        centralwidget = new QWidget(NeuroVizPanel);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        NeuroTab = new QTabWidget(centralwidget);
        NeuroTab->setObjectName(QString::fromUtf8("NeuroTab"));
        NeuroTab->setEnabled(true);
        NeuroTab->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));

        verticalLayout->addWidget(NeuroTab);


        horizontalLayout->addLayout(verticalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 5, 0, 1, 1);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy1);
        groupBox_5->setMinimumSize(QSize(150, 118));
        groupBox_5->setMaximumSize(QSize(0, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        TopicValue = new QLineEdit(groupBox_5);
        TopicValue->setObjectName(QString::fromUtf8("TopicValue"));
        TopicValue->setFocusPolicy(Qt::StrongFocus);
        TopicValue->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout_3->addWidget(TopicValue, 0, 0, 1, 2);

        label = new QLabel(groupBox_5);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 1, 0, 1, 1);

        AcquisitionStatus = new QLabel(groupBox_5);
        AcquisitionStatus->setObjectName(QString::fromUtf8("AcquisitionStatus"));

        gridLayout_3->addWidget(AcquisitionStatus, 1, 1, 1, 1);

        StopButton = new QPushButton(groupBox_5);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));
        StopButton->setEnabled(false);
        sizePolicy.setHeightForWidth(StopButton->sizePolicy().hasHeightForWidth());
        StopButton->setSizePolicy(sizePolicy);
        StopButton->setCheckable(false);
        StopButton->setChecked(false);

        gridLayout_3->addWidget(StopButton, 2, 0, 1, 2);


        gridLayout_2->addWidget(groupBox_5, 0, 0, 1, 1);

        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy2);
        groupBox_6->setMaximumSize(QSize(16777215, 60));
        gridLayout_4 = new QGridLayout(groupBox_6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        NativeRateLabel = new QLabel(groupBox_6);
        NativeRateLabel->setObjectName(QString::fromUtf8("NativeRateLabel"));
        NativeRateLabel->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(NativeRateLabel, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_6, 1, 0, 1, 1);

        groupBox_9 = new QGroupBox(centralwidget);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        sizePolicy2.setHeightForWidth(groupBox_9->sizePolicy().hasHeightForWidth());
        groupBox_9->setSizePolicy(sizePolicy2);
        groupBox_9->setMaximumSize(QSize(16777215, 60));
        gridLayout_6 = new QGridLayout(groupBox_9);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        MessageSeqLabel = new QLabel(groupBox_9);
        MessageSeqLabel->setObjectName(QString::fromUtf8("MessageSeqLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(MessageSeqLabel->sizePolicy().hasHeightForWidth());
        MessageSeqLabel->setSizePolicy(sizePolicy3);
        MessageSeqLabel->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(MessageSeqLabel, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_9, 3, 0, 1, 1);

        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        sizePolicy2.setHeightForWidth(groupBox_7->sizePolicy().hasHeightForWidth());
        groupBox_7->setSizePolicy(sizePolicy2);
        groupBox_7->setMaximumSize(QSize(16777215, 60));
        gridLayout_5 = new QGridLayout(groupBox_7);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        MessageRateLabel = new QLabel(groupBox_7);
        MessageRateLabel->setObjectName(QString::fromUtf8("MessageRateLabel"));
        sizePolicy3.setHeightForWidth(MessageRateLabel->sizePolicy().hasHeightForWidth());
        MessageRateLabel->setSizePolicy(sizePolicy3);
        MessageRateLabel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(MessageRateLabel, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_7, 2, 0, 1, 1);

        groupBox_10 = new QGroupBox(centralwidget);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setMinimumSize(QSize(0, 69));
        verticalLayout_2 = new QVBoxLayout(groupBox_10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        InfoButton = new QPushButton(groupBox_10);
        InfoButton->setObjectName(QString::fromUtf8("InfoButton"));
        InfoButton->setEnabled(false);

        verticalLayout_2->addWidget(InfoButton);


        gridLayout_2->addWidget(groupBox_10, 4, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        NeuroVizPanel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NeuroVizPanel);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 992, 22));
        NeuroVizPanel->setMenuBar(menubar);
        statusbar = new QStatusBar(NeuroVizPanel);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        NeuroVizPanel->setStatusBar(statusbar);
        QWidget::setTabOrder(TopicValue, StopButton);

        retranslateUi(NeuroVizPanel);

        NeuroTab->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(NeuroVizPanel);
    } // setupUi

    void retranslateUi(QMainWindow *NeuroVizPanel)
    {
        NeuroVizPanel->setWindowTitle(QApplication::translate("NeuroVizPanel", "neuroviz", nullptr));
        groupBox_5->setTitle(QApplication::translate("NeuroVizPanel", "Topic", nullptr));
        TopicValue->setText(QApplication::translate("NeuroVizPanel", "/neurodata", nullptr));
        label->setText(QApplication::translate("NeuroVizPanel", "Status:", nullptr));
        AcquisitionStatus->setText(QApplication::translate("NeuroVizPanel", "Idle", nullptr));
        StopButton->setText(QApplication::translate("NeuroVizPanel", "Stop", nullptr));
        groupBox_6->setTitle(QApplication::translate("NeuroVizPanel", "Native rate:", nullptr));
        NativeRateLabel->setText(QApplication::translate("NeuroVizPanel", "~ Hz", nullptr));
        groupBox_9->setTitle(QApplication::translate("NeuroVizPanel", "Message sequence:", nullptr));
        MessageSeqLabel->setText(QApplication::translate("NeuroVizPanel", "0", nullptr));
        groupBox_7->setTitle(QApplication::translate("NeuroVizPanel", "Message rate:", nullptr));
        MessageRateLabel->setText(QApplication::translate("NeuroVizPanel", "~ Hz", nullptr));
        groupBox_10->setTitle(QApplication::translate("NeuroVizPanel", "Data info:", nullptr));
        InfoButton->setText(QApplication::translate("NeuroVizPanel", "info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NeuroVizPanel: public Ui_NeuroVizPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // NEUROVIZMWHXFT_H
