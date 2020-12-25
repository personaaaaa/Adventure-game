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
map <int,Disaster> kind(){
    disaster_kind[0] = {"dizheng",1,0};
    disaster_kind[1] = {"tafang",2,0};
    disaster_kind[2] = {"mengshou",3,0};
    disaster_kind[3] = {"hongshui",4,0};
    disaster_kind[4] = {"ganhan",5,0};
    return disaster_kind;
}
//灾难对应id的获取
map <int,Disaster> destory = kind();
int disaster(){
    srand(time(NULL));
    int destory_num = rand() % NUM_DESTORY + 1;
    for(int i=0;i<destory.size();i++){
        if(destory_num==destory[i].id){
            printf("%s has happended\n",destory[i].name);
            destory[i].num += 1;
        }
        if (destory[i].num > 1){
            printf("you hava none grade!\n");
            return true;
        }
    }
    return false;
}
#endif //HELLOWORLD_DISASTER_H
