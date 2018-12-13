#pragma once

#include "mtengine/serialization/Data.hpp"

#include <string>
    
namespace mtengine
{
    namespace serialization
    {
	class IStateLoader
	{
	public:
	    virtual Data* load(const std::string& filepath); 
	};	
    }
}
