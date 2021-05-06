
#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {


    ui->setupUi(this);

    ui->sceneDockWidget->setWindowTitle("Scene");
    ui->sourceDockWidget->setWindowTitle("Source");
    ui->audioMixerDockWidget->setWindowTitle("Audio Mixer");
    
}

MainWindow::~MainWindow() {

    delete ui;
}

