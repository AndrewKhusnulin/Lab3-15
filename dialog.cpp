#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);    
    keyShiftB = new QShortcut(this);
    keyShiftB->setKey(Qt::SHIFT + Qt::Key_B);
    connect(keyShiftB, SIGNAL(activated()), this, SLOT(ShortcutShiftB()));
    pushButton_2 = new QPushButton;

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::send(QList<QString> olist)
{
    list = new QList<QString>;
    list = &olist;
    for(int i=0; i<olist.size(); i++)
    {
         ui->listWidget->insertItem(ui->listWidget->count(), olist.at(i));
    }
}

void Dialog::on_pushButton_clicked()
{
    QString findstring;
        findstring=ui->lineEdit->text();
        QListWidgetItem *item;
        QList<QListWidgetItem *> found=ui->listWidget->findItems(findstring,  Qt::MatchContains);
        item = found.at(0);
        ui->listWidget->setItemSelected(item,true);
}

void Dialog::ShortcutShiftB()//Переключение между результатами в поиске
{
    static int a = 1;
    QString findstring;
        findstring=ui->lineEdit->text();
        QListWidgetItem *item;
        QList<QListWidgetItem *> found=ui->listWidget->findItems(findstring,  Qt::MatchContains);
        item = found.at(a);
        ui->listWidget->setItemSelected(item,true);
    if (a+1 == found.size()) a=0; else ++a;
}




