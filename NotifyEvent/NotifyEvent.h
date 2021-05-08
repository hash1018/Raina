
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
    Scene* scene;

public:
    CurrentSceneChangedEvent(Scene* scene);
	~CurrentSceneChangedEvent();

public:
    inline Scene* getScene() const { return this->scene; }
};

#endif //_NOTIFYEVENT_H
