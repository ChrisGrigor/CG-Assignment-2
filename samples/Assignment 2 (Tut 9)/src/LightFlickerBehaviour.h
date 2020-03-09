#pragma once
#include "florp/game/IBehaviour.h"
#include <GLM/detail/type_vec3.hpp>

class LightFlickerBehaviour : public florp::game::IBehaviour {
public:
	LightFlickerBehaviour(float speed, float min = 0.0f, float max = 1.0f);

	void OnLoad(entt::entity entity) override;
	void Update(entt::entity entity) override;

private:
	float myInitialAttenuation;
	float myFlickerSpeed;
	float myTimingOffset;
	float myMin, myMax;

	//Get light movement
	glm::vec3 newPosition;
	float angle = 4.7;
	float radius = 10;

	float angleIncrement = 1.5;
	float radiusIncrement = 5;
};
