
#ifndef _CONTROLWIDGET_H
#define _CONTROLWIDGET_H

#include <qwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui { class ControlWidget; }
QT_END_NAMESPACE

class ControlWidget : public QWidget {

private:
	Ui::ControlWidget* ui;

public:
	ControlWidget(QWidget* parent = nullptr);
	~ControlWidget();

protected:
	virtual void paintEvent(QPaintEvent* event);


private slots:
	void settingButtonClicked();

};

#endif //_CONTROLWIDGET_H