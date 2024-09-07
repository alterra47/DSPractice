#include<stdio.h>
#include<string.h>
void isPalin(char *s){
	static int i=0;
	if(i==strlen(s)/2){
		printf("Palindrome!\n");
		return;
	}
	else if(s[i]==s[strlen(s)-i-1]){
		i++;
		return isPalin(s);
	}
	else{
		printf("Not palindrome!\n");
		return;
	}
}
int main(){
	char a[20];
	printf("Enter any string:\n");
	scanf("%s", a);
	isPalin(a);
	return 0;
}
