
#ifndef _SCENEWIDGET_H
#define _SCENEWIDGET_H

#include <qwidget.h>

class SceneWidget : public QWidget {

public:
	SceneWidget(QWidget* parent = nullptr);
	~SceneWidget();

protected:
	virtual void paintEvent(QPaintEvent* event);

};

#endif //_SCENEWIDGET_H