#pragma once

#include "testgame/system/PrintSystem.hpp"

#include <mtengine/factory/IRegister.hpp>
#include <mtengine/system/System.hpp>

namespace testgame
{
    class SystemRegister : public mtengine::IRegister<mtengine::System, int>
    {
	public:
	    void registerTypes(mtengine::Factory<mtengine::System, int>* factory)
	    {
		factory->registerType<PrintSystem>("PrintSystem");
	    }
    };
}
