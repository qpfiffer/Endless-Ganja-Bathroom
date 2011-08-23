#pragma once
#include "PolycodeView.h"
#include "Polycode.h"

using namespace Polycode;

class egb {
public:
    egb(PolycodeView *view);
    ~egb();

    bool Update();
private:
    Core *core;
    Scene *mainScene;
    ScenePrimitive *ground;
    ScenePrimitive *box;
    SceneMesh *washer;
};