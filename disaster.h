//
// Created by Li Wenshu on 2020/12/24.
//

#ifndef HELLOWORLD_DISASTER_H
#define HELLOWORLD_DISASTER_H

#define NUM_DESTORY 5

struct Disaster{
    char *name;
    int id;
    int num;
};

struct Disaster detail[NUM_DESTORY]={
        {"dizheng",1,0},
        {"tafang",2,0},
        {"mengshou",3,0},
        {"hongshui",4,0},
        {"ganhan",5,0}
};

#endif //HELLOWORLD_DISASTER_H
