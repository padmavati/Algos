int isPower(int A) {
    int maxLimit = A/3, number, power;
    if(((A/2) * (A/2) == A) || A==1)
      return 1;
    if(A%2){
        for(number = 3; number <= maxLimit; number++){
             power = 2;
             while(pow(number, power) < A){
                 power ++;
             }
             if(pow(number, power) == A)
               return 1;
        }   
        
    }
    else{
        for(number = 2; number <= maxLimit; number++){
             power = 2;
              while(pow(number, power) < A){
                 power ++;
             }
             if(pow(number, power) == A)
                return 1;
        }
    }
    return 0;
}
