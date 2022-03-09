/********************************************************************************
** Form generated from reading UI file 'panelPXMvyr.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PANELPXMVYR_H
#define PANELPXMVYR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
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
    QTabWidget *tabWidget;
    QWidget *eeg_tab;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
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
    QVBoxLayout *verticalLayout_8;
    QFrame *frame;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_5;
    QLineEdit *TopicValue;
    QPushButton *TopicButton;
    QGroupBox *groupBox_6;
    QLabel *NativeRateLabel;
    QGroupBox *groupBox_7;
    QLabel *MessageRateLabel;
    QGroupBox *groupBox_8;
    QComboBox *TimeWindowValue;
    QSpacerItem *verticalSpacer;
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
        horizontalLayout_2 = new QHBoxLayout(eeg_tab);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
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


        verticalLayout_2->addWidget(groupBox);

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


        verticalLayout_2->addWidget(groupBox_2);

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


        verticalLayout_2->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(eeg_tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(groupBox_4);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        frame = new QFrame(eeg_tab);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy4);
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout_8->addWidget(frame);


        horizontalLayout_2->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        groupBox_5 = new QGroupBox(eeg_tab);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy5);
        groupBox_5->setMinimumSize(QSize(150, 95));
        groupBox_5->setMaximumSize(QSize(0, 16777215));
        TopicValue = new QLineEdit(groupBox_5);
        TopicValue->setObjectName(QString::fromUtf8("TopicValue"));
        TopicValue->setGeometry(QRect(10, 30, 131, 25));
        TopicValue->setFocusPolicy(Qt::StrongFocus);
        TopicValue->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        TopicButton = new QPushButton(groupBox_5);
        TopicButton->setObjectName(QString::fromUtf8("TopicButton"));
        TopicButton->setGeometry(QRect(10, 60, 131, 25));
        sizePolicy.setHeightForWidth(TopicButton->sizePolicy().hasHeightForWidth());
        TopicButton->setSizePolicy(sizePolicy);
        TopicButton->setCheckable(false);
        TopicButton->setChecked(false);

        verticalLayout_7->addWidget(groupBox_5, 0, Qt::AlignTop);

        groupBox_6 = new QGroupBox(eeg_tab);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy6);
        groupBox_6->setMaximumSize(QSize(16777215, 60));
        NativeRateLabel = new QLabel(groupBox_6);
        NativeRateLabel->setObjectName(QString::fromUtf8("NativeRateLabel"));
        NativeRateLabel->setGeometry(QRect(10, 30, 131, 20));
        NativeRateLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(groupBox_6);

        groupBox_7 = new QGroupBox(eeg_tab);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        sizePolicy6.setHeightForWidth(groupBox_7->sizePolicy().hasHeightForWidth());
        groupBox_7->setSizePolicy(sizePolicy6);
        groupBox_7->setMaximumSize(QSize(16777215, 60));
        MessageRateLabel = new QLabel(groupBox_7);
        MessageRateLabel->setObjectName(QString::fromUtf8("MessageRateLabel"));
        MessageRateLabel->setGeometry(QRect(10, 30, 131, 20));
        MessageRateLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(groupBox_7);

        groupBox_8 = new QGroupBox(eeg_tab);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        sizePolicy3.setHeightForWidth(groupBox_8->sizePolicy().hasHeightForWidth());
        groupBox_8->setSizePolicy(sizePolicy3);
        groupBox_8->setMinimumSize(QSize(0, 69));
        groupBox_8->setMaximumSize(QSize(16777215, 16777215));
        TimeWindowValue = new QComboBox(groupBox_8);
        TimeWindowValue->addItem(QString());
        TimeWindowValue->addItem(QString());
        TimeWindowValue->addItem(QString());
        TimeWindowValue->addItem(QString());
        TimeWindowValue->addItem(QString());
        TimeWindowValue->addItem(QString());
        TimeWindowValue->setObjectName(QString::fromUtf8("TimeWindowValue"));
        TimeWindowValue->setGeometry(QRect(10, 30, 131, 25));
        TimeWindowValue->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(136, 138, 133);"));

        verticalLayout_7->addWidget(groupBox_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_7);

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
        groupBox_5->setTitle(QApplication::translate("NeuroVizPanel", "Topic", nullptr));
        TopicButton->setText(QApplication::translate("NeuroVizPanel", "Run", nullptr));
        groupBox_6->setTitle(QApplication::translate("NeuroVizPanel", "Native rate:", nullptr));
        NativeRateLabel->setText(QApplication::translate("NeuroVizPanel", "0 Hz", nullptr));
        groupBox_7->setTitle(QApplication::translate("NeuroVizPanel", "Message rate:", nullptr));
        MessageRateLabel->setText(QApplication::translate("NeuroVizPanel", "0 Hz", nullptr));
        groupBox_8->setTitle(QApplication::translate("NeuroVizPanel", "Time window:", nullptr));
        TimeWindowValue->setItemText(0, QApplication::translate("NeuroVizPanel", "1 s", nullptr));
        TimeWindowValue->setItemText(1, QApplication::translate("NeuroVizPanel", "2 s", nullptr));
        TimeWindowValue->setItemText(2, QApplication::translate("NeuroVizPanel", "5 s", nullptr));
        TimeWindowValue->setItemText(3, QApplication::translate("NeuroVizPanel", "10 s", nullptr));
        TimeWindowValue->setItemText(4, QApplication::translate("NeuroVizPanel", "20 s", nullptr));
        TimeWindowValue->setItemText(5, QApplication::translate("NeuroVizPanel", "30 s", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(eeg_tab), QApplication::translate("NeuroVizPanel", "EEG", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("NeuroVizPanel", "EXG", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NeuroVizPanel: public Ui_NeuroVizPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PANELPXMVYR_H

