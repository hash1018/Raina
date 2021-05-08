
#ifndef _CHANGEMANAGER_H
#define _CHANGEMANAGER_H

#include "../Base/Singleton.h"
#include <qlist.h>

class Observer;
class NotifyEvent;

class ChangeManager {

	DeclareSingleton(ChangeManager)

private:
	QList<Observer*> list;

public:
	void registerObserver(Observer* observer);
	void updateNotifyEvent(NotifyEvent* event);
};

#endif //_CHANGEMANAGER_H