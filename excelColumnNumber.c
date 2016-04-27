int titleToNumber(char* A) {
    int length = 1, columnNumber, index=0;
    for(;A[length]!='\0';length++){
        if(A[length] < 'A' || A[length] > 'Z')
           return 0;
    }
    for(length-=1; length >= 0; length--, index++){
        columnNumber += (A[length] - 'A' +1)*pow(26, index);
    }
    return columnNumber;
}
