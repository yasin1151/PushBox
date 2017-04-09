#ifndef _GidHandler_H_
#define _GidHandler_H_

#include "MapGidConfig.h"
#include "yUtils\Helper\Handler\HandlerTemplate.h"
#include "yUtils\Tmp\CSingleInstanceTmp.h"


using namespace yUtils;

class GidHandler : public MapGidNode,
					public CSingleInstanceTmp<GidHandler>
{

};

#define GID (*(GidHandler::GetInstance()))


#endif