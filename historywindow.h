#ifndef HISTORYWINDOW_H
#define HISTORYWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QMessageBox>
#inclide <QDialog>

namespace Uih {
class HistoryWindow;
}

class HistoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryWindow(QWidget *parent = 0);
    ~HistoryWindow();

private slots:

private:
    Uih::HistoryWindow *uih;
};

#endif
