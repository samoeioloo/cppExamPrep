//
// Created by Chris Kay on 2022/06/03.
//

#include <iostream>

//>>, <<, +, -, /, *, +=, *=, -=,!=, ++, —, [], (), >,<,~
using namespace std;
class Person {
public:
    string firstname;
    string middlename;
    string lastname;
    int age;
    char gender; // M/F
    Person(string first, string mid, string last, int age, char gender ): firstname(first), middlename(mid), lastname(last), age(age), gender(gender){
        setNet();
    }
    void setNet(){ netWorth=34; }
    friend std::ostream & operator<<(std::ostream & out, const Person & rhs); //could have been defined here as well. Friend MUST stay {}
    friend std::istream & operator>>(std::istream & in, Person & rhs){
        in >> rhs.netWorth >> rhs.age;
        return in;
    };
}


int main(){

}
