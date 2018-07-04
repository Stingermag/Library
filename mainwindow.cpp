#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
#include <QCoreApplication>
#include <QFile>
#include <QTextCodec> // подключение класса кодека текста
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

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

Book book1[4];

void MainWindow::on_pushButton_clicked()
{
    int count = -1,bookcount = 0;
    QString t;
    QString namee;
    QString avtore;


    QString stroch;



    QFile file("C:/Users/koles/Documents/untitled/test.txt");

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
     //  for(int i = 0;i<999;i++)
       {
         //  if(stroch[i] != "\n")

               avtore = stroch;
               avtore.chop(2);

       }
       stroch = file.readLine();
     //  for(int i = count+1;i<999;i++)
       {
          // if(stroch[i] != "\n")
               namee = stroch;
                namee.chop(2);
       }
       stroch = file.readLine();
      // for(int i = count+1;i<999;i++)
       {
          // if(stroch[i] != "\n")
               t = stroch;
                t.chop(2);

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
  //  while (stroch[count+1] != "*" && stroch[count+1] != "\0")


}


//  QString  buffer1 = "4fsd23";

 // QString stroch = ui->textEdit_2->toPlainText();

//  ui->textEdit->insertPlainText(stroch);


/*
QFile fileIn("filein.txt");
   QFile fileOut("fileout.txt");
   if(fileIn.open(QIODevice::ReadOnly) && fileOut.open(QIODevice::WriteOnly))
   { //Если первый файл открыт для чтения, а второй для записи успешн
       QByteArray block = fileIn.read(10); // Считываем 10 байт в массив block из filein.txt
       fileOut.write(block); // Записываем 10 байт в файл fileout.txt
       fileIn.close(); // Закрываем filein.txt
       fileOut.close(); // Закрываем fileout.txt
   }
*/

void MainWindow::on_pushButton_3_clicked()
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

void MainWindow::on_pushButton_4_clicked()
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


