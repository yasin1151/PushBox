#include "NumberSplit.h"



NumberSplit* NumberSplit::create(const std::string& fileName)
{
	NumberSplit* pNum = new NumberSplit;
	
	if (pNum && pNum->initWithFile(fileName))
	{
		pNum->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pNum);
	}

	return pNum;
}


bool NumberSplit::initWithFile(const std::string& fileName)
{
	
	return true;
}
