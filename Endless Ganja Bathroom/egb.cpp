#include "egb.h"

egb::egb(PolycodeView *view) {
	core = new Win32Core(view, 1280,720,false,0,60);	  
	CoreServices::getInstance()->getResourceManager()->addArchive("default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);

    mainScene = new Scene();
    ground = new ScenePrimitive(ScenePrimitive::TYPE_PLANE, 5,5);
	ground->setColor(1.0,0.0,0.0,1.0);
	mainScene->addEntity(ground);

    /*box = new ScenePrimitive(ScenePrimitive::TYPE_BOX, 1,1,1);
	box->setColor(0.0,1.0,0.0,1.0);
	box->setPosition(0.0, 0.5, 0.0);
	mainScene->addEntity(box);*/

    washer = new SceneMesh("Models/washerTest.mesh");
    washer->loadTexture("Models/washerTexture.png");
    washer->setPosition(0.0, 0.0, 0.0);
    mainScene->addEntity(washer);

    mainScene->getDefaultCamera()->setPosition(10,10,10);
	mainScene->getDefaultCamera()->lookAt(Vector3(0,3,0));
}

egb::~egb() {
    delete mainScene;
    delete ground;
    delete washer;
    delete core;
}

bool egb::Update() {
	return core->Update();
}