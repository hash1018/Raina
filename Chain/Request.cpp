
#include "Request.h"

Request::Request(Request::RequestType requestType)
	:requestType(requestType) {

}

Request::~Request() {


}

/////////////////////////////////////////////////////////////////


RequestChangeScene::RequestChangeScene(const QString& name, ChangeType changeType)
	:Request(RequestType::RequestChangeScene), changeType(changeType), name(name), scene(nullptr) {

}

RequestChangeScene::RequestChangeScene(const Scene* scene, ChangeType changeType)
	: Request(RequestType::RequestChangeScene), changeType(changeType), scene(scene) {

}

RequestChangeScene::~RequestChangeScene() {


}

//////////////////////////////////////////////////////////////////

RequestChangeSource::RequestChangeSource(Scene* const scene, const QString& name, ChangeType changeType)
	:Request(RequestType::RequestChangeSource), scene(scene), changeType(changeType), name(name), source(nullptr) {

}


RequestChangeSource::RequestChangeSource(Scene* const scene, const Source* source, ChangeType changeType)
	: Request(RequestType::RequestChangeSource), scene(scene), changeType(changeType), source(source) {

}

RequestChangeSource::~RequestChangeSource() {

}