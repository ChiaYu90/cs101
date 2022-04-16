#include <stdio.h>
#include <stdlib.h>
#define len 10
typedef struct my_mm
{
    int total;
    int* mp[len];
    int m[len];
}my_mm_t;
int g_mem[10];
my_mm_t mms;
void print_arr(int n){
    for(int i=0;i<len;i++)  printf("%d", mms.m[i]); //
    if(n)   printf("<- Out of space");
    printf("\n");
}
int* my_calloc (int n, int size){
    int m_cnt = 0, cnt=0 ;
    int tol;

    for(int i=0;i<len;i++) {
        if(mms.m[i] == 0)  cnt++;
        if(mms.m[i] ==1 || i == 9){    
            m_cnt = (m_cnt>cnt) ? m_cnt: cnt; //if(cnt >m_cnt)  m_cnt =cnt;
            cnt =0;
        }
    }
    if (m_cnt >= size){
        g_mem[++mms.total] = size;
        for(int i=0, tol=0; i<len &&tol<size;i++)  {
            if(!mms.m[i]) {
                mms.m[i] = 1; //if(size--&&mms.np[i])
                tol++;
                mms.mp[i] = &g_mem[mms.total];
            }
        }
        print_arr(0);
        //printf("%d %p\n",g_mem[mms.total],&g_mem[mms.total]);
        return &g_mem[mms.total];
    }
    else if (m_cnt <size){
        print_arr(1);
        return NULL;
    }
    
}
void my_free(int *p){
    for(int i=0; i<len;i++){
        if(p == mms.mp[i]){
            mms.mp[i] = NULL;
            mms.m[i] = 0;
        }
    }
    p = NULL;
    print_arr(0);
}

int main (){
    int* np1 = my_calloc(1,1);
    int* np2 = my_calloc(1,2);
    int* np3 = my_calloc(1,3);
    int* np4 = my_calloc(1,4);
    my_free(np1);
    my_free(np4);
    int* np5 = my_calloc(1,5);
    int* np6 = my_calloc(1,1);
    return 0;
}
