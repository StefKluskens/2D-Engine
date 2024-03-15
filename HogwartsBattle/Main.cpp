#if _DEBUG
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Core/2D-SDL-Engine.h"
#include "HogwartsBattle.h"

int main()
{
	Engine::SDLEngine engine("../Data/", "Hogwarts Battle");
	HB::HogwartsBattle hb;
	engine.Run([&hb]() {hb.Load(); });
	return 0;
}