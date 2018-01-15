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

void MainWindow::solve()//Вычисления
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
    if (type == 10)//для десятичной
    {
    s = QString::number(c); // Преобразуем результат в строковый вид
    ui->textEdit->setText(s); // Вывести результат в edtC
    list.append(QString::number(a)+choice+QString::number(b)+"="+s);
    }
    if (type == 16)//для шестнадцатеричной
    {
        QString hexa;
        hexa.setNum((uint)c,16);
        ui->textEdit->setText(hexa);
        list.append(QString::number(a)+choice+QString::number(b)+"="+hexa);
    }
    if (type == 8)//для восмеричной
    {
        QString hexa;
        hexa.setNum((uint)c,8);
        ui->textEdit->setText(hexa);
        list.append(QString::number(a)+choice+QString::number(b)+"="+hexa);
    }
    if ((choice == "/") && (b == 0))
    ui->textEdit->setText("Нельзя делить на ноль!(Можно)");
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
//Для мгновенного расчета для a , b и окно подсчета
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
    if (QMessageBox::Yes == QMessageBox::question(this, "Калькулятор",
                          "Желаете выйти?",
                          QMessageBox::Yes|QMessageBox::No))
    {
    event->accept();
    }

}

void MainWindow::on_pushButton_2_clicked()
{
       Dialog * dialog = new Dialog;
       dialog->setAttribute(Qt::WA_DeleteOnClose, true);
       dialog->show();
       dialog->send(list);
}

  void MainWindow::set(int oa, int ob, QString ochoice)
  {
      ui->spinBox1->setValue(oa);
      ui->spinBox1->setValue(ob);
      choice = ochoice;
      solve();
  }

  void MainWindow::receive()
  {
       ui->textEdit->setText("Dude!");
  }
