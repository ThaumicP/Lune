#include <Lune.h>

class Sandbox : public Lune::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Lune::Application* Lune::CreateApplication()
{
	return new Sandbox();
}
