#pragma once

#include "mtengine/serialization/Data.hpp"

#include <string>

namespace mtengine
{
    namespace serialization
    {
	class ISerializer
	{
	public:
	    virtual void serialize(const Data* data) = 0;
	    virtual Data* deserialize() = 0;
	};	
    }
}
