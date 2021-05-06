
#include "SourceWidget.h"
#include <qpainter.h>

SourceWidget::SourceWidget(QWidget* parent)
	:QWidget(parent) {

}

SourceWidget::~SourceWidget() {

}

void SourceWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);

	painter.fillRect(this->rect(), QColor(0, 0, 55));
}

