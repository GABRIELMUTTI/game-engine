#pragma once

namespace utility
{
    template<class T>
    class StructureProperty
    {
        typedef typename T::iterator Iterator;

        private:
            T& structure;
        
        public:
            StructureProperty(T& structure) :
                structure(structure) {}

            Iterator begin() const
            {
                return structure.begin();
            }

            Iterator end() const
            {
                return structure.end();
            }

            std::size_t size() const
            {
                return structure.size();
            }
    };
}
