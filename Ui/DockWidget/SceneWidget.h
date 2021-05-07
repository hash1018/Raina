
#ifndef _SCENEWIDGET_H
#define _SCENEWIDGET_H

#include <qwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui { class SceneWidget; }
QT_END_NAMESPACE


class SceneWidget : public QWidget {

private:
	Ui::SceneWidget* ui;

public:
	SceneWidget(QWidget* parent = nullptr);
	~SceneWidget();

protected:
	virtual void paintEvent(QPaintEvent* event);

};

#endif //_SCENEWIDGET_H