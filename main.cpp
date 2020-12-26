//冒险游戏设计
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<string.h>
#include "gem.h"
#include "disaster.h"

int main() {
    int round = 1, flag = 0, grade = 0;
    char name[100];
    printf("input your name:");
    scanf("%s", &name);
    initialize_disaster();
    do {
        char choose[10];
        printf("this is the round %d\n", round);
        Disaster destory = disaster_get();
        printf("%s has happended\n",get_disastername(destory));
        if(get_disasternum(destory)>1){
            printf("you have none grade\n");
            exit(0);
        }
        Gem gem = gem_get();
        printf("you have get a %s\n",get_gemname(gem));
        grade += get_gemgrade(gem);
        printf("your grade is %d\n",grade);
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