

#include "SceneWidget.h"
#include <qpainter.h>
#include <./ui_SceneWidget.h>
#include "../Base/RainaCore.h"
#include "../Base/Scene.h"

SceneWidget::SceneWidget(QWidget* parent)
	:QWidget(parent),ui(new Ui::SceneWidget) {

	ui->setupUi(this);

	connect(ui->addButton, &QPushButton::clicked, this, &SceneWidget::addButtonClicked);
	connect(ui->removeButton, &QPushButton::clicked, this, &SceneWidget::removeButtonClicked);
	connect(ui->moveUpButton, &QPushButton::clicked, this, &SceneWidget::moveUpButtonClicked);
	connect(ui->moveDownButton, &QPushButton::clicked, this, &SceneWidget::moveDownButtonClicked);

}

SceneWidget::~SceneWidget() {

	delete ui;
}

void SceneWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);
}

void SceneWidget::updateList() {

	ui->listWidget->clear();

	int size = RainaCore::getInstance()->getSceneManager()->size();

	for (int i = 0; i < size; i++) {
	
		ui->listWidget->addItem(RainaCore::getInstance()->getSceneManager()->at(i)->getName());
	}
}


void SceneWidget::addButtonClicked() {

	RainaCore::getInstance()->getSceneManager()->add(new Scene(""));
	this->updateList();
	ui->listWidget->setCurrentRow(RainaCore::getInstance()->getSceneManager()->size() - 1);
}

void SceneWidget::removeButtonClicked() {

	int index = ui->listWidget->currentRow();
	if (index == -1)
		return;

	RainaCore::getInstance()->getSceneManager()->remove(RainaCore::getInstance()->getSceneManager()->at(index));
	this->updateList();

	int size = RainaCore::getInstance()->getSceneManager()->size();
	if (size == 0)
		return;

	if (index < size)
		ui->listWidget->setCurrentRow(index);
	else
		ui->listWidget->setCurrentRow(size - 1);

	
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
}