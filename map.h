/************************************************
*   Name: Map Generator 
*   Author: wenge
*   C++ is the best language in the world
************************************************/
//For MSC
    #ifdef _MSC_VER
    #define _CRT_SECURE_NO_DEPRECATE
    #define _CRT_SECURE_NO_WARNINGS
    #endif
///////////////////includes//////////////////////
#include <iostream> 
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <queue>
#include <string>
#include "rand.h"
using namespace std;
/////////////////definitions/////////////////////
const int adj4x[]={1,-1,0,0};
const int adj4y[]={0,0,1,-1};
const int adj8x[]={1,-1,0,0,1,1,-1,-1};
const int adj8y[]={0,0,1,-1,1,-1,1,-1};
struct point{
    int x,y;
    point(){}
    point(int xi,int yi):x(xi),y(yi){}
};
int n=1000,m=1000;
char gamemap[1005][1005];
//////////////////block fill/////////////////////
void block_fill(char fill,int centerx,int centery,int minsizex,int minsizey,double L=0.87){
    queue<point> q;
    for(int i=max(1,centerx-minsizex);i<=min(n,centerx+minsizex);i++){
        for(int j=max(1,centery-minsizey);j<=min(n,centery+minsizey);j++){
            if(gamemap[i][j]=='\0'){
                gamemap[i][j]=fill;
                q.push(point(i,j));
            }
        }
    }
    while(!q.empty()){
        int xi=q.front().x,yi=q.front().y;
        for(int i=0;i<4;i++){
            int adjcnt=0;
            for(int j=0;j<8;j++){
                if(xi+adj4x[i]+adj8x[j]>=1&&xi+adj4x[i]+adj8x[j]<=1000){
                    if(yi+adj4y[i]+adj8y[j]>=1&&yi+adj4y[i]+adj8y[j]<=1000){
                        if(gamemap[xi+adj4x[i]+adj8x[j]][yi+adj4y[i]+adj8y[j]]==fill){
                            adjcnt++;
                        }
                    }
                }
            }
            if(xi+adj4x[i]>=1&&xi+adj4x[i]<=1000){
                if(yi+adj4y[i]>=1&&yi+adj4y[i]<=1000){
                    if(gamemap[xi+adj4x[i]][yi+adj4y[i]]=='\0'&&(rand()/2147483647.0)<pow(adjcnt/8.0,L)){
                        gamemap[xi+adj4x[i]][yi+adj4y[i]]=fill;
                        q.push(point(xi+adj4x[i],yi+adj4y[i]));
                    }
                }
            }
        }
        q.pop();
    }
    return;
}
void generateplains(int centerx,int centery,int K){
    if(rand()<2147483647.0/K)block_fill('A',centerx,centery,2+(rand()%5),2+(rand()%5),0.78);
}
void generatedesert(int centerx,int centery,int K){
    if(rand()<2147483647.0/K)block_fill('.',centerx,centery,2+(rand()%20),2+(rand()%20),0.85);
}
void generateiceplains(int centerx,int centery,int K){
    if(rand()<2147483647.0/K)block_fill(',',centerx,centery,2+(rand()%20),2+(rand()%20),0.85);
}
void generatewater_pool(int centerx,int centery,int K){
    if(rand()<2147483647.0/K)block_fill('~',centerx,centery,20+(rand()%30),20+(rand()%30),0.74);
}
/////////////////oblique fill////////////////////
void oblique_fill(char fill,int centerx,int centery,int height,int width,bool shiftdir,int shift,double L=0.87){
    queue<point> q;
    if(!shiftdir){
        int k=0;
        for(int i=max(1,centerx-height);i<=min(n,centerx+height);i++,k++){
            for(int j=max(1,centery-width+k*shift);j<=min(n,centery+width+k*shift);j++){
                if(gamemap[i][j]=='\0'){
                    gamemap[i][j]=fill;
                    q.push(point(i,j));
                }
            }
        }
    }
    else{
        int k=0;
        for(int i=max(1,centery-width);i<=min(n,centery+width);i++,k++){
            for(int j=max(1,centerx-height+k*shift);j<=min(n,centerx+height+k*shift);j++){
                if(gamemap[j][i]=='\0'){
                    gamemap[j][i]=fill;
                    q.push(point(j,i));
                }
            }
        }
    }
    while(!q.empty()){
        int xi=q.front().x,yi=q.front().y;
        for(int i=0;i<4;i++){
            int adjcnt=0;
            for(int j=0;j<8;j++){
                if(xi+adj4x[i]+adj8x[j]>=1&&xi+adj4x[i]+adj8x[j]<=1000){
                    if(yi+adj4y[i]+adj8y[j]>=1&&yi+adj4y[i]+adj8y[j]<=1000){
                        if(gamemap[xi+adj4x[i]+adj8x[j]][yi+adj4y[i]+adj8y[j]]==fill){
                            adjcnt++;
                        }
                    }
                }
            }
            if(xi+adj4x[i]>=1&&xi+adj4x[i]<=1000){
                if(yi+adj4y[i]>=1&&yi+adj4y[i]<=1000){
                    if(gamemap[xi+adj4x[i]][yi+adj4y[i]]=='\0'&&(rand()/2147483647.0)<pow(adjcnt/8.0,L)){
                        gamemap[xi+adj4x[i]][yi+adj4y[i]]=fill;
                        q.push(point(xi+adj4x[i],yi+adj4y[i]));
                    }
                }
            }
        }
        q.pop();
    }
    return;
}
void generatehills(int centerx,int centery){
    int width=1+(rand()%3);
    oblique_fill('^',centerx,centery,100+(rand()%200),width,rand()%2,rand()%(width*2)-width,0.84);
}
void generatewater_river(int centerx,int centery){
    int width=1+(rand()%3);
    oblique_fill('~',centerx,centery,200+(rand()%300),width,rand()%2,rand()%(width*2)-width,0.84);
}
////////////////////terrain//////////////////////
const int terrainnumber=6;
int terraincount[100];
char terrain[100]={'\0','A','_','^','.',',','~'};
string terrainname[100]={"","forest","plains","hills","desert","iceplains","water"};
//////////////////////main///////////////////////
int genmap(string mapname){
    for(int i=1;i<=3;i++){
        generatewater_river(rand()%1000+1,rand()%1000+1);
    }
    for(int i=1;i<=2;i++){
        generatewater_pool(rand()%1000+1,rand()%1000+1,1);
    }
    for(int i=1;i<=15;i++){
        generatehills(rand()%1000+1,rand()%1000+1);
    }
    for(int i=1;i<=3000;i++){
        generatedesert(rand()%1000+1,rand()%1000+1,200);
    }
    for(int i=1;i<=3000;i++){
        generateiceplains(rand()%1000+1,rand()%1000+1,200);
    }
    for(int i=1;i<=10000;i++){
        generateplains(rand()%1000+1,rand()%1000+1,20);
    }
    
	mapname="saves\\"+mapname+".world";
    ofstream file(mapname);
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            if(gamemap[i][j]=='\0')gamemap[i][j]='_';
            for(int k=1;k<=terrainnumber;k++){
                if(gamemap[i][j]==terrain[k]){
                    terraincount[k]++;
                }
            }
            file<<gamemap[i][j];
        }
        file<<endl;
    }
    file<<"0"; 
    file.close();
    for(int i=1;i<=terrainnumber;i++){
        cout<<terrainname[i]<<" : "<<terraincount[i]<<endl;
    }
    return 0;
}
