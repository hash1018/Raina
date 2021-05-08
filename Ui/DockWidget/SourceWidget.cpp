
#include "SourceWidget.h"
#include <qpainter.h>
#include <./ui_SourceWidget.h>
#include "../NotifyEvent/NotifyEvent.h"
#include "../Base/Scene.h"
#include "../NotifyEvent/ChangeManager.h"
SourceWidget::SourceWidget(QWidget* parent)
	:QWidget(parent), ui(new Ui::SourceWidget),scene(nullptr) {

	ui->setupUi(this);

	connect(ui->addButton, &QPushButton::clicked, this, &SourceWidget::addButtonClicked);
	connect(ui->removeButton, &QPushButton::clicked, this, &SourceWidget::removeButtonClicked);
	connect(ui->moveDownButton, &QPushButton::clicked, this, &SourceWidget::moveDownButtonClicked);
	connect(ui->moveUpButton, &QPushButton::clicked, this, &SourceWidget::moveUpButtonClicked);


	ChangeManager::getInstance()->registerObserver(this);
}

SourceWidget::~SourceWidget() {

	delete ui;
}

void SourceWidget::updateNotifyEvent(NotifyEvent* event) {

	if (event->getEventType() == NotifyEvent::EventType::CurrentSceneChanged) {
	
        this->scene = dynamic_cast<CurrentSceneChangedEvent*>(event)->getScene();

		this->updateList();
	}

}

void SourceWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);

	//painter.fillRect(this->rect(), QColor(0, 0, 55));
}

void SourceWidget::addButtonClicked() {

}

void SourceWidget::removeButtonClicked() {

}

void SourceWidget::moveUpButtonClicked() {

}

void SourceWidget::moveDownButtonClicked() {


}

void SourceWidget::updateList() {

	ui->listWidget->clear();

	if (this->scene == nullptr)
		return;

	ui->listWidget->addItem(this->scene->getName());
}
