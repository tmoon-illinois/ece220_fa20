#include <iostream>

using namespace std;
template <class T>
T Mul(T a, T b){
    return a*b;
}

template <class T>
T myswap(T &a, T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}

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
    Point p1(1,2);
    Point p2(3,1);

    Point p3;
    p3 = Mul(p1,p2);
    p3.show();

    int a=1, b = 2;
    myswap(a,b);
    cout<<a<<","<<b<<endl;

    myswap(p1, p2);

    p1.show();
    p2.show();
}

