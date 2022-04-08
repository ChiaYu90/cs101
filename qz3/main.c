#include <stdio.h>

void rec_dec(char *s) {
	if(*s == '\0') {
		printf("\n");
		return;}
	printf("%c,", *s);
	rec_dec(++s);
}

FILE* fp;
void hanoi(char A, char C, char B, int n){
    if (n==1){
        fprintf(fp, "MOVE 1 from %c to %c\n", A, C);
            return ;
    }
    else {
        hanoi(A, B, C, n-1);
        fprintf(fp, "MOVE %d from %c to %c\n", n, A,C);
        hanoi(B, C, A,n-1);
    return;
    }
}
void hanoi_tower(int n) {

	fp = fopen( "hanoi.txt", "w+");
    hanoi('A', 'B', 'C', n);
	fclose(fp);
}

int multiplication(int i, int j) {
    
    if(i==10){
        return 0;
    }
    if(j == 9) {
		printf("%d*%d=%d \n", i, j, i*j);
		multiplication(i+1, 1);
	} else {
		printf("%d*%d=%d ", i, j, i*j);
		multiplication(i, j+1);
	}

}

int main(void) {
	char s[] = "1234567890";
	rec_dec(s);

	printf("func#1-----------------------\n");
	hanoi_tower(16);
	printf("func#2-----------------------\n");
	multiplication(1, 1);
	printf("func#3-----------------------\n");
	return 0;
}
