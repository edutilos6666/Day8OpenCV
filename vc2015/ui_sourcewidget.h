/********************************************************************************
** Form generated from reading UI file 'sourcewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOURCEWIDGET_H
#define UI_SOURCEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SourceWidget
{
public:
    QLabel *lblSWFPS;
    QSpinBox *sbSW;
    QProgressBar *pbSW;
    QPushButton *btnSWChoose;

    void setupUi(QWidget *SourceWidget)
    {
        if (SourceWidget->objectName().isEmpty())
            SourceWidget->setObjectName(QStringLiteral("SourceWidget"));
        SourceWidget->resize(936, 63);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SourceWidget->sizePolicy().hasHeightForWidth());
        SourceWidget->setSizePolicy(sizePolicy);
        SourceWidget->setMaximumSize(QSize(936, 63));
        lblSWFPS = new QLabel(SourceWidget);
        lblSWFPS->setObjectName(QStringLiteral("lblSWFPS"));
        lblSWFPS->setGeometry(QRect(170, 20, 47, 21));
        sbSW = new QSpinBox(SourceWidget);
        sbSW->setObjectName(QStringLiteral("sbSW"));
        sbSW->setGeometry(QRect(230, 20, 61, 22));
        pbSW = new QProgressBar(SourceWidget);
        pbSW->setObjectName(QStringLiteral("pbSW"));
        pbSW->setGeometry(QRect(360, 20, 551, 23));
        pbSW->setValue(0);
        btnSWChoose = new QPushButton(SourceWidget);
        btnSWChoose->setObjectName(QStringLiteral("btnSWChoose"));
        btnSWChoose->setGeometry(QRect(20, 20, 91, 23));

        retranslateUi(SourceWidget);

        QMetaObject::connectSlotsByName(SourceWidget);
    } // setupUi

    void retranslateUi(QWidget *SourceWidget)
    {
        SourceWidget->setWindowTitle(QApplication::translate("SourceWidget", "SourceWidget", Q_NULLPTR));
        lblSWFPS->setText(QApplication::translate("SourceWidget", "FPS:", Q_NULLPTR));
        pbSW->setFormat(QApplication::translate("SourceWidget", " %v|%m", Q_NULLPTR));
        btnSWChoose->setText(QApplication::translate("SourceWidget", "Choose Movie", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SourceWidget: public Ui_SourceWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOURCEWIDGET_H
