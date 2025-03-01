#include "Rigidbody.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include "PhysicsWorld.h"

Engine::Rigidbody::Rigidbody(glm::vec2 pos, float density, float mass, float restitution, float area, bool isStatic, float radius, float width, float height, Shape bodyShape)
	:m_Position(pos),
	m_linearVelocity(glm::vec2(0.0f)),
	m_Rotation(0.0f),
	m_RotationalVelocity(0.0f),
	Density(density),
	Mass(mass),
	Restitution(restitution),
	Area(area),
	IsStatic(isStatic),
	m_Radius(radius),
	Width(width),
	Height(height),
	BodyShape(bodyShape)
{
}

std::unique_ptr<Engine::Rigidbody> Engine::Rigidbody::CreateCircleBody(float radius, glm::vec2 position, float density, bool IsStatic, float restitution)
{
	float area = radius * radius * (float)M_PI;

	if (area < PhysicsWorld::GetInstance().MinBodySize || area > PhysicsWorld::GetInstance().MaxBodySize)
	{
		//TODO: Log error
		return nullptr;
	}

	if (density < PhysicsWorld::GetInstance().MinDensity || density > PhysicsWorld::GetInstance().MaxDensity)
	{
		//TODO: Log error
		return nullptr;
	}

	restitution = glm::clamp(restitution, 0.0f, 1.0f);

	float mass = area * density;

	return std::make_unique<Engine::Rigidbody>(position, density, mass, restitution, area, IsStatic, radius, 0.0f, 0.0f, Shape::Circle);
}

std::unique_ptr<Engine::Rigidbody> Engine::Rigidbody::CreateBoxBody(float width, float height, glm::vec2 position, float density, bool IsStatic, float restitution)
{
	float area = width * height * (float)M_PI;

	if (area < PhysicsWorld::GetInstance().MinBodySize || area > PhysicsWorld::GetInstance().MaxBodySize)
	{
		//TODO: Log error
		return nullptr;
	}

	if (density < PhysicsWorld::GetInstance().MinDensity || density > PhysicsWorld::GetInstance().MaxDensity)
	{
		//TODO: Log error
		return nullptr;
	}

	restitution = glm::clamp(restitution, 0.0f, 1.0f);

	float mass = area * density;

	return std::make_unique<Engine::Rigidbody>(position, density, mass, restitution, area, IsStatic, 0.0f, width, height, Shape::Box);
}
