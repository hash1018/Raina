

#include "SceneWidget.h"
#include <qpainter.h>
#include <./ui_SceneWidget.h>

SceneWidget::SceneWidget(QWidget* parent)
	:QWidget(parent),ui(new Ui::SceneWidget) {

	ui->setupUi(this);
}

SceneWidget::~SceneWidget() {

	delete ui;
}

void SceneWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);

	
}