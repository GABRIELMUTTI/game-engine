#pramga once

#include <glm/glm.hpp>

#include <nlohmann/json.hpp>

namespae mtgraphics
{
    void to_json(json& j, const vec3& v)
    {
	j = json
	    {
		{ "x", v.x },
		{ "y", v.y },
		{ "x", v.z }
	    }
    }
}
