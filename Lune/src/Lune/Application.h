#pragma once

#include "Core.h"

namespace Lune
{
	class LUNE_API Application
	{
	public:
		Application();
		~Application();

		void Run();
	};

	Application* CreateApplication();
}
