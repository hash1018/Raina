
#include "SourceWidget.h"
#include <qpainter.h>
#include <./ui_SourceWidget.h>

SourceWidget::SourceWidget(QWidget* parent)
	:QWidget(parent), ui(new Ui::SourceWidget) {

	ui->setupUi(this);

	connect(ui->addButton, &QPushButton::clicked, this, &SourceWidget::addButtonClicked);
	connect(ui->removeButton, &QPushButton::clicked, this, &SourceWidget::removeButtonClicked);
	connect(ui->moveDownButton, &QPushButton::clicked, this, &SourceWidget::moveDownButtonClicked);
	connect(ui->moveUpButton, &QPushButton::clicked, this, &SourceWidget::moveUpButtonClicked);
}

SourceWidget::~SourceWidget() {

	delete ui;
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