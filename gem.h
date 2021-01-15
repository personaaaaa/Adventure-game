//
// Created by Li Wenshu on 2020/12/24.
//
#ifndef HELLOWORLD_GEM_H
#define HELLOWORLD_GEM_H
#define NUM_GEM 3
#define NUM_CHEST 2
#include<map>
using namespace std;

class Fortune{
public:
    Fortune(){}
    virtual char *getName() = 0;
    virtual int getGrade() = 0;
};

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

class Chest:public Fortune{
private:
    int id;
    char *name1;
    int grade1;
    char *name2;
    int grade2;
public:
    Chest(int i, char *na1, int gr1, char *na2, int gr2):Fortune(){
        id = i;
        name1 = na1;
        grade1 = gr1;
        name2 = na2;
        grade2 = gr2;
    }
    char *getName(){
        cout<<"you have get a chest!"<<endl;
        return name1;
    }
    int getGrade(){
        return grade1+grade2;
    }
};
//宝箱的对应id获取
map<int,Chest*> chestMap;
void initialize_chest() {
    chestMap[0] = new Chest(4, "hupo",1,"hongbaoshi",5);
    chestMap[1] = new Chest(5, "zhuanshi", 15,"hongbaoshi", 5);
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
