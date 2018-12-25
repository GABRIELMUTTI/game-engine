#pragma once

#include <unordered_map>

namespace utility
{
    class UID
    {
    public:
	unsigned int id;

	UID() :
	    id(0)
	{
	    
	}
	
	UID(unsigned int id) :
	    id(id)
	{
	    
	}
	
	bool operator ==(const UID& other) const
	{
	    return id == other.id;
	}

	bool operator !=(const UID& other) const
	{
	    return id != other.id;
	}
	
	bool operator <(const UID& other) const
	{
	    return id < other.id;
	}

	bool operator >(const UID& other) const
	{
	    return id > other.id;
	}

	bool operator <=(const UID& other) const
	{
	    return id <= other.id;
	}

	bool operator >=(const UID& other) const
	{
	    return id >= other.id;
	}
    };
}

namespace std
{
    using utility::UID;
    
    template<>
    struct hash<UID>
    {
	std::size_t operator()(const UID& uid) const
	{
	    return std::hash<unsigned int>()(uid.id);
	}
    };
}
