
#include "ChangeManager.h"
#include "Observer.h"

ChangeManager::ChangeManager() {

}

ChangeManager::~ChangeManager() {


}

void ChangeManager::registerObserver(Observer* observer) {

	this->list.append(observer);
}

void ChangeManager::updateNotifyEvent(NotifyEvent* event) {

	for (int i = 0; i < this->list.size(); i++)
		this->list.at(i)->updateNotifyEvent(event);
}