#pragma once
#include "../Core/Singleton.h"

namespace Engine
{
	class PhysicsWorld final : public Singleton<PhysicsWorld>
	{
	public:
		const float MinBodySize{ 0.01f * 0.01f };
		const float MaxBodySize{ 64.0f * 64.0f };

		//g/cm^3
		const float MinDensity{ 0.2f };
		const float MaxDensity{ 21. };

	private:
		friend class Singleton<PhysicsWorld>;
		PhysicsWorld() = default;
	};
}