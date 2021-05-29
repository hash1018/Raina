
#include "ScreenWidget.h"
#include <qpainter.h>

ScreenWidget::ScreenWidget(QWidget* parent)
	:QWidget(parent) {

}

ScreenWidget::~ScreenWidget() {

}

void ScreenWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor("#282828"));
}