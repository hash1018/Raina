
#include "SourceWidget.h"
#include <qpainter.h>
#include <./ui_SourceWidget.h>
#include "../NotifyEvent/NotifyEvent.h"
#include "../Base/Scene.h"
#include "../NotifyEvent/ChangeManager.h"
#include "../Base/Source.h"

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

    this->scene->add(new Source("1"));
    this->updateList();

    int index = this->scene->size() - 1;
    ui->listWidget->setCurrentRow(index);
}

void SourceWidget::removeButtonClicked() {

    int index = ui->listWidget->currentRow();
    if (index == -1)
        return;

    this->scene->remove(this->scene->at(index));
    this->updateList();

    int size = this->scene->size();
    if (size == 0) {
        return;
    }

    if (index < size) {
        ui->listWidget->setCurrentRow(index);
    }
    else {
        ui->listWidget->setCurrentRow(size - 1);
    }

}

void SourceWidget::moveUpButtonClicked() {

    int index = ui->listWidget->currentRow();
    if (index == -1)
        return;

    if (index == 0)
        return;

    this->scene->swap(index, index - 1);
    this->updateList();
    ui->listWidget->setCurrentRow(index - 1);
}

void SourceWidget::moveDownButtonClicked() {

    int index = ui->listWidget->currentRow();
    if (index == -1)
        return;

    if (index == ui->listWidget->count() - 1)
        return;

    this->scene->swap(index, index + 1);
    this->updateList();
    ui->listWidget->setCurrentRow(index + 1);
}

void SourceWidget::updateList() {

	ui->listWidget->clear();

	if (this->scene == nullptr)
		return;

    for(int i=0; i<this->scene->size(); i++)
        ui->listWidget->addItem(this->scene->at(i)->getName());

}
