#include <stdio.h>
int fibonacci(int n){
    int fib[n+1];
    fib[0]=0;
    fib[1]=1;
    for (int i=2;i<=n;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    return fib[n];
}

int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    if (n<0){
        printf("Invalid input! n should be a non-negative integer.\n");
        return 1;
    }
    printf("Fibonacci number at position %d is: %d\n",n,fibonacci(n));
    return 0;
}