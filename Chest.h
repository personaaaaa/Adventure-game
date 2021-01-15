//
// Created by Li Wenshu on 2021/1/15.
//

#ifndef HELLOWORLD_CHEST_H
#define HELLOWORLD_CHEST_H

#define NUM_CHEST 2
#include<map>
#include "Fortune.h"
using namespace std;

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

#endif //HELLOWORLD_CHEST_H
