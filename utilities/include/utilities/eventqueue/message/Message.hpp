#pragma once

#include "../../misc/Variant.hpp"
#include <unordered_map>
#include <cstring>

namespace utility
{
    class Message
    {
        private:
            const unsigned int MAX_VARIANTS = 16;
            const unsigned int STRING_LENGTH = 256;

            std::unordered_map<std::string, int> argumentIndexes;
            Variant* arguments;
            unsigned int count;
            const std::string type;

        public:
            Message(const std::string& type) :
		arguments(new Variant[MAX_VARIANTS]),
                count(0),
		type(type)
            {

            }

            void addArgument(const std::string& name, const int value)
            {
                argumentIndexes[name] = count;
                arguments[count].type = Variant::INTEGER;
                arguments[count].value.ival = value;
                count++;
            }

            void addArgument(const std::string& name, const unsigned int value)
            {
                argumentIndexes[name] = count;
                arguments[count].type = Variant::UINTEGER;
                arguments[count].value.uival = value;
                count++;
            }

            void addArgument(const std::string& name, const float value)
            {
                argumentIndexes[name] = count;
                arguments[count].type = Variant::FLOAT;
                arguments[count].value.fval = value;
                count++;
            }

            void addArgument(const std::string& name, const bool value)
            {
                argumentIndexes[name] = count;
                arguments[count].type = Variant::BOOL;
                arguments[count].value.bval = value;
                count++;
            }

            void addArgument(const std::string& name, const std::string& value)
            {
                argumentIndexes[name] = count;
                arguments[count].type = Variant::STRING;
                arguments[count].value.strval = new char[STRING_LENGTH];
                strcpy(arguments[count].value.strval, value.c_str());
                count++;
            }

            std::string getType()
            {
                return type;
            }

            int getInt(const std::string& name)
            {
                unsigned int index = argumentIndexes[name];
                return arguments[index].value.ival;
            }

            unsigned int getUnsignedInt(const std::string& name)
            {
                unsigned int index = argumentIndexes[name];
                return arguments[index].value.uival;
            }

            float getFloat(const std::string& name)
            {
                unsigned int index = argumentIndexes[name];
                return arguments[index].value.fval;
            }

            bool getBool(const std::string& name)
            {
                unsigned int index = argumentIndexes[name];
                return arguments[index].value.bval;
            }

            std::string getString(const std::string& name)
            {
                unsigned int index = argumentIndexes[name];
                return std::string(arguments[index].value.strval);
            }

            bool hasArgument(const std::string& name)
            {
                auto it = argumentIndexes.find(name);
                if (it != argumentIndexes.end())
                {
                    return true;
                }
                
                return false;
            }
    };
}
