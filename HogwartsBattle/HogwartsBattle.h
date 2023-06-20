#pragma once

namespace HB
{
	class HogwartsBattle final
	{
	public:
		HogwartsBattle() = default;
		~HogwartsBattle() = default;

		HogwartsBattle(const HogwartsBattle&) = delete;
		HogwartsBattle(HogwartsBattle&&) = delete;
		HogwartsBattle& operator= (const HogwartsBattle&) = delete;
		HogwartsBattle& operator= (const HogwartsBattle&&) = delete;

		void Load();
	};
}