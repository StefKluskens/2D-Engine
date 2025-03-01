#include "ShapeObject.h"
#include "SceneGraph/GameObject.h"

ShapeObject::ShapeObject(Engine::GameObject* pObject)
	: BaseComponent(pObject)
{
	auto pos = m_pOwner->GetTransform()->GetWorldPosition();
	m_pCircle = std::make_unique<Engine::Circle>((int)pos.x, (int)pos.y, 20, 255, 0, 0);

	pos.x += 50;
	m_pBox = std::make_unique<Engine::Box>(pos, 20, 20, 255, 0, 0, true);
}

void ShapeObject::Render() const
{
	m_pCircle->Render();
	m_pBox->Render();
}
