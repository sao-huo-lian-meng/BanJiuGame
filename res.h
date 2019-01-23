#ifndef _RES
#define _RES


/*
	Resources
		1.resources
			define
			output
			defkind
	#end
*/


#include "bigint.h"
/////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

//struct resource

struct resource {
	string name;
	string description;
	bigint count;
	resource(){
		name="test";
		description="This is a text";
		count=0;
	}
	resource(string _name,string _description){
		name=_name;
		description=_description;
		count=0;
	}
};

//output resources
//TODO:保留三位小数 

const int log10s[15]= {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int log10(const bigint &x) {
	return (x.s.size()-1)*8+(lower_bound(log10s,log10s+10,x.s.back())-log10s);
}
ostream &operator << (ostream &out, const resource &x) {
	if(x.count!=bigint()) {
		register int digits=log10(x.count);
		out << x.name << ":";
		if(x.count.s.size()==1&&x.count.s.back()<9000)out << x.count.s.back();
		else out << double(x.count.s.back())/(log10s[digits%8]) << "*10^" <<digits;
	}
	return out;
}

resource resources[1005];

//define resources.

void defres(int id,string _name,string _description){
	resources[id]=resource(_name,_description);
}

//the resources are defined below:
//TODO:new resources

void resinit(){
	defres(1  ,"斑鸠","");
	defres(2  ,"烤斑鸠","万恶之源");
	defres(3  ,"木头","");
	defres(4  ,"石头","");
	defres(5  ,"铜","");
	defres(6  ,"锡","");
	defres(7  ,"银","");
	defres(8  ,"金","");
	defres(9  ,"钨","");
	defres(10 ,"铂金","");
	defres(11 ,"铅","");
	defres(12 ,"铁","");
	defres(13 ,"钢","");
	defres(14 ,"钛金","");
	defres(15 ,"钛合金","没毛病");
	defres(16 ,"黑曜石","");
	defres(17 ,"石英","");
	defres(18 ,"土豪金","然并卵");
	defres(19 ,"琥珀","");
	defres(20 ,"红水晶","");
	defres(21 ,"黄水晶","");
	defres(22 ,"绿水晶","");
	defres(23 ,"蓝水晶","");
	defres(24 ,"紫水晶","");
	defres(25 ,"钻石","");
	defres(26 ,"符石","这不科学");
	defres(27 ,"磁石","");
	defres(28 ,"熔岩","");
	defres(29 ,"鸠血石","就像斑鸠的血");
	defres(30 ,"红魔晶","");
	defres(31 ,"黄魔晶","");
	defres(32 ,"绿魔晶","");
	defres(33 ,"蓝魔晶","");
	defres(34 ,"紫魔晶","");
	defres(35 ,"白魔晶","");
	defres(36 ,"符文魔晶","这很魔法");
	defres(37 ,"强磁石","");
	defres(38 ,"真火","");
	defres(39 ,"贤者之石","Al+Cu=Au+Cl");
	defres(40 ,"钯金","");
	defres(41 ,"钴","");
	defres(42 ,"铀","这很稳定");
	defres(43 ,"钚","");
	defres(44 ,"氪金","对，你没有氪金");
	defres(45 ,"灵木","");
	defres(46 ,"魂冰","");
	defres(47 ,"狱岩","");
	defres(48 ,"圣土","");
	defres(49 ,"最好的物质","");
	defres(50 ,"豆腐块","");
	defres(51 ,"黄油","可以用来制作强大的黄油刀");
	defres(52 ,"奶酪","");
	defres(53 ,"曲奇","点击获取曲奇");
	defres(54 ,"哲学物质","辣妹儿~");
	defres(55 ,"电池","");
	defres(56 ,"培根","");
	defres(57 ,"板砖","");
	defres(58 ,"黑暗板砖","");
	defres(59 ,"滑稽果","滑稽树上滑稽果，滑稽树下你和我");
	defres(60 ,"锑(Sb)","一种SB的物质，就像它的名字一样");
	defres(61 ,"稿纸","");
	defres(62 ,"试卷","");
	defres(63 ,"作业本","带给学生无尽的题库");
	defres(64 ,"大象","");
	defres(65 ,"乌龟","");
	defres(66 ,"蛇","");
	defres(67 ,"基岩","");
	defres(68 ,"虚空","基岩之后，便只剩下了虚空");
	defres(69 ,"致密的物质","");
	defres(70 ,"很致密的物质","");
	defres(71 ,"更致密的物质","");
	defres(72 ,"最致密的物质","然而没有坍缩成黑洞");
	defres(73 ,"凝胶","");
	defres(74 ,"软泥","");
	defres(75 ,"灰烬","物质的极致。");
}

#endif



























