
#ifndef _NOTIFYEVENT_H
#define _NOTIFYEVENT_H

#include <qlist.h>

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
	QList<const Scene*> list;
    const Scene* scene;

public:
	CurrentSceneChangedEvent(const QList<const Scene*>& list, const Scene* scene);
	~CurrentSceneChangedEvent();

public:
	inline const QList<const Scene*>& getList() const { return this->list; }
    inline const Scene* getScene() const { return this->scene; }
};

//////////////////////////////////////////////////////////////

class CurrentSourceChangedEvent : public NotifyEvent {

private:
	const Scene* scene;
	const Source* source;

public:
	CurrentSourceChangedEvent(const Scene* scene, const Source* source);
	~CurrentSourceChangedEvent();

public:
	inline const Scene* getScene() const { return this->scene; }
	inline const Source* getSource() const { return this->source; }
};

#endif //_NOTIFYEVENT_H
