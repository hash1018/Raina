
#ifndef _SCREENWIDGET_H
#define _SCREENWIDGET_H

#include <qwidget.h>

class ScreenWidget : public QWidget {

public:
	ScreenWidget(QWidget* parent = nullptr);
	~ScreenWidget();

protected:
	virtual void paintEvent(QPaintEvent* event);

};

#endif //_SCREENWIDGET_H