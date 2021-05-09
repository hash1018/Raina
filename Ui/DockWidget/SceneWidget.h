
#ifndef _SCENEWIDGET_H
#define _SCENEWIDGET_H

#include <qwidget.h>
#include "../Chain/Chain.h"
#include "../NotifyEvent/Observer.h"
#include <qlist.h>

QT_BEGIN_NAMESPACE
namespace Ui { class SceneWidget; }
QT_END_NAMESPACE

class Scene;

class SceneWidget : public QWidget, public Chain, public Observer {

private:
	Ui::SceneWidget* ui;

private:
	QList<const Scene*> list;

public:
	SceneWidget(QWidget* parent = nullptr, Chain* chain = nullptr);
	~SceneWidget();

	virtual void updateNotifyEvent(NotifyEvent* event);
	
private:
	void updateList();

protected:
	virtual void paintEvent(QPaintEvent* event);

private slots:
	void addButtonClicked();
	void removeButtonClicked();
	void moveUpButtonClicked();
	void moveDownButtonClicked();
	void listCurrentRowChanged(int row);

};

#endif //_SCENEWIDGET_H