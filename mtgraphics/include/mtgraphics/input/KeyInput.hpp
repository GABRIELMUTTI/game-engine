#pragma once

#include "mtgraphics/engine/GLInclude.hpp"

#include <functional>

namespace mtgraphics
{
    class KeyInput
    {
    public:
	const GLuint windowId;
	const GLint key;
	const GLint scancode;
	const GLint action;
	const GLint mods;

	KeyInput(GLuint windowId, GLint key, GLint scancode, GLint action, GLint mods) :
	    windowId(windowId),
	    key(key),
	    scancode(scancode),
	    action(action),
	    mods(mods)
	{

	}
    };
}

namespace std
{
    template<>
    struct hash<mtgraphics::KeyInput>
    {
        std::size_t operator()(const mtgraphics::KeyInput& keyInput) const
        {
            return (std::hash<int>()(keyInput.key) ^
                    ((std::hash<int>()(keyInput.action) << 1) >> 1) ^
                    ((std::hash<int>()(keyInput.mods) << 1)));
        }
    };

    inline bool operator==(const mtgraphics::KeyInput& lhs, const mtgraphics::KeyInput& rhs)
    {
        if (lhs.key != rhs.key) { return false; }
        if (lhs.action != rhs.action) { return false; }
        if (lhs.mods != rhs.mods) { return false; }

        return true;
    }

    inline bool operator!=(const mtgraphics::KeyInput& lhs, const mtgraphics::KeyInput& rhs)
    {
        return !(lhs == rhs);
    }
}
