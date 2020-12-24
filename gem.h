//
// Created by Li Wenshu on 2020/12/24.
//

#ifndef HELLOWORLD_GEM_H
#define HELLOWORLD_GEM_H

#define NUM_GEM 3

// 定义结构体 - 宝石
struct Gems {
    // id - 作为宝石的唯一数字标记，每种宝石只有这一个标记
    int id;
    // name - 宝石名称
    char *name;
    // grade - 宝石得分
    int grade;
};

struct Gems gem[NUM_GEM]={
        {1,"hupo",1},
        {2,"zhuanshi",15},
        {3,"hongbaoshi",5}
};

#endif //HELLOWORLD_GEM_H
