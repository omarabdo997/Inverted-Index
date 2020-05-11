#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->load_status->hide();
    ui->load_status->setAutoFillBackground(true);
    ui->documents_list->setFont(QFont("times",12));
    ui->document_data->setFont(QFont("times",12));
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
    dir_path = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                      "/home",
                                                      QFileDialog::ShowDirsOnly
                                                      | QFileDialog::DontResolveSymlinks);
    QSplashScreen *splash=new QSplashScreen(this);
    splash->setPixmap(QPixmap(":/images/1_hi7euM223Sr-9PIi1Pk7ng.png").scaled(632,322));

    splash->show();
    delay(10);
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

void MainWindow::bold(QString &data, QString word)
{
    QString current_word="";
    for(int i=0;i<data.length();i++)
    {
        if(data[i]==" ")
        {
            if(current_word.toLower()==word.toLower())
            {
                data.insert(i,"</b>");
                data.insert(i-word.length(),"<b>");
                i+=7;
                current_word="";
            }
        }
        else
        {
            current_word+=data[i];
        }
    }
}


void MainWindow::on_search_button_clicked()
{
    ui->documents_list->clear();
    for(int i=0;i<10;i++)
    {
        ui->documents_list->addItem(QString::number(i)+".txt");
    }
    searched=ui->search_field->text();
}

void MainWindow::on_documents_list_itemDoubleClicked(QListWidgetItem *item)
{
    QString file_name=item->text();
    QFile file(dir_path+"/"+file_name);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream fileStream(&file);
    QString data=fileStream.readAll();
    bold(data,searched);
    ui->document_data->setText(data);
    file.close();
}
