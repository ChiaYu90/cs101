#include <iostream>

using namespace std;

class MMmanger{
    private:
        int MM_len;
        int* gm;
        int** mp;
    public:
        MMmanger(int size){
            MM_len = size;
            gm = (int*)calloc(size, sizeof(int));
            mp = (int**)calloc(size,sizeof(int*));
        }
        ~MMmanger(){
            free(gm);
            free(mp);
        }
        int* alloc_MM (int size){
            int index;
            int cnt = 0;
            for(index=0;index<MM_len;index++) {
                if(!mp[index])  cnt++;
                else cnt = 0;
                if (cnt == size){
                    index -= size-1;
                    break; 
                }
            }
            if (cnt <size){
                print_calloc_array(1,size);
                return NULL;
            }
            for(int i=0;i<size;i++)  {
                mp[index+i] = &gm[index];

            }
            print_calloc_array(0, size);
            return &gm[index];
        }
        void free_MM(int *p){
            for(int i=0; i<MM_len;i++){
                if(p == mp[i]){
                    //cout << p <<" "<<mp[i]<<endl;
                    mp[i] = NULL;
                }
            }
            print_calloc_array(0,MM_len);
        }
        int get_MMCapacity(){
            int capacity = 0;
            for (int i=0;i<MM_len;i++)  if (!mp[i]) capacity++;
            return capacity;
        }
        void print_calloc_array(int flag,int size){
            cout << "Capacity:"<< get_MMCapacity() <<'-';
            for(int i=0;i<MM_len;i++)  mp[i]? cout << "1":cout<<"0" ;
            if(flag)   cout << "<- Out of space: demand " <<size ;
            cout << endl;
        }
};

int main(){
    MMmanger mmer(10);
    int *p1 = mmer.alloc_MM(1);
    int *p2 = mmer.alloc_MM(2);
    int *p3 = mmer.alloc_MM(3);
    int *p4 = mmer.alloc_MM(4);
    mmer.free_MM(p1);
    mmer.free_MM(p4);
    int *p5 = mmer.alloc_MM(6);
    return 0;
}
