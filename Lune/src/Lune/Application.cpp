#include "Application.h"

#include "ApplicationEvent.h"
#include "Lune/Log.h"

namespace Lune
{
	Application::Application() {}

	Application::~Application() {}

	bool err = false;
	bool Application::ErrorCatch(std::string msg)
	{
		if (err)
		{
			LN_CORE_ERROR(msg);
			system("PAUSE");
			return false;
		}
		else
			return true;
	}

	void Application::Run()
	{
		if (Start())
			while (!err)
				Update();
	}

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

	WindowResizeEvent e(1280, 720);

	bool Application::Start() // Called once at the start
	{
		LN_INFO(e.IsInCategory(EventCategoryKeyboard));

		return ErrorCatch("Failed to initialize the application");
	}

	bool Application::Update() // Called once every tick
	{


		return ErrorCatch("Failed to update the application");
	}
}
