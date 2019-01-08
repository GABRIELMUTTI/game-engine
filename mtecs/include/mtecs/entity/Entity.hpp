#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/component/Mask.hpp"

#include <string>

namespace mtecs
{
    class Entity
    {	
    private:
	uint id;
	std::string name;
	Mask mask;

    public:
	Entity(uint id, const std::string& name);

	uint getId() const;
	std::string getName() const;
	Mask getMask() const;
	    
	bool hasComponents(const Mask& componentMask) const;
	void setMask(const Mask& mask);
    };
}
