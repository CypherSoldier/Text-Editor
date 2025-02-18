#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the Ctrl+O shortcut
    shortcut_open = new QShortcut(QKeySequence(tr("Ctrl+O")), this);
    shortcut_save = new QShortcut(QKeySequence(tr("Ctrl+S")), this);

    // Connect the shortcut's activated signal to the actionOpen slot
    connect(shortcut_open, &QShortcut::activated, this, &MainWindow::on_actionOpen_triggered);
    connect(shortcut_save, &QShortcut::activated, this, &MainWindow::on_actionSave_triggered);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    //shortcut = new QShortcut(QKeySequence(tr("Ctrl+O", "File|Open")), this); // see python pyqt video that was doing the same thing

    QString fileName = QFileDialog::getOpenFileName(this, tr("Select text file"), "", tr("Text files (*.txt)"));

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        file.close();
    } else {
        QMessageBox::warning(this, tr("Error"), tr("Cannot open file: %1").arg(file.errorString()));
    }
}


void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save");

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }
    QTextStream out(&file);

    out << ui->textEdit->toPlainText() << "\n";

    file.close();
}

void MainWindow::on_actionExit_triggered()
{
    QWidget::close();
}

/*
void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select text file"), "", tr("Text files (*.txt)"));

    if (!fileName.isEmpty()) { // Check if a file was selected
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) { // Open the file for reading
            QTextStream in(&file); // Create a QTextStream to read from the file
            QString fileContent = in.readAll(); // Read all contents into a QString
            ui->textEdit->setText(fileContent); // Set the text in the textEdit widget
            file.close(); // Close the file
        } else {
            // Handle error opening the file (optional)
            QMessageBox::warning(this, tr("Error"), tr("Could not open file for reading."));
        }
    }
}
*/

/*
void MainWindow::on_actionNew_triggered()
{
    // 1. Get a file path from the user using a file dialog
    QString filePath = QFileDialog::getSaveFileName(this, "Create a new file",QDir::homePath(), "Text files (*.txt);;All files (*.*)");

    // Check if the user cancelled the dialog
    if (filePath.isEmpty()) {
        return; // User cancelled
    }

    // 2. Create a Qfile object
    QFile file(filePath);

    // 3. Attempt to open the file for writing
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Display an error message box to the user
        QMessageBox::critical(this, "Error", "Could not create file: " + file.errorString());
        return; // Exit the function if the file couldn't be opened
    }

    // 4. Create a text stream to easily write text to the file
    QTextStream out(&file);

    // 5. Write some initial content to the file (optional)
    out << "New file created!\n";

    // 6. Close the file
    file.close();

    // 7. Provide feedback to the user (optional)
    QMessageBox::information(this, "Success", "File created successfully!");
}
*/
