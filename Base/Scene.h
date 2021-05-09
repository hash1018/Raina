
#ifndef _SCENE_H
#define _SCENE_H

#include <qlist.h>
class Scene;
class Source;

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
	int indexOf(Scene* scene)const { return this->list.indexOf(scene); }

    inline Scene* const& at(int index) const { return this->list.at(index); }
    inline int size() const { return this->list.size(); }

	void clear();

};

///////////////////////////////////////////////////////////


class Scene {

private:
	QString name;
	//temp
	static int number;

private:
    QList<Source*> list;

public:
	Scene(const QString& name);
	~Scene();

public:
    void add(Source* source);
    void remove(Source* source);
    void swap(int index, int index2);
	int indexOf(Source* source)const { return this->list.indexOf(source); }

    inline Source* const& at(int index) const { return this->list.at(index); }
    inline int size() const { return this->list.size(); }

    void clear();

public:
	void setName(const QString& name) { this->name = name; }

public:
	const QString& getName() const { return this->name; }
};

#endif //_SCENE_H
