#pragma once
#include "florp/app/ApplicationLayer.h"

class SceneBuilder : public florp::app::ApplicationLayer {
public:
	void Initialize() override;

	
	//how many lights to use
	int numLights = 25; //Max 25
};
