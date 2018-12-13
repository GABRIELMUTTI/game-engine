#pragma once

#include "mtengine/serialization/List.hpp"

#include <string>
#include <cstring>


namespace mtengine
{
    namespace serialization
    {
	class Data
	{
	private:
	    enum Type { Int, Float, String, List };
	    typedef union
	    {
		int intValue;
		float floatValue;
		char* stringValue;
		void* listValue;
	    } Value;
	    
	public:	
	    std::string name;
	    Value value;
	    Type type;

	    Data(const std::string& name, int value);
	    Data(const std::string& name, float value);
	    Data(const std::string& name, char* value);
	    Data(const std::string& name, void* value);
	};
    }
}

