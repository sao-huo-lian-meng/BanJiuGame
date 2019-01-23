#ifndef _RECIPES
#define _RECIPES

#include "bigint.h"
#include "res.h"
#include "equip.h"
/////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

extern resource resources[1005];

struct recipe{
	vector<int> res;
	vector<bigint> rescnt;
	recipe(){};
	recipe(int* _res,bigint* _rescnt){
		//TODO:recipe constructor
	}
};
#endif
