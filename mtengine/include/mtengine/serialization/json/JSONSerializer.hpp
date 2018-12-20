#pragma once

#include "mtengine/serialization/ISerializer.hpp"

#include <nlohmann/json.hpp>
#include <MetaStuff/include/Meta.h>

namespace mtengine
{
    namespace serialization
    {
	using json = nlohman::json;
	
	class JSONSerializer : public ISerializer<JSONSerializer>
	{
	public:
	    template<typename T>
	    std::string serialize(const T& obj)
	    {
		json j = obj;
		return j.dump()
	    }

	    template<typename T>
	    void deserialize(T& obj, const std::string& serializedState)
	    {
		const json j = json::parse(serializedState);

		meta::doForAllMembers<T>(
		    [&obj, const &j](auto& member)
		    {
			auto& objName = j[member.getName()];

			if (!objname.is_null())
			{
			    using TMember = meta::get_member_type<decltype(member)>;

			
			    if (member.hasSetter())
			    {
				member.set(obj, objName.template get<TMember>());
			    }
			    else if (member.canGettRef())
			    {
				member.getReg(obj) = objName.template get<TMember>();
			    }
			    else
			    {
				throw std::runtime_error("Error: can't deserialize member because it's read only.");
			    }
			}
			else
			{
			    throw std::runtime_error("Error: can't deserialize from Json::json to Class.");
			}
		    });
	    }
	};
    }
}
