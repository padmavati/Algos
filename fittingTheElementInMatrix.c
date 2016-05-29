//
//  main.c
//  fittingTheElementInMatrix
//
//  Created by padmavb on 5/28/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
void insertElement(int ** matrix, int size, int element){
    int rowIndex = size-1, colIndex = size-1;
    while(rowIndex > 0 && colIndex >0){
        if(matrix[rowIndex][colIndex-1] < element && matrix[rowIndex-1][colIndex] < element){
            break;
        }
        else if(matrix[rowIndex][colIndex-1] > element && matrix[rowIndex-1][colIndex] < element){
            matrix[rowIndex][colIndex] = matrix[rowIndex][colIndex-1];
            colIndex--;
        }
        else if(matrix[rowIndex][colIndex-1] < element && matrix[rowIndex-1][colIndex] > element){
            matrix[rowIndex][colIndex] = matrix[rowIndex-1][colIndex];
            rowIndex--;
        }
        else{
            if(matrix[rowIndex][colIndex-1] < matrix[rowIndex-1][colIndex]){
                matrix[rowIndex][colIndex] = matrix[rowIndex-1][colIndex];
                rowIndex--;
            }
            else{
                matrix[rowIndex][colIndex] = matrix[rowIndex][colIndex-1];
                colIndex--;
            }
        }
    }
    while(rowIndex == 0 && colIndex > 0){
        if(matrix[rowIndex][colIndex-1] > element){
            matrix[rowIndex][colIndex] = matrix[rowIndex][colIndex-1];
            colIndex--;
        }
        else
            break;
    }
    while(rowIndex > 0 && colIndex == 0){
        if(matrix[rowIndex-1][colIndex] < element){
            matrix[rowIndex][colIndex] = matrix[rowIndex-1][colIndex];
            rowIndex--;
        }
        else
            break;
    }
    matrix[rowIndex][colIndex] = element;
}
void printMatrix(int **matrix, int size){
    int rowIndex=0, colIndex = 0;
    for(;rowIndex<size; rowIndex++){
        for(colIndex=0;colIndex< size; colIndex++){
            printf("%d\t", matrix[rowIndex][colIndex]);
        }
        printf("\n");
    }
}
int main(int argc, const char * argv[]) {
    
    int sizeOfMatrix, rowIndex, colIndex, element;
    scanf("%d", &sizeOfMatrix);
    int ** matrix = (int **)malloc(sizeOfMatrix * sizeof(int *));
    for(rowIndex = 0; rowIndex < sizeOfMatrix; rowIndex ++){
        matrix[rowIndex] = (int *)malloc(sizeOfMatrix * sizeof(int));
        for(colIndex=0; colIndex < sizeOfMatrix; colIndex++)
            scanf("%d", &matrix[rowIndex][colIndex]);
    }
    scanf("%d", &element);
    printMatrix(matrix, sizeOfMatrix);
    insertElement(matrix, sizeOfMatrix, element);
    printMatrix(matrix, sizeOfMatrix);
    return 0;
}
