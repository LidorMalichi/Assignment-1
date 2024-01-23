//
// Created by vboxuser on 1/20/24.
//

#include "NumClass.h"

int numLength(int);
int armstrongRec(int, int)
int palindromeRec(int, int);

int isArmstrong(int x){
    if(x < 0){
        return 0;
    }
    return ((x == armstrongRec(x, numLength(x))) ? 1:0);
}

int isPalindrome(int x){
    if(x < 0){
        return 0;
    }
    return ((x == palindromeRec(x, 0)) ? 1:0);
}

int armstrongRec(int x, int power){
    int sum = 0;
    int i;
    if(x == 0){
        return sum;
    }

    sum = 1;
    for(i = 0; i < power; i++){
        sum = sum * (x % 10);
    }
    return sum + armstrongRec((x/10) , power);

}

int palindromeRec(int x, int sum){
    if(x == 0){
        return sum;
    }
    sum = (sum * 10) + (x % 10);
    return palindromeRec((x / 10), sum);
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