
#include "RainaCore.h"
#include "Scene.h"

RainaCore::RainaCore()
	:sceneManager(nullptr) {


}

RainaCore::~RainaCore() {


}

void RainaCore::initialize() {

	this->sceneManager = new SceneManager;
}

void RainaCore::deinitialize() {

	if (this->sceneManager != nullptr) {
		delete this->sceneManager;
		this->sceneManager = nullptr;
	}
}