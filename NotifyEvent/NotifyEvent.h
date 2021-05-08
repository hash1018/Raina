
#ifndef _NOTIFYEVENT_H
#define _NOTIFYEVENT_H

class Scene;

class NotifyEvent {

public:
	enum class EventType {
		CurrentSceneChanged,

	};

protected:
	EventType eventType;

public:
	NotifyEvent(EventType eventType);
	virtual ~NotifyEvent() = 0;


public:
	inline EventType getEventType() const { return this->eventType; }
};


////////////////////////////////////////////////////////////

class CurrentSceneChangedEvent : public NotifyEvent {

private:
	Scene* const scene;

public:
	CurrentSceneChangedEvent(Scene* const scene);
	~CurrentSceneChangedEvent();

public:
	inline Scene* const getScene() const { return this->scene; }
};

#endif //_NOTIFYEVENT_H