//
// Created by Li Wenshu on 2020/12/24.
//
#ifndef HELLOWORLD_DISASTER_H
#define HELLOWORLD_DISASTER_H
#define NUM_DESTORY 5
//定义灾难的结构体
struct Disaster{
    char *name;
    int id;
    int num;
};
//灾难map的定义初始化
map <int,Disaster> disaster_kind;
void initialize_disaster(){
    disaster_kind[0] = {"dizheng",1,0};
    disaster_kind[1] = {"tafang",2,0};
    disaster_kind[2] = {"mengshou",3,0};
    disaster_kind[3] = {"hongshui",4,0};
    disaster_kind[4] = {"ganhan",5,0};
}
//灾难对应id的获取
Disaster disaster_get(){
    srand(time(NULL));
    int destory_num = rand() % NUM_DESTORY + 1;
    for(int i=0;i<disaster_kind.size();i++){
        if(destory_num==disaster_kind[i].id){
            disaster_kind[i].num += 1;
            return disaster_kind[i];
        }
    }
}
#endif //HELLOWORLD_DISASTER_H