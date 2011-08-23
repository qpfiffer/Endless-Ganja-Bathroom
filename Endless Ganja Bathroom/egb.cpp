#include "egb.h"

egb::egb(PolycodeView *view) {
	core = new Win32Core(view, 640,480,false,0,60);	  
	CoreServices::getInstance()->getResourceManager()->addArchive("default.pak");
	CoreServices::getInstance()->getResourceManager()->addDirResource("default", false);
}

egb::~egb() {
    delete core;
}

bool egb::Update() {
	return core->Update();
}