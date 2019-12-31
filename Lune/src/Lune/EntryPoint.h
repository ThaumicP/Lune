#pragma once

#ifdef LN_PLATFORM_WINDOWS

extern Lune::Application* Lune::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Lune::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif
