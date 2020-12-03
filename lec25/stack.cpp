#include <iostream>
using namespace std;
template <class T>
class stack{
    private:
        int TOS;
        int size;
        T *data;
    public:
        stack(int _size =3){
            size = _size;
            TOS = -1;
            data = new T[size];
        }
        ~stack(){delete []data;}
        void push(const T &value){
            if(TOS == size-1){
                cout<<"stack overflow!"<<endl;
                return;
            }
            TOS++;
            data[TOS] = value;
        }
        T top(){return data[TOS];}
        void pop(){
            if(TOS==-1){
                cout<<"stack underflow!"<<endl;
                return;
            }
            TOS--;
        }
        bool empty(){
            if(TOS==-1) return true;
            else return false;
        }
};

class Point{
    private:
        int x,y;
    public:
        Point(){x=0;y=0;}
        Point(int _x, int _y){x=_x;y=_y;}
        void show(){cout<<x<<","<<y<<endl;}
        Point operator*(const Point &p){
            Point temp(x * p.x, y * p.y);
            return temp;
        }
};
int main(){
    stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    s.pop();
    
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);

    while(!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }
    s1.pop();
}




