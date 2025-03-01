#include "Camera.h"
#include "../SceneGraph/GameObject.h"
#include "../SceneGraph/Scene.h"

Engine::Camera::Camera(GameObject* pObject, glm::vec2 pos, glm::vec2 speed)
	: BaseComponent(pObject)
	, m_Position(pos)
	, m_MovementSpeed(speed)
{
}

void Engine::Camera::Update(float /*deltaTime*/)
{
	
}