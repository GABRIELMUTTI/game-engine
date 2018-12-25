#pragma once

#include "mtengine/identifier/UID.hpp"

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
	std::unordered_map<const UID, TypeConversionProc> typeConversionProcedures;

	template<typename U, void(*Func)(U)>
	static inline void typeConversionStub(T obj)
	{
	    U u_obj = static_cast<U>(obj);
	    return Func(u_obj);
	}
	    
    public:
	void execute(const UID uid, T obj)
	{
	    TypeConversionProc typeProcedure = typeConversionProcedures[uid];

	    typeProcedure(obj);
	}

	template<typename U, void(*Function)(U)>
	void registerType(const UID uid)
	{
	    typeConversionProcedures[uid] = &typeConversionStub<U, Function>;
	}
    };

}
