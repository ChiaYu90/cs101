#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class ReplaceMyString{
    private:
        ofstream out;
        ifstream in;
        string str;
        int str_len;
        int iu = 0;
        
    public:
        void replacestring(string a, string b){
            in.open("main.cpp");
            out.open("Rmain.cpp");
            while(!in.eof()){
                in >> str;
                iu = str.find(a);
                if(iu>0)   str.replace(iu, a.length(), b); 
                out << str ;
                str_len = str.length();               
                if (str[str_len-1] == ';' || str[0] == '<' && str[str_len-1] == '>'|| str[str_len-1] == ':' 
                    || str[str_len-1] == '{' || str[str_len-1] == '}')  out << endl;
                else out << ' ';
            }   
            in.close();
            out.close();
        }
};
int main(){
    ReplaceMyString IU, my;
    my.replacestring("IU", "IU is best");
    return 0;
}
