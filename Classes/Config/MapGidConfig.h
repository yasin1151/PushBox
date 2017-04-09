#ifndef _MapGidConfig_H_
#define _MapGidConfig_H_

#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;


class MapGidNode
{
public:
	unordered_map<string, int> gidMap;

	int operator[] (const string& name)
	{
		return gidMap[name];
	}

	void insert(const string& name, int gid)
	{
		gidMap[name] = gid;
	}

};

#endif