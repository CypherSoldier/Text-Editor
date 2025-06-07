#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QPushButton>  // Add this
#include <QTextEdit>    // Add this
#include <QLineEdit>    // Add this
#include <QMessageBox>  // For QMessageBox in .cpp

namespace Ui {
class findDialog;
}

class findDialog : public QDialog
{
    Q_OBJECT

public:
    explicit findDialog(QTextEdit *textEdit, QWidget *parent = nullptr);
    ~findDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::findDialog *ui;
    QTextEdit *m_textEdit;
};

#endif // FINDDIALOG_H
