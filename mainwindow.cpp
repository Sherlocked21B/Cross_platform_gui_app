#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstnum;
bool multriggered=false;
bool dividetriggered=false;
bool plustriggered=false;
bool minustriggered=false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digitpressed()));
        connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digitpressed()));
        connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digitpressed()));
        connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digitpressed()));
        connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digitpressed()));
        connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digitpressed()));
        connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digitpressed()));
        connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digitpressed()));
        connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digitpressed()));
        connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digitpressed()));

       connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(operatorpressed()));
       connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(operatorpressed()));
       connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(operatorpressed()));
       connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(operatorpressed()));

       connect(ui->pushButton_equalsto,SIGNAL(released()),this,SLOT(equaltopressed()));

    }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::digitpressed()
{
    QPushButton *button = (QPushButton *)sender();
    QString text= ui->display->text();
    QString buttontext=button->text();
    if(text=="0.0"){
    ui->display->setText(buttontext);
    }
    else {
        ui->display->setText(text+buttontext);
    }

}

void MainWindow::operatorpressed()
{
    QPushButton *operatorbutton = (QPushButton *)sender();
    QString displaynum = ui->display->text();
    QString butsymbol = operatorbutton->text();
    firstnum = displaynum.toDouble();

    multriggered=false;
    dividetriggered=false;
    plustriggered=false;
    minustriggered=false;

    if (QString::compare(butsymbol,"*",Qt::CaseInsensitive)==0){
        multriggered=true;
    }
    else if (QString::compare(butsymbol,"/",Qt::CaseInsensitive)==0){
        dividetriggered=true;
     }
    else if (QString::compare(butsymbol,"+",Qt::CaseInsensitive)==0){
        plustriggered=true;
     }
    else if (QString::compare(butsymbol,"-",Qt::CaseInsensitive)==0){
        minustriggered=true;
     }
    ui->display->setText("");

}
void MainWindow::equaltopressed()
{
    double answer=0.0;
    QPushButton *operatorbutton = (QPushButton *)sender();

    QString seconddisplaynum= ui->display->text();

    double secondnum = seconddisplaynum.toDouble();

    if (multriggered)
    {
        answer=firstnum * secondnum;
    }
    else if (dividetriggered)
    {
        answer=firstnum / secondnum;
    }
    else if (plustriggered)
    {
        answer=firstnum + secondnum;
    }
    else if (minustriggered)
    {
        answer= firstnum - secondnum;
    }

       ui->display->setText(QString::number(answer));

}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->display->setText("0.0");
}


void MainWindow::on_change_sign_clicked()
{
    QString item= ui->display->text();
    double itemval=item.toDouble();
    itemval=itemval*(-1.0);
    ui->display->setText(QString::number(itemval));
}

void MainWindow::on_Delete_clicked()
{
    QString item= ui->display->text();
    item.remove(item.size()-1,item.size()-1);
    ui->display->setText(item);
}

void MainWindow::on_pushButton_equalsto_2_clicked()
{

    QString item= ui->display->text();
     ui->display->setText(item+".");

}


void MainWindow::on_pushButton_AC_2_clicked()
{
    con =new converter(this);
    con->show();
}
