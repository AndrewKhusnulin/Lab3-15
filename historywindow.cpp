#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a = 0, b = 0, type = 10, imediatly = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    a = ui->spinBox1->value(); // Берем текст edtA и преобразовываем его в число a
    b = ui->spinBox2->value(); // Берем текст edtB и преобразовываем его в число b
    choice = ui->comboBox->currentText();
    this->solve();
}

void MainWindow::solve()
{
    QString s;
    double c;
    if (choice == "+")
        c = a + b; // Складываем числа
    else if (choice == "-")
        c = a - b;
    else if (choice == "*")
        c = a * b;
    else if (choice == "/") {
            if (b != 0)
                c = (double)a/(double)b;
        }
    if (type == 10)
    {
    s = QString::number(c); // Преобразуем результат в строковый вид
    ui->textEdit->setText(s); // Вывести результат в edtC
    }
    if (type == 16)
    {
        QString hexa;
        hexa.setNum((uint)c,16);
        ui->textEdit->setText(hexa);
    }
    if (type == 8)
    {
        QString hexa;
        hexa.setNum((uint)c,8);
        ui->textEdit->setText(hexa);
    }
    if ((choice == "/") && (b == 0))
    ui->textEdit->setText("Dude!");
}

void MainWindow::on_radioButton_clicked(bool checked)
{
    if (checked)
        type = 10;
}

void MainWindow::on_radioButton_2_clicked(bool checked)
{
    if (checked)
        type = 16;
    if ((checked)&&(imediatly))
    {
        type = 16;
        this->solve();
    }
}



void MainWindow::on_radioButton_3_clicked(bool checked)
{
    if (checked)
        type = 8;
    if ((checked)&&(imediatly))
    {
        type = 8;
        this->solve();
    }
}

void MainWindow::on_checkBox_clicked(bool checked)
{
        imediatly = checked;
}

void MainWindow::on_spinBox1_valueChanged(int arg1)
{
    if (imediatly)
    {
        a = ui->spinBox1->value();
        this->solve();
    }
}

void MainWindow::on_spinBox2_valueChanged(int arg1)
{
    if (imediatly)
    {
        b = ui->spinBox2->value();
        this->solve();
    }
}


void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
     choice = ui->comboBox->currentText();
     this->solve();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    if (QMessageBox::Yes == QMessageBox::question(this, "Closed?",
                          "But why?",
                          QMessageBox::Yes|QMessageBox::No))
    {
    event->accept();
    }

}
