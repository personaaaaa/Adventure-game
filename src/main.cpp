//
// Created by Storm Phoenix on 2021/1/15.
//

#include <iostream>
#include <cstdio>
#include <GameScene.h>

int main() {
    // 创建游戏场景
    GameScene *scene = new GameScene();

    std::string username;
    std::cout << "Inputs your name: ";
    std::cin >> username;
    std::cout << std::endl;

    std::string keep;
    int grade = 0;
    while (true) {
        std::cout << "Keep going ?";
        std::cin >> keep;

        if (keep == "yes") {
            // 继续下一回合
            Disaster *disaster = scene->nextRound();
            // 检查灾难是否发生
            if (disaster == nullptr || !disaster->isValid()) {
                // 灾难没有发生、或灾难没有达到两次，则可以继续获得奖励
                Fortune *fortune = scene->getReward();
                std::cout << "Discover reward: " << fortune->getDescription() << std::endl;
                grade += fortune->getGrade();
                // TODO
            } else {
                // 无法继续进行冒险
                // TODO
            }
        } else {
            // 跳出循环
            // TODO
        }
    }
}