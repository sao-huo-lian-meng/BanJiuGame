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
//TODO:������λС�� 

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
	defres(1  ,"���","");
	defres(2  ,"�����","���֮Դ");
	defres(3  ,"ľͷ","");
	defres(4  ,"ʯͷ","");
	defres(5  ,"ͭ","");
	defres(6  ,"��","");
	defres(7  ,"��","");
	defres(8  ,"��","");
	defres(9  ,"��","");
	defres(10 ,"����","");
	defres(11 ,"Ǧ","");
	defres(12 ,"��","");
	defres(13 ,"��","");
	defres(14 ,"�ѽ�","");
	defres(15 ,"�ѺϽ�","ûë��");
	defres(16 ,"����ʯ","");
	defres(17 ,"ʯӢ","");
	defres(18 ,"������","Ȼ����");
	defres(19 ,"����","");
	defres(20 ,"��ˮ��","");
	defres(21 ,"��ˮ��","");
	defres(22 ,"��ˮ��","");
	defres(23 ,"��ˮ��","");
	defres(24 ,"��ˮ��","");
	defres(25 ,"��ʯ","");
	defres(26 ,"��ʯ","�ⲻ��ѧ");
	defres(27 ,"��ʯ","");
	defres(28 ,"����","");
	defres(29 ,"�Ѫʯ","�������Ѫ");
	defres(30 ,"��ħ��","");
	defres(31 ,"��ħ��","");
	defres(32 ,"��ħ��","");
	defres(33 ,"��ħ��","");
	defres(34 ,"��ħ��","");
	defres(35 ,"��ħ��","");
	defres(36 ,"����ħ��","���ħ��");
	defres(37 ,"ǿ��ʯ","");
	defres(38 ,"���","");
	defres(39 ,"����֮ʯ","Al+Cu=Au+Cl");
	defres(40 ,"�ٽ�","");
	defres(41 ,"��","");
	defres(42 ,"��","����ȶ�");
	defres(43 ,"��","");
	defres(44 ,"봽�","�ԣ���û��봽�");
	defres(45 ,"��ľ","");
	defres(46 ,"���","");
	defres(47 ,"����","");
	defres(48 ,"ʥ��","");
	defres(49 ,"��õ�����","");
	defres(50 ,"������","");
	defres(51 ,"����","������������ǿ��Ļ��͵�");
	defres(52 ,"����","");
	defres(53 ,"����","�����ȡ����");
	defres(54 ,"��ѧ����","���ö�~");
	defres(55 ,"���","");
	defres(56 ,"���","");
	defres(57 ,"��ש","");
	defres(58 ,"�ڰ���ש","");
	defres(59 ,"������","�������ϻ��������������������");
	defres(60 ,"��(Sb)","һ��SB�����ʣ�������������һ��");
	defres(61 ,"��ֽ","");
	defres(62 ,"�Ծ�","");
	defres(63 ,"��ҵ��","����ѧ���޾������");
	defres(64 ,"����","");
	defres(65 ,"�ڹ�","");
	defres(66 ,"��","");
	defres(67 ,"����","");
	defres(68 ,"���","����֮�󣬱�ֻʣ�������");
	defres(69 ,"���ܵ�����","");
	defres(70 ,"�����ܵ�����","");
	defres(71 ,"�����ܵ�����","");
	defres(72 ,"�����ܵ�����","Ȼ��û��̮���ɺڶ�");
	defres(73 ,"����","");
	defres(74 ,"����","");
	defres(75 ,"�ҽ�","���ʵļ��¡�");
}

#endif



























