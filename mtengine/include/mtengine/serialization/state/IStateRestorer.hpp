#pragma once

#include "mtengine/system/System.hpp"
#include "mtengine/serialization/Data.hpp"
    
#include <mtecs/component/Component.hpp>
    
namespace mtengine
{
    class IStateRestorer
    {	    
    public:
	virtual void restore(serialization::Data* state) = 0;
    };
}
