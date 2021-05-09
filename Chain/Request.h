
#ifndef _REQUEST_H
#define _REQUEST_H

#include <qstring.h>
class Scene;
class Source;

class Request {

public:
	enum class RequestType {
		RequestChangeScene,
		RequestChangeSource,
	};

protected:
	RequestType requestType;

public:
	Request(RequestType requestType);
	virtual ~Request() = 0;

	inline RequestType getRequestType() const { return this->requestType; }

};

////////////////////////////////////////////////////////////////

class RequestChangeScene : public Request {

public:
	enum class ChangeType {
		Add,
		Remove,
		MoveUp,
		MoveDown,
		CurrentScene,
	};

private:

	ChangeType changeType;

	//used for Type-Add
	QString name;

	//used for Remove,MoveUp,MoveDown
	const Scene* scene;

public:
	RequestChangeScene(const QString& name, ChangeType changeType = ChangeType::Add);
	RequestChangeScene(const Scene* scene, ChangeType changeType);
	~RequestChangeScene();

	
public:
	inline ChangeType getChangeType() const { return this->changeType; }
	inline const QString& getName() const { return this->name; }
	inline const Scene* getScene() const { return this->scene; }
};

///////////////////////////////////////////////////////////////////////

class RequestChangeSource : public Request {

public:
	enum class ChangeType {
		Add,
		Remove,
		MoveUp,
		MoveDown,
		CurrentSource,
	};

private:

	Scene* const scene;

	ChangeType changeType;

	//used for Type-Add
	QString name;

	//used for Remove,MoveUp,MoveDown
	const Source* source;

public:
	RequestChangeSource(Scene* const scene, const QString& name, ChangeType changeType = ChangeType::Add);
	RequestChangeSource(Scene* const scene, const Source* source, ChangeType changeType);
	~RequestChangeSource();


public:
	inline Scene* const getScene() const { return this->scene; }
	inline ChangeType getChangeType() const { return this->changeType; }
	inline const QString& getName() const { return this->name; }
	inline const Source* getSource() const { return this->source; }
};


#endif //_REQUEST_H