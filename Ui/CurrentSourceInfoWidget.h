
#ifndef _CURRENTSOURCEINFOWIDGET_H
#define _CURRENTSOURCEINFOWIDGET_H

#include <qwidget.h>
#include "../NotifyEvent/Observer.h"
#include "../Chain/Chain.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CurrentSourceInfoWidget; }
QT_END_NAMESPACE

class Source;

class CurrentSourceInfoWidget : public QWidget, public Observer, public Chain  {

private:
	Ui::CurrentSourceInfoWidget* ui;

private:
	const Source* source;

public:
	CurrentSourceInfoWidget(QWidget* parent = nullptr, Chain* chain = nullptr);
	~CurrentSourceInfoWidget();

	virtual void updateNotifyEvent(NotifyEvent* event);

protected:
	virtual void paintEvent(QPaintEvent* event);
};

#endif //_CURRENTSOURCEINFOWIDGET_H