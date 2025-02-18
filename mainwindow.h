#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QTextEdit>
#include <QFileDialog>
#include <QDir>
#include <QShortcut>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    QShortcut* shortcut_open;
    QShortcut* shortcut_save;
};
#endif // MAINWINDOW_H
