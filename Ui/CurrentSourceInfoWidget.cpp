
#include "CurrentSourceInfoWidget.h"
#include <qpainter.h>
#include "../NotifyEvent/NotifyEvent.h"
#include <./ui_CurrentSourceInfoWidget.h>
#include "../Base/Source.h"

CurrentSourceInfoWidget::CurrentSourceInfoWidget(QWidget* parent, Chain* chain)
	:QWidget(parent), Chain(chain), ui(new Ui::CurrentSourceInfoWidget), source(nullptr) {

	ui->setupUi(this);
}

CurrentSourceInfoWidget::~CurrentSourceInfoWidget() {

	delete ui;
}

void CurrentSourceInfoWidget::updateNotifyEvent(NotifyEvent* event) {

	if (event->getEventType() == NotifyEvent::EventType::CurrentSceneChanged) {
	
		ui->label->setText("");
		ui->label_2->setText("");

		this->source = nullptr;
	}
	else if (event->getEventType() == NotifyEvent::EventType::CurrentSourceChanged) {
	
		this->source = dynamic_cast<CurrentSourceChangedEvent*>(event)->getSource();
		ui->label->setText(source->getName());
	}
}

void CurrentSourceInfoWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);
	painter.fillRect(this->rect(), QColor(166, 166, 166));
}


