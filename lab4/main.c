#include <stdio.h>
#include <stdlib.h>


int* get_num(int (*n)[10], int size, int want, int* s){
    for((*s)=0; (*s)<size; (*s)++){
        if((*n)[(*s)] == want) {
            return &(*n)[(*s)];
        }
    }
}
void sort(int** ap, int size) {
	 
	for(int i = 0; i < size; i++) {
		int a = i;
		for(int j = i + 1; j < size; j++) {
			if(*ap[i] > *ap[j]) {
				int* temp = ap[i];
				ap[i] = ap[j];
				ap[j] = temp;
				int temp_num = a;
				a = j;
				j = temp_num;
			}
		}
		printf("&n[%d]->%p, n[%d] = %d, ", a, ap[a], a, *(ap[i]));
		printf("ap[%d]->%p, *ap[%d] = %d\n", i, ap[i], i, *(ap[i]));
	}
}
int main (){
    int n[] = {6,4,7,2,0,9,8,1,5,3};
    int* p;
    int* ap[10];
    int s;

  
    p = get_num(&n, 8, 9, &s);
    printf("No.1 -----------\n");
    printf("&n[%d]->%p, n[%d]=%d; ",s,p,s,*p);
    printf("p->%p, *p=%d\n",p, *p);

    printf("No.2 -----------\n");
    for (int i=0;i<10;i++)  ap[i] = &n[i];
    sort(ap, 10);

    return 0;
}
