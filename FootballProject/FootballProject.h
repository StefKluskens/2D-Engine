#pragma once

namespace FP
{
	class FootballProject
	{
	public:
		FootballProject() = default;
		~FootballProject() = default;

		FootballProject(const FootballProject&) = delete;
		FootballProject(FootballProject&&) = delete;
		FootballProject& operator= (const FootballProject&) = delete;
		FootballProject& operator= (const FootballProject&&) = delete;

		void Load();
	};
}