//
//  main.c
//  findPrimeNumber
//
//  Created by padmavb on 4/23/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>

int isPrime(int A) {
    if((A ==1 || A%2==0)&& A!=2)
        return 0;
    int maxLimit = A/3, startNum=3;
    for(; startNum <= maxLimit; startNum+=2){
        if(A%startNum == 0)
            return 0;
    }
    return 1;
    
}