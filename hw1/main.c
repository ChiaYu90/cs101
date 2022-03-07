#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int compare(const void* a,const void* b){
	return (* (int*)a - * (int*)b);
}
int main(int argc, char *argv[]) {
	FILE* fp;
	int n, spe, flag;	
	int num[6];
	time_t cur_t;
	time(&cur_t);
	printf("歡迎光臨長庚樂透彩購買機台\n");
	printf("請問您要購買幾組樂透彩:");
	scanf("%d", &n);
	printf("以為您購買的%d組樂透組合輸入至lotto.txt\n", n);
	fp = fopen("lotto.txt", "w+");  
	//if(fp = fopen("lotto.txt", "w+") == NULL)	printf("Cannot open the file");
	
	fprintf(fp, "=========lotto649=========\n");
	fprintf(fp, "=%s", ctime(&cur_t));
	for(int i=1; i<=5; i++){
		fprintf(fp, "[%d]: ", i);
		if(i <= n){		
			time(&cur_t); 
			srand((unsigned) time(NULL) + i);
			for(int j=0; j<6; j++)	num[j] = rand()%60;
			
			do
			{
				spe = rand()%10;
			}while(spe == 0);
			do{
				flag =0;
				qsort(num, 6, sizeof(int), compare);
				for(int j=0; j<6; j++){
					if (num[j] == 0){
						flag = 1;
						num[j] = rand()%60;
					}
					else if (num[j] == num[j+1]&& j<5) {
						num[j+1] =  rand()%60;
						flag = 1;
					}
				} 
			} while (flag);
			for(int j=0; j<6; j++) fprintf(fp, "%d ", num[j]);			
			fprintf(fp, "%d", spe);
			fprintf(fp, "\n");
		}
		else{
			fprintf(fp,"-- -- -- -- -- -- --\n");
		}
	}
	fprintf(fp, "======== csie@CGU =========\n");
	fclose(fp);
	return 0;
}	
