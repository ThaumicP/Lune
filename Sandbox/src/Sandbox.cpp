#include "lnpch.h"
#include <Lune.h>

#include "imgui/imgui.h"

class ExampleLayer : public Lune::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World!");
		ImGui::End();
	}
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
