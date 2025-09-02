/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_findDialog
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *findDialog)
    {
        if (findDialog->objectName().isEmpty())
            findDialog->setObjectName("findDialog");
        findDialog->resize(311, 164);
        label = new QLabel(findDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 91, 21));
        lineEdit = new QLineEdit(findDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(150, 20, 113, 24));
        pushButton = new QPushButton(findDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 80, 80, 24));

        retranslateUi(findDialog);

        QMetaObject::connectSlotsByName(findDialog);
    } // setupUi

    void retranslateUi(QDialog *findDialog)
    {
        findDialog->setWindowTitle(QCoreApplication::translate("findDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("findDialog", "Enter search term", nullptr));
        pushButton->setText(QCoreApplication::translate("findDialog", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class findDialog: public Ui_findDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
