//
// Created by dyh on 2024/5/6.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "MainWindow.h"
#include "AzimuthBar.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->widget, &AzimuthBar::onChangeAzimuth);
}

MainWindow::~MainWindow() {
    delete ui;
}
