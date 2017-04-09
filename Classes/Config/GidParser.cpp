#include "GidParser.h"

bool GidParser::Parse(const char* fileName)
{
	
	if (!fileName)
	{
		return false;
	}

	using namespace tinyxml2;
	auto handler = GidHandler::GetInstance();
	XMLDocument doc;
	doc.LoadFile(fileName);
	XMLElement* Root = doc.RootElement();


	if (!Root)
	{
		return false;
	}

	XMLElement* Node = Root->FirstChildElement();

	string name;
	int gid;

	while (Node)
	{
		auto ChildNode = Node->FirstChildElement();

		name = ChildNode->GetText();
		ChildNode = ChildNode->NextSiblingElement();

		gid = atoi(ChildNode->GetText());

		handler->insert(std::move(name), gid);
		Node = Node->NextSiblingElement();
	}

	return true;
}
