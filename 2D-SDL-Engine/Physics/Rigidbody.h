#pragma once
#include <glm/glm.hpp>
#include <memory>

namespace Engine 
{
	class Rigidbody final
	{
	public:
		enum class Shape
		{
			Circle = 0,
			Box = 1
		};

		Rigidbody(glm::vec2 pos, float density, float mass, float restitution, float area, bool isStatic, float radius, float width, float height, Shape bodyShape);
		~Rigidbody() = default;
		Rigidbody(const Rigidbody& other) = delete;
		Rigidbody(Rigidbody&& other) noexcept = delete;
		Rigidbody& operator=(const Rigidbody& other) = delete;
		Rigidbody& operator=(Rigidbody&& other) = delete;

		static std::unique_ptr<Rigidbody> CreateCircleBody(float radius, glm::vec2 position, float density, bool IsStatic, float restitution);
		static std::unique_ptr<Rigidbody> CreateBoxBody(float width, float height, glm::vec2 position, float density, bool IsStatic, float restitution);

		const float Density;
		const float Restitution;
		const float Mass;
		const float Area;

		const bool IsStatic;

		const float m_Radius;
		const float Width;
		const float Height;

		const Shape BodyShape;

	private:
		glm::vec2 m_Position;
		glm::vec2 m_linearVelocity;
		float m_Rotation;
		float m_RotationalVelocity;
	};
}