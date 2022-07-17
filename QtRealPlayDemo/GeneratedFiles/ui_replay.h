/********************************************************************************
** Form generated from reading UI file 'replay.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLAY_H
#define UI_REPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_replay
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QWidget *reViewer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *playBtn;
    QPushButton *closeBtn;
    QSlider *slider;

    void setupUi(QWidget *replay)
    {
        if (replay->objectName().isEmpty())
            replay->setObjectName(QStringLiteral("replay"));
        replay->resize(572, 419);
        gridLayout = new QGridLayout(replay);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        reViewer = new QWidget(replay);
        reViewer->setObjectName(QStringLiteral("reViewer"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(reViewer->sizePolicy().hasHeightForWidth());
        reViewer->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(reViewer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        playBtn = new QPushButton(replay);
        playBtn->setObjectName(QStringLiteral("playBtn"));

        horizontalLayout->addWidget(playBtn);

        closeBtn = new QPushButton(replay);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));

        horizontalLayout->addWidget(closeBtn);


        verticalLayout->addLayout(horizontalLayout);

        slider = new QSlider(replay);
        slider->setObjectName(QStringLiteral("slider"));
        slider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(slider);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(replay);

        QMetaObject::connectSlotsByName(replay);
    } // setupUi

    void retranslateUi(QWidget *replay)
    {
        replay->setWindowTitle(QApplication::translate("replay", "replay", Q_NULLPTR));
        playBtn->setText(QApplication::translate("replay", "play", Q_NULLPTR));
        closeBtn->setText(QApplication::translate("replay", "close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class replay: public Ui_replay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLAY_H
