#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->directory_lineEdit->setText("H:/3rd comp/Inverted Index/questions/");
    ui->progressBar->hide();
    ui->textEdit->setReadOnly(true);
    /*ui->textEdit->setTextColor(QColorConstants::Blue);
    ui->textEdit->append("document :: 0.txt");
    ui->textEdit->setTextColor(QColorConstants::Black);
    ui->textEdit->append("");
    ui->textEdit->append("hi");
    ui->textEdit->append("");
    ui->textEdit->setTextColor(QColorConstants::Blue);
    ui->textEdit->append("document :: 65515.txt");
    ui->textEdit->setTextColor(QColorConstants::Black);
    ui->textEdit->append("");
    ui->textEdit->append("hi");
    ui->textEdit->append("");*/
    //    ui->textEdit->insertPlainText("hello ");
    //    ui->textEdit->setFontUnderline(true);
    //    ui->textEdit->setFontWeight(99);
    //    ui->textEdit->insertPlainText("Adham");
    //    ui->textEdit->setFontUnderline(false);
    //    ui->textEdit->setFontWeight(50);
    //    ui->textEdit->insertPlainText(" Hesham");

    /*QString line = "the process is the mohamed theme the";
    QString word = "the";
    QString test="What are the laws to change your status from a student visa to a green card in the US, how do they compare to the immigration laws in Canada?";
    int x = 0,y,start=0;
    while(1)
    {
        y = line.indexOf(word,start);
        if(y==0 && (line[word.size()]==' '||line[word.size()]=='?'||line[word.size()]==','||line[word.size()]=='.'||line[word.size()]==':'))
        {
            ui->textEdit->setFontUnderline(true);
            ui->textEdit->setFontWeight(99);
            ui->textEdit->insertPlainText(word);
            ui->textEdit->setFontUnderline(false);
            ui->textEdit->setFontWeight(50);
            x=y+word.size();
            start=x;
        }
        else if(y!=-1 && (line[y+word.size()]==' '||line[y+word.size()]=='?'||line[y+word.size()]==','||line[y+word.size()]=='.'||line[y+word.size()]==':')
                      && (line[y-1]==' '||line[y-1]=='?'||line[y-1]==','||line[y-1]=='.'||line[y-1]==':'))
        {
            ui->textEdit->insertPlainText(line.mid(x,y-x));
            ui->textEdit->setFontUnderline(true);
            ui->textEdit->setFontWeight(99);
            ui->textEdit->insertPlainText(word);
            ui->textEdit->setFontUnderline(false);
            ui->textEdit->setFontWeight(50);
            x=y+word.size();
            start=x;
        }
        else if(y==line.size()-word.size() && (line[y-1]==' '||line[y-1]=='?'||line[y-1]==','||line[y-1]=='.'||line[y-1]==':'))
        {
            ui->textEdit->insertPlainText(line.mid(x,y-x));
            ui->textEdit->setFontUnderline(true);
            ui->textEdit->setFontWeight(99);
            ui->textEdit->insertPlainText(word);
            ui->textEdit->setFontUnderline(false);
            ui->textEdit->setFontWeight(50);
            x=y+word.size();
            start=x;
        }
        else if(y==-1)
        {
            break;
        }
        else
        {
            start=y+word.size();
        }
    }*/

    /*int x = 0 ,y = 0;
    if(line.left(word.size()+1)==word+" ")
    {
        ui->textEdit->setFontUnderline(true);
        ui->textEdit->setFontWeight(99);
        ui->textEdit->insertPlainText(word);
        ui->textEdit->setFontUnderline(false);
        ui->textEdit->setFontWeight(50);
        ui->textEdit->insertPlainText(" ");
        x=y+word.size()+1;
    }
    while(1)
    {
        y = line.indexOf(" " + word + " ",x);
        if(y!=-1)
        {
            ui->textEdit->insertPlainText(" ");
            ui->textEdit->insertPlainText(line.mid(x,y-x+1));
            ui->textEdit->setFontUnderline(true);
            ui->textEdit->setFontWeight(99);
            ui->textEdit->insertPlainText(word);
            ui->textEdit->setFontUnderline(false);
            ui->textEdit->setFontWeight(50);
            ui->textEdit->insertPlainText(" ");
            x=y+word.size()+2;
        }
        else
        {
            break;
        }
    }
    if(line.right(word.size()+1)==" " +word)
    {
        ui->textEdit->insertPlainText(line.mid(x,y-x+1));
        ui->textEdit->setFontUnderline(true);
        ui->textEdit->setFontWeight(99);
        ui->textEdit->insertPlainText(word);
        ui->textEdit->setFontUnderline(false);
        ui->textEdit->setFontWeight(50);
    }*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

//tree myTree;
QString dir;
QStringList file_names;

void MainWindow::on_ok_button_clicked()
{
    ui->progressBar->show();
    dir = ui->directory_lineEdit->text();
    QDir directory(dir);
    file_names = directory.entryList(QDir::Files,QDir::Name);
    int files_number = file_names.size();
    /*for (int j=0;j<files_number;j++)
    {
        ui->textEdit->append(file_names[j]);
        ui->progressBar->setValue(j*100/files_number);
    }*/
    for (int i=0;i<files_number;i++)
    {
        QString fileLocation = dir + file_names[i];
        QFile File(fileLocation);
        if (File.open(QIODevice::ReadOnly))
        {
            QTextStream in(&File);
            while (!in.atEnd())
            {
                QString line = in.readLine();         //reads line at a time
                QRegExp rx("(\\ |\\,|\\.|\\:|\\t|\\?)");
                QStringList words=line.split(rx, QString::SkipEmptyParts);   //splits line into words
                for (int j=0;j<words.size();j++)
                {
                    //myTree.insert(words[k],i);
                }
            }
            File.close();
        }
        if(i%200==0)
        {
            ui->progressBar->setValue(i*100/files_number);
            qApp->processEvents();
        }
    }
    ui->progressBar->hide();
    QMessageBox::information(this,"finished","documents are uploaded succesfully");
}

void MainWindow::on_search_button_clicked()
{
    ui->textEdit->clear();
    QString word = ui->search_lineEdit->text();
    QVector <int> indices;
    //indices = myTree.search(word);
    for (int i = 0; i<indices.size(); i++)
    {
        ui->textEdit->setTextColor(QColorConstants::Blue);
        ui->textEdit->append("document :: " + file_names[indices[i]]);
        ui->textEdit->setTextColor(QColorConstants::Black);
        ui->textEdit->append("");
        QString fileLocation = dir + file_names[indices[i]];
        QFile File(fileLocation);
        if (File.open(QIODevice::ReadOnly))
        {
            QTextStream in(&File);
            while (!in.atEnd())
            {
                QString line = in.readLine();         //reads line at a time
                int x = 0,y,start=0;
                while(1)
                {
                    y = line.indexOf(word,start);
                    if(y==0 && (line[word.size()]==' '||line[word.size()]=='?'||line[word.size()]==','||line[word.size()]=='.'||line[word.size()]==':'))
                    {
                        ui->textEdit->setFontUnderline(true);
                        ui->textEdit->setFontWeight(99);
                        ui->textEdit->insertPlainText(word);
                        ui->textEdit->setFontUnderline(false);
                        ui->textEdit->setFontWeight(50);
                        x=y+word.size();
                        start=x;
                    }
                    else if(y!=-1 && (line[y+word.size()]==' '||line[y+word.size()]=='?'||line[y+word.size()]==','||line[y+word.size()]=='.'||line[y+word.size()]==':')
                            && (line[y-1]==' '||line[y-1]=='?'||line[y-1]==','||line[y-1]=='.'||line[y-1]==':'))
                    {
                        ui->textEdit->insertPlainText(line.mid(x,y-x));
                        ui->textEdit->setFontUnderline(true);
                        ui->textEdit->setFontWeight(99);
                        ui->textEdit->insertPlainText(word);
                        ui->textEdit->setFontUnderline(false);
                        ui->textEdit->setFontWeight(50);
                        x=y+word.size();
                        start=x;
                    }
                    else if(y==line.size()-word.size() && (line[y-1]==' '||line[y-1]=='?'||line[y-1]==','||line[y-1]=='.'||line[y-1]==':'))
                    {
                        ui->textEdit->insertPlainText(line.mid(x,y-x));
                        ui->textEdit->setFontUnderline(true);
                        ui->textEdit->setFontWeight(99);
                        ui->textEdit->insertPlainText(word);
                        ui->textEdit->setFontUnderline(false);
                        ui->textEdit->setFontWeight(50);
                        x=y+word.size();
                        start=x;
                    }
                    else if(y==-1)
                    {
                        break;
                    }
                    else
                    {
                        start=y+word.size();
                    }
                }
                /*int x = 0 ,y = 0;
                while(1)
                {
                    y = line.indexOf(word,x);
                    if(y!=-1)
                    {
                        ui->textEdit->insertPlainText(line.mid(x,y-x));
                        ui->textEdit->setFontUnderline(true);
                        ui->textEdit->setFontWeight(99);
                        ui->textEdit->insertPlainText(word);
                        ui->textEdit->setFontUnderline(false);
                        ui->textEdit->setFontWeight(50);
                        x=y+word.size();
                    }
                    else
                    {
                        break;
                    }
                }*/
                /*QStringList words = line.split(" ");  //splits line into words
                line="";
                for (int j=0;j<words.size();j++)
                {
                    if(words[j]==word)
                    {
                        ui->textEdit->setFontUnderline(true);
                        ui->textEdit->setFontWeight(99);
                        ui->textEdit->insertPlainText(words[j]);
                        ui->textEdit->setFontUnderline(false);
                        ui->textEdit->setFontWeight(50);
                    }
                    else
                    {
                        ui->textEdit->insertPlainText(words[j]);
                    }

                }*/
            }
            File.close();
        }
        ui->textEdit->append("");
    }
}
