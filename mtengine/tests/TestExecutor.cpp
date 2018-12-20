#include <iostream>
#include <typeinfo>

#include "mtengine/executor/Executor.hpp"
#include "mtengine/component/C_Transform.hpp"
#include "mtengine/component/C_Camera.hpp"

#include <mtecs/component/Component.hpp>


#include <utilities/delegate/Delegate.hpp>

#include <nlohmann/json.hpp>


using namespace mtengine;
using namespace mtecs;
using namespace utility;
using json = nlohmann::json;

namespace glm
{
    void to_json(json& j, const vec3& v)
    {
	j = json
	    {
		{ "x", v.x },
		{ "y", v.y },
		{ "x", v.z }
	    };
    }
}

template<typename T>
static inline void testFunction(T* comp)
{
    meta::doForAllMembers<T>(
	[&comp](const auto& member)
	{
	    json j;
	    j[member.getName()] = (member.get(*comp));

	    std::cout << j << std::endl;
	});
}

int main()
{
    Executor<Component*> executer;
    
    executer.registerType<C_Transform*, &testFunction<C_Transform>>("C_Transform");
    executer.registerType<C_Camera*, &testFunction<C_Camera>>("C_Camera");


    Component* baseTransform = new C_Transform();
    Component* baseCamera = new C_Camera();

    std::cout << "With Executor::" << std::endl;
    executer.execute("C_Transform", baseTransform);
    std::cout << "Camera::" << std::endl;
    executer.execute("C_Camera", baseCamera);


    
    

    

    return 0;
}
