#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
#include <QCoreApplication>
#include <QFile>
#include<QTextStream>
#include <QTextCodec> // подключение класса кодека текста
#include "mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
int bookcount = 0;
class Book
{
  public:
    QString Year;
    QString NameAvtor;
    QString BookName;
  public:
    void Reading(QString name,QString t,QString avtor)
    {
     Year = t;
     NameAvtor = avtor;
     BookName = name;
    }
    QString YearViv()
    {
        return Year;
    }
    QString NameViv()
    {
        return BookName;
    }
    QString AvtorrViv()
    {
        return NameAvtor;
    }
};
MainWindow::~MainWindow()
{
    delete ui;
}

Book book1[20];

void MainWindow::on_pushButton_clicked()
{
    int count = -1;
    QString t;
    QString namee;
    QString avtore;
    QString stroch;
    QFile file("D:/Library/test.txt");

    if(!file.open(QIODevice::ReadOnly))
    {
        ui->textEdit->insertPlainText("не открылось\n");
    }
    else
    {
     ui->textEdit->setText("\0");
     ui->textEdit_2->setText("\0");
     ui->textEdit_3->setText("\0");
     while(!file.atEnd())
     {
       stroch = file.readLine();
       {
       {
               avtore = stroch;
               avtore.chop(1);
       }
       stroch = file.readLine(); 
       {
               namee = stroch;
                namee.chop(1);
       }
       stroch = file.readLine();     
       {     
               t = stroch;
                t.chop(1);
       }
           book1[bookcount].Reading(namee,t,avtore);
           namee = "";
           t = "";
           avtore = "";
          bookcount++;
       }
     ui->textEdit->insertPlainText(book1[bookcount-1].AvtorrViv());
         ui->textEdit->insertPlainText("\t");
           ui->textEdit->insertPlainText(book1[bookcount-1].NameViv());
            ui->textEdit->insertPlainText("\t");
             ui->textEdit->insertPlainText(book1[bookcount-1].YearViv());
                ui->textEdit->insertPlainText("\n");
     }
    }
}



void MainWindow::on_pushButton_3_clicked()   // кнопка поиска по автору
{
    ui->textEdit->setText("\0");
    QString stroch = ui->textEdit_2->toPlainText();

    for(int i =0;i<4;i++)
    {
        if(book1[i].NameAvtor == stroch)
        {
            ui->textEdit->insertPlainText(book1[i].AvtorrViv());
                ui->textEdit->insertPlainText("\t");
                  ui->textEdit->insertPlainText(book1[i].NameViv());
                    ui->textEdit->insertPlainText("\t");
                    ui->textEdit->insertPlainText(book1[i].YearViv());
                       ui->textEdit->insertPlainText("\n");
        }
    }

}

void MainWindow::on_pushButton_4_clicked()  // кнопка поиска по назвванию
{
    ui->textEdit->setText("\0");

    QString stroch = ui->textEdit_3->toPlainText();

    for(int i =0;i<4;i++)
    {
        if(book1[i].BookName == stroch)
        {
            ui->textEdit->insertPlainText(book1[i].AvtorrViv());
                ui->textEdit->insertPlainText("\t");
                  ui->textEdit->insertPlainText(book1[i].NameViv());
                    ui->textEdit->insertPlainText("\t");
                    ui->textEdit->insertPlainText(book1[i].YearViv());
        }
    }

}



void MainWindow::on_pushButton_5_clicked()   // кнопка добавления книг
{

     QString Avtor = ui->textEdit_4->toPlainText();
     QString Name = ui->textEdit_5->toPlainText();
     QString Year = ui->textEdit_6->toPlainText();
//     Avtor.chop(2);
  //   Name.chop(2);
    // Year.chop(2);

    book1[bookcount++].Reading(Avtor,Name,Year);


    ui->textEdit->insertPlainText(book1[bookcount-1].NameAvtor);
        ui->textEdit->insertPlainText("\t");
          ui->textEdit->insertPlainText(book1[bookcount-1].BookName);
            ui->textEdit->insertPlainText("\t");
            ui->textEdit->insertPlainText(book1[bookcount-1].Year);
             ui->textEdit->insertPlainText("\n");

}

void MainWindow::on_pushButton_6_clicked()   //кнопка поиска по дате
{
     ui->textEdit->setText("\0");

    QString date1,date2;

    int datee1,datee2;
    int datee11;


    date1 = ui->textEdit_7->toPlainText();
    date2 = ui->textEdit_8->toPlainText();

    datee1 = date1.toInt();
    datee11 = date2.toInt();

for(int i = 0;i<20;i++)
{
    datee2 = book1[i].Year.toInt();

    if(datee1 <= datee2 &&  datee11 >= datee2)
    {
        ui->textEdit->insertPlainText(book1[i].NameAvtor);
            ui->textEdit->insertPlainText("\t");
              ui->textEdit->insertPlainText(book1[i].BookName);
                ui->textEdit->insertPlainText("\t");
                ui->textEdit->insertPlainText(book1[i].Year);
                 ui->textEdit->insertPlainText("\n");


    }

}



}

void MainWindow::on_pushButton_7_clicked()
{



    QString  stroch = ui->textEdit_9->toPlainText();
//    stroch.chop(2);
//    QStringList strList;
//    /*Считываем исходный файл в контейнер*/

//    if(!file.open(QIODevice::ReadOnly))
//    {
//        ui->textEdit->insertPlainText("не открылось\n");
//    }
//    else
//    {
//        while(!file.atEnd())
//        {
//        strList << file.readLine();
//        //strList[count].chop(1);
//        count++;
//        }
//        file.close();
//    }
    int indicator=0;
    for(int i=0;i<bookcount;i++)
    {
       // if(strList[i]==stroch)
        if(book1[i].NameAvtor==stroch)
        {
            indicator=1;
            for(int j=i;j<bookcount;j++)
            {
                book1[j]=book1[j+1];
            }
            bookcount--;
            //strList.removeAt(ind_del);
        }
    }

    if(indicator==1)
    {
     QFile file("D:/Library/test.txt");
    if ((file.exists())&&(file.open(QIODevice::WriteOnly)))
    {
        QTextStream stream(&file);
        //foreach(QString s, strList)
        for(int i=0;i<bookcount;i++)
        {
            QString stroch1=book1[i].AvtorrViv();
            QString stroch2=book1[i].NameViv();
            QString stroch3=book1[i].YearViv();
            stream<<stroch1<<"\n"<<stroch2<<"\n"<<stroch3<<"\n";
        }
       // stream<<book1[1].Year;
        file.close();




    }
    }

}


void MainWindow::on_pushButton_8_clicked()
{
    QString  stroch = ui->textEdit_10->toPlainText();
    int indicator=0;
    for(int i=0;i<bookcount;i++)
    {

        if(book1[i].BookName==stroch)
        {
            indicator=1;
            for(int j=i;j<bookcount;j++)
            {
                book1[j]=book1[j+1];
            }
            bookcount--;
        }
    }
    if(indicator==1)
    {
     QFile file("D:/Library/test.txt");
    if ((file.exists())&&(file.open(QIODevice::WriteOnly)))
    {
        QTextStream stream(&file);

        for(int i=0;i<bookcount;i++)
        {
            QString stroch1=book1[i].AvtorrViv();
            QString stroch2=book1[i].NameViv();
            QString stroch3=book1[i].YearViv();
            stream<<stroch1<<"\n"<<stroch2<<"\n"<<stroch3<<"\n";
        }
        file.close();
    }
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    QString  stroch = ui->textEdit_11->toPlainText();
    QString  s_change=ui->textEdit_12->toPlainText();
    int indicator=0;
    for(int i=0;i<bookcount;i++)
    {
        QString s_compare_tec=book1[i].AvtorrViv();
        if(s_compare_tec==stroch)
        {
            indicator=1;
            book1[i].NameAvtor=s_change;

        }
    }
    if(indicator==1)
    {
     QFile file("D:/Library/test.txt");
    if ((file.exists())&&(file.open(QIODevice::WriteOnly)))
    {
        QTextStream stream(&file);

        for(int i=0;i<bookcount;i++)
        {
            QString stroch1=book1[i].AvtorrViv();
            QString stroch2=book1[i].NameViv();
            QString stroch3=book1[i].YearViv();
            stream<<stroch1<<"\n"<<stroch2<<"\n"<<stroch3<<"\n";
        }
        file.close();
    }
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    QString  stroch = ui->textEdit_13->toPlainText();
    QString  s_change=ui->textEdit_14->toPlainText();
    int indicator=0;
    for(int i=0;i<bookcount;i++)
    {
        QString s_compare_tec=book1[i].NameViv();
        if(s_compare_tec==stroch)
        {
            indicator=1;
            book1[i].BookName=s_change;

        }
    }
    if(indicator==1)
    {
     QFile file("D:/Library/test.txt");
    if ((file.exists())&&(file.open(QIODevice::WriteOnly)))
    {
        QTextStream stream(&file);

        for(int i=0;i<bookcount;i++)
        {
            QString stroch1=book1[i].AvtorrViv();
            QString stroch2=book1[i].NameViv();
            QString stroch3=book1[i].YearViv();
            stream<<stroch1<<"\n"<<stroch2<<"\n"<<stroch3<<"\n";
        }
        file.close();
    }
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    QString  stroch = ui->textEdit_15->toPlainText();
    QString  s_change=ui->textEdit_16->toPlainText();
    int indicator=0;
    for(int i=0;i<bookcount;i++)
    {
        QString s_compare_tec=book1[i].YearViv();
        if(s_compare_tec==stroch)
        {
            indicator=1;
            book1[i].Year=s_change;

        }
    }
    if(indicator==1)
    {
     QFile file("D:/Library/test.txt");
    if ((file.exists())&&(file.open(QIODevice::WriteOnly)))
    {
        QTextStream stream(&file);

        for(int i=0;i<bookcount;i++)
        {
            QString stroch1=book1[i].AvtorrViv();
            QString stroch2=book1[i].NameViv();
            QString stroch3=book1[i].YearViv();
            stream<<stroch1<<"\n"<<stroch2<<"\n"<<stroch3<<"\n";
        }
        file.close();
    }
    }
}

void MainWindow::on_action_triggered()
{
    QMessageBox::warning(this,"gfergtrg","lol");
}
