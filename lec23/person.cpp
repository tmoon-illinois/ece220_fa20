#include <iostream>
#include <cstring>

using namespace std;
class Person{
    char name[20];
    int age;
public:
    //void ShowData(){ cout<<"name: "<<name<<endl;};
    Person(char const *_name, int _age);
    Person();
    void setName(char const *_name){ strcpy(name, _name);}
    void ShowData();
};

Person::Person(char const *_name, int _age){
    strcpy(name, _name);
    age = _age;
}
Person::Person(){
    strcpy(name, "");
    age = 0;
}
void Person::ShowData(){
    cout<<"name: "<<name<<endl;
    cout<<"age: "<<age<<endl;

}


int main(){
    Person p1("AAA", 20);
    Person p2;

    p1.setName("BBB");
    p1.ShowData();
    p2.ShowData();
}
