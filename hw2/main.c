#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

#define counterFile "counter.bin"
int id;
char name[32];
//int cnt_file(void);
void op_file(int);
void lotto_print(int , int , int );
void init_file (void);
void record (int, int, int);
int get_counter (void);
void set_counter (int);
void emp_set (int ); 
int compare(const void* a,const void* b){
	return (* (int*)a - * (int*)b);
}
typedef struct {
	int lotto_no;
	int lotto_receipt;
	int emp_id;
	char lotto_date[10];
	char lotto_time[10];
}lotto_record_t;

typedef struct {
	int emp_id;
	char emp_name[15];
	int emp_salary;
}emp_record_t;
int main(int argc, char *argv[]) {
	FILE* fp;
	int n, cnt, op_id;	
	init_file();  //初始化記錄檔 
	cnt = get_counter();
	cnt++; 
	printf("歡迎光臨長庚樂透彩購買機台\n");
	printf("請輸入操作人員ID(O~5):");
	//printf("請輸入操作人員ID(O~5):");
	scanf("%d", &op_id);
	op_file(op_id);
	if (!op_id)	{
		
		int salary;
	//UI
        printf("please input the ID you want to add:");
        scanf("%d",&id);
        printf("please input the NAME you want to add:");
        scanf("%s",name);
        printf("please input the salary you want to add:");
        scanf("%d",&salary);
        emp_set(salary);
        printf("end the input");
	}
	else {
		printf("請問您要購買幾組樂透彩 (1~5):");
		scanf("%d", &n);
	
		lotto_print(cnt, n, op_id);
		set_counter(cnt);  //記錄counter++ 
		record(cnt, n, op_id);
	}
	
	return 0;
}
void op_file(int op_id){
	int id[1];
	id[0] = op_id;
	FILE* fid = fopen("operator_id.bin","wb+");
	fwrite(id, sizeof(int), 1, fid);
	fclose(fid);
}
void lotto_print(int cnt, int n, int op){	
	char lottofile[32];
	time_t cur_t;
	time(&cur_t);
	int spe, flag, num[6];
	snprintf(lottofile, 32, "lotto[%05d].txt", cnt);
	FILE* fp = fopen(lottofile, "w+");
	fprintf(fp, "=========lotto649=========\n");
	fprintf(fp, "=======+ No.%04d +========\n", cnt);
	fprintf(fp, "= %.*s =\n", 24, ctime(&cur_t)); 					//有bug 
	
	for(int i=1; i<=5; i++){
		fprintf(fp, "[%d]: ", i);
		if(i <= n){		 
			srand((unsigned) time(NULL) + i);
			for(int j=0; j<6; j++)	num[j] = rand()%60;
			
			do{
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
			for(int j=0; j<6; j++) fprintf(fp, "%02d ", num[j]);			
			fprintf(fp, "%d", spe);
			fprintf(fp, "\n");
		}
		else{
			fprintf(fp,"-- -- -- -- -- -- --\n");
		}
	}
    printf("以為您購買的%d組樂透組合輸入至%s\n", n, lottofile);
	fprintf(fp, "=======* Op.%05d *========\n", op);
	fprintf(fp, "======== csie@CGU =========\n");	
} 
void init_file() {  //判斷有無counter.bin 
	int writeArray[1] = {0};
	FILE* fp = fopen(counterFile, "r");  //先打開(唯讀) 
	if(fp == NULL) {  //若無此檔案 
		FILE* tmpfp = fopen(counterFile, "wb+");  //開一個新的 
		fwrite(writeArray, sizeof(int), 1, tmpfp);  //寫進去"No.0" 
		fclose(tmpfp);
	} else {  //若有 
		fclose(fp);  //直接關掉，不做改變 
	}
}

int get_counter() {  //讀取counter.bin(寫入readArray[0]) 
	int readArray[1];
	FILE* tmpfp = fopen(counterFile, "rb");  //唯讀 
	fread(readArray, sizeof(int), 1, tmpfp);  //將讀取counter.bin(tmpfp)的結果寫入counterArray 
	fclose(tmpfp);
	return readArray[0];
}
void set_counter(int counter) {  //記錄counter++ 
	int writeArray[1];
	writeArray[0] = counter;
	FILE* tmpfp = fopen(counterFile, "wb");
	fwrite(writeArray, sizeof(int), 1, tmpfp);
	fclose(tmpfp);
}
void record (int cnt, int n, int op_id){
	FILE* fp;
	char buff[10];
	lotto_record_t rec;
	time_t now = time(0);
	
	rec.lotto_no = cnt;
	rec.lotto_receipt = n*50*1.1;
	rec.emp_id = op_id; 
	strftime (buff, 100,"%Y%m%d", localtime(&now));
	strcpy(rec.lotto_date, buff);
	strftime (buff, 100,"%H:%M:%S", localtime(&now));
	strcpy(rec.lotto_time, buff);
	//fp = fopen() ;
	if((fp = fopen("records.bin","rb+")) ==NULL){
		FILE* fptmp = fopen("records.bin","wb");
		//fwrite (&rec, sizeof(lotto_record_t), 1, fptmp);
		fclose(fptmp);
	}
	
		fp = fopen("records.bin","ab+");
		fwrite(&rec, sizeof(lotto_record_t), 1, fp);
		fclose (fp);
	
}
void emp_set (int salary){
	FILE* fop = fopen("operator_id.txt","ab");
	emp_record_t recordEmployee;
	recordEmployee.emp_id = id;
	strcpy(recordEmployee.emp_name, name);
	recordEmployee.emp_salary = salary;

	fwrite(&recordEmployee, sizeof(recordEmployee), 1, fop);
	fclose(fop);

} 
