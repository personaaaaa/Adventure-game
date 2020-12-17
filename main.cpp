//冒险游戏设计
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<string.h>

char query(char *destory[], int number){
    for (int i=0;i<number;i++){
        if (strcmp(destory[number],destory[i])==0){
            printf("the game is over!\n");
            return true;
        }
    }
    return false;
}
int main(){
    int round = 1,flag=0,grade = 0;
    char name[100];
    printf("input your name:");
    scanf("%s",&name);
    do{
        char choose[10];
        char *destory_detail[6];
        printf("this is the round %d\n",round);
        srand(time(NULL));
        int destory = rand()%5 +1;
        if (destory == 1){
            printf("dizheng has happended\n");
            destory_detail[round-1] = "dizheng";
            if (query(destory_detail,round-1)){
                printf("you have none grade!\n");
                exit(0);
            }
        }else if(destory == 2){
            printf("tafang has happended\n");
            destory_detail [round-1] = "tafang";
            if (query(destory_detail,round-1)){
                printf("you have none grade!\n");
                exit(0);
            }
        }else if(destory == 3){
            printf("megnshou has happended\n");
            destory_detail[round-1] = "mengshou";
            if (query(destory_detail,round-1)){
                printf("you have none grade!\n");
                exit(0);
            }
        }else if(destory == 4){
            printf("hongshui has happended\n");
            destory_detail[round-1] = "hongshui";
            if (query(destory_detail,round-1)){
                printf("you have none grade!\n");
                exit(0);
            }
        }else{
            printf("ganhan has happended\n");
            destory_detail[round-1] = "ganhan";
            if (query(destory_detail,round-1)){
                printf("you have none grade!\n");
                exit(0);
            }
        }
        int number = rand()%15 + 1;
        if (number<=5){
            grade += 1;
            printf("you get a hupo!\n");
        }else if(number>10){
            grade += 15;
            printf("you get a zhuanshi!\n");
        }else{
            grade +=5;
            printf("you get a hongbaoshi!\n");
        }
        printf("if you want to continue? Yes OR No\n");
        scanf("%s",&choose);
        if (strcmp(choose,"Yes") == 0){
            flag = 1;
            printf("continue\n");
        }
        else{
            flag = 0;
            printf("over\n");
            printf("your grade is %d",grade);
        }
        round += 1;
    }while(flag == 1);
}

/*#读取文件问题
#include<stdio.h>
int main(){
    FILE *fp = NULL;
    char buff[256];
    fp = fopen("C:\\Users\\Li Wenshu\\CLionProjects\\Workspace\\\CLionProject\\\HelloWorld\\temp\\test.txt","r");
    fscanf(fp,"%s",buff);
    printf("1:%s\n",buff);
    fgets(buff,256,(FILE*)fp);
    printf("2:%s\n",buff);
    fgets(buff,256,(FILE*)fp);
    printf("3:%s\n",buff);
    fclose(fp);
}
*/

/*输入输出问题
#include<stdio.h>
int main(){
    char nums[100];
    int i;
    printf("enter you input:");
    scanf("%s,%d",nums,&i);
    printf("your input:%s,%d",nums,i);
    printf("\n");
    return 0;
}
 */

/*
#include <stdio.h>
#include <limits.h>

int main(){
    printf("int：%lu \n",sizeof(int));
    return 0;
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