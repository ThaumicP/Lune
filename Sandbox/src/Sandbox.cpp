#include "lnpch.h"
#include <Lune.h>

#include "MyLayers.h"

class Sandbox : public Lune::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Lune::ImGuiLayer());
	}

	~Sandbox() {}
};

Lune::Application* Lune::CreateApplication()
{
	return new Sandbox();
}