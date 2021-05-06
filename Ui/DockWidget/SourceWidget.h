
#ifndef _SOURCEWIDGET_H
#define _SOURCEWIDGET_H

#include <qwidget.h>

class SourceWidget : public QWidget {

public:
	SourceWidget(QWidget* parent = nullptr);
	~SourceWidget();

protected:
	virtual void paintEvent(QPaintEvent* event);

};

#endif //_SOURCEWIDGET_H