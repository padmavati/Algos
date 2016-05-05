//
//  main.c
//  setZeros
//
//  Created by padmavb on 5/2/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
void setZeroes(int** A, int n11, int n12) {
    int rowIndex = 0, colIndex = 0,j;
    for(; rowIndex<n11; rowIndex++){
        for(colIndex = 0;colIndex<n12;colIndex++){
            if(A[rowIndex][colIndex] == 0){
                j=0;
                do{
                    if(A[rowIndex][j]!=0){
                        A[rowIndex][j]=2;
                    }
                    j++;
                }while(j<n12);
                j=0;
                do{
                    if(A[j][colIndex]!=0){
                        A[j][colIndex]=2;
                    }
                    j++;
                }while(j<n11);
            }
        }
    }
    for(rowIndex=0; rowIndex<n11; rowIndex++){
        for(colIndex=0;colIndex<n12;colIndex++){
            if(A[rowIndex][colIndex] == 2){
                A[rowIndex][colIndex]=0;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    int m, n,i,j;
    int ** input;
    scanf("%d%d",&m,&n);
    input = (int **)malloc(m*sizeof(int *));
    for(i=0;i<m;i++){
        input[i] = (int *)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
          scanf("%d",&input[i][j]);
    }
    setZeroes(input, m, n);
    return 0;
}
