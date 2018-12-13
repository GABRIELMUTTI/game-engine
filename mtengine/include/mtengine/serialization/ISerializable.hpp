#pragma once

#include "mtengine/serialiation/Data.hpp"

namespace mtengine
{
    namespace serialization
    {
	class ISerializable
	{
	public:
	    Data* serialize() const = 0;
	    void deserialize(const Data* data) = 0; 
	};	
    }
    
}
