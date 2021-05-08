
#ifndef _SOURCEWIDGET_H
#define _SOURCEWIDGET_H

#include <qwidget.h>
#include "../NotifyEvent/Observer.h"


QT_BEGIN_NAMESPACE
namespace Ui { class SourceWidget; }
QT_END_NAMESPACE

class Scene;

class SourceWidget : public QWidget, public Observer {

private:
	Ui::SourceWidget* ui;

private:
    Scene* scene;


public:
	SourceWidget(QWidget* parent = nullptr);
	~SourceWidget();

	virtual void updateNotifyEvent(NotifyEvent* event);

protected:
	virtual void paintEvent(QPaintEvent* event);

private slots:
	void addButtonClicked();
	void removeButtonClicked();
	void moveUpButtonClicked();
	void moveDownButtonClicked();

private:
	void updateList();
};

#endif //_SOURCEWIDGET_H
