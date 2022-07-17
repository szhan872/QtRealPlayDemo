/********************************************************************************
** Form generated from reading UI file 'qtrealplaydemo.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTREALPLAYDEMO_H
#define UI_QTREALPLAYDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtRealPlayDemoClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *IPBox;
    QLabel *label_2;
    QLineEdit *PortBox;
    QLabel *label_3;
    QLineEdit *UserNameBox;
    QLabel *label_4;
    QLineEdit *PassWordBox;
    QPushButton *LoginButton;
    QPushButton *LogoutButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QWidget *Viewer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *StartButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *StopButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *drawButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *hangButton;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *talkButton;
    QPushButton *RecButton;
    QPushButton *unRecBtn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *ReplayBtn;
    QSpacerItem *horizontalSpacer_8;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtRealPlayDemoClass)
    {
        if (QtRealPlayDemoClass->objectName().isEmpty())
            QtRealPlayDemoClass->setObjectName(QStringLiteral("QtRealPlayDemoClass"));
        QtRealPlayDemoClass->resize(887, 560);
        centralWidget = new QWidget(QtRealPlayDemoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        IPBox = new QLineEdit(centralWidget);
        IPBox->setObjectName(QStringLiteral("IPBox"));

        horizontalLayout->addWidget(IPBox);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        PortBox = new QLineEdit(centralWidget);
        PortBox->setObjectName(QStringLiteral("PortBox"));

        horizontalLayout->addWidget(PortBox);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        UserNameBox = new QLineEdit(centralWidget);
        UserNameBox->setObjectName(QStringLiteral("UserNameBox"));

        horizontalLayout->addWidget(UserNameBox);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        PassWordBox = new QLineEdit(centralWidget);
        PassWordBox->setObjectName(QStringLiteral("PassWordBox"));

        horizontalLayout->addWidget(PassWordBox);

        LoginButton = new QPushButton(centralWidget);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));

        horizontalLayout->addWidget(LoginButton);

        LogoutButton = new QPushButton(centralWidget);
        LogoutButton->setObjectName(QStringLiteral("LogoutButton"));

        horizontalLayout->addWidget(LogoutButton);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        Viewer = new QWidget(groupBox);
        Viewer->setObjectName(QStringLiteral("Viewer"));

        gridLayout_3->addWidget(Viewer, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(0, 50));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        StartButton = new QPushButton(groupBox_2);
        StartButton->setObjectName(QStringLiteral("StartButton"));

        horizontalLayout_2->addWidget(StartButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        StopButton = new QPushButton(groupBox_2);
        StopButton->setObjectName(QStringLiteral("StopButton"));

        horizontalLayout_2->addWidget(StopButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        drawButton = new QPushButton(groupBox_2);
        drawButton->setObjectName(QStringLiteral("drawButton"));

        horizontalLayout_2->addWidget(drawButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        hangButton = new QPushButton(groupBox_2);
        hangButton->setObjectName(QStringLiteral("hangButton"));

        horizontalLayout_2->addWidget(hangButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        talkButton = new QPushButton(groupBox_2);
        talkButton->setObjectName(QStringLiteral("talkButton"));

        horizontalLayout_2->addWidget(talkButton);

        RecButton = new QPushButton(groupBox_2);
        RecButton->setObjectName(QStringLiteral("RecButton"));

        horizontalLayout_2->addWidget(RecButton);

        unRecBtn = new QPushButton(groupBox_2);
        unRecBtn->setObjectName(QStringLiteral("unRecBtn"));

        horizontalLayout_2->addWidget(unRecBtn);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(275, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(275, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        ReplayBtn = new QPushButton(centralWidget);
        ReplayBtn->setObjectName(QStringLiteral("ReplayBtn"));

        horizontalLayout_3->addWidget(ReplayBtn);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);

        QtRealPlayDemoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtRealPlayDemoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 887, 23));
        QtRealPlayDemoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtRealPlayDemoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtRealPlayDemoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtRealPlayDemoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtRealPlayDemoClass->setStatusBar(statusBar);

        retranslateUi(QtRealPlayDemoClass);

        QMetaObject::connectSlotsByName(QtRealPlayDemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtRealPlayDemoClass)
    {
        QtRealPlayDemoClass->setWindowTitle(QApplication::translate("QtRealPlayDemoClass", "QtRealPlayDemo", Q_NULLPTR));
        label->setText(QApplication::translate("QtRealPlayDemoClass", "IP: ", Q_NULLPTR));
        label_2->setText(QApplication::translate("QtRealPlayDemoClass", "Port(http):", Q_NULLPTR));
        label_3->setText(QApplication::translate("QtRealPlayDemoClass", "UserName: ", Q_NULLPTR));
        label_4->setText(QApplication::translate("QtRealPlayDemoClass", "PassWord: ", Q_NULLPTR));
        LoginButton->setText(QApplication::translate("QtRealPlayDemoClass", "Login", Q_NULLPTR));
        LogoutButton->setText(QApplication::translate("QtRealPlayDemoClass", "Logout", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("QtRealPlayDemoClass", "Video Port", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("QtRealPlayDemoClass", "Control Panel", Q_NULLPTR));
        StartButton->setText(QApplication::translate("QtRealPlayDemoClass", "Start", Q_NULLPTR));
        StopButton->setText(QApplication::translate("QtRealPlayDemoClass", "Stop", Q_NULLPTR));
        drawButton->setText(QApplication::translate("QtRealPlayDemoClass", "draw", Q_NULLPTR));
        hangButton->setText(QApplication::translate("QtRealPlayDemoClass", "Hang", Q_NULLPTR));
        talkButton->setText(QApplication::translate("QtRealPlayDemoClass", "talk", Q_NULLPTR));
        RecButton->setText(QApplication::translate("QtRealPlayDemoClass", "StartRecording", Q_NULLPTR));
        unRecBtn->setText(QApplication::translate("QtRealPlayDemoClass", "StopRecording", Q_NULLPTR));
        ReplayBtn->setText(QApplication::translate("QtRealPlayDemoClass", "Replay", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtRealPlayDemoClass: public Ui_QtRealPlayDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTREALPLAYDEMO_H
