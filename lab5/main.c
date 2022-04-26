#include <stdio.h>
#include <stdlib.h>

int* get_int_array(int n){
    return calloc(n, sizeof(int));
}
void set_value(int* p, int v){
    *p = v;
}
int print_array(int* p, int n){
    printf("[");
    for(int i=0; i<n-1; i++){
        printf("%d, ",*(p+i));
    }
    printf("%d]\n", *(p+n-1));
}
typedef struct array_list{
    int n;
    int* (*fuc1) (int);
    void (*fun2) (int *, int);
    int (*fun3) (int *, int);
} array_list_t;
char* func(char* a, char* b){
    int len_a, len_b;
    while(*(a+len_a) != '\0')   len_a++;
    while(*(b+len_b) != '\0')   len_b++;
    char* m = calloc(sizeof(char),len_a+len_b+1); //(char)malloc(sizeof(char)*(len_a+len_b+1));
    for(int i=0;i<len_a;i++) *(m+i) = *(a+i);
    for(int i=0;i<len_b;i++) *(m+i+len_a) = *(b+i);
    *(m+len_a+len_b) = '\0';
    return m;
}
char* add_str_func(char* a, char* b, char* (*func_ptr) (char*, char*)){
    return func_ptr(a, b);
}
int main(){
    printf("No.1------------\n");    
    int n = 10;
    int *ip = get_int_array(n);
    for(int i=0; i<n; i++) {
        set_value(ip+i, i+1);
    }
    print_array(ip, n);
    printf("No.2------------\n");
    array_list_t no2;
    no2.n = 20;
    no2.fuc1 = get_int_array;
    no2.fun2 = set_value;
    no2.fun3 = print_array;
    int *ip2 = no2.fuc1(no2.n);
    for(int i=0; i<no2.n; i++) {
        no2.fun2(ip2+i, i+1);
    }
    no2.fun3(ip2, no2.n);

    printf("No.3------------\n");
    char a[] ="IUIU!";
    char b[] = "@CGU";
    printf("add_str_func = %s\n", add_str_func(a, b, func));
    return 0;
}
