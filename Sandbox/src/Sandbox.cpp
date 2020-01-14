#include "lnpch.h"
#include <Lune.h>

#include "imgui/imgui.h"

class ExampleLayer : public Lune::Layer
{
public:
	ExampleLayer() : Layer("Example") {}


};

class ClientApplication : public Lune::Application
{
public:
	ClientApplication()
	{
		PushLayer(new ExampleLayer());
	}

	~ClientApplication() {}
};

Lune::Application* Lune::CreateApplication()
{
	return new ClientApplication();
}
