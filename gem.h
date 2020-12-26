//
// Created by Li Wenshu on 2020/12/24.
//
#ifndef HELLOWORLD_GEM_H
#define HELLOWORLD_GEM_H
#define NUM_GEM 3
#include<map>
using namespace std;
// 定义结构体 - 宝石
struct Gem {
    // id - 作为宝石的唯一数字标记，每种宝石只有这一个标记
    int id;
    // name - 宝石名称
    char *name;
    // grade - 宝石得分
    int grade;
};
//宝石的对应id获取
map<int,Gem> gems;
Gem gem_get(){
    srand(time(NULL));
    int number_gem = rand() % NUM_GEM + 1;
    gems[0] = {1,"hupo",1};
    gems[1] = {2,"zhuanshi",15};
    gems[2] = {3,"hongbaoshi",5};
    for(int i=0;i<gems.size();i++){
        if (number_gem==gems[i].id){
            return gems[i];
        }
    }
}
#endif //HELLOWORLD_GEM_H
