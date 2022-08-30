// Write a program to check if a number is palindrome

#include<stdio.h>

int main(){
    int num, n, rem, rev=0;

    printf("Enter a number: ");
    scanf("%d", &num);
    n = num;
    
    while (n != 0){
        rem = n%10;
        rev = rev*10+rem;
        n = n/10;
    }
    
    if (rev == num){
    	printf("%d is a palindrome.", num);
	}
	else{
		printf("%d is not a palindrome.", num);
	}

	return 0;
}
