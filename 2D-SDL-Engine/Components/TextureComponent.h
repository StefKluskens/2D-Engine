#pragma once
#include "BaseComponent.h"
#include <memory>
#include <glm/glm.hpp>
#include <string>
#include "../FileTypes/Texture.h"

namespace Engine
{
	class TransformComponent;

	class TextureComponent final : public BaseComponent
	{
	public:
		TextureComponent(GameObject* pObject, const std::string& fileName);
		virtual ~TextureComponent() = default;
		TextureComponent(const TextureComponent& other) = delete;
		TextureComponent(TextureComponent&& other) noexcept = delete;
		TextureComponent& operator=(const TextureComponent& other) = delete;
		TextureComponent& operator=(TextureComponent&& other) = delete;

		void Start() override {};
		void Render() const override;
		void OnGuiRender() override {};
		void Update(float /*deltaTime*/) override {};
		void FixedUpdate(float /*deltaTime*/) override {};

		void SetTexture(const std::string& fileName);
		Texture* GetTexture() const { return m_pTexture.get(); }

		const glm::vec2 GetTextureSize() const;

	private:
		std::unique_ptr<Texture> m_pTexture;
		glm::vec3 m_Position{};
		TransformComponent* m_pTransform{};
	};
}