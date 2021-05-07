
#include "ControlWidget.h"
#include <qpainter.h>
#include <./ui_ControlWidget.h>

ControlWidget::ControlWidget(QWidget* parent)
	:QWidget(parent), ui(new Ui::ControlWidget) {

	ui->setupUi(this);
}

ControlWidget::~ControlWidget() {

	delete ui;
}

void ControlWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);

	painter.fillRect(this->rect(), QColor(77, 77, 77));
}