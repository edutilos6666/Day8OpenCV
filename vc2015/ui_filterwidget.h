/********************************************************************************
** Form generated from reading UI file 'filterwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERWIDGET_H
#define UI_FILTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterWidget
{
public:
    QTableView *tvFilterFW;
    QLabel *lblFilterSizeFW;
    QComboBox *cbFilterSizeFW;
    QCheckBox *cbNFilterFW;
    QCheckBox *cbNOutputFW;

    void setupUi(QWidget *FilterWidget)
    {
        if (FilterWidget->objectName().isEmpty())
            FilterWidget->setObjectName(QStringLiteral("FilterWidget"));
        FilterWidget->resize(381, 500);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FilterWidget->sizePolicy().hasHeightForWidth());
        FilterWidget->setSizePolicy(sizePolicy);
        FilterWidget->setMaximumSize(QSize(381, 500));
        tvFilterFW = new QTableView(FilterWidget);
        tvFilterFW->setObjectName(QStringLiteral("tvFilterFW"));
        tvFilterFW->setGeometry(QRect(20, 10, 341, 291));
        lblFilterSizeFW = new QLabel(FilterWidget);
        lblFilterSizeFW->setObjectName(QStringLiteral("lblFilterSizeFW"));
        lblFilterSizeFW->setGeometry(QRect(30, 370, 71, 16));
        cbFilterSizeFW = new QComboBox(FilterWidget);
        cbFilterSizeFW->setObjectName(QStringLiteral("cbFilterSizeFW"));
        cbFilterSizeFW->setGeometry(QRect(170, 370, 121, 22));
        cbFilterSizeFW->setLayoutDirection(Qt::LeftToRight);
        cbNFilterFW = new QCheckBox(FilterWidget);
        cbNFilterFW->setObjectName(QStringLiteral("cbNFilterFW"));
        cbNFilterFW->setGeometry(QRect(30, 410, 111, 31));
        cbNOutputFW = new QCheckBox(FilterWidget);
        cbNOutputFW->setObjectName(QStringLiteral("cbNOutputFW"));
        cbNOutputFW->setGeometry(QRect(190, 410, 111, 31));

        retranslateUi(FilterWidget);

        QMetaObject::connectSlotsByName(FilterWidget);
    } // setupUi

    void retranslateUi(QWidget *FilterWidget)
    {
        FilterWidget->setWindowTitle(QApplication::translate("FilterWidget", "Form", Q_NULLPTR));
        lblFilterSizeFW->setText(QApplication::translate("FilterWidget", "Filter Size:", Q_NULLPTR));
        cbFilterSizeFW->clear();
        cbFilterSizeFW->insertItems(0, QStringList()
         << QApplication::translate("FilterWidget", "3", Q_NULLPTR)
         << QApplication::translate("FilterWidget", "5", Q_NULLPTR)
         << QApplication::translate("FilterWidget", "7", Q_NULLPTR)
        );
        cbNFilterFW->setText(QApplication::translate("FilterWidget", "Normalize Filter", Q_NULLPTR));
        cbNOutputFW->setText(QApplication::translate("FilterWidget", "Normalize Output", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FilterWidget: public Ui_FilterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERWIDGET_H
