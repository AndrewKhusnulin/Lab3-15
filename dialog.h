#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QList>
#include <QShortcut>
#include <QListWidgetItem>


#include "mainwindow.h"

namespace Ui {
class Dialog;
class MainWindow;
}

class Dialog : public QDialog
{
    Q_OBJECT
    QList<QString> * list;
    QList<QListWidgetItem *> founded;
    QMainWindow * mainwindow;


public:
    explicit Dialog(QWidget *parent = 0);
    void send(QList<QString> list);
   // void slotShortcutShiftB();
    ~Dialog();
    Ui::Dialog *ui;
    QShortcut * keyShiftB;  // объект сочетания клавиш
    QPushButton * pushButton_2;
private slots:

    void on_pushButton_clicked();
    void ShortcutShiftB();


};

#endif // DIALOG_H
