#pragma once
#include <Lune.h>

class ExampleLayer : public Lune::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnEvent(Lune::Event& e) override
	{
		LN_TRACE("{0}", e);
	}
};
