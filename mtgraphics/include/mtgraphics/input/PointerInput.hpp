#pragma once

#include "mtgraphics/engine/GLInclude.hpp"

namespace mtgraphics
{
    class PointerInput
    {
    public:
	const GLuint windowId;
	const GLint xPos;
	const GLint yPos;

	PointerInput(GLuint windowId, GLint xPos, GLint yPos) :
	    windowId(windowId),
	    xPos(xPos),
	    yPos(yPos)
	{

	}
    };
}
