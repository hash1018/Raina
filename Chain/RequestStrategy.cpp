

#include "RequestStrategy.h"
#include "Request.h"
#include "../Base/RainaCore.h"
#include "../Base/Scene.h"
#include "../NotifyEvent/NotifyEvent.h"
#include "../Ui/MainWindow.h"

RequestStrategy::RequestStrategy(MainWindow* mainWindow, Request* request)
	:mainWindow(mainWindow), request(request) {

}

RequestStrategy::~RequestStrategy() {


}

////////////////////////////////////////////////////////


RequestChangeSceneStrategy::RequestChangeSceneStrategy(MainWindow* mainWindow, Request* request)
	:RequestStrategy(mainWindow, request) {

}

RequestChangeSceneStrategy::~RequestChangeSceneStrategy() {

}

bool RequestChangeSceneStrategy::response() {


	RequestChangeScene* request = dynamic_cast<RequestChangeScene*>(this->request);

	if (request->getChangeType() == RequestChangeScene::ChangeType::Add) {
	
		Scene* scene = new Scene(request->getName());
		
		RainaCore::getInstance()->getSceneManager()->add(scene);
		
		QList<const Scene*> list;
		for (int i = 0; i < RainaCore::getInstance()->getSceneManager()->size(); i++) {
			list.append(RainaCore::getInstance()->getSceneManager()->at(i));
		}
		
		CurrentSceneChangedEvent event(list, scene);
		this->mainWindow->updateNotifyEvent(&event);
		
	}

	return true;
}