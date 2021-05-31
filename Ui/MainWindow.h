
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qlist.h>
#include "../Chain/Chain.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Observer;
class NotifyEvent;

class MainWindow : public QMainWindow, public Chain {

    Q_OBJECT

private:
    Ui::MainWindow* ui;

private:
    QList<Observer*> observers;

public:
    MainWindow();
    ~MainWindow();

    virtual void request(Request* request);
    void updateNotifyEvent(NotifyEvent* event);


protected:
    virtual void paintEvent(QPaintEvent* event);
};


#endif // MAINWINDOW_H
