

#include "NotifyEvent.h"

NotifyEvent::NotifyEvent(EventType eventType)
	:eventType(eventType) {

}

NotifyEvent::~NotifyEvent() {


}

/////////////////////////////////////////////////////////////


CurrentSceneChangedEvent::CurrentSceneChangedEvent(const QList<const Scene*>& list, const Scene* scene)
	:NotifyEvent(EventType::CurrentSceneChanged), list(list), scene(scene) {

}

CurrentSceneChangedEvent::~CurrentSceneChangedEvent() {


}


///////////////////////////////////////////////////////////////

CurrentSourceChangedEvent::CurrentSourceChangedEvent(const Scene* scene, const Source* source)
	:NotifyEvent(EventType::CurrentSourceChanged), scene(scene), source(source) {

}

CurrentSourceChangedEvent::~CurrentSourceChangedEvent() {

}