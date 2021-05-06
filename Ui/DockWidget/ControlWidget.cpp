
#include "ControlWidget.h"
#include <qpainter.h>

ControlWidget::ControlWidget(QWidget* parent)
	:QWidget(parent) {

}

ControlWidget::~ControlWidget() {

}

void ControlWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);

	painter.fillRect(this->rect(), QColor(77, 77, 77));
}