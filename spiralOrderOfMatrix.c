
#include <stdio.h>
#include<stdlib.h>
void printSpiralOrderOfMatrix(int ** matrix, int noOfRows, int noOfColumns){
    
    int i, k = 0, l = 0;
    while(k < noOfRows && l < noOfColumns){
        
        for(i=l;i < noOfColumns;i++)
            printf("%d\t",matrix[k][i]);
        k++;
        for(i=k;i<noOfRows;i++)
            printf("%d\t", matrix[i][noOfColumns-1]);
        noOfColumns--;
        if(k < noOfRows){
            for(i= noOfColumns-1; i >= l;i--)
                printf("%d\t",matrix[noOfRows-1][i]);
            noOfRows--;
        }
        if(l < noOfColumns){
            for(i=noOfRows-1;i>=k;i--)
                printf("%d\t", matrix[i][l]);
            l++;
        }
    }
    
}

int main(int argc, const char * argv[]) {
   
    int noOfRows, noOfColumns, index;
    scanf("%d%d", &noOfRows, &noOfColumns);
    int ** matrix = (int **)malloc(noOfRows*sizeof(int *));
    for(index = 0; index < noOfRows; index++){
        matrix[index] = (int *)malloc(noOfColumns*sizeof(int));
        for(int colIndex=0; colIndex < noOfColumns; colIndex++)
        scanf("%d", &matrix[index][colIndex]);
    }
    printSpiralOrderOfMatrix(matrix, noOfRows, noOfColumns);
    return 0;
}
