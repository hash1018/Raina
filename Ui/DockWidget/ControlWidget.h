
#ifndef _CONTROLWIDGET_H
#define _CONTROLWIDGET_H

#include <qwidget.h>

class ControlWidget : public QWidget {

public:
	ControlWidget(QWidget* parent = nullptr);
	~ControlWidget();

protected:
	virtual void paintEvent(QPaintEvent* event);

};

#endif //_CONTROLWIDGET_H