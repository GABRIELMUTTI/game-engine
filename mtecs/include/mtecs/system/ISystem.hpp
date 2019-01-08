#pragma once

#include "mtecs/typedef/Typedef.hpp"

namespace mtecs
{
    namespace internal
    {
	class ISystem
	{
	private:
	    uint id;
	    bool enabled;
	
	public:
	    ISystem(uint id, bool enabled);
	
	    virtual void update(float deltaTime) = 0;
	    virtual void initialize() = 0;

	    uint getId() const;
	    bool isEnabled() const;

	    void setEnabled(bool enabled);
	};	
    }
}
