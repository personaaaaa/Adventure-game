//
// Created by Li Wenshu on 2021/1/15.
//

#ifndef HELLOWORLD_FORTUNE_H
#define HELLOWORLD_FORTUNE_H

class Fortune{
public:
    Fortune(){}
    virtual char *getName() = 0;
    virtual int getGrade() = 0;
};

#endif //HELLOWORLD_FORTUNE_H

