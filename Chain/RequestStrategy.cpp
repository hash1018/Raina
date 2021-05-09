

#include "RequestStrategy.h"
#include "Request.h"
#include "../Base/RainaCore.h"
#include "../Base/Scene.h"
#include "../NotifyEvent/NotifyEvent.h"
#include "../Ui/MainWindow.h"
#include "../Base/Source.h"

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
	
	else if (request->getChangeType() == RequestChangeScene::ChangeType::Remove) {
	
		if (request->getScene() == nullptr)
			return true;

		SceneManager* sceneManager = RainaCore::getInstance()->getSceneManager();

		int index = sceneManager->indexOf(const_cast<Scene*>(request->getScene()));
		sceneManager->remove(const_cast<Scene*>(request->getScene()));
		int size = sceneManager->size();

		QList<const Scene*> list;
		for (int i = 0; i < size; i++) {
			list.append(sceneManager->at(i));
		}

		if (size == 0) {

			CurrentSceneChangedEvent event(list, nullptr);
			this->mainWindow->updateNotifyEvent(&event);
		}
		else if (index < size) {
		
			CurrentSceneChangedEvent event(list, sceneManager->at(index));
			this->mainWindow->updateNotifyEvent(&event);
		}
		else {
		
			CurrentSceneChangedEvent event(list, sceneManager->at(size - 1));
			this->mainWindow->updateNotifyEvent(&event);
		}
	}
	else if (request->getChangeType() == RequestChangeScene::ChangeType::MoveUp) {
	
		SceneManager* sceneManager = RainaCore::getInstance()->getSceneManager();
		int index = sceneManager->indexOf(const_cast<Scene*>(request->getScene()));

		sceneManager->swap(index, index - 1);
	
		QList<const Scene*> list;
		for (int i = 0; i < sceneManager->size(); i++) {
			list.append(sceneManager->at(i));
		}

		CurrentSceneChangedEvent event(list, sceneManager->at(index - 1));
		this->mainWindow->updateNotifyEvent(&event);
	}
	else if (request->getChangeType() == RequestChangeScene::ChangeType::MoveDown) {
	
		SceneManager* sceneManager = RainaCore::getInstance()->getSceneManager();
		int index = sceneManager->indexOf(const_cast<Scene*>(request->getScene()));

		sceneManager->swap(index, index + 1);

		QList<const Scene*> list;
		for (int i = 0; i < sceneManager->size(); i++) {
			list.append(sceneManager->at(i));
		}

		CurrentSceneChangedEvent event(list, sceneManager->at(index + 1));
		this->mainWindow->updateNotifyEvent(&event);
	}
	else if (request->getChangeType() == RequestChangeScene::ChangeType::CurrentScene) {
	
		SceneManager* sceneManager = RainaCore::getInstance()->getSceneManager();

		QList<const Scene*> list;
		for (int i = 0; i < sceneManager->size(); i++) {
			list.append(sceneManager->at(i));
		}

		CurrentSceneChangedEvent event(list, request->getScene());
		this->mainWindow->updateNotifyEvent(&event);
	}

	return true;
}



///////////////////////////////////////////////////////////////////////


RequestChangeSourceStrategy::RequestChangeSourceStrategy(MainWindow* mainWindow, Request* request)
	:RequestStrategy(mainWindow, request) {

}

RequestChangeSourceStrategy::~RequestChangeSourceStrategy() {

}

bool RequestChangeSourceStrategy::response() {

	RequestChangeSource* request = dynamic_cast<RequestChangeSource*>(this->request);

	if (request->getChangeType() == RequestChangeSource::ChangeType::Add) {
	
		request->getScene()->add(new Source(request->getName()));

		CurrentSourceChangedEvent event(request->getScene(), nullptr);
		this->mainWindow->updateNotifyEvent(&event);
	}
	else if (request->getChangeType() == RequestChangeSource::ChangeType::Remove) {
	
		request->getScene()->remove(const_cast<Source*>(request->getSource()));

		CurrentSourceChangedEvent event(request->getScene(), nullptr);
		this->mainWindow->updateNotifyEvent(&event);
	}
	else if (request->getChangeType() == RequestChangeSource::ChangeType::CurrentSource) {
	
		CurrentSourceChangedEvent event(request->getScene(), request->getSource());
		this->mainWindow->updateNotifyEvent(&event);
	}
	else if (request->getChangeType() == RequestChangeSource::ChangeType::MoveUp) {
	
		int index = request->getScene()->indexOf(const_cast<Source*>(request->getSource()));

		request->getScene()->swap(index, index - 1);

		CurrentSourceChangedEvent event(request->getScene(), request->getScene()->at(index - 1));
		this->mainWindow->updateNotifyEvent(&event);
	}
	else if (request->getChangeType() == RequestChangeSource::ChangeType::MoveDown) {
	
		int index = request->getScene()->indexOf(const_cast<Source*>(request->getSource()));

		request->getScene()->swap(index, index + 1);

		CurrentSourceChangedEvent event(request->getScene(), request->getScene()->at(index + 1));
		this->mainWindow->updateNotifyEvent(&event);
	}

	return true;
}