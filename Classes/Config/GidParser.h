#ifndef _GidParser_H_
#define _GidParser_H_

#include "yUtils\Helper\Parser\AbsParser.h"
#include "GidHandler.h"
#include "yUtils\Helper\tinyxml2.h"

using namespace yUtils;

class GidParser : public CAbsParser
{
public:
	bool Parse(const char* fileName) override;
};

#endif