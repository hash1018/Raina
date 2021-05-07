
#include "PropertyWidget.h"
#include <qpainter.h>

PropertyWidget::PropertyWidget(QWidget* parent)
	:QWidget(parent) {
	
}

PropertyWidget::~PropertyWidget() {

}

void PropertyWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(166, 166, 166));
}


