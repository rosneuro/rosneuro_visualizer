/********************************************************************************
** Form generated from reading UI file 'panelIhRUPe.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PANELIHRUPE_H
#define PANELIHRUPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_NeuroVizPanel
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *eeg_tab;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout;
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
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_6;
    QListWidget *ChannelsList;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_5;
    QLabel *MessageRateLabel;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_6;
    QLabel *MessageSeqLabel;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_7;
    QComboBox *TimeWindowValue;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_4;
    QLabel *NativeRateLabel;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_3;
    QLineEdit *TopicValue;
    QLabel *label;
    QLabel *TopicStatus;
    QPushButton *TopicButton;
    QGroupBox *groupBox_10;
    QPushButton *infoButton;
    QCustomPlot *eegScope;
    QWidget *tab_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *NeuroVizPanel)
    {
        if (NeuroVizPanel->objectName().isEmpty())
            NeuroVizPanel->setObjectName(QString::fromUtf8("NeuroVizPanel"));
        NeuroVizPanel->resize(1010, 864);
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
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        eeg_tab = new QWidget();
        eeg_tab->setObjectName(QString::fromUtf8("eeg_tab"));
        gridLayout_8 = new QGridLayout(eeg_tab);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, 0, -1);
        groupBox = new QGroupBox(eeg_tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
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
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(ScaleValue->sizePolicy().hasHeightForWidth());
        ScaleValue->setSizePolicy(sizePolicy2);
        ScaleValue->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        verticalLayout_3->addWidget(ScaleValue);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(eeg_tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        LowPassCheck = new QCheckBox(groupBox_2);
        LowPassCheck->setObjectName(QString::fromUtf8("LowPassCheck"));

        verticalLayout_4->addWidget(LowPassCheck);

        LowPassValue = new QDoubleSpinBox(groupBox_2);
        LowPassValue->setObjectName(QString::fromUtf8("LowPassValue"));

        verticalLayout_4->addWidget(LowPassValue);

        HighPassCheck = new QCheckBox(groupBox_2);
        HighPassCheck->setObjectName(QString::fromUtf8("HighPassCheck"));

        verticalLayout_4->addWidget(HighPassCheck);

        HighPassValue = new QDoubleSpinBox(groupBox_2);
        HighPassValue->setObjectName(QString::fromUtf8("HighPassValue"));

        verticalLayout_4->addWidget(HighPassValue);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(eeg_tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        ReferenceValue = new QComboBox(groupBox_3);
        ReferenceValue->addItem(QString());
        ReferenceValue->addItem(QString());
        ReferenceValue->addItem(QString());
        ReferenceValue->addItem(QString());
        ReferenceValue->setObjectName(QString::fromUtf8("ReferenceValue"));
        ReferenceValue->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        verticalLayout_5->addWidget(ReferenceValue);

        ReferenceOpt = new QComboBox(groupBox_3);
        ReferenceOpt->setObjectName(QString::fromUtf8("ReferenceOpt"));
        ReferenceOpt->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        verticalLayout_5->addWidget(ReferenceOpt);


        gridLayout->addWidget(groupBox_3, 2, 0, 1, 1);

        groupBox_4 = new QGroupBox(eeg_tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy3);
        groupBox_4->setMinimumSize(QSize(119, 0));
        groupBox_4->setMaximumSize(QSize(119, 16777215));
        verticalLayout_6 = new QVBoxLayout(groupBox_4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
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

        verticalLayout_6->addWidget(ChannelsList);


        gridLayout->addWidget(groupBox_4, 3, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 6, 0, 1, 1);

        groupBox_7 = new QGroupBox(eeg_tab);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox_7->sizePolicy().hasHeightForWidth());
        groupBox_7->setSizePolicy(sizePolicy5);
        groupBox_7->setMaximumSize(QSize(16777215, 60));
        gridLayout_5 = new QGridLayout(groupBox_7);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        MessageRateLabel = new QLabel(groupBox_7);
        MessageRateLabel->setObjectName(QString::fromUtf8("MessageRateLabel"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(MessageRateLabel->sizePolicy().hasHeightForWidth());
        MessageRateLabel->setSizePolicy(sizePolicy6);
        MessageRateLabel->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(MessageRateLabel, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_7, 2, 0, 1, 1);

        groupBox_9 = new QGroupBox(eeg_tab);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        sizePolicy5.setHeightForWidth(groupBox_9->sizePolicy().hasHeightForWidth());
        groupBox_9->setSizePolicy(sizePolicy5);
        groupBox_9->setMaximumSize(QSize(16777215, 60));
        gridLayout_6 = new QGridLayout(groupBox_9);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        MessageSeqLabel = new QLabel(groupBox_9);
        MessageSeqLabel->setObjectName(QString::fromUtf8("MessageSeqLabel"));
        sizePolicy6.setHeightForWidth(MessageSeqLabel->sizePolicy().hasHeightForWidth());
        MessageSeqLabel->setSizePolicy(sizePolicy6);
        MessageSeqLabel->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(MessageSeqLabel, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_9, 3, 0, 1, 1);

        groupBox_8 = new QGroupBox(eeg_tab);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        sizePolicy6.setHeightForWidth(groupBox_8->sizePolicy().hasHeightForWidth());
        groupBox_8->setSizePolicy(sizePolicy6);
        groupBox_8->setMinimumSize(QSize(0, 69));
        groupBox_8->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_7 = new QGridLayout(groupBox_8);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        TimeWindowValue = new QComboBox(groupBox_8);
        TimeWindowValue->addItem(QString());
        TimeWindowValue->addItem(QString());
        TimeWindowValue->addItem(QString());
        TimeWindowValue->addItem(QString());
        TimeWindowValue->addItem(QString());
        TimeWindowValue->addItem(QString());
        TimeWindowValue->setObjectName(QString::fromUtf8("TimeWindowValue"));
        TimeWindowValue->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        gridLayout_7->addWidget(TimeWindowValue, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_8, 4, 0, 1, 1);

        groupBox_6 = new QGroupBox(eeg_tab);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        sizePolicy5.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy5);
        groupBox_6->setMaximumSize(QSize(16777215, 60));
        gridLayout_4 = new QGridLayout(groupBox_6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        NativeRateLabel = new QLabel(groupBox_6);
        NativeRateLabel->setObjectName(QString::fromUtf8("NativeRateLabel"));
        NativeRateLabel->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(NativeRateLabel, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_6, 1, 0, 1, 1);

        groupBox_5 = new QGroupBox(eeg_tab);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy7);
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

        TopicStatus = new QLabel(groupBox_5);
        TopicStatus->setObjectName(QString::fromUtf8("TopicStatus"));

        gridLayout_3->addWidget(TopicStatus, 1, 1, 1, 1);

        TopicButton = new QPushButton(groupBox_5);
        TopicButton->setObjectName(QString::fromUtf8("TopicButton"));
        TopicButton->setEnabled(true);
        sizePolicy.setHeightForWidth(TopicButton->sizePolicy().hasHeightForWidth());
        TopicButton->setSizePolicy(sizePolicy);
        TopicButton->setCheckable(false);
        TopicButton->setChecked(false);

        gridLayout_3->addWidget(TopicButton, 2, 0, 1, 2);


        gridLayout_2->addWidget(groupBox_5, 0, 0, 1, 1);

        groupBox_10 = new QGroupBox(eeg_tab);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setMinimumSize(QSize(0, 69));
        infoButton = new QPushButton(groupBox_10);
        infoButton->setObjectName(QString::fromUtf8("infoButton"));
        infoButton->setGeometry(QRect(17, 33, 126, 25));

        gridLayout_2->addWidget(groupBox_10, 5, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_2, 0, 3, 1, 1);

        eegScope = new QCustomPlot(eeg_tab);
        eegScope->setObjectName(QString::fromUtf8("eegScope"));
        sizePolicy.setHeightForWidth(eegScope->sizePolicy().hasHeightForWidth());
        eegScope->setSizePolicy(sizePolicy);
        eegScope->setMinimumSize(QSize(0, 0));
        eegScope->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout_8->addWidget(eegScope, 0, 2, 1, 1);

        tabWidget->addTab(eeg_tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setEnabled(true);
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        horizontalLayout->addLayout(verticalLayout);

        NeuroVizPanel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NeuroVizPanel);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1010, 22));
        NeuroVizPanel->setMenuBar(menubar);
        statusbar = new QStatusBar(NeuroVizPanel);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        NeuroVizPanel->setStatusBar(statusbar);
        QWidget::setTabOrder(tabWidget, ScaleValue);
        QWidget::setTabOrder(ScaleValue, LowPassCheck);
        QWidget::setTabOrder(LowPassCheck, LowPassValue);
        QWidget::setTabOrder(LowPassValue, HighPassCheck);
        QWidget::setTabOrder(HighPassCheck, HighPassValue);
        QWidget::setTabOrder(HighPassValue, ReferenceValue);
        QWidget::setTabOrder(ReferenceValue, ReferenceOpt);
        QWidget::setTabOrder(ReferenceOpt, TopicValue);
        QWidget::setTabOrder(TopicValue, TopicButton);
        QWidget::setTabOrder(TopicButton, TimeWindowValue);

        retranslateUi(NeuroVizPanel);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(NeuroVizPanel);
    } // setupUi

    void retranslateUi(QMainWindow *NeuroVizPanel)
    {
        NeuroVizPanel->setWindowTitle(QApplication::translate("NeuroVizPanel", "neuroviz", nullptr));
        groupBox->setTitle(QApplication::translate("NeuroVizPanel", "Scale", nullptr));
        ScaleValue->setItemText(0, QApplication::translate("NeuroVizPanel", "1 uV", nullptr));
        ScaleValue->setItemText(1, QApplication::translate("NeuroVizPanel", "2.5 uV", nullptr));
        ScaleValue->setItemText(2, QApplication::translate("NeuroVizPanel", "5 uV", nullptr));
        ScaleValue->setItemText(3, QApplication::translate("NeuroVizPanel", "10 uV", nullptr));
        ScaleValue->setItemText(4, QApplication::translate("NeuroVizPanel", "25 uV", nullptr));
        ScaleValue->setItemText(5, QApplication::translate("NeuroVizPanel", "50 uV", nullptr));
        ScaleValue->setItemText(6, QApplication::translate("NeuroVizPanel", "100 uV", nullptr));
        ScaleValue->setItemText(7, QApplication::translate("NeuroVizPanel", "250 uV", nullptr));
        ScaleValue->setItemText(8, QApplication::translate("NeuroVizPanel", "500 uV", nullptr));
        ScaleValue->setItemText(9, QApplication::translate("NeuroVizPanel", "1 mV", nullptr));
        ScaleValue->setItemText(10, QApplication::translate("NeuroVizPanel", "2.5 mV", nullptr));
        ScaleValue->setItemText(11, QApplication::translate("NeuroVizPanel", "5 mV", nullptr));
        ScaleValue->setItemText(12, QApplication::translate("NeuroVizPanel", "10 mV", nullptr));
        ScaleValue->setItemText(13, QApplication::translate("NeuroVizPanel", "25 mV", nullptr));
        ScaleValue->setItemText(14, QApplication::translate("NeuroVizPanel", "50 mV", nullptr));

        groupBox_2->setTitle(QApplication::translate("NeuroVizPanel", "Filtering", nullptr));
        LowPassCheck->setText(QApplication::translate("NeuroVizPanel", "Low pass", nullptr));
        HighPassCheck->setText(QApplication::translate("NeuroVizPanel", "High pass", nullptr));
        groupBox_3->setTitle(QApplication::translate("NeuroVizPanel", "Reference", nullptr));
        ReferenceValue->setItemText(0, QApplication::translate("NeuroVizPanel", "None", nullptr));
        ReferenceValue->setItemText(1, QApplication::translate("NeuroVizPanel", "Average", nullptr));
        ReferenceValue->setItemText(2, QApplication::translate("NeuroVizPanel", "Electrode", nullptr));
        ReferenceValue->setItemText(3, QApplication::translate("NeuroVizPanel", "Bipole", nullptr));

        groupBox_4->setTitle(QApplication::translate("NeuroVizPanel", "Electrodes", nullptr));
        groupBox_7->setTitle(QApplication::translate("NeuroVizPanel", "Message rate:", nullptr));
        MessageRateLabel->setText(QApplication::translate("NeuroVizPanel", "~ Hz", nullptr));
        groupBox_9->setTitle(QApplication::translate("NeuroVizPanel", "Message sequence:", nullptr));
        MessageSeqLabel->setText(QApplication::translate("NeuroVizPanel", "0", nullptr));
        groupBox_8->setTitle(QApplication::translate("NeuroVizPanel", "Time window:", nullptr));
        TimeWindowValue->setItemText(0, QApplication::translate("NeuroVizPanel", "1 s", nullptr));
        TimeWindowValue->setItemText(1, QApplication::translate("NeuroVizPanel", "2 s", nullptr));
        TimeWindowValue->setItemText(2, QApplication::translate("NeuroVizPanel", "5 s", nullptr));
        TimeWindowValue->setItemText(3, QApplication::translate("NeuroVizPanel", "10 s", nullptr));
        TimeWindowValue->setItemText(4, QApplication::translate("NeuroVizPanel", "20 s", nullptr));
        TimeWindowValue->setItemText(5, QApplication::translate("NeuroVizPanel", "30 s", nullptr));

        groupBox_6->setTitle(QApplication::translate("NeuroVizPanel", "Native rate:", nullptr));
        NativeRateLabel->setText(QApplication::translate("NeuroVizPanel", "~ Hz", nullptr));
        groupBox_5->setTitle(QApplication::translate("NeuroVizPanel", "Topic", nullptr));
        TopicValue->setText(QApplication::translate("NeuroVizPanel", "/neurodata", nullptr));
        label->setText(QApplication::translate("NeuroVizPanel", "Status:", nullptr));
        TopicStatus->setText(QApplication::translate("NeuroVizPanel", "Idle", nullptr));
        TopicButton->setText(QApplication::translate("NeuroVizPanel", "Stop", nullptr));
        groupBox_10->setTitle(QApplication::translate("NeuroVizPanel", "Data info:", nullptr));
        infoButton->setText(QApplication::translate("NeuroVizPanel", "info", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(eeg_tab), QApplication::translate("NeuroVizPanel", "EEG", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("NeuroVizPanel", "EXG", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NeuroVizPanel: public Ui_NeuroVizPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PANELIHRUPE_H
