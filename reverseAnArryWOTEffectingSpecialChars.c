//
//  main.c
//  reverseAnArrayWOTEffectingSpecialchars
//
//  Created by padmavb on 5/9/16.
//  Copyright © 2016 padmavb. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int checkAlphabet(char c){
    if((c >= 'A'&& c<='Z') || (c>='a'&& c<='z'))
        return 1;
    return 0;
}
void reverseCharacters(char * inpStr){
    int index = 0,lastIndex;
    char temp;
    for(index=0;inpStr[index]!='\0';index++);
    for(lastIndex=index-1,index=0;index<=lastIndex; ){
        if(checkAlphabet(inpStr[index]) && checkAlphabet(inpStr[lastIndex])){
            temp = inpStr[index];
            inpStr[index] = inpStr[lastIndex];
            inpStr[lastIndex] = temp;
            index++;
            lastIndex--;
        }
        else if(!checkAlphabet(inpStr[index]))
            index++;
        else if(!checkAlphabet(inpStr[lastIndex]))
            lastIndex--;
    }
}
int main(int argc, const char * argv[]) {
    char * inpStr = (char *)malloc(100*sizeof(char));
    scanf("%s",inpStr);
    reverseCharacters(inpStr);
    printf("%s\n", inpStr);
    return 0;
}
