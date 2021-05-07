
#ifndef _PROPERTYWIDGET_H
#define _PROPERTYWIDGET_H

#include <qwidget.h>

class PropertyWidget : public QWidget {

public:
	PropertyWidget(QWidget* parent = nullptr);
	~PropertyWidget();

protected:
	virtual void paintEvent(QPaintEvent* event);
};

#endif //_PROPERTYWIDGET_H