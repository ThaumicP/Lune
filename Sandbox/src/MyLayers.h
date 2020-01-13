#pragma once

class ExampleLayer : public Lune::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{

	}

	void OnEvent(Lune::Event& event) override
	{
		if (event.GetEventType() == Lune::EventType::KeyPressed)
		{
			Lune::KeyPressedEvent& e = (Lune::KeyPressedEvent&)event;
			LN_TRACE("You pressed [{0}]", (char)e.GetKeyCode());
		}
	}
};
