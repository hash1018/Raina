

#include "SceneWidget.h"
#include <qpainter.h>
#include <./ui_SceneWidget.h>
#include "../Base/RainaCore.h"
#include "../Base/Scene.h"
#include "../NotifyEvent/NotifyEvent.h"


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


}


void SceneWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);
}

void SceneWidget::updateList() {

	disconnect(ui->listWidget, &QListWidget::currentRowChanged, this, &SceneWidget::listCurrentRowChanged);

	ui->listWidget->clear();

	int size = RainaCore::getInstance()->getSceneManager()->size();

	for (int i = 0; i < size; i++) {
	
		ui->listWidget->addItem(RainaCore::getInstance()->getSceneManager()->at(i)->getName());
	}

	connect(ui->listWidget, &QListWidget::currentRowChanged, this, &SceneWidget::listCurrentRowChanged);
}


void SceneWidget::addButtonClicked() {

	RainaCore::getInstance()->getSceneManager()->add(new Scene(""));
	this->updateList();

	int index = RainaCore::getInstance()->getSceneManager()->size() - 1;
	ui->listWidget->setCurrentRow(index);
	
	//CurrentSceneChangedEvent event(RainaCore::getInstance()->getSceneManager()->at(index));
	//ChangeManager::getInstance()->updateNotifyEvent(&event);
}

void SceneWidget::removeButtonClicked() {

	int index = ui->listWidget->currentRow();
	if (index == -1)
		return;

	RainaCore::getInstance()->getSceneManager()->remove(RainaCore::getInstance()->getSceneManager()->at(index));
	this->updateList();

	int size = RainaCore::getInstance()->getSceneManager()->size();
	if (size == 0) {

	//	CurrentSceneChangedEvent event(nullptr);
	//	ChangeManager::getInstance()->updateNotifyEvent(&event);

		return;
	}

	if (index < size) {
		ui->listWidget->setCurrentRow(index);

	//	CurrentSceneChangedEvent event(RainaCore::getInstance()->getSceneManager()->at(index));
	//	ChangeManager::getInstance()->updateNotifyEvent(&event);
	}
	else {
		ui->listWidget->setCurrentRow(size - 1);

	//	CurrentSceneChangedEvent event(RainaCore::getInstance()->getSceneManager()->at(size - 1));
	//	ChangeManager::getInstance()->updateNotifyEvent(&event);
	}

	
}

void SceneWidget::moveUpButtonClicked() {

	int index = ui->listWidget->currentRow();
	if (index == -1)
		return;

	if (index == 0)
		return;

	RainaCore::getInstance()->getSceneManager()->swap(index, index - 1);
	this->updateList();
	ui->listWidget->setCurrentRow(index - 1);

	//CurrentSceneChangedEvent event(RainaCore::getInstance()->getSceneManager()->at(index - 1));
	//ChangeManager::getInstance()->updateNotifyEvent(&event);
}

void SceneWidget::moveDownButtonClicked() {

	int index = ui->listWidget->currentRow();
	if (index == -1)
		return;

	if (index == ui->listWidget->count() - 1)
		return;

	RainaCore::getInstance()->getSceneManager()->swap(index, index + 1);
	this->updateList();
	ui->listWidget->setCurrentRow(index + 1);

	//CurrentSceneChangedEvent event(RainaCore::getInstance()->getSceneManager()->at(index + 1));
	//ChangeManager::getInstance()->updateNotifyEvent(&event);
}

void SceneWidget::listCurrentRowChanged(int row) {

	//CurrentSceneChangedEvent event(RainaCore::getInstance()->getSceneManager()->at(row));
	//ChangeManager::getInstance()->updateNotifyEvent(&event);
}