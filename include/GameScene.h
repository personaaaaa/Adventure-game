//
// Created by Storm Phoenix on 2021/1/15.
//

#include <fortune/Gem.h>
#include <fortune/Chest.h>
#include <Disaster.h>
#include <random>
#include <ctime>

// 游戏场景类，管理冒险过程中需要用到的所有数据
class GameScene {
public:
    GameScene() {
        initialize();
        // 用当前系统时间初始化种子
        srand(time(nullptr));
    }

    Fortune *getReward() {
        int chosen = random() % fortunes.size();
        return fortunes[chosen];
    }

    Disaster *nextRound() {
        return randomDisaster();
    }

private:
    Disaster *randomDisaster() {
        int chosen = random() % disasters.size() + 1;
        if (chosen == 0) {
            // disaster not happens
            return nullptr;
        } else {
            Disaster *disaster = disasters[chosen - 1];
            disaster->happens();
            return disaster;
        }
    }

    // 初始化游戏场景数据
    void initialize() {
        // 初始化游戏奖励
        initializeFortunes();
        // 初始化游戏惩罚
        initializeDisaster();
    }

    // 初始化游戏中遇到的所有 Fortune 类
    void initializeFortunes() {
        // build gems
        fortunes.push_back(new Gem(5, "red gem"));
        fortunes.push_back(new Gem(10, "blue gem"));
        fortunes.push_back(new Gem(15, "green gem"));

        // build chest
        std::vector<Gem *> chestContent;
        chestContent.push_back(new Gem(1, "stone"));
        chestContent.push_back(new Gem(2, "yahaha"));
        fortunes.push_back(new Chest(chestContent));
    }

    // 初始化游戏中遇到的所有 Disaster
    void initializeDisaster() {
        // build disaster
        disasters.push_back(new Disaster("flood"));
    }

private:
    std::vector<Fortune *> fortunes;
    std::vector<Disaster *> disasters;
};