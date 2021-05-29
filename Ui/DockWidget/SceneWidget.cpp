

#include "SceneWidget.h"
#include <qpainter.h>
#include <./ui_SceneWidget.h>
#include "../Base/Scene.h"
#include "../NotifyEvent/NotifyEvent.h"
#include "../Chain/Request.h"

SceneWidget::SceneWidget(QWidget* parent, Chain* chain)
	:QWidget(parent), Chain(chain), ui(new Ui::SceneWidget) {

	ui->setupUi(this);

	connect(ui->addButton, &QPushButton::clicked, this, &SceneWidget::addButtonClicked);
	connect(ui->removeButton, &QPushButton::clicked, this, &SceneWidget::removeButtonClicked);
	connect(ui->moveUpButton, &QPushButton::clicked, this, &SceneWidget::moveUpButtonClicked);
	connect(ui->moveDownButton, &QPushButton::clicked, this, &SceneWidget::moveDownButtonClicked);

}

SceneWidget::~SceneWidget() {

	delete ui;
}

void SceneWidget::updateNotifyEvent(NotifyEvent* event) {

	if (event->getEventType() == NotifyEvent::EventType::CurrentSceneChanged) {
	
		CurrentSceneChangedEvent* event2 = dynamic_cast<CurrentSceneChangedEvent*>(event);

		this->list = event2->getList();

		this->updateList();

		int index = this->list.indexOf(event2->getScene());

		disconnect(ui->listWidget, &QListWidget::currentRowChanged, this, &SceneWidget::listCurrentRowChanged);
		ui->listWidget->setCurrentRow(index);
		connect(ui->listWidget, &QListWidget::currentRowChanged, this, &SceneWidget::listCurrentRowChanged);
	}
}


void SceneWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);

	painter.fillRect(this->rect(), QColor("#535353"));
}

void SceneWidget::updateList() {

	disconnect(ui->listWidget, &QListWidget::currentRowChanged, this, &SceneWidget::listCurrentRowChanged);

	ui->listWidget->clear();

	for (int i = 0; i < this->list.size(); i++) {
	
		ui->listWidget->addItem(this->list.at(i)->getName());
	}

	connect(ui->listWidget, &QListWidget::currentRowChanged, this, &SceneWidget::listCurrentRowChanged);
}


void SceneWidget::addButtonClicked() {
	
	RequestChangeScene request("123");
	this->request(&request);
}

void SceneWidget::removeButtonClicked() {

	int index = ui->listWidget->currentRow();
	if (index == -1)
		return;

	RequestChangeScene request(this->list.at(index), RequestChangeScene::ChangeType::Remove);
	this->request(&request);
}

void SceneWidget::moveUpButtonClicked() {

	int index = ui->listWidget->currentRow();
	if (index == -1)
		return;

	if (index == 0)
		return;


	RequestChangeScene request(this->list.at(index), RequestChangeScene::ChangeType::MoveUp);
	this->request(&request);
}

void SceneWidget::moveDownButtonClicked() {

	
	int index = ui->listWidget->currentRow();
	if (index == -1)
		return;

	if (index == ui->listWidget->count() - 1)
		return;

	RequestChangeScene request(this->list.at(index), RequestChangeScene::ChangeType::MoveDown);
	this->request(&request);
}

void SceneWidget::listCurrentRowChanged(int row) {

	if (row == -1)
		return;

	RequestChangeScene request(this->list.at(row), RequestChangeScene::ChangeType::CurrentScene);
	this->request(&request);

}