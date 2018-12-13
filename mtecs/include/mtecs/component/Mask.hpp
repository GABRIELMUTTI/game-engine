#pragma once

#include <cmath>

namespace mtecs
{
    class Mask
    {
    private:
	int mask;
	unsigned int maskIndex;

	void updateIndex();
	
    public:
	enum Has { All, Any };

	Mask();
	Mask(int mask);

	void update(const Mask& addition);
	void remove(const Mask& deduction);
	bool has(const Mask& mask, Has has = Has::All) const;
	unsigned int index() const;
	int getMask() const;

            
	Mask maskOr(const Mask& mask) const;
	Mask maskAnd(const Mask& mask) const;
            
	bool operator ==(const Mask& other) const
	{
	    return (mask | other.mask) == mask;
	}

	bool operator !=(const Mask& other) const
	{
	    return !(*this == other);
	}

	bool operator <(const Mask& other) const
	{
	    return mask < other.mask;
	}
    };
}
