#pragma once
#include "Components/BaseComponent.h"
#include <memory>

#include "Shapes/Shapes.h"

class ShapeObject final : public Engine::BaseComponent
{
public:
	ShapeObject(Engine::GameObject* pObject);
	virtual ~ShapeObject() = default;
	ShapeObject(const ShapeObject& other) = delete;
	ShapeObject(ShapeObject&& other) noexcept = delete;
	ShapeObject& operator=(const ShapeObject& other) = delete;
	ShapeObject& operator=(ShapeObject&& other) = delete;

	void Start() override {};
	void Render() const override;
	void OnGuiRender() override {};
	void Update(float /*deltaTime*/) override {};
	void FixedUpdate(float /*deltaTime*/) override {};

private:
	std::unique_ptr<Engine::Circle> m_pCircle;
	std::unique_ptr<Engine::Box> m_pBox;
};

