
#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include "../Base/LanguageManager.h"
#include "../Chain/RequestStrategyFactory.h"
#include "../Chain/RequestStrategy.h"
#include <qpainter.h>

MainWindow::MainWindow()
    : QMainWindow(nullptr) ,Chain(nullptr)
    , ui(new Ui::MainWindow) {


    ui->setupUi(this);

    ui->sceneDockWidget->setWindowTitle(getLanUiValue("Dock/Scenes"));
    ui->sourceDockWidget->setWindowTitle(getLanUiValue("Dock/Sources"));
    ui->audioMixerDockWidget->setWindowTitle(getLanUiValue("Dock/Audio Mixer"));
    ui->controlDockWidget->setWindowTitle(getLanUiValue("Dock/Control"));


    this->observers.append(ui->sceneWidget);
    this->observers.append(ui->sourceWidget);
    this->observers.append(ui->currentSourceInfoWidget);

    ui->sceneWidget->setChain(this);
    ui->sourceWidget->setChain(this);
    ui->currentSourceInfoWidget->setChain(this);
}

MainWindow::~MainWindow() {

    delete ui;
}

void MainWindow::request(Request* request) {
   
    RequestStrategy* strategy = RequestStrategyFactory::create(this, request);

    if (strategy != nullptr) {
    
        strategy->response();
        delete strategy;
    }
}


void MainWindow::updateNotifyEvent(NotifyEvent* event) {

    for (int i = 0; i < this->observers.size(); i++)
        this->observers.at(i)->updateNotifyEvent(event);
}

void MainWindow::paintEvent(QPaintEvent* event) {

    QPainter painter(this);

    painter.fillRect(this->rect(), QColor("#282828"));
}