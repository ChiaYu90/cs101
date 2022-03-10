#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int compare(const void* a,const void* b){
	return (* (int*)a - * (int*)b);
}
int main(int argc, char *argv[]) {
	FILE* fp;
	FILE* fid;
	FILE* ftimes;
	int n, spe, flag;
	int op_id;	
	int num[6], t = 1;
	time_t cur_t;
	time(&cur_t);
	
	printf("歡迎光臨長庚樂透彩購買機台\n");
	printf("請輸入操作人員ID(O~5):");
	scanf("%d", &op_id);
	printf("請問您要購買幾組樂透彩 (1~5):");
	scanf("%d", &n);
	
	fp = fopen("lotto.txt", "w+");  
	fid = fopen("operator_id.bin","wb+");
	fwrite(&op_id, sizeof(int), 1, fid);
	fclose(fid);
	/*if((ftimes = fopen("times.txt", "rb+")) == NULL)	{
		ftimes = fopen("times.txt", "wb+");
		t = 1;
		if((fwrite(&t, sizeof(int), 1, ftimes)) != 1) printf("write fail\n");
		//write(&t, sizeof(int), 1, ftimes);
		//printf("cgu\n");
	}
	else {
		fclose(ftimes);
		if((ftimes = fopen("times.txt","wb+")) ==NULL)	printf("open fail\n");
		if((fread(&t, sizeof(int), 1, ftimes)) != 1) printf("read fail\n");
		//fseek(ftimes, 0, SEEK_SET); 
		t++;
		if((fwrite(&t, sizeof(int), 1, ftimes)) != 1) printf("write fail\n");
		printf("%d\n",t);
	}
	fclose(ftimes); */
	fprintf(fp, "=========lotto649=========\n");
	fprintf(fp, "=======+ No.%04d +========\n",t);
	fprintf(fp, "=%s", ctime(&cur_t)); 					//有bug 
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
			for(int j=0; j<6; j++) fprintf(fp, "%2d ", num[j]);			
			fprintf(fp, "%d", spe);
			fprintf(fp, "\n");
		}
		else{
			fprintf(fp,"-- -- -- -- -- -- --\n");
		}
	}
    printf("以為您購買的%d組樂透組合輸入至lotto[%05d].txt\n", n, t);
	fprintf(fp, "=======* Op.%05d *========\n",op_id);
	fprintf(fp, "======== csie@CGU =========\n");
	fclose(fp);
	return 0;
}