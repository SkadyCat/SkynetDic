#include "Dic.h"
#include <cstdio>
extern "C" {
#include <lua5.3/lua.h>
#include <lua5.3/lauxlib.h>
#include <lua5.3/lualib.h>
};

#include <iostream>  
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

unordered_map<string, unordered_map<string, int>*>* Dic::maps;
void Dic::add(string map, string key, int address)
{
	// cout<<map<<maps->count(map);
	if (maps->count(map) == 0) {
		createMap(map);
	}
	unordered_map<string, int>* selectMap = (*maps)[map];
	selectMap->insert({ key,address });
}
string Dic::createMap(string key) {
	unordered_map<string, int>* tp = new unordered_map<string, int>();
	maps->insert({ key,tp });
	return key;
}
int Dic::get(string map, string key)
{
	unordered_map<string, int>* selectMap = (*maps)[map];
	return (*selectMap)[key];
}



int Dic::init() {

	if (maps == nullptr) {
		maps = new unordered_map<string, unordered_map<string, int>*>();

	}

	return 0;
}
Dic::Dic()
{


}

Dic::~Dic()
{
}
extern "C" int init(lua_State * L) {



	Dic::init();

	return 0;
}
extern "C" int get(lua_State * L) {

	size_t lens = 0;
	
	string v1(luaL_checkstring(L, 1));
	string v2(luaL_checkstring(L, 2));
	//printf("%s,%s,%d----------len = %ld\n","try find ",val,Dic::get((val)),Dic::maps->size());
	lua_pushnumber(L, Dic::get(v1,v2));
	return 1;
}

extern "C" int add(lua_State * L) {
	size_t lens = 0;

	string map(luaL_checkstring(L, 1));
	string key(luaL_checkstring(L, 2));
	int v2 = luaL_checkinteger(L, 3);

	// cout<<map<<key<<v2;
	Dic::add(map,key,v2);
	//printf("%s--------------%d",(val),v2);
	return 0;
}

static luaL_Reg luaLibs[] =
{
	{ "get", get },
	{"add",add},
	{"init",init},
	{ NULL, NULL }
};
extern "C" int luaopen_Dic(lua_State * L) {
	lua_newtable(L);
	luaL_setfuncs(L, luaLibs, 0);
	return 1;
}
