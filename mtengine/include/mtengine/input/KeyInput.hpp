#pragma once

#include <string>

namespace mtengine
{
    class KeyInput
    {
    private:
	std::string windowIdToken = "WindowId=";
	std::string keyToken = "Key=";
	std::string scancodeToken = "Scancode=";
	std::string actionToken = "Action=";
	std::string modsToken = "Mods=";
	    
	void fromString(const std::string& str)
	{
	    int windowId, key, scancode, action, mods;
		
	    std::size_t windex = str.find(windowIdToken);
	    std::size_t kindex = str.find(keyToken);
	    std::size_t sindex = str.find(scancodeToken);
	    std::size_t aindex = str.find(actionToken);
	    std::size_t mindex = str.find(modsToken);
		
	    windowId =  stoi(str.substr(windex + windowIdToken.size()   , kindex - windowIdToken.size()));
	    key =       stoi(str.substr(kindex + keyToken.size()        , sindex - keyToken.size()));
	    scancode =  stoi(str.substr(sindex + scancodeToken.size()   , aindex - scancodeToken.size()));
	    action =    stoi(str.substr(aindex + actionToken.size()     , mindex - actionToken.size()));
	    mods =      stoi(str.substr(mindex + modsToken.size()       , str.size() - (mindex + modsToken.size())));
		
	    this->windowId = windowId;
	    this->key = key;
	    this->scancode = scancode;
	    this->action = action;
	    this->mods = mods;
	}
	    
    public:
	int windowId;
	int key;
	int scancode;
	int action;
	int mods;
	    	
	KeyInput(int windowId, int key, int scancode, int action, int mods) :
	    windowId(windowId),
	    key(key),
	    scancode(scancode),
	    action(action),
	    mods(mods)
	{
		
	}

	KeyInput(const std::string& str)
	{

	}
      
	std::string toString() const
	{
	    std::string output;
	    output.append(windowIdToken);     output.append(std::to_string(windowId));
	    output.append(keyToken);          output.append(std::to_string(key));
	    output.append(scancodeToken);     output.append(std::to_string(scancode));
	    output.append(actionToken);       output.append(std::to_string(action));
	    output.append(modsToken);         output.append(std::to_string(mods));
                
	    return output;
	}
    };
}

namespace std
{
    template<>
    struct hash<mtengine::KeyInput>
    {
        std::size_t operator()(const mtengine::KeyInput& keyInput) const
        {
            return (std::hash<int>()(keyInput.key) ^
                    ((std::hash<int>()(keyInput.action) << 1) >> 1) ^
                    ((std::hash<int>()(keyInput.mods) << 1)));
        }
    };

    inline bool operator==(const mtengine::KeyInput& lhs, const mtengine::KeyInput& rhs)
    {
        if (lhs.key != rhs.key) { return false; }
        if (lhs.action != rhs.action) { return false; }
        if (lhs.mods != rhs.mods) { return false; }

        return true;
    }

    inline bool operator!=(const mtengine::KeyInput& lhs, const mtengine::KeyInput& rhs)
    {
        return !(lhs == rhs);
    }
}
