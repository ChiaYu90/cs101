#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class myString {

};
class ReadClass {
    private:
        ifstream read;
        string str, tmp;
        int class_num = 0;
        int flag = 0;
        string name[10];
    public:
        void showClass(){
            read.open("main.cpp");
            while(!read.eof()){
                read >> str;
                if (!str.compare("class")){
                    class_num++;
                    read >> tmp;
                    //cout << tmp <<endl;
                    name[class_num] = tmp;                    
                }
            }
            cout << class_num << " " << "class in main.cpp\n";
            for (int i =1;i<=class_num; i++){
                cout << "class " << name[i] <<endl;
            }
            read.close();
        }
};
int main(){
    ReadClass rfile;
    rfile.showClass();
    return 0;
}

