#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->load_status->hide();
    ui->load_status->setAutoFillBackground(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_load_button_clicked()
{
    QFont font_10("times",10);
    QPalette palette;
    int error=1; //nothing loaded
    QString dir_path = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                      "/home",
                                                      QFileDialog::ShowDirsOnly
                                                      | QFileDialog::DontResolveSymlinks);
    QSplashScreen *splash=new QSplashScreen(this);
    splash->setPixmap(QPixmap(":/images/1_hi7euM223Sr-9PIi1Pk7ng.png").scaled(632,322));

    splash->show();
    delay(50);
    if(dir_path!="")
        error=2; //dir loaded but doesn't have text files in it
    QDir dir(dir_path);
    QFileInfo file;
    QDirIterator iterator(dir.absolutePath(), QDirIterator::Subdirectories);
    while (iterator.hasNext())
    {
        file.setFile(iterator.next());
        if(file.suffix()=="txt")
        {
            error=0;
            qDebug()<<file.filePath();
        }
    }
    if(error==1)
    {
        ui->load_status->setText("No directory loaded!");
        palette.setColor(QPalette::WindowText,Qt::red);

    }
    else if(error==2)
    {
        ui->load_status->setText("No text files found!");
        palette.setColor(QPalette::WindowText,Qt::red);
    }
    else if(error==0)
    {
        ui->load_status->setText("Directory Loaded Successfully!");
        palette.setColor(QPalette::WindowText,Qt::blue);
    }
    ui->load_status->setFont(font_10);
    ui->load_status->setPalette(palette);
    ui->load_status->show();
    splash->close();
}
void MainWindow::delay(float time)
{
    QTime dieTime= QTime::currentTime().addMSecs(time);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}

