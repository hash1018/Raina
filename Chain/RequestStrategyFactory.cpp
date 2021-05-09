
#include "RequestStrategyFactory.h"
#include "Request.h"
#include "RequestStrategy.h"

RequestStrategyFactory::RequestStrategyFactory() {

}

RequestStrategyFactory::~RequestStrategyFactory() {

}

RequestStrategy* RequestStrategyFactory::create(MainWindow* mainWindow, Request* request) {

	RequestStrategy* strategy = nullptr;

	if (request->getRequestType() == Request::RequestType::RequestChangeScene) {
	
		strategy = new RequestChangeSceneStrategy(mainWindow, request);
	}

	return strategy;
}