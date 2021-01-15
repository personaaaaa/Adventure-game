//
// Created by Storm Phoenix on 2021/1/15.
//

#ifndef HELLOWORLD_GEM_H
#define HELLOWORLD_GEM_H

#include <fortune/Fortune.h>

class Gem : public Fortune {
public:
    Gem(int grade, std::string name) : grade(grade), name(name) {}

    virtual std::string getDescription() override {
        return name;
    }

    virtual int getGrade() override {
        return grade;
    }

private:
    int grade;
    std::string name;
};

#endif //HELLOWORLD_GEM_H
