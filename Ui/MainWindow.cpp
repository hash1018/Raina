
#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "../Base/LanguageManager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {


    ui->setupUi(this);

    ui->sceneDockWidget->setWindowTitle(getLanUiValue("Dock/Scenes"));
    ui->sourceDockWidget->setWindowTitle(getLanUiValue("Dock/Sources"));
    ui->audioMixerDockWidget->setWindowTitle(getLanUiValue("Dock/Audio Mixer"));
    ui->controlDockWidget->setWindowTitle(getLanUiValue("Dock/Control"));
}

MainWindow::~MainWindow() {

    delete ui;
}

