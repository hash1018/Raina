
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

void SceneManager::swap(int index, int index2) {

	this->list.swap(index, index2);
}

void SceneManager::clear() {

	while (this->list.isEmpty() == false)
		delete this->list.takeFirst();
}


/////////////////////////////////////////////////////

int Scene::number = 0;

Scene::Scene(const QString& name)
	:name(name) {

	this->name = name + QString::number(Scene::number++);
}

Scene::~Scene() {


}