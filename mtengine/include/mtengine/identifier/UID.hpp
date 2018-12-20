#pragma once

namespace mtengine
{
    class UID
    {
    private:
	unsigned int id;

    public:
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
