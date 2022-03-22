#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct {
	int lotto_no;
	int lotto_receipt;
	int emp_id;
	char lotto_date[10];
	char lotto_time[10];
}lotto_record_t;
lotto_record_t record[10];

void rep_file(int n) {
	char date[10];
	int sum_no = 0, sum_total =0;
	FILE* fp = fopen("Report.txt","w+");
	fprintf(fp, "========= lotto649 Report =========\n");
	fprintf(fp, "- Date ------ Num. ------ Receipt -\n");
	for (int i=0; i<=n; i++){
		fprintf(fp, "%s      %2d/%02d       %4d\n", record[i].lotto_date, record[i].lotto_no
											, (record[i].lotto_receipt/55), record[i].lotto_receipt);
	
		sum_no += record[i].lotto_no;
		sum_total += record[i].lotto_receipt;
		//printf("%s%d\n",record[i].lotto_date,i);
	}
	fprintf(fp, "-----------------------------------\n");
	fprintf(fp, "%8d%7d/%02d       %d\n",n+1, sum_no, (sum_total/55), sum_total);
	
	time_t now = time(0);
	strftime (date, 100,"%Y%m%d", localtime(&now));
	fprintf(fp, "========= %sPrinted =========\n", date);
}
int main(int argc, char *argv[]) {
	lotto_record_t tmp;
	//lotto_record_t record[10];
	int i;
	FILE* fp = fopen("records.bin", "rb");
	if(fp == NULL)	printf("open fail\n"); 
	while (fread(&tmp, sizeof(lotto_record_t), 1, fp)){
		if(strcmp("\0", record[0].lotto_date) == 0)	{
			record[0].lotto_no = tmp.lotto_no;
			strcpy(record[0].lotto_date, tmp.lotto_date) ;
			record[0].lotto_receipt = tmp.lotto_receipt;
		}
		if(strcmp(tmp.lotto_date, record[i].lotto_date) == 0){
			record[i].lotto_no = (record[i].lotto_no > tmp.lotto_no) ? record[i].lotto_no : tmp.lotto_no;
			record[i].lotto_receipt += tmp.lotto_receipt;	
		}
		else{
			i++;
			record[i].lotto_no = tmp.lotto_no;
			strcpy(record[i].lotto_date, tmp.lotto_date) ;
			record[i].lotto_receipt = tmp.lotto_receipt;
		}
		//printf("%s %d\n",record[i].lotto_date,i);
	}
	
	fclose(fp);
	rep_file(i);
	return 0;
}
