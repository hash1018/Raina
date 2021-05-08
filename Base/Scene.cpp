
#include "Scene.h"
#include "Source.h"

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

    this->list.swapItemsAt(index, index2);
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

    this->clear();
}

void Scene::add(Source* source){

    this->list.append(source);
}
void Scene::remove(Source* source){

    int index = this->list.indexOf(source);

    if (index == -1)
        return;

    this->list.takeAt(index);

    delete source;
}

void Scene::swap(int index, int index2){

    this->list.swapItemsAt(index, index2);
}

void Scene::clear() {

    while (this->list.isEmpty() == false)
        delete this->list.takeFirst();
}
