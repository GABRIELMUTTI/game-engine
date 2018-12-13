#pragma once

namespace mtengine
{
    class PointerInput
    {
	public:
	    const unsigned int windowId;
	    const float xPos;
	    const float yPos;

	    PointerInput(unsigned int windowId, float xPos, float yPos) :
		windowId(windowId),
		xPos(xPos),
		yPos(yPos)
	    {
		
	    }
    };
}
