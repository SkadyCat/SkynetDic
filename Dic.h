#pragma once

#include <iostream>
#include <unordered_map>

using namespace std;
class Dic
{


public:

	static unordered_map<string,unordered_map<string , int>*>* maps;
	void static add(string map,string key, int address);
	string static createMap(string key);
	int static init();
	int static get(string map,string key);
	Dic();
	~Dic();
};

