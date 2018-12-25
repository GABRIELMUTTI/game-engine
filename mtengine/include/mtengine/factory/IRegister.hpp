#pragma once

#include "mtengine/factory/Factory.hpp"

namespace mtengine
{
    template<class BaseType, class ... FuncArgs>
    class IRegister
    {
    public:
	virtual void registerTypes(Factory<BaseType, FuncArgs ...>& factory) = 0;
    };
}
