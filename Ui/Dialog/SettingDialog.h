

#ifndef _SETTINGDIALOG_H
#define _SETTINGDIALOG_H

#include <qdialog.h>

QT_BEGIN_NAMESPACE
namespace Ui { class SettingDialog; }
QT_END_NAMESPACE

class SettingDialog : public QDialog {

private:
	Ui::SettingDialog* ui;

public:
	SettingDialog(QWidget* parent = nullptr);
	~SettingDialog();



};


#endif //_SETTINGDIALOG_H