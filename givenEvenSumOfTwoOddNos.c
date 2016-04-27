 int isPrime(int number){
     if((number!=2 && number%2 == 0) || number ==1)
       return 0;
      int maxLimit = number/3, index = 3;
      for(;index <= maxLimit; index+=2){
          if(number%index == 0)
            return 0;
      }
      return 1;
 }
int* primesum(int A, int *len1) {
    int * result = (int *)malloc(2*sizeof(int));
    *len1 = (int *)malloc(sizeof(int));
    int index=0, number = 2;
    if(A%2 != 0){
        *len1 = 0;
        return result;
    }
    if(A == 4){
        result[index++] = result[index++]= 2;
    }
    for(number=3; number < A ; number+=2){
        if(isPrime(number) && isPrime(A-number)){
            result[index++] = number;
            result[index++] = A-number;
            break;
        }
    }
    *len1 = 2;
    return result;
}
