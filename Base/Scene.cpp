
#include "Scene.h"


SceneManager::SceneManager() {

}

SceneManager::~SceneManager() {

	this->clear();
}

void SceneManager::add(Scene* scene) {

	this->list.append(scene);
}

void SceneManager::remove(Scene* scene) {

	int index = this->list.indexOf(scene);

	if (index == -1)
		return;

	this->list.takeAt(index);

	delete scene;
}

void SceneManager::clear() {

	while (this->list.isEmpty() == false)
		delete this->list.takeFirst();
}


/////////////////////////////////////////////////////


Scene::Scene(const QString& name)
	:name(name) {

}

Scene::~Scene() {


}