#include <iostream>
#include <string>

using namespace std;

class Clock {
    
    protected:
        string meridian;
        int hour;
        int minute;
        int second;
    public:
        Clock(int hr, int min, int sec, string mer){
            if (hr>12||hr<1)    cout << "mistake" <<endl;
            else hour = hr;
            if (min>59||min<0)    cout << "mistake" <<endl;
            else minute = min;
            if (sec>59||sec<0)    cout << "mistake" <<endl;
            else second = sec;
            if (mer!="AM" && mer!="PM")    cout << "mistake" <<endl;
            else meridian = mer;
        }
        void display(){
            cout << hour <<":" <<minute << ":" << second <<" "<<meridian <<endl;
        }
};

class  StandardClock :public Clock{
    public:
        StandardClock(int hr, int min, int sec, string mer): Clock(hr, min ,sec ,mer){}
        void display(){
            if(meridian =="AM")
                cout << "上午 " <<hour <<":" <<minute << ":" << second <<endl;
            else if(meridian =="PM")
                cout << "下午 " <<hour <<":" <<minute << ":" << second <<endl;
        }
};
class  MilitaryClock :public Clock{
    public:
        MilitaryClock(int hr, int min, int sec, string mer) : Clock(hr, min ,sec ,mer){}
    void display(){
        if(meridian =="AM")
            cout <<hour <<":" <<minute << ":" << second <<endl;
        else if(meridian =="PM"){
            hour += 12;
            cout << hour <<":" <<minute << ":" << second <<endl;
        }    
    }
};
int main (){
    Clock cc(10, 25, 43,"AM");
    StandardClock sc(10, 25, 43,"AM");
    MilitaryClock mc(10, 25, 43,"PM");
    cc.display();
    sc.display();
    mc.display();
    return 0;
}
