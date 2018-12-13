#pragma once

#include <utility>

namespace utility
{
    template<class T>
    class Delegate
    {
        typedef void* InstancePtr;
        typedef void(*InternalFunction)(InstancePtr, T);
        typedef std::pair<InstancePtr, InternalFunction> Stub;

        private:
            Stub stub;

        private:
            template<class Class, void(Class::*Function)(T)>
            static inline void classMethodStub(InstancePtr instance, T arg)
            {
                return (static_cast<Class*>(instance)->*Function)(arg);
            }

            template<void(*Function)(T)>
            static inline void freeMethodStub(InstancePtr instance, T arg)
            {
                return Function(arg);
            }

        public:
            void invoke(T arg)
            {
                return stub.second(stub.first, arg);
            }

            template<class Class, void(Class::*Function)(T)>
            void bind(Class* instance)
            {
                stub.first = instance;
                stub.second = &classMethodStub<Class, Function>;
            }

            template<void(*Function)(T)>
            void bind()
            {
                stub.first = nullptr;
                stub.second = &freeMethodStub<Function>;
            }
    };
}
