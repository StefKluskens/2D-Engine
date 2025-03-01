#if _DEBUG
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Core/2D-SDL-Engine.h"
#include "Sandbox.h"

int main()
{
	Engine::SDLEngine engine("../Data/", "Sandbox Project");
	SB::SandBox sb;
	engine.Run([&sb]() {sb.Load(); });
	return 0;
}