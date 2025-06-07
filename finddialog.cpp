#include "finddialog.h"
#include "ui_finddialog.h"

findDialog::findDialog(QTextEdit *textEdit, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::findDialog), m_textEdit(textEdit)
{
    ui->setupUi(this);
}

findDialog::~findDialog()
{
    delete ui;
}

void findDialog::on_pushButton_clicked()
{
    QString searchTerm = ui->lineEdit->text();
    //
    // accept();
    QTextDocument *document = m_textEdit->document();

    bool found = false;

    // undo previous change (if any)
    document->undo();

    if (searchTerm.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search Field"),
                                 tr("The search field is empty. "
                                    "Please enter a word and click Find."));
    } else {
        QTextCursor highlightCursor(document);
        QTextCursor cursor(document);

        cursor.beginEditBlock();

        QTextCharFormat plainFormat(highlightCursor.charFormat());
        QTextCharFormat colorFormat = plainFormat;
        colorFormat.setForeground(Qt::red);

        while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
            highlightCursor = document->find(searchTerm, highlightCursor,
                                             QTextDocument::FindWholeWords);

            if (!highlightCursor.isNull()) {
                found = true;
                highlightCursor.movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor.mergeCharFormat(colorFormat);
            }
        }

        cursor.endEditBlock();
        if (found == false) {
            QMessageBox::information(this, tr("Word Not Found"),
                                     tr("Sorry, the word cannot be found."));
        }
    }
}

