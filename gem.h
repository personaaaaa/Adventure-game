//
// Created by Li Wenshu on 2020/12/24.
//
#ifndef HELLOWORLD_GEM_H
#define HELLOWORLD_GEM_H
#define NUM_GEM 3
#include<map>
using namespace std;

class Gem {
private:
    // 定义一些属性
    int id;   //宝石对应的唯一ID
    char *name;   //宝石名称
    int grade;  //宝石对应得分
public:
    Gem();
    Gem(int i,char *na,int gr);
    // 定义方法（method）获取宝石的分数和名称
    char* get_gemname(){
        return name;
    }
    int get_gemgrade(){
        return grade;
    }
};
Gem::Gem(int i,char *na,int gr){
    id = i;
    name = na;
    grade = gr;
}
Gem::Gem(){

}
//宝石的对应id获取
map<int,Gem> gem_kind;
void initialize_gem(){
    gem_kind[0] = Gem(1,"hupo",1);
    gem_kind[1] = Gem(2,"zhuanshi",15);
    gem_kind[2] = Gem(3,"hongbaoshi",5);
}

Gem gem_get(){
    srand(time(NULL));
    int number_gem = rand() % NUM_GEM;
    return gem_kind[number_gem];
}
#endif //HELLOWORLD_GEM_H
