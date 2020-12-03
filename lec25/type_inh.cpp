#include <iostream>

using namespace std;
class AAA{
    private:
        int a;
    protected:
        int b;
    public:
        int c;
        AAA(){a=1;b=2;c=3;}
        int getb(){return b;}
        int getc(){return c;}
        friend void setA(AAA &A, int x);
};

class BBB_PUB : public AAA{
    public:
        BBB_PUB(){b=10;}

};
class BBB_PRI : private AAA{
    public:
        BBB_PRI(){b=100;c=200;}
        int getb(){return b;}
        int getc(){return c;}

};

void setA(AAA &A, int x){
   A.a = x;
}
int main(){
    AAA a;

    /*
    BBB_PUB bpub;
    BBB_PRI bpri;

//    cout<<bpub.a<<endl; //private
//    cout<<bpub.b<<endl; //protected
    cout<<bpub.c<<endl;
    cout<<bpub.getb()<<endl;

    cout<<bpri.getb()<<endl;
    cout<<bpri.getc()<<endl;

//    cout<<bpri.a<<endl; //private
//    cout<<bpri.b<<endl; //protected
//    cout<<bpri.c<<endl;
//    */
}
