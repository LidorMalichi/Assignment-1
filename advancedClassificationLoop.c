//
// Created by vboxuser on 1/20/24.
//

#include "NumClass.h"

int numLength(int);

int isArmstrong(int x){
    int sum = 0;
    int temp = x;
    int base = 1;
    int power = numLength(x);
    int i;

    while(temp > 0){
        for(i = 0; i < power; i++){
            base = base * (temp % 10);
        }
        sum += base;
        base = 1;
        temp /= 10;
    }
    return ((sum == x) ? 1:0);
}

int isPalindrome(int x){
    int sum = 0;
    int temp = x;
    while(temp > 0){
        sum = (sum * 10) + (temp % 10);
        temp /= 10;
    }
    return ((x == sum) ? 1:0);
}

int numLength(int x){
    int temp = 0;
    if(x == 0){
        return temp;
    }
    while(x > 0){
        temp++;
        x = x / 10;
    }
    return temp;
}
