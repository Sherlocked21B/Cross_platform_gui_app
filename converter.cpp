#include "converter.h"
#include "ui_converter.h"

converter::converter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::converter)
{
    ui->setupUi(this);
    ui->comboBox->addItem("choose to convert");
    ui->comboBox->addItem("dollor to rupees");
    ui->comboBox->addItem("rupees to dollor");
    ui->comboBox->addItem("indian currency to rupees");
    ui->comboBox->addItem("rupee to indian currency ");
    ui->comboBox->addItem("euro to rupees");
    ui->comboBox->addItem("rupees to euro");

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
}

converter::~converter()
{
    delete ui;
}

void converter::digitpressed()
{
    QPushButton *button = (QPushButton *)sender();
    QString text= ui->display_2->text();
    QString buttontext=button->text();
    if(text=="0.0"){
    ui->display_2->setText(buttontext);
    }
    else {
        ui->display_2->setText(text+buttontext);
    }
}

void converter::on_convert_clicked()
{
    double solution;
    QString val = ui->display_2->text();
    double calcval= val.toDouble();
    QString conversion=ui->comboBox->currentText();
    if (QString::compare(conversion,"dollor to rupees",Qt::CaseInsensitive)==0)
    {
        ui->display_2->setText('$'+val);
        solution=calcval*110.61;
        ui->display_3->setText("nrs  "+QString::number(solution));
    }
    if (QString::compare(conversion,"rupees to dollor",Qt::CaseInsensitive)==0)
    {
        ui->display_2->setText("nrs  "+val);
        solution=calcval/110.61;
        ui->display_3->setText("$"+QString::number(solution));
    }
    if (QString::compare(conversion,"indian currency to rupees",Qt::CaseInsensitive)==0)
    {
        ui->display_2->setText("IC  "+val);
        solution=calcval/1.6;
        ui->display_3->setText("nrs  "+QString::number(solution));
    }
    if (QString::compare(conversion,"rupee to indian currency ",Qt::CaseInsensitive)==0)
    {
        ui->display_2->setText("nrs  "+val);
        solution=calcval*1.6;
        ui->display_3->setText("IC  "+QString::number(solution));
    }
    if (QString::compare(conversion,"euro to rupees",Qt::CaseInsensitive)==0)
    {
        ui->display_2->setText("€  "+val);
        solution=calcval*125.05;
        ui->display_3->setText("nrs  "+QString::number(solution));
    }
    if (QString::compare(conversion,"rupees to euro",Qt::CaseInsensitive)==0)
    {
        ui->display_2->setText("nrs  "+val);
        solution=calcval/125.05;
        ui->display_3->setText("€  "+QString::number(solution));
    }
}
