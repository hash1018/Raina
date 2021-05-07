
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

	Scene* const& at(int index) const { return this->list.at(index); }
	int size() const { return this->list.size(); }

	void clear();

};

///////////////////////////////////////////////////////////


class Scene {

private:
	QString name;

public:
	Scene(const QString& name);
	~Scene();

public:
	void setName(const QString& name) { this->name = name; }

public:
	const QString& getName() const { return this->name; }
};

#endif //_SCENE_H