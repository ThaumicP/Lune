#pragma once

#include "Lune/Layer.h"

#include "Lune/Events/ApplicationEvent.h"
#include "Lune/Events/KeyEvent.h"
#include "Lune/Events/MouseEvent.h"

namespace Lune
{
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}
