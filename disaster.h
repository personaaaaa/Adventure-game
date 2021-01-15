//
// Created by Li Wenshu on 2020/12/24.
//
#ifndef HELLOWORLD_DISASTER_H
#define HELLOWORLD_DISASTER_H
#define NUM_DESTORY 5
//定义灾难的结构体
class Disaster{
private:
    char *name;
    int id;
    int occurrence;
public:
    Disaster();

    Disaster(char* na,int i,int nu);

    //方法定义：获取灾难的名称和发生次数
    char *getName(){
        return name;
    }
    int getOccurrence(){
        return occurrence;
    }
    void happens(){
        occurrence ++;
    }
};
//构造函数初始化
Disaster::Disaster(char *na,int i,int nu) {
    name = na;
    id = i;
    occurrence = nu;
}
Disaster::Disaster(){

}

//灾难map的定义初始化
map <int,Disaster *> disasterMap;
void initialize_disaster(){
    disasterMap[0] = new Disaster("dizheng",1,0);
    disasterMap[1] = new Disaster("tafang",2,0);
    disasterMap[2] = new Disaster("mengshou",3,0);
    disasterMap[3] = new Disaster("hongshui",4,0);
    disasterMap[4] = new Disaster("ganhan",5,0);
}
//灾难对应id的获取
Disaster *disaster_get(){
    srand(time(NULL));
    int destoryNum = rand() % NUM_DESTORY;
    //add(disasterMap[destory_num]);
    return disasterMap[destoryNum];
}
#endif //HELLOWORLD_DISASTER_H