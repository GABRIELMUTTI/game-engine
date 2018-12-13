#pragma once

#include "testgame/test/Base.hpp"

namespace testgame
{
    class Test : public Base
    {
        public:
            Test() {}
            Test(int id, int x, float what) : id(id), x(x), what(what) {}

            int id;
            int x;
            float what;
    };
}
