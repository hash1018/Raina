
#ifndef _RAINACORE_H
#define _RAINACORE_H

#include "Singleton.h"

class SceneManager;

class RainaCore {

	DeclareSingleton(RainaCore)

private:
	SceneManager* sceneManager;

public:
	void initialize();
	void deinitialize();

	inline SceneManager* const getSceneManager() const { return this->sceneManager; }

};

#endif //_RAINACORE_H