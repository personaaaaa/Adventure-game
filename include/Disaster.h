//
// Created by Storm Phoenix on 2021/1/15.
//

#ifndef HELLOWORLD_DISASTER_H
#define HELLOWORLD_DISASTER_H

#include <string>

class Disaster {
public:
    Disaster(std::string name) : name(name), occurrence(0) {}

    std::string getName() {
        return name;
    }

    bool isValid() {
        return occurrence >= 2;
    }

    void happens() {
        occurrence++;
    }

private:
    std::string name;
    int occurrence;
};

#endif //HELLOWORLD_DISASTER_H
