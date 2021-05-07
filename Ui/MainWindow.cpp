
#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "../Base/LanguageManager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {


    ui->setupUi(this);

    ui->sceneDockWidget->setWindowTitle(getLanUiValue("Menu/Video"));
    ui->sourceDockWidget->setWindowTitle("Source");
    ui->audioMixerDockWidget->setWindowTitle("Audio Mixer");
    ui->controlDockWidget->setWindowTitle("Control");
}

MainWindow::~MainWindow() {

    delete ui;
}

