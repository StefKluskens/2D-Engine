#pragma once
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

struct SDL_Renderer;

namespace FP
{
	class Circle final
	{
	public:
		Circle(SDL_Renderer* surface, int n_cx, int n_cy, int radius, int r, int g, int b);
		virtual ~Circle() = default;
		Circle(const Circle& other) = delete;
		Circle(Circle&& other) noexcept = delete;
		Circle& operator=(const Circle& other) = delete;
		Circle& operator=(Circle&& other) = delete;

		void Render() const;

		bool IsInsideCircle(glm::vec2 pos, int mouseX, int mouseY) const;

	private:
		void Draw() const;
		void SetPixel(int x, int y) const;

		SDL_Renderer* m_pRenderer;
		int m_CenterX;
		int m_CenterY;
		int m_Radius;

		glm::vec3 m_Color;
	};
}