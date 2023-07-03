#include "TextureComponent.h"
#include "TransformComponent.h"
#include "../SceneGraph/GameObject.h"
#include "../Core/FileManager.h"
#include "../Renderer/Renderer.h"

Engine::TextureComponent::TextureComponent(GameObject* pObject, const std::string& fileName)
	: BaseComponent(pObject)
{
	m_pTransform = pObject->GetTransform();
	SetTexture(fileName);
}

void Engine::TextureComponent::Render() const
{
	if (m_pTexture != nullptr)
	{
		auto pos = GetOwner()->GetTransform()->GetLocalPosition();
		Renderer::GetInstance().RenderTexture(*m_pTexture, pos);
	}
}

void Engine::TextureComponent::SetTexture(const std::string& fileName)
{
	m_pTexture = FileManager::GetInstance().LoadTexture(fileName);
}

const glm::vec2 Engine::TextureComponent::GetTextureSize() const
{
	float x = static_cast<float>(m_pTexture->GetSize().x);
	float y = static_cast<float>(m_pTexture->GetSize().y);

	return glm::vec2(x, y);
}