/********************************************************************************
** Form generated from reading UI file 'displaywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYWIDGET_H
#define UI_DISPLAYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayWidget
{
public:
    QLabel *lblStatusDW;
    QLabel *lblRecordingDW;
    QLabel *lblFileNameDW;
    QLineEdit *editFileNameDW;
    QLabel *lblFPSDW;
    QSpinBox *sbDW;
    QCheckBox *cbRecordDW;
    QCheckBox *cbPreserveDW;
    QLabel *lblDisplay;

    void setupUi(QWidget *DisplayWidget)
    {
        if (DisplayWidget->objectName().isEmpty())
            DisplayWidget->setObjectName(QStringLiteral("DisplayWidget"));
        DisplayWidget->resize(498, 500);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DisplayWidget->sizePolicy().hasHeightForWidth());
        DisplayWidget->setSizePolicy(sizePolicy);
        DisplayWidget->setMaximumSize(QSize(498, 500));
        lblStatusDW = new QLabel(DisplayWidget);
        lblStatusDW->setObjectName(QStringLiteral("lblStatusDW"));
        lblStatusDW->setGeometry(QRect(10, 400, 47, 21));
        lblRecordingDW = new QLabel(DisplayWidget);
        lblRecordingDW->setObjectName(QStringLiteral("lblRecordingDW"));
        lblRecordingDW->setGeometry(QRect(60, 400, 71, 21));
        lblFileNameDW = new QLabel(DisplayWidget);
        lblFileNameDW->setObjectName(QStringLiteral("lblFileNameDW"));
        lblFileNameDW->setGeometry(QRect(140, 400, 47, 21));
        editFileNameDW = new QLineEdit(DisplayWidget);
        editFileNameDW->setObjectName(QStringLiteral("editFileNameDW"));
        editFileNameDW->setGeometry(QRect(210, 400, 161, 20));
        lblFPSDW = new QLabel(DisplayWidget);
        lblFPSDW->setObjectName(QStringLiteral("lblFPSDW"));
        lblFPSDW->setGeometry(QRect(390, 400, 31, 21));
        sbDW = new QSpinBox(DisplayWidget);
        sbDW->setObjectName(QStringLiteral("sbDW"));
        sbDW->setGeometry(QRect(430, 400, 42, 22));
        cbRecordDW = new QCheckBox(DisplayWidget);
        cbRecordDW->setObjectName(QStringLiteral("cbRecordDW"));
        cbRecordDW->setGeometry(QRect(190, 450, 70, 17));
        cbPreserveDW = new QCheckBox(DisplayWidget);
        cbPreserveDW->setObjectName(QStringLiteral("cbPreserveDW"));
        cbPreserveDW->setGeometry(QRect(290, 450, 191, 17));
        lblDisplay = new QLabel(DisplayWidget);
        lblDisplay->setObjectName(QStringLiteral("lblDisplay"));
        lblDisplay->setGeometry(QRect(20, 40, 441, 321));

        retranslateUi(DisplayWidget);

        QMetaObject::connectSlotsByName(DisplayWidget);
    } // setupUi

    void retranslateUi(QWidget *DisplayWidget)
    {
        DisplayWidget->setWindowTitle(QApplication::translate("DisplayWidget", "Form", Q_NULLPTR));
        lblStatusDW->setText(QApplication::translate("DisplayWidget", "Status:", Q_NULLPTR));
        lblRecordingDW->setText(QApplication::translate("DisplayWidget", "Not Recording", Q_NULLPTR));
        lblFileNameDW->setText(QApplication::translate("DisplayWidget", "Filename", Q_NULLPTR));
        lblFPSDW->setText(QApplication::translate("DisplayWidget", "FPS", Q_NULLPTR));
        cbRecordDW->setText(QApplication::translate("DisplayWidget", "Record", Q_NULLPTR));
        cbPreserveDW->setText(QApplication::translate("DisplayWidget", "Preserve Aspect Ratio for Display", Q_NULLPTR));
        lblDisplay->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DisplayWidget: public Ui_DisplayWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYWIDGET_H
