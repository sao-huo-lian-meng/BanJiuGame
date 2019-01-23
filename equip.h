#ifndef _EQUIP
#define _EQUIP


#include "bigint.h"
/////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

struct equip{
	int equiptype;
	string name;
	string description;
	bigint damage;
	bigint defense;
	double speed;
	double damagemultiplier;
	double defensemultiplier;
	double speedmultiplier;
	bool isdelta;
	/////////////////////////////////////////////////
	equip():
	equiptype(0),name("equipname"),description("This is a text"),
	damage(10),defense(10),speed(5),
	damagemultiplier(1),defensemultiplier(1),speedmultiplier(1),
	isdelta(true){}
	/////////////////////////////////////////////////
	equip(int _equiptype,string _name,string _description,
		bigint _damage,bigint _defense,double _speed,
		double _damagemultiplier,double _defensemultiplier,double _speedmultiplier,
		bool _isdelta):
	equiptype(_equiptype),name(_name),description(_description),
	damage(_damage),defense(_defense),speed(_speed),
	damagemultiplier(_damagemultiplier),defensemultiplier(_defensemultiplier),speedmultiplier(_speedmultiplier),
	isdelta(_isdelta){}
};

//TODO:Define equipments

#endif
