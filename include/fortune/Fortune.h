//
// Created by Storm Phoenix on 2021/1/15.
//

#ifndef HELLOWORLD_FORTUNE_H
#define HELLOWORLD_FORTUNE_H

#include <string>

class Fortune {
public:
    virtual std::string getDescription() = 0;

    virtual int getGrade() = 0;
};

#endif //HELLOWORLD_FORTUNE_H
