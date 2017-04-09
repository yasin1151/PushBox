#ifndef __NumberSplit__H__
#define __NumberSPlit__H__
#include "cocos2d.h"
USING_NS_CC;

class NumberSplit : public Ref
{
protected:
	Size m_numSize;

public:
	static NumberSplit* create(const std::string& fileName);
	bool initWithFile(const std::string& fileName);

};

#endif
