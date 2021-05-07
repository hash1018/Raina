

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

	RainaCore::getInstance()->getSceneManager()->add(new Scene("123123"));
	this->updateList();
}

void SceneWidget::removeButtonClicked() {

}

void SceneWidget::moveUpButtonClicked() {

}

void SceneWidget::moveDownButtonClicked() {


}