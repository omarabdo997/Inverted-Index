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
    tree=BalancedBinaryTree();
    QFont font_10("times",10);
    QPalette palette;
    int error=1; //nothing loaded
    dir_path = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                      "/home",
                                                      QFileDialog::ShowDirsOnly
                                                      | QFileDialog::DontResolveSymlinks);
    QSplashScreen *splash=new QSplashScreen(this);
    splash->setPixmap(QPixmap(":/images/1_hi7euM223Sr-9PIi1Pk7ng.png").scaled(632,322));
    ui->statusbar->showMessage("Building inverted index.....",50);
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
            build_inverted_index(file);
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
        ui->statusbar->showMessage("Done",3000);
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
        if(data[i].isLetterOrNumber())
        {
            current_word+=data[i];
        }
        else
        {
            if(current_word.toLower()==word.toLower())
            {
                data.insert(i,"</b>");
                data.insert(i-word.length(),"<b>");
                i+=7;

            }
            current_word="";
        }


    }
    if(word.toLower()!="" and current_word.toLower()==word.toLower())
    {

        data.insert(data.length()-1-word.length(),"<b>");
        data.push_back("</b>");

    }
}

void MainWindow::build_inverted_index(QFileInfo file_info)
{
    QFile file(file_info.filePath());
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream fileStream(&file);
    QString data=fileStream.readAll();
    QString current_word="";
    for(int i=0;i<data.length();i++)
    {
        if(data[i].isLetterOrNumber())
        {
            current_word+=data[i];
        }
        else
        {
            tree.insert(current_word.toLower(),file_info.baseName());
            current_word="";
        }
    }
    if(current_word!="")
    {
        tree.insert(current_word.toLower(),file_info.baseName());
    }
    file.close();
}


void MainWindow::on_search_button_clicked()
{

    QString searched_word=ui->search_field->text();
    if(searched_word=="" or searched_word==searched)
    {
        return;
    }
    for(int i=0;i<searched_word.size();i++)
    {
        if (not searched_word[i].isLetterOrNumber())
        {
            QMessageBox::information(this,"Search error","You can only search for word with letters and numbers!");
            return;
        }
    }
    ui->document_data->clear();
    ui->documents_list->clear();
    QVector<QString>file_names=tree.get(searched_word);
    for(int i=0;i<file_names.size();i++)
    {
        ui->documents_list->addItem(file_names[i]+".txt");
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
