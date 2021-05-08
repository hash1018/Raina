
#include "CurrentSourceInfoWidget.h"
#include <qpainter.h>
#include "../NotifyEvent/NotifyEvent.h"
#include "../NotifyEvent/ChangeManager.h"
#include <./ui_CurrentSourceInfoWidget.h>

CurrentSourceInfoWidget::CurrentSourceInfoWidget(QWidget* parent)
	:QWidget(parent), ui(new Ui::CurrentSourceInfoWidget) {


	ui->setupUi(this);

	ChangeManager::getInstance()->registerObserver(this);
}

CurrentSourceInfoWidget::~CurrentSourceInfoWidget() {

}

void CurrentSourceInfoWidget::updateNotfiyEvent(NotifyEvent* event) {

	
}

void CurrentSourceInfoWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(166, 166, 166));
}


