#pragma once

#include <vector>
#include <string>

namespace mtengine
{
    namespace serialization
    {
	class Data;
	
	class List
	{
	private:
	    std::vector<Data*> pairs;
	    
	public:
	    List();

	    void add(Data* data);
	    void remove(const std::string& name);
	    Data* getData(const std::string& name);
	    unsigned int size();
	};
    }
}
