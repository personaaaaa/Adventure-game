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

struct Disaster *q;

int destory(){
    srand(time(NULL));
    int destory = rand() % NUM_DESTORY + 1;
    return destory;
}

int disaster(int num_destory){
    for (q=detail;q<detail+NUM_DESTORY;q++){
        if(num_destory==q->id){
            printf("%s has happended\n",q->name);
            q->num += 1;
        }
        if (q->num > 1){
            printf("you hava none grade!\n");
            return true;
        }
    }
    return false;
}

#endif //HELLOWORLD_DISASTER_H
