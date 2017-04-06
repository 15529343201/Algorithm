//寻找[1,100]之间的素数 
#include<stdio.h>
int isPrime(int n){
	/*判断n是否是素数，是则返回1，不是则返回0*/
	int i;
	for(i=2;i<n;i++){
		if(n%i==0)
		  return 0;
	} 
	return 1;
}
getPrime(int low,int high){
	int i;
	for(i=low;i<=high;i++)
	  if(isPrime(i))
	    printf("%d ",i);
}
int main()
{
	int low,high;
	printf("Please input the domain for searching prime\n");
	printf("low limitation:");
	scanf("%d",&low);
	printf("high limitation:");
	scanf("%d",&high);
	printf("The whole primes in this domain are\n");
	getPrime(low,high);
	return 0;
}
/*
Please input the domain for searching prime
low limitation:1
high limitation:100
The whole primes in this domain are
1 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
*/ 
