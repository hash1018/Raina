
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