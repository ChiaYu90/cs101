#include <stdio.h>
#include <stdlib.h>

int my_strlen(char* s){
    int n;
    while(*(s+n) != '\0') n++;
    return n;
}
int rec_strlen(char *s){
    if(*s == '\0') return 0;
    return 1 + rec_strlen(s+1);
}
char* my_sort(char* s){
	char tmp;
	for (int i=0; i<my_strlen(s); i++){
		for(int j=0; j<my_strlen(s)-i-1; j++){
			if(*(s+j) > *(s+j+1)){
				tmp = *(s+j);
				*(s+j) = *(s+j+1);
				*(s+j+1) = tmp;
			}
		}
	}
	for(int i=0 ; i<13;i++)	printf("%c",*(s+i));
	return s;
}
int main (){
    char s[] = "UI is a girl!";

    printf("len = %d\n", my_strlen(s));
    printf("len = %d\n", rec_strlen(s));
    printf("sort = %s\n", my_sort(s));
	return 0;
}
