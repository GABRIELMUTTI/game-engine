#pragma once

/* [[[cog
import json

systemTypesFile = open("/home/gabriel/Documents/projects/game-engine/mtengine/registry/system_registry.json")
jsonStr = systemTypesFile.read()
jsonData = json.loads(jsonStr)

]]] */
// [[[end]]]

/* [[[cog
for type in jsonData:
    cog.outl("#include \"mtengine/system/%s.hpp\"" % type)
]]] */
#include "mtengine/system/S_FirstPersonCamera.hpp"
#include "mtengine/system/S_FirstPersonMovement.hpp"
#include "mtengine/system/S_Input.hpp"
#include "mtengine/system/S_ModelRenderer.hpp"
/// [[[end]]]

#include "mtengine/factory/IRegister.hpp"
#include "mtengine/identifier/UIDGenerator.hpp"

namespace mtengine
{
    class SystemRegister : public IRegister<System, uint>
    {
    private:
	UIDGenerator* uidGenerator;

    public:
	SystemRegister(UIDGenerator& uidGenerator) :
	    uidGenerator(&uidGenerator)
	{
	    
	}
	
	void registerTypes(Factory<System, uint>& factory)
	{
	    /* [[[cog
	       for type in jsonData:
	           cog.outl("uidGenerator->registerType<%s>();" % type)
	           cog.outl("factory.registerType<%s>(uidGenerator->getUID<%s>());" % (type, type))

	       ]]] */
	    uidGenerator->registerType<S_FirstPersonCamera>();
	    factory.registerType<S_FirstPersonCamera>(uidGenerator->getUID<S_FirstPersonCamera>());
	    uidGenerator->registerType<S_FirstPersonMovement>();
	    factory.registerType<S_FirstPersonMovement>(uidGenerator->getUID<S_FirstPersonMovement>());
	    uidGenerator->registerType<S_Input>();
	    factory.registerType<S_Input>(uidGenerator->getUID<S_Input>());
	    uidGenerator->registerType<S_ModelRenderer>();
	    factory.registerType<S_ModelRenderer>(uidGenerator->getUID<S_ModelRenderer>());
	    // [[[end]]]
	}
    };
}
