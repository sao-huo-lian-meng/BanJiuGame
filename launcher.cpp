/************************************************
*   Name: Game Loader
*   Author: zrl,wenge
*   C++ is the best language in the world
************************************************/
///////////////////includes//////////////////////
#include <windows.h>
#include <bits/stdc++.h>
#include <conio.h>
#include "map.h"
using namespace std;
/////////////////definitions/////////////////////
char inputbuffer[10000];
char* inputstr() {
	cin>>inputbuffer;
	return inputbuffer;
}
char worldlist[105][105];
void printmain() {
	cout<<"###############################################"<<endl;
	cout<<"#               Version:beta 0.0.0            #"<<endl;
	cout<<"#      Copyright by Saohuo Lianmeng Studio    #"<<endl;
	cout<<"#              [1]Create a world              #"<<endl;
	cout<<"#              [2]Delete a world              #"<<endl;
	cout<<"#              [3]Load a world                #"<<endl;
	cout<<"#              [4]Exit                        #"<<endl;
	cout<<"###############################################"<<endl;
	return;
}
void firstlaunch() {
	ofstream fl;
	fl.open("data\\setting.ini");
	cout<<"What language do you want to use?\n您在游戏中想使用什么语言？\n";
	cout<<"   [1] English\n";
	cout<<"   [2] 简体中文\n";
	cout<<"   [3] 正體中文\n";
	char pi;
	while(1) {
		pi=getch();

		if(pi=='1') {
			fl<<pi<<'\n';
			cout<<"Setting up, please wait...\n";
			break;
		}
		if(pi=='2') {
			fl<<pi<<'\n';
			cout<<"正在配置游戏，请稍等...\n";
			break;
		}
		if(pi=='3') {
			fl<<pi<<'\n';
			cout<<"正在配置遊戲，請稍等...\n";
			break;
		}
	}
	return;
}
ifstream file;
char in;
//////////////////////main///////////////////////
int main() {
	ifstream load;
	int lt;
	load.open("data\\record.rec");
	load>>lt;
	if(lt==0)
		firstlaunch();
	load.close();
	remove("data\\record.rec");
	ofstream li;
	li.open("data\\record.rec");
	li<<lt+1;
	li.close();
	while(in!='4') {
		system("cls");
		printmain();
		in=getch();
		if(in=='1') {
			cout<<"The name of your world would like to be:";
			genmap(inputstr());
			cout<<"Create message:\n";
			system("saves\\dir.bat");
			cout<<"\n\nCreate program ended successful, press any key to continue..."<<endl;
			getch();
		} else if(in=='2') {
			cout<<"Please wait..."<<endl;
			int worldcount=0;
			Sleep(100);
			file.open("list.txt");
			while(file.getline(worldlist[worldcount],100)) {
				worldcount++;
			}
			file.close();
			if(!worldcount) {
				cout<<"You don't have a world yet. Please create one first."<<endl;
				system("pause");
				continue;
			} else {
				cout<<"This is your world list.\n\n";
				for(int i=0; i<worldcount; i++) {
					for(int j=0; j<strlen(worldlist[i])-6; j++) {
						cout<<worldlist[i][j];
					}
					cout<<"\n";
				}
				cout<<"Put in the name of the world you want to delete:";
				char temp[105]="saves\\";
				strcat(temp,inputstr());
				strcat(temp,".world");
				system("saves\\dir.bat");
				if(DeleteFile(temp))cout<<"\nDelete successful.";
				else cout<<"Delete failed.";
				cout<<" Press any key to continue...";
				getch();
			}
		} else if(in=='3') {
			cout<<"Please wait..."<<endl;
			int worldcount=0;
			Sleep(100);
			file.open("list.txt");
			while(file.getline(worldlist[worldcount],100)) {
				worldcount++;
			}
			file.close();
			if(!worldcount) {
				cout<<"You don't have a world yet. Please create one first."<<endl;
				system("pause");
				continue;
			} else {
				cout<<"This is your world list.\n\n";
				for(int i=0; i<worldcount; i++) {
					for(int j=0; j<strlen(worldlist[i])-6; j++) {
						cout<<worldlist[i][j];
					}
					cout<<"\n";
				}
				cout<<"Put in the name of the world you want to load:";
				char temp[105]="start BanjiuGame.exe saves\\";
				strcat(temp,inputstr());
				strcat(temp,".world");
				system(temp);
				break;
			}
		}
	}
	return 0;
}
