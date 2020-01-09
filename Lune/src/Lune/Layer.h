#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Lune
{
	class LUNE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() { LN_TRACE("Layer [{0}] has been attached", m_DebugName); }
		virtual void OnDetach() { LN_TRACE("Layer [{0}] has been detached", m_DebugName); }
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}
