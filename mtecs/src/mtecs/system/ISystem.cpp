#include "mtecs/system/ISystem.hpp"

namespace mtecs
{
    namespace internal
    {
	ISystem::ISystem(uint id, bool enabled) :
	    id(id),
	    enabled(enabled)
	{
	    
	}
	
	uint ISystem::getId() const
	{
	    return id;
	}
	
	bool ISystem::isEnabled() const
	{
	    return enabled;
	}

	void ISystem::setEnabled(bool enabled)
	{
	    this->enabled = enabled;
	}
    }
}
