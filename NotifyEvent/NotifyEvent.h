
#ifndef _NOTIFYEVENT_H
#define _NOTIFYEVENT_H

class Scene;
class Source;

class NotifyEvent {

public:
	enum class EventType {
		CurrentSceneChanged,
		CurrentSourceChanged,

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

//////////////////////////////////////////////////////////////

class CurrentSourceChangedEvent : public NotifyEvent {

private:
	Source* source;

public:
	CurrentSourceChangedEvent(Source* source);
	~CurrentSourceChangedEvent();

public:
	inline Source* getSource() const { return this->source; }
};

#endif //_NOTIFYEVENT_H
