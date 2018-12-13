#include "mtecs/component/Mask.hpp"

namespace mtecs
{
    Mask::Mask()
    {
        mask = 0;
    }

    Mask::Mask(int mask)
    {
        this->mask = mask;
        updateIndex();
    }

    void Mask::update(const Mask& addition)
    {
        mask |= addition.mask;
        updateIndex();
    }

    void Mask::remove(const Mask& deduction)
    {
        mask ^= deduction.mask;
        updateIndex();
    }

    bool Mask::has(const Mask& mask, Has has) const
    {
        if (has == Has::All)
        {
            return (this->mask | mask.mask) == this->mask;
        }
        else
        {
            return (this->mask & mask.mask) != 0;
        }
    }

    unsigned int Mask::index() const
    {
        return maskIndex;
    }

    void Mask::updateIndex()
    {
        maskIndex = std::log2(mask);
    }

    int Mask::getMask() const
    {
        return mask;
    }

    Mask Mask::maskOr(const Mask& mask) const
    {
        return Mask(this->mask | mask.mask);
    }

    Mask Mask::maskAnd(const Mask& mask) const
    {
        return Mask(this->mask & mask.mask);
    }
}
