

#include "SceneWidget.h"
#include <qpainter.h>

SceneWidget::SceneWidget(QWidget* parent)
	:QWidget(parent) {

}

SceneWidget::~SceneWidget() {


}

void SceneWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);

	painter.fillRect(this->rect(), QColor(123, 123, 123));
}