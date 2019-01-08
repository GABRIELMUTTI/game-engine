#pragma once

namespace mtecs
{
    namespace internal
    {
	template<class T>
	class ISetter
	{
	public:
	    virtual void set(T& obj) = 0;
	};	
    }
}
