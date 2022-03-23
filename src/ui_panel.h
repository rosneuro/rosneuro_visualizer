/********************************************************************************
** Form generated from reading UI file 'panelIpVWGv.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PANELIPVWGV_H
#define PANELIPVWGV_H

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
#include "rosneuro_visualizer/ScopePanel.hpp"

QT_BEGIN_NAMESPACE

class Ui_NeuroVizPanel
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTabWidget *NeuroTab;
    QWidget *eeg_tab;
    QGridLayout *gridLayout_8;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QComboBox *EEGScaleValue;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *EEGLowPassCheck;
    QDoubleSpinBox *EEGLowPassValue;
    QCheckBox *EEGHighPassCheck;
    QDoubleSpinBox *EEGHighPassValue;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QComboBox *EEGReferenceValue;
    QComboBox *EEGReferenceOpt;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_7;
    QComboBox *EEGTimeWindowValue;
    QSpacerItem *verticalSpacer;
    ScopePanel *eegScope;
    QWidget *exg_tab;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_11;
    QGroupBox *groupBox_11;
    QVBoxLayout *verticalLayout_7;
    QComboBox *EXGScaleValue;
    QGroupBox *groupBox_12;
    QVBoxLayout *verticalLayout_8;
    QCheckBox *EXGLowPassCheck;
    QDoubleSpinBox *EXGLowPassValue;
    QCheckBox *EXGHighPassCheck;
    QDoubleSpinBox *EXGHighPassValue;
    QGroupBox *groupBox_13;
    QVBoxLayout *verticalLayout_9;
    QComboBox *EXGReferenceValue;
    QComboBox *EXGReferenceOpt;
    QGroupBox *groupBox_14;
    QGridLayout *gridLayout_9;
    QComboBox *EXGTimeWindowValue;
    QSpacerItem *verticalSpacer_2;
    ScopePanel *exgScope;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_5;
    QLabel *MessageRateLabel;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_4;
    QLabel *NativeRateLabel;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_6;
    QLabel *MessageSeqLabel;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_3;
    QLineEdit *TopicValue;
    QLabel *label;
    QLabel *TopicStatus;
    QPushButton *TopicButton;
    QGroupBox *groupBox_10;
    QVBoxLayout *verticalLayout_2;
    QPushButton *InfoButton;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_6;
    QListWidget *ChannelsList;
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
        NeuroTab = new QTabWidget(centralwidget);
        NeuroTab->setObjectName(QString::fromUtf8("NeuroTab"));
        NeuroTab->setEnabled(true);
        NeuroTab->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));
        eeg_tab = new QWidget();
        eeg_tab->setObjectName(QString::fromUtf8("eeg_tab"));
        gridLayout_8 = new QGridLayout(eeg_tab);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(-1, -1, 0, -1);
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
        EEGScaleValue = new QComboBox(groupBox);
        EEGScaleValue->addItem(QString());
        EEGScaleValue->addItem(QString());
        EEGScaleValue->addItem(QString());
        EEGScaleValue->addItem(QString());
        EEGScaleValue->addItem(QString());
        EEGScaleValue->addItem(QString());
        EEGScaleValue->addItem(QString());
        EEGScaleValue->addItem(QString());
        EEGScaleValue->addItem(QString());
        EEGScaleValue->addItem(QString());
        EEGScaleValue->addItem(QString());
        EEGScaleValue->addItem(QString());
        EEGScaleValue->addItem(QString());
        EEGScaleValue->addItem(QString());
        EEGScaleValue->addItem(QString());
        EEGScaleValue->setObjectName(QString::fromUtf8("EEGScaleValue"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(EEGScaleValue->sizePolicy().hasHeightForWidth());
        EEGScaleValue->setSizePolicy(sizePolicy2);
        EEGScaleValue->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        verticalLayout_3->addWidget(EEGScaleValue);


        verticalLayout_10->addWidget(groupBox);

        groupBox_2 = new QGroupBox(eeg_tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        EEGLowPassCheck = new QCheckBox(groupBox_2);
        EEGLowPassCheck->setObjectName(QString::fromUtf8("EEGLowPassCheck"));

        verticalLayout_4->addWidget(EEGLowPassCheck);

        EEGLowPassValue = new QDoubleSpinBox(groupBox_2);
        EEGLowPassValue->setObjectName(QString::fromUtf8("EEGLowPassValue"));
        EEGLowPassValue->setMaximum(4096.000000000000000);
        EEGLowPassValue->setValue(100.000000000000000);

        verticalLayout_4->addWidget(EEGLowPassValue);

        EEGHighPassCheck = new QCheckBox(groupBox_2);
        EEGHighPassCheck->setObjectName(QString::fromUtf8("EEGHighPassCheck"));

        verticalLayout_4->addWidget(EEGHighPassCheck);

        EEGHighPassValue = new QDoubleSpinBox(groupBox_2);
        EEGHighPassValue->setObjectName(QString::fromUtf8("EEGHighPassValue"));
        EEGHighPassValue->setMaximum(4096.000000000000000);
        EEGHighPassValue->setValue(1.000000000000000);

        verticalLayout_4->addWidget(EEGHighPassValue);


        verticalLayout_10->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(eeg_tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        EEGReferenceValue = new QComboBox(groupBox_3);
        EEGReferenceValue->addItem(QString());
        EEGReferenceValue->addItem(QString());
        EEGReferenceValue->addItem(QString());
        EEGReferenceValue->addItem(QString());
        EEGReferenceValue->setObjectName(QString::fromUtf8("EEGReferenceValue"));
        EEGReferenceValue->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        verticalLayout_5->addWidget(EEGReferenceValue);

        EEGReferenceOpt = new QComboBox(groupBox_3);
        EEGReferenceOpt->setObjectName(QString::fromUtf8("EEGReferenceOpt"));
        EEGReferenceOpt->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        verticalLayout_5->addWidget(EEGReferenceOpt);


        verticalLayout_10->addWidget(groupBox_3);

        groupBox_8 = new QGroupBox(eeg_tab);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_8->sizePolicy().hasHeightForWidth());
        groupBox_8->setSizePolicy(sizePolicy3);
        groupBox_8->setMinimumSize(QSize(0, 69));
        groupBox_8->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_7 = new QGridLayout(groupBox_8);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        EEGTimeWindowValue = new QComboBox(groupBox_8);
        EEGTimeWindowValue->addItem(QString());
        EEGTimeWindowValue->addItem(QString());
        EEGTimeWindowValue->addItem(QString());
        EEGTimeWindowValue->addItem(QString());
        EEGTimeWindowValue->addItem(QString());
        EEGTimeWindowValue->addItem(QString());
        EEGTimeWindowValue->setObjectName(QString::fromUtf8("EEGTimeWindowValue"));
        EEGTimeWindowValue->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        gridLayout_7->addWidget(EEGTimeWindowValue, 0, 0, 1, 1);


        verticalLayout_10->addWidget(groupBox_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_10);

        eegScope = new ScopePanel(eeg_tab);
        eegScope->setObjectName(QString::fromUtf8("eegScope"));
        sizePolicy.setHeightForWidth(eegScope->sizePolicy().hasHeightForWidth());
        eegScope->setSizePolicy(sizePolicy);
        eegScope->setMinimumSize(QSize(0, 0));
        eegScope->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(eegScope);


        gridLayout_8->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        NeuroTab->addTab(eeg_tab, QString());
        exg_tab = new QWidget();
        exg_tab->setObjectName(QString::fromUtf8("exg_tab"));
        exg_tab->setEnabled(true);
        gridLayout = new QGridLayout(exg_tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(-1, -1, 0, -1);
        groupBox_11 = new QGroupBox(exg_tab);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setEnabled(true);
        sizePolicy1.setHeightForWidth(groupBox_11->sizePolicy().hasHeightForWidth());
        groupBox_11->setSizePolicy(sizePolicy1);
        groupBox_11->setMaximumSize(QSize(115, 69));
        verticalLayout_7 = new QVBoxLayout(groupBox_11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        EXGScaleValue = new QComboBox(groupBox_11);
        EXGScaleValue->addItem(QString());
        EXGScaleValue->addItem(QString());
        EXGScaleValue->addItem(QString());
        EXGScaleValue->addItem(QString());
        EXGScaleValue->addItem(QString());
        EXGScaleValue->addItem(QString());
        EXGScaleValue->addItem(QString());
        EXGScaleValue->addItem(QString());
        EXGScaleValue->addItem(QString());
        EXGScaleValue->addItem(QString());
        EXGScaleValue->addItem(QString());
        EXGScaleValue->addItem(QString());
        EXGScaleValue->addItem(QString());
        EXGScaleValue->addItem(QString());
        EXGScaleValue->addItem(QString());
        EXGScaleValue->setObjectName(QString::fromUtf8("EXGScaleValue"));
        sizePolicy2.setHeightForWidth(EXGScaleValue->sizePolicy().hasHeightForWidth());
        EXGScaleValue->setSizePolicy(sizePolicy2);
        EXGScaleValue->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        verticalLayout_7->addWidget(EXGScaleValue);


        verticalLayout_11->addWidget(groupBox_11);

        groupBox_12 = new QGroupBox(exg_tab);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        sizePolicy1.setHeightForWidth(groupBox_12->sizePolicy().hasHeightForWidth());
        groupBox_12->setSizePolicy(sizePolicy1);
        verticalLayout_8 = new QVBoxLayout(groupBox_12);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        EXGLowPassCheck = new QCheckBox(groupBox_12);
        EXGLowPassCheck->setObjectName(QString::fromUtf8("EXGLowPassCheck"));

        verticalLayout_8->addWidget(EXGLowPassCheck);

        EXGLowPassValue = new QDoubleSpinBox(groupBox_12);
        EXGLowPassValue->setObjectName(QString::fromUtf8("EXGLowPassValue"));
        EXGLowPassValue->setMaximum(4096.000000000000000);
        EXGLowPassValue->setValue(100.000000000000000);

        verticalLayout_8->addWidget(EXGLowPassValue);

        EXGHighPassCheck = new QCheckBox(groupBox_12);
        EXGHighPassCheck->setObjectName(QString::fromUtf8("EXGHighPassCheck"));

        verticalLayout_8->addWidget(EXGHighPassCheck);

        EXGHighPassValue = new QDoubleSpinBox(groupBox_12);
        EXGHighPassValue->setObjectName(QString::fromUtf8("EXGHighPassValue"));
        EXGHighPassValue->setMaximum(4096.000000000000000);
        EXGHighPassValue->setValue(1.000000000000000);

        verticalLayout_8->addWidget(EXGHighPassValue);


        verticalLayout_11->addWidget(groupBox_12);

        groupBox_13 = new QGroupBox(exg_tab);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        sizePolicy1.setHeightForWidth(groupBox_13->sizePolicy().hasHeightForWidth());
        groupBox_13->setSizePolicy(sizePolicy1);
        verticalLayout_9 = new QVBoxLayout(groupBox_13);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        EXGReferenceValue = new QComboBox(groupBox_13);
        EXGReferenceValue->addItem(QString());
        EXGReferenceValue->addItem(QString());
        EXGReferenceValue->addItem(QString());
        EXGReferenceValue->addItem(QString());
        EXGReferenceValue->setObjectName(QString::fromUtf8("EXGReferenceValue"));
        EXGReferenceValue->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        verticalLayout_9->addWidget(EXGReferenceValue);

        EXGReferenceOpt = new QComboBox(groupBox_13);
        EXGReferenceOpt->setObjectName(QString::fromUtf8("EXGReferenceOpt"));
        EXGReferenceOpt->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        verticalLayout_9->addWidget(EXGReferenceOpt);


        verticalLayout_11->addWidget(groupBox_13);

        groupBox_14 = new QGroupBox(exg_tab);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        sizePolicy3.setHeightForWidth(groupBox_14->sizePolicy().hasHeightForWidth());
        groupBox_14->setSizePolicy(sizePolicy3);
        groupBox_14->setMinimumSize(QSize(0, 69));
        groupBox_14->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_9 = new QGridLayout(groupBox_14);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        EXGTimeWindowValue = new QComboBox(groupBox_14);
        EXGTimeWindowValue->addItem(QString());
        EXGTimeWindowValue->addItem(QString());
        EXGTimeWindowValue->addItem(QString());
        EXGTimeWindowValue->addItem(QString());
        EXGTimeWindowValue->addItem(QString());
        EXGTimeWindowValue->addItem(QString());
        EXGTimeWindowValue->setObjectName(QString::fromUtf8("EXGTimeWindowValue"));
        EXGTimeWindowValue->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        gridLayout_9->addWidget(EXGTimeWindowValue, 0, 0, 1, 1);


        verticalLayout_11->addWidget(groupBox_14);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout_11);

        exgScope = new ScopePanel(exg_tab);
        exgScope->setObjectName(QString::fromUtf8("exgScope"));
        sizePolicy.setHeightForWidth(exgScope->sizePolicy().hasHeightForWidth());
        exgScope->setSizePolicy(sizePolicy);
        exgScope->setMinimumSize(QSize(0, 0));
        exgScope->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(exgScope);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        NeuroTab->addTab(exg_tab, QString());

        verticalLayout->addWidget(NeuroTab);


        horizontalLayout->addLayout(verticalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox_7->sizePolicy().hasHeightForWidth());
        groupBox_7->setSizePolicy(sizePolicy4);
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

        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        sizePolicy4.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy4);
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
        sizePolicy4.setHeightForWidth(groupBox_9->sizePolicy().hasHeightForWidth());
        groupBox_9->setSizePolicy(sizePolicy4);
        groupBox_9->setMaximumSize(QSize(16777215, 60));
        gridLayout_6 = new QGridLayout(groupBox_9);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        MessageSeqLabel = new QLabel(groupBox_9);
        MessageSeqLabel->setObjectName(QString::fromUtf8("MessageSeqLabel"));
        sizePolicy3.setHeightForWidth(MessageSeqLabel->sizePolicy().hasHeightForWidth());
        MessageSeqLabel->setSizePolicy(sizePolicy3);
        MessageSeqLabel->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(MessageSeqLabel, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_9, 3, 0, 1, 1);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy5);
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

        groupBox_10 = new QGroupBox(centralwidget);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setMinimumSize(QSize(0, 69));
        verticalLayout_2 = new QVBoxLayout(groupBox_10);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        InfoButton = new QPushButton(groupBox_10);
        InfoButton->setObjectName(QString::fromUtf8("InfoButton"));

        verticalLayout_2->addWidget(InfoButton);


        gridLayout_2->addWidget(groupBox_10, 5, 0, 1, 1);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy6);
        groupBox_4->setMinimumSize(QSize(161, 0));
        groupBox_4->setMaximumSize(QSize(119, 16777215));
        verticalLayout_6 = new QVBoxLayout(groupBox_4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        ChannelsList = new QListWidget(groupBox_4);
        ChannelsList->setObjectName(QString::fromUtf8("ChannelsList"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(ChannelsList->sizePolicy().hasHeightForWidth());
        ChannelsList->setSizePolicy(sizePolicy7);
        ChannelsList->setMinimumSize(QSize(0, 20));
        ChannelsList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ChannelsList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        ChannelsList->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout_6->addWidget(ChannelsList);


        gridLayout_2->addWidget(groupBox_4, 6, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        NeuroVizPanel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(NeuroVizPanel);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1010, 22));
        NeuroVizPanel->setMenuBar(menubar);
        statusbar = new QStatusBar(NeuroVizPanel);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        NeuroVizPanel->setStatusBar(statusbar);
        QWidget::setTabOrder(EEGScaleValue, EEGLowPassCheck);
        QWidget::setTabOrder(EEGLowPassCheck, EEGLowPassValue);
        QWidget::setTabOrder(EEGLowPassValue, EEGHighPassCheck);
        QWidget::setTabOrder(EEGHighPassCheck, EEGHighPassValue);
        QWidget::setTabOrder(EEGHighPassValue, EEGReferenceValue);
        QWidget::setTabOrder(EEGReferenceValue, EEGReferenceOpt);
        QWidget::setTabOrder(EEGReferenceOpt, TopicValue);
        QWidget::setTabOrder(TopicValue, TopicButton);
        QWidget::setTabOrder(TopicButton, EEGTimeWindowValue);

        retranslateUi(NeuroVizPanel);

        NeuroTab->setCurrentIndex(0);
        EEGScaleValue->setCurrentIndex(5);
        EEGTimeWindowValue->setCurrentIndex(3);
        EXGScaleValue->setCurrentIndex(5);
        EXGTimeWindowValue->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(NeuroVizPanel);
    } // setupUi

    void retranslateUi(QMainWindow *NeuroVizPanel)
    {
        NeuroVizPanel->setWindowTitle(QApplication::translate("NeuroVizPanel", "neuroviz", nullptr));
        groupBox->setTitle(QApplication::translate("NeuroVizPanel", "Scale", nullptr));
        EEGScaleValue->setItemText(0, QApplication::translate("NeuroVizPanel", "1 uV", nullptr));
        EEGScaleValue->setItemText(1, QApplication::translate("NeuroVizPanel", "2.5 uV", nullptr));
        EEGScaleValue->setItemText(2, QApplication::translate("NeuroVizPanel", "5 uV", nullptr));
        EEGScaleValue->setItemText(3, QApplication::translate("NeuroVizPanel", "10 uV", nullptr));
        EEGScaleValue->setItemText(4, QApplication::translate("NeuroVizPanel", "25 uV", nullptr));
        EEGScaleValue->setItemText(5, QApplication::translate("NeuroVizPanel", "50 uV", nullptr));
        EEGScaleValue->setItemText(6, QApplication::translate("NeuroVizPanel", "100 uV", nullptr));
        EEGScaleValue->setItemText(7, QApplication::translate("NeuroVizPanel", "250 uV", nullptr));
        EEGScaleValue->setItemText(8, QApplication::translate("NeuroVizPanel", "500 uV", nullptr));
        EEGScaleValue->setItemText(9, QApplication::translate("NeuroVizPanel", "1 mV", nullptr));
        EEGScaleValue->setItemText(10, QApplication::translate("NeuroVizPanel", "2.5 mV", nullptr));
        EEGScaleValue->setItemText(11, QApplication::translate("NeuroVizPanel", "5 mV", nullptr));
        EEGScaleValue->setItemText(12, QApplication::translate("NeuroVizPanel", "10 mV", nullptr));
        EEGScaleValue->setItemText(13, QApplication::translate("NeuroVizPanel", "25 mV", nullptr));
        EEGScaleValue->setItemText(14, QApplication::translate("NeuroVizPanel", "50 mV", nullptr));

        groupBox_2->setTitle(QApplication::translate("NeuroVizPanel", "Filtering", nullptr));
        EEGLowPassCheck->setText(QApplication::translate("NeuroVizPanel", "Low pass", nullptr));
        EEGHighPassCheck->setText(QApplication::translate("NeuroVizPanel", "High pass", nullptr));
        groupBox_3->setTitle(QApplication::translate("NeuroVizPanel", "Reference", nullptr));
        EEGReferenceValue->setItemText(0, QApplication::translate("NeuroVizPanel", "None", nullptr));
        EEGReferenceValue->setItemText(1, QApplication::translate("NeuroVizPanel", "Average", nullptr));
        EEGReferenceValue->setItemText(2, QApplication::translate("NeuroVizPanel", "Electrode", nullptr));
        EEGReferenceValue->setItemText(3, QApplication::translate("NeuroVizPanel", "Bipole", nullptr));

        groupBox_8->setTitle(QApplication::translate("NeuroVizPanel", "Time window:", nullptr));
        EEGTimeWindowValue->setItemText(0, QApplication::translate("NeuroVizPanel", "1 s", nullptr));
        EEGTimeWindowValue->setItemText(1, QApplication::translate("NeuroVizPanel", "2 s", nullptr));
        EEGTimeWindowValue->setItemText(2, QApplication::translate("NeuroVizPanel", "5 s", nullptr));
        EEGTimeWindowValue->setItemText(3, QApplication::translate("NeuroVizPanel", "10 s", nullptr));
        EEGTimeWindowValue->setItemText(4, QApplication::translate("NeuroVizPanel", "20 s", nullptr));
        EEGTimeWindowValue->setItemText(5, QApplication::translate("NeuroVizPanel", "30 s", nullptr));

        NeuroTab->setTabText(NeuroTab->indexOf(eeg_tab), QApplication::translate("NeuroVizPanel", "EEG", nullptr));
        groupBox_11->setTitle(QApplication::translate("NeuroVizPanel", "Scale", nullptr));
        EXGScaleValue->setItemText(0, QApplication::translate("NeuroVizPanel", "1 uV", nullptr));
        EXGScaleValue->setItemText(1, QApplication::translate("NeuroVizPanel", "2.5 uV", nullptr));
        EXGScaleValue->setItemText(2, QApplication::translate("NeuroVizPanel", "5 uV", nullptr));
        EXGScaleValue->setItemText(3, QApplication::translate("NeuroVizPanel", "10 uV", nullptr));
        EXGScaleValue->setItemText(4, QApplication::translate("NeuroVizPanel", "25 uV", nullptr));
        EXGScaleValue->setItemText(5, QApplication::translate("NeuroVizPanel", "50 uV", nullptr));
        EXGScaleValue->setItemText(6, QApplication::translate("NeuroVizPanel", "100 uV", nullptr));
        EXGScaleValue->setItemText(7, QApplication::translate("NeuroVizPanel", "250 uV", nullptr));
        EXGScaleValue->setItemText(8, QApplication::translate("NeuroVizPanel", "500 uV", nullptr));
        EXGScaleValue->setItemText(9, QApplication::translate("NeuroVizPanel", "1 mV", nullptr));
        EXGScaleValue->setItemText(10, QApplication::translate("NeuroVizPanel", "2.5 mV", nullptr));
        EXGScaleValue->setItemText(11, QApplication::translate("NeuroVizPanel", "5 mV", nullptr));
        EXGScaleValue->setItemText(12, QApplication::translate("NeuroVizPanel", "10 mV", nullptr));
        EXGScaleValue->setItemText(13, QApplication::translate("NeuroVizPanel", "25 mV", nullptr));
        EXGScaleValue->setItemText(14, QApplication::translate("NeuroVizPanel", "50 mV", nullptr));

        groupBox_12->setTitle(QApplication::translate("NeuroVizPanel", "Filtering", nullptr));
        EXGLowPassCheck->setText(QApplication::translate("NeuroVizPanel", "Low pass", nullptr));
        EXGHighPassCheck->setText(QApplication::translate("NeuroVizPanel", "High pass", nullptr));
        groupBox_13->setTitle(QApplication::translate("NeuroVizPanel", "Reference", nullptr));
        EXGReferenceValue->setItemText(0, QApplication::translate("NeuroVizPanel", "None", nullptr));
        EXGReferenceValue->setItemText(1, QApplication::translate("NeuroVizPanel", "Average", nullptr));
        EXGReferenceValue->setItemText(2, QApplication::translate("NeuroVizPanel", "Electrode", nullptr));
        EXGReferenceValue->setItemText(3, QApplication::translate("NeuroVizPanel", "Bipole", nullptr));

        groupBox_14->setTitle(QApplication::translate("NeuroVizPanel", "Time window:", nullptr));
        EXGTimeWindowValue->setItemText(0, QApplication::translate("NeuroVizPanel", "1 s", nullptr));
        EXGTimeWindowValue->setItemText(1, QApplication::translate("NeuroVizPanel", "2 s", nullptr));
        EXGTimeWindowValue->setItemText(2, QApplication::translate("NeuroVizPanel", "5 s", nullptr));
        EXGTimeWindowValue->setItemText(3, QApplication::translate("NeuroVizPanel", "10 s", nullptr));
        EXGTimeWindowValue->setItemText(4, QApplication::translate("NeuroVizPanel", "20 s", nullptr));
        EXGTimeWindowValue->setItemText(5, QApplication::translate("NeuroVizPanel", "30 s", nullptr));

        NeuroTab->setTabText(NeuroTab->indexOf(exg_tab), QApplication::translate("NeuroVizPanel", "EXG", nullptr));
        groupBox_7->setTitle(QApplication::translate("NeuroVizPanel", "Message rate:", nullptr));
        MessageRateLabel->setText(QApplication::translate("NeuroVizPanel", "~ Hz", nullptr));
        groupBox_6->setTitle(QApplication::translate("NeuroVizPanel", "Native rate:", nullptr));
        NativeRateLabel->setText(QApplication::translate("NeuroVizPanel", "~ Hz", nullptr));
        groupBox_9->setTitle(QApplication::translate("NeuroVizPanel", "Message sequence:", nullptr));
        MessageSeqLabel->setText(QApplication::translate("NeuroVizPanel", "0", nullptr));
        groupBox_5->setTitle(QApplication::translate("NeuroVizPanel", "Topic", nullptr));
        TopicValue->setText(QApplication::translate("NeuroVizPanel", "/neurodata", nullptr));
        label->setText(QApplication::translate("NeuroVizPanel", "Status:", nullptr));
        TopicStatus->setText(QApplication::translate("NeuroVizPanel", "Idle", nullptr));
        TopicButton->setText(QApplication::translate("NeuroVizPanel", "Stop", nullptr));
        groupBox_10->setTitle(QApplication::translate("NeuroVizPanel", "Data info:", nullptr));
        InfoButton->setText(QApplication::translate("NeuroVizPanel", "info", nullptr));
        groupBox_4->setTitle(QApplication::translate("NeuroVizPanel", "Electrodes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NeuroVizPanel: public Ui_NeuroVizPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PANELIPVWGV_H
