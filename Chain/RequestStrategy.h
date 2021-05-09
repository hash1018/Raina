
#ifndef _REQUESTSTRATEGY_H
#define _REQUESTSTRATEGY_H

class MainWindow;
class Request;

class RequestStrategy {


protected:
	MainWindow* mainWindow;
	Request* request;

public:
	RequestStrategy(MainWindow* mainWindow, Request* request);
	virtual ~RequestStrategy() = 0;

	virtual bool response() = 0;
};

/////////////////////////////////////////////////////////

class RequestChangeSceneStrategy : public RequestStrategy {

public:
	RequestChangeSceneStrategy(MainWindow* mainWindow, Request* request);
	~RequestChangeSceneStrategy();

	virtual bool response();
};

//////////////////////////////////////////////////////////

class RequestChangeSourceStrategy : public RequestStrategy {

public:
	RequestChangeSourceStrategy(MainWindow* mainWindow, Request* request);
	~RequestChangeSourceStrategy();

	virtual bool response();
};

#endif //_REQUESTSTRATEGY_H