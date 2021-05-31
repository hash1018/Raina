
#include "ControlWidget.h"
#include <qpainter.h>
#include <./ui_ControlWidget.h>
#include "../Dialog/SettingDialog.h"

ControlWidget::ControlWidget(QWidget* parent)
	:QWidget(parent), ui(new Ui::ControlWidget) {

	ui->setupUi(this);

	connect(ui->settingButton, &QPushButton::clicked, this, &ControlWidget::settingButtonClicked);
}

ControlWidget::~ControlWidget() {

	delete ui;
}

void ControlWidget::paintEvent(QPaintEvent* event) {

	QPainter painter(this);


	painter.fillRect(this->rect(), QColor("#535353"));
}

void ControlWidget::settingButtonClicked() {

	SettingDialog dialog;

	dialog.exec();
}