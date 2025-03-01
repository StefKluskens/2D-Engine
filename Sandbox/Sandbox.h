#pragma once
namespace SB
{
	class SandBox final
	{
	public:
		SandBox() = default;
		~SandBox() = default;

		SandBox(const SandBox&) = delete;
		SandBox(SandBox&&) = delete;
		SandBox& operator= (const SandBox&) = delete;
		SandBox& operator= (const SandBox&&) = delete;

		void Load();
	};
}