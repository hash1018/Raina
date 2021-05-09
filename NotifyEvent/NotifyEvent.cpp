

#include "NotifyEvent.h"

NotifyEvent::NotifyEvent(EventType eventType)
	:eventType(eventType) {

}

NotifyEvent::~NotifyEvent() {


}

/////////////////////////////////////////////////////////////


CurrentSceneChangedEvent::CurrentSceneChangedEvent(Scene* const scene)
	:NotifyEvent(EventType::CurrentSceneChanged), scene(scene) {

}

CurrentSceneChangedEvent::~CurrentSceneChangedEvent() {


}


///////////////////////////////////////////////////////////////

CurrentSourceChangedEvent::CurrentSourceChangedEvent(Source* source)
	:NotifyEvent(EventType::CurrentSourceChanged), source(source) {

}

CurrentSourceChangedEvent::~CurrentSourceChangedEvent() {

}