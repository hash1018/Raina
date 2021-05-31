
#include "SettingDialog.h"
#include <./ui_SettingDialog.h>

SettingDialog::SettingDialog(QWidget* parent)
	:QDialog(parent),ui(new Ui::SettingDialog) {

	ui->setupUi(this);


	ui->comboBox->addItem("123");
	ui->comboBox->addItem("123");
	ui->comboBox->addItem("123");
}

SettingDialog::~SettingDialog() {

	delete ui;
}

