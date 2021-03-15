#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
double numOfElements;
bool userAddedElement = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(released()), this, SLOT(btn_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()), this, SLOT(btn_pressed()));
    
    connect(ui->pushButton_test,SIGNAL(released()), this, SLOT(testAddDelete_operation_pressed()));
    connect(ui->pushButton_start,SIGNAL(released()), this, SLOT(testAddDelete_operation_pressed()));

    connect(ui->pushButton_add,SIGNAL(released()), this, SLOT(addDelete_operation_pressed()));
    connect(ui->pushButton_delete,SIGNAL(released()), this, SLOT(addDelete_operation_pressed()));
    

    ui->pushButton_add->setCheckable(true);
    ui->pushButton_delete->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btn_pressed()
{
    //qDebug() << "test";
    QPushButton* button = (QPushButton*)sender(); 

    double labelNumber;
    QString newLabel;
	
    if((ui->pushButton_addComponent->isChecked() || ui->pushButton_deleteComponent->isChecked())
    {
         labelNumber = button->text().toDouble();
		 userAddedElement = true;
         newLabel = QString::number(labelNumber,'g',15);

    }
    else
    {
        if(ui->label->text().contains('.') && button->text()== "0")
        {
            newLabel = ui->label->text() + button->text();
        }
        else
        {
            labelNumber = (ui->label->text() + button->text()).toDouble(); 
            newLabel = QString::number(labelNumber,'g',15);
        }
    }

    ui->label->setText(newLabel);

}


void MainWindow::testAddDelete_operation_pressed()(){
    QPushButton* button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;

    if(button->text() == "delete")
    {
        labelNumber = ui->label->text().toDouble();  
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
    }
    if(button->text() == "add")
    {
        labelNumber = ui->label->text().toDouble();
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);

    }

}

void MainWindow::on_pushButton_clear_released(){
    ui->label->setText("0");
    ui->pushButton_add->setChecked(false);
    ui->pushButton_delete->setChecked(false);
    userAddedElement = false;

}

void MainWindow::on_pushButton_equals_released(){

    double labelNumber, secondNum;
     QString newLabel;
    secondNum = ui->label->text().toDouble();

    if(ui->pushButton_add->isChecked())
    {
        labelNumber = numOfElements++;		//Count add to cart
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_add->setChecked(false);
    }
    else if(ui->pushButton_delete->isChecked())
    {
        labelNumber = numOfElements--;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_delete->setChecked(false);

    }

    userAddedElement = false;

}
void MainWindow::addDelete_operation_pressed()
{
    QPushButton* button = (QPushButton*)sender();

    numOfElements = ui->label->text().toDouble();
    button->setChecked(true);

}
