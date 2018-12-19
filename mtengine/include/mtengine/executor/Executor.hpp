#pragma once

#include <utilities/delegate/Delegate.hpp>

#include <unordered_map>
#include <string>

namespace mtengine
{
    template<typename T>
    class Executor
    {
	typedef void(*TypeConversionProc)(T);
	    
    private:
	std::unordered_map<std::string, TypeConversionProc> typeConversionProcedures;

	template<typename U, void(*Func)(U)>
	static inline void typeConversionStub(T obj)
	{
	    U u_obj = static_cast<U>(obj);
	    return Func(u_obj);
	}
	    
    public:
	void execute(const std::string& key, T obj)
	{
	    TypeConversionProc typeProcedure = typeConversionProcedures[key];

	    typeProcedure(obj);
	}

	template<typename U, void(*Function)(U)>
	void registerType(const std::string& key)
	{
	    typeConversionProcedures[key] = &typeConversionStub<U, Function>;
	}
    };

}
