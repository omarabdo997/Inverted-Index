#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDirIterator>
#include <QDebug>
#include <QPalette>
#include <QSplashScreen>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_load_button_clicked();

private:
    Ui::MainWindow *ui;
    void delay(float time);
};
#endif // MAINWINDOW_H
