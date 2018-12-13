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

            Iterator begin()
            {
                return structure.begin();
            }

            Iterator end()
            {
                return structure.end();
            }

            std::size_t size()
            {
                return structure.size();
            }
    };
}
