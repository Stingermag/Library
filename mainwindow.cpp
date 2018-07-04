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
    QString Avtor,Name,Year;
     Avtor = ui->textEdit_4->toPlainText();
     Name = ui->textEdit_5->toPlainText();
     Year = ui->textEdit_6->toPlainText();
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
