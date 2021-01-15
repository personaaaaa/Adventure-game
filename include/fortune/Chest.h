//
// Created by Storm Phoenix on 2021/1/15.
//

#ifndef HELLOWORLD_CHEST_H
#define HELLOWORLD_CHEST_H

#include <fortune/Gem.h>
#include <vector>

class Chest : public Fortune {
public:
    Chest(std::vector<Gem *> gems) : gems(gems) {
        grade = 0;
        int size = gems.size();
        for (int i = 0; i < size; i++) {
            grade += gems[i]->getGrade();
        }
    }

    virtual std::string getDescription() override {
        std::string ret = "Chest including: ";
        int size = gems.size();
        for (int i = 0; i < size; i++) {
            ret += gems[i]->getDescription() + ", ";
        }
        return ret;
    }

    virtual int getGrade() override {
        return grade;
    }

private:
    std::vector<Gem *> gems;
    int grade;
};

#endif //HELLOWORLD_CHEST_H
