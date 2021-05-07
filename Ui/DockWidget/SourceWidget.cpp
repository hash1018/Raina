
#include "SourceWidget.h"
#include <qpainter.h>
#include <./ui_SourceWidget.h>

SourceWidget::SourceWidget(QWidget* parent)
	:QWidget(parent), ui(new Ui::SourceWidget) {

	ui->setupUi(this);
}

SourceWidget::~SourceWidget() {

	delete ui;
}

void SourceWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);

	painter.fillRect(this->rect(), QColor(0, 0, 55));
}

