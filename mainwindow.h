#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDirIterator>
#include <QDebug>
#include <QPalette>
#include <QSplashScreen>
#include <QTime>
#include <QListWidgetItem>
#include <QMessageBox>
#include <binarytree.h>

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

    void on_search_button_clicked();

    void on_documents_list_itemDoubleClicked(QListWidgetItem *item);

    void on_actionNew_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    void delay(float time);
    QString dir_path;
    void bold(QString &data,QString word);
    QString searched;
    void build_inverted_index(QFileInfo file_info);
    BinaryTree tree;

};
#endif // MAINWINDOW_H
