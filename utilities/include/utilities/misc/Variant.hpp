#pragma once

namespace utility
{
    struct Variant
    {
        enum Type 
        {
            INTEGER,
            UINTEGER,
            FLOAT,
            BOOL,
            STRING,
        };

        Type type;

        union
        {
            int ival;
            unsigned int uival;
            float fval;
            bool bval;
            char* strval;
        } value;

        Variant()
        {

        }
    };
}
