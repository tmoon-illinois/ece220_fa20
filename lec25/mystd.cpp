#include <stdio.h>
#include <iostream>
namespace mystd{
    class ostream{
        public:
            ostream& operator<<(const char *str){
                printf("%s", str);
                return *this;
            }
            ostream& operator<<(int i){
                printf("%d", i);
                return *this;
            }
            ostream& operator<<(double i){
                printf("%lf", i);
                return *this;
            }
    };

    ostream cout;
    const char *endl = "\n";
}

using namespace std;
int main(){
    cout<<"AAA, "<<20<<endl;
}
