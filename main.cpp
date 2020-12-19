//冒险游戏设计
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<string.h>

#define NUM_DESTORY 5
#define NUM_GEM 3

// 定义结构体 - 宝石
struct Gem {
    // id - 作为宝石的唯一数字标记，每种宝石只有这一个标记
    int id;
    // name - 宝石名称
    char *name;
    // grade - 宝石得分
    int grade;
};


int destory_number[NUM_DESTORY] = {0, 0, 0, 0, 0};
int grade = 0;

char Destory(int destory) {
    //int destory_number[NUM_DESTORY];
    char *destory_detail[NUM_DESTORY] = {"dizheng", "tafang", "mengshou", "hongshui", "ganhan"};
    printf("%s has happended\n", destory_detail[destory - 1]);
    destory_number[destory - 1] += 1;
    for (int i=0;i<5;i++){
        printf("%s\n", destory_number[i]);
    }
    if (destory_number[destory - 1] > 1) {
        return true;
    }
    return false;
}

char Grade(int number) {
    char *type_gem[NUM_GEM] = {"hupo", "zhuanshi", "hongbaoshi"};
    int gem_grade[NUM_GEM] = {1, 15, 5};
    printf("you have got a %s\n", type_gem[number - 1]);
    grade += gem_grade[number - 1];
    return grade;
}

int main() {
    int round = 1, flag = 0;
    char name[100];
    printf("input your name:");
    scanf("%s", &name);
    do {
        char choose[10];
        char *destory_detail[6];
        printf("this is the round %d\n", round);
        srand(time(NULL));
        int destory = rand() % NUM_DESTORY + 1;
        if (Destory(destory)) {
            printf("you have none grade!\n");
            exit(0);
        }
        int number = rand() % 3 + 1;
        Grade(number);
        reinput:
        printf("if you want to continue? Yes OR No\n");
        scanf("%s", &choose);
        if (strcmp(choose, "Yes") == 0 or strcmp(choose, "yes") == 0) {
            flag = 1;
            printf("continue\n");
        } else if (strcmp(choose, "No") == 0 or strcmp(choose, "no") == 0) {
            flag = 0;
            printf("over\n");
            printf("your grade is %d", grade);
        } else {
            printf("you have input error, please re-input:");
            goto reinput;
        }
        round += 1;
    } while (flag == 1);
}

*/

/*
#include<stdio.h>
int main(){
    FILE *fp = nullptr;
    char buff[256];
    fp = fopen("C:\\Users\\Li Wenshu\\CLionProjects\\Workspace\\Adventure-game\\temp\\test.txt", "r");
//    fp = fopen("C:\\Users\\Li Wenshu\\CLionProjects\\Workspace\\CLionProject\\HelloWorld\\temp\\test.txt","r");
    fscanf(fp,"%s",buff);

    printf("1:%s\n",buff);
    fgets(buff,256,(FILE*)fp);
    printf("2:%s\n",buff);
    fgets(buff,256,(FILE*)fp);
    printf("3:%s\n",buff);
    fclose(fp);
}
*/

/*
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

bool isNumber(char number[], int len) {
    for (int j=0; j<len; j++ ){
        if (isdigit(number[j]) == false){
            printf("the input is error!");
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(NULL));
    int i;
    i = rand() % 100 + 1;
    char number[100];
    do {
        printf("Enter a number:");
        scanf("%s", &number);
        if (isNumber(number, 100)) {
            int num = atoi(number);
            if (num > i) {
                printf("too big!");
                continue;
            } else if (num < i) {
                printf("too small!");
                continue;
            } else {
                printf("win");
                break;
            }
        } else {
            // TODO
            printf("error");
            continue;
        }
    } while (true);
}
*/