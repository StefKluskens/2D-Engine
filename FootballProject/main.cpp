#if _DEBUG
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Core/2D-SDL-Engine.h"
#include "FootballProject.h"

int main()
{
	Engine::SDLEngine engine("../Data/", "Football Project");
	FP::FootballProject fp;
	engine.Run([&fp]() {fp.Load(); });
	return 0;
}