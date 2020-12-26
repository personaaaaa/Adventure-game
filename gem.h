//
// Created by Li Wenshu on 2020/12/24.
//
#ifndef HELLOWORLD_GEM_H
#define HELLOWORLD_GEM_H
#define NUM_GEM 3
#include<map>
using namespace std;

struct Gem {
    // 定义一些属性
    int id;   //宝石对应的唯一ID
    char *name;   //宝石名称
    int grade;  //宝石对应得分

    // 定义方法（method）获取宝石的分数和名称
    char* get_gemname(){
        return name;
    }
    int get_gemgrade(){
        return grade;
    }
};

//宝石的对应id获取
map<int,Gem> gem;
Gem gem_get(){
    srand(time(NULL));
    int number_gem = rand() % NUM_GEM + 1;
    gem[0] = {1,"hupo",1};
    gem[1] = {2,"zhuanshi",15};
    gem[2] = {3,"hongbaoshi",5};
    for(int i=0;i<gem.size();i++){
        if (number_gem==gem[i].id){
            return gem[i];
        }
    }
}
#endif //HELLOWORLD_GEM_H
