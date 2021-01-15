//
// Created by Li Wenshu on 2020/12/24.
//
#ifndef HELLOWORLD_GEM_H
#define HELLOWORLD_GEM_H
#define NUM_GEM 3
#include<map>
#include "Fortune.h"
#include "Chest.h"
using namespace std;

class Gemstone:public Fortune{
private:
    int id;
    char *name;
    int grade;
public:
    Gemstone(int i,char *na, int gr):Fortune(){
        id = i;
        name = na;
        grade = gr;
    }
    char *getName(){
        cout<<"you hava get a gemstone!"<<endl;
        return name;
    }
    int getGrade(){
        return grade;
    }
};
//宝石的对应id获取
map<int,Gemstone*> gemMap;
void initialize_gem(){
    gemMap[0] = new Gemstone(1,"hupo",1);
    gemMap[1] = new Gemstone(2,"zhuanshi",15);
    gemMap[2] = new Gemstone(3,"hongbaoshi",5);
}

Fortune *getMoney(){
    srand(time(NULL));
    int gemNumber = rand() % (NUM_GEM+NUM_CHEST);
    if(gemNumber<NUM_GEM){
        return gemMap[gemNumber];
    }
    else{
        return chestMap[gemNumber-NUM_GEM];
    }
}
#endif //HELLOWORLD_GEM_H
