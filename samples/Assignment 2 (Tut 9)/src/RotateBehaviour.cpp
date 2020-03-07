#include "RotateBehaviour.h"
#include "florp/app/Window.h"
#include "florp/app/Application.h"
#include "florp/game/Transform.h"
#include "florp/game/SceneManager.h"
#include "florp/app/Timing.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <GLM/gtx/wrap.hpp>

void MoveBehaviour::Update(entt::entity entity) {
	using namespace florp::app;
	auto& transform = CurrentRegistry().get<florp::game::Transform>(entity);
	Window::Sptr window = Application::Get()->GetWindow();

	glm::vec3 translate = glm::vec3(0.0f);
	if (window->IsKeyDown(Key::I))
		translate.z -= 2.0f;
	if (window->IsKeyDown(Key::K))
		translate.z += 2.0f;
	if (window->IsKeyDown(Key::J))
		translate.x -= 2.0f;
	if (window->IsKeyDown(Key::L))
		translate.x += 2.0f;

	translate *= Timing::DeltaTime * mySpeed;

	if (glm::length(translate) > 0) {
		translate = glm::mat3(transform.GetLocalTransform()) * translate;
		translate += transform.GetLocalPosition();
		transform.SetPosition(translate);
	}
}
