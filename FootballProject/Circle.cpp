#include "Circle.h"
#include <SDL.h>

FP::Circle::Circle(SDL_Renderer* surface, int n_cx, int n_cy, int radius, int r, int g, int b)
	: m_pRenderer(surface)
	, m_CenterX(n_cx)
	, m_CenterY(n_cy)
	, m_Radius(radius)
	, m_Color(r, g, b)
{
}

void FP::Circle::Render() const
{
	Draw();
}

bool FP::Circle::IsInsideCircle(glm::vec2 pos, int mouseX, int mouseY) const
{
	int distanceSquared = (mouseX - (int)pos.x) * (mouseX - (int)pos.x) + (mouseY - (int)pos.y) * (mouseY - (int)pos.y);
	return distanceSquared <= m_Radius * m_Radius;
}

void FP::Circle::Draw() const
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

void FP::Circle::SetPixel(int x, int y) const
{
	Uint8 red = static_cast<Uint8>(m_Color.x);
	Uint8 green = static_cast<Uint8>(m_Color.y);
	Uint8 blue = static_cast<Uint8>(m_Color.z);

	SDL_SetRenderDrawColor(m_pRenderer, red, green, blue, 255);
	SDL_RenderDrawPoint(m_pRenderer, x, y);
}
