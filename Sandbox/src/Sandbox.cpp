#include "lnpch.h"
#include "MyLayers.h"

class Sandbox : public Lune::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {}
};

Lune::Application* Lune::CreateApplication()
{
	return new Sandbox();
}
