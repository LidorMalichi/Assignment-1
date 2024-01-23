//
// Created by vboxuser on 1/20/24.
//

#include "NumClass.h"

int factorial[] = {1, 1, 2, 6, 24, 120,
                   720, 5040, 40320, 362880};

int isPrime(int x){

    int i;
    //if x == 0 return 0
    if(X <= 0)
    {
        return 0;
    }

    for(i = 2; i*i <= n; i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}


int isStrong(int x){

    int temp = x;
    int sum = 0;

    if(x <= 0){
        return 0;
    }

    while(temp > 0){
        sum += factorial[(temp % 10)];
        temp = temp / 10;
    }

    return((x == sum) ? 1:0);
}