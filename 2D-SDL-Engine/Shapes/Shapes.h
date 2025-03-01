#pragma once
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <SDL.h>

#include "../Renderer/Renderer.h"

namespace Engine
{
	struct Circle
	{
	public:
		Circle(int centerX, int centerY, int radius, int r, int g, int b)
			: m_CenterX(centerX)
			, m_CenterY(centerY)
			, m_Radius(radius)
			, m_Color(r, g, b)
			, m_pRenderer(Renderer::GetInstance().GetRenderer())
		{}

		void Render() const
		{
			double error = (double)-m_Radius;
			double x = (double)m_Radius - 0.5;
			double y = (double)0.5;
			double cx = m_CenterX - 0.5;
			double cy = m_CenterY - 0.5;

			while (x >= y)
			{
				SetPixel((int)(cx + x), (int)(cy + y));
				SetPixel((int)(cx + y), (int)(cy + x));

				if (x != 0)
				{
					SetPixel((int)(cx - x), (int)(cy + y));
					SetPixel((int)(cx + y), (int)(cy - x));
				}

				if (y != 0)
				{
					SetPixel((int)(cx + x), (int)(cy - y));
					SetPixel((int)(cx - y), (int)(cy + x));
				}

				if (x != 0 && y != 0)
				{
					SetPixel((int)(cx - x), (int)(cy - y));
					SetPixel((int)(cx - y), (int)(cy - x));
				}

				error += y;
				++y;
				error += y;

				if (error >= 0)
				{
					--x;
					error -= x;
					error -= x;
				}
			}
		}

		bool IsInsideCircle(glm::vec2 pos, int mouseX, int mouseY) const
		{
			int distanceSquared = (mouseX - (int)pos.x) * (mouseX - (int)pos.x) + (mouseY - (int)pos.y) * (mouseY - (int)pos.y);
			return distanceSquared <= m_Radius * m_Radius;
		}

	private:

		void SetPixel(int x, int y) const
		{
			Uint8 red = static_cast<Uint8>(m_Color.x);
			Uint8 green = static_cast<Uint8>(m_Color.y);
			Uint8 blue = static_cast<Uint8>(m_Color.z);

			SDL_SetRenderDrawColor(m_pRenderer, red, green, blue, 255);
			SDL_RenderDrawPoint(m_pRenderer, x, y);
		}

		int m_CenterX;
		int m_CenterY;
		int m_Radius;
		SDL_Renderer* m_pRenderer;

		glm::vec3 m_Color;
	};

	struct Box
	{
	public:
		Box(glm::vec2 pos, int width, int height, int r, int g, int b, bool fill)
			: m_Position(pos)
			, m_Width(width)
			, m_Height(height)
			, m_Color(r, g, b)
			, m_Fill(fill)
			, m_pRenderer(Renderer::GetInstance().GetRenderer())
		{
		}

		void Render() const
		{
			Uint8 red = static_cast<Uint8>(m_Color.x);
			Uint8 green = static_cast<Uint8>(m_Color.y);
			Uint8 blue = static_cast<Uint8>(m_Color.z);

			SDL_SetRenderDrawColor(m_pRenderer, red, green, blue, 255);

			SDL_Rect rect = {
				static_cast<int>(m_Position.x),
				static_cast<int>(m_Position.y),
				m_Width,
				m_Height
			};

			if (!m_Fill)
			{
				SDL_RenderDrawRect(m_pRenderer, &rect);
			}
			else
			{
				SDL_RenderFillRect(m_pRenderer, &rect);
			}
			
		}

		bool IsInsideBox()
		{
			return false;
		}

	private:
		glm::vec2 m_Position;
		glm::vec3 m_Color;

		int m_Width;
		int m_Height;

		bool m_Fill;

		SDL_Renderer* m_pRenderer;
	};
}