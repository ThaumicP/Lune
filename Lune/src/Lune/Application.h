#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Lune
{
	class LUNE_API Application
	{
	public:
		Application();
		~Application();

		bool Start();
		bool Update();
		void Run();
		bool ErrorCatch(std::string msg);
	};

	Application* CreateApplication();
}
