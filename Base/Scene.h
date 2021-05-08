
#ifndef _SCENE_H
#define _SCENE_H

#include <qlist.h>
class Scene;

class SceneManager {

	friend class RainaCore;

private:
	QList<Scene*> list;

private:
	SceneManager();
	~SceneManager();

public:
	void add(Scene* scene);
	void remove(Scene* scene);
	void swap(int index, int index2);

	Scene* const& at(int index) const { return this->list.at(index); }
	int size() const { return this->list.size(); }

	void clear();

};

///////////////////////////////////////////////////////////


class Scene {

private:
	QString name;
	//temp
	static int number;

private:
	QList<int> list;

public:
	Scene(const QString& name);
	~Scene();

public:
	void setName(const QString& name) { this->name = name; }

public:
	const QString& getName() const { return this->name; }
};

#endif //_SCENE_H