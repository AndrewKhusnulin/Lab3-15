#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#include <QList>

#include "dialog.h"

namespace Ui {
class MainWindow;
class Dialog;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int type;
    int a;
    int b;
    bool imediatly;
    QString choice;
    QList<QString> list;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void set(int oa, int ob, QString ochoice);

private slots:


    void on_pushButton_clicked();

    void on_radioButton_clicked(bool checked);

    void on_radioButton_2_clicked(bool checked);

    void on_radioButton_3_clicked(bool checked);

    void on_checkBox_clicked(bool checked);

    void on_spinBox1_valueChanged(int arg1);

    void on_spinBox2_valueChanged(int arg1);

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void receive();


private:
    Ui::MainWindow *ui;
    void solve();
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
