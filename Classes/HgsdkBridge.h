#ifndef __HGSDK_BRIDGE_H__
#define __HGSDK_BRIDGE_H__
#include <string>

#define OPEN_HGSDK 0

class HgsdkBridge {
public :
	bool static preloadOrNot(std::string* group);
};

#endif // __HGSDK_BRIDGE_H__