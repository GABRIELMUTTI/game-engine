#pragma once

/* [[[cog
import json

componentTypesFile = open("/home/gabriel/Documents/projects/game-engine/mtengine/registry/component_registry.json")
jsonStr = componentTypesFile.read()
jsonData = json.loads(jsonStr)

]]] */
// [[[end]]]

/* [[[cog
for type in jsonData:
    cog.outl("#include \"mtengine/component/%s.hpp\"" % type)
]]] */
#include "mtengine/component/C_Transform.hpp"
#include "mtengine/component/C_Input.hpp"
#include "mtengine/component/C_FirstPersonMovement.hpp"
#include "mtengine/component/C_Camera.hpp"
/// [[[end]]]

#include "mtengine/factory/IRegister.hpp"
#include "mtengine/identifier/UIDGenerator.hpp"

namespace mtengine
{
    class ComponentRegister : public IRegister<Component>
    {
    private:
	UIDGenerator* uidGenerator;

    public:
	ComponentRegister(UIDGenerator& uidGenerator) :
	    uidGenerator(&uidGenerator)
	{
	    
	}
	
	void registerTypes(Factory<Component>& factory)
	{
	    /* [[[cog
	       for type in jsonData:
	           cog.outl("uidGenerator->registerType<%s>();" % type)
	           cog.outl("factory.registerType<%s>(uidGenerator->getUID<%s>());" % (type, type))

	       ]]] */
	    uidGenerator->registerType<C_Transform>();
	    factory.registerType<C_Transform>(uidGenerator->getUID<C_Transform>());
	    uidGenerator->registerType<C_Input>();
	    factory.registerType<C_Input>(uidGenerator->getUID<C_Input>());
	    uidGenerator->registerType<C_FirstPersonMovement>();
	    factory.registerType<C_FirstPersonMovement>(uidGenerator->getUID<C_FirstPersonMovement>());
	    uidGenerator->registerType<C_Camera>();
	    factory.registerType<C_Camera>(uidGenerator->getUID<C_Camera>());
	    // [[[end]]]
	}
    };
}
