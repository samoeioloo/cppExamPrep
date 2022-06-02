//
// Created by Chris Kay on 2022/05/29.
//
#include "string"
#include "iostream"
#include "fstream"
//#include "ostream"
#include "sstream"
#include "vector"

#define MyMacro(x,y) std::cout << (x+y) << std::endl
#define MyMacro1(x,y) std::cout << (x##y) << std::endl
using namespace std;


//struct defaults to public, class defaults to private.
struct MyStruct {
    MyStruct(int a, std::string b): a(a), b(b){};
    int a;
    std::string b;
    int getC() {return c;}
    ~MyStruct(){std::cout<<"\ndestruction boiz";}
private:
    int c=89;
protected:
    int d;
};

void testStruct(){
    MyStruct a = {1,"56"};
    cout<<a.getC();
}

void testIO(){
    //const char a[] = {'c','o','n','t','a','i','n','e','r','s','.','o','\0'};
    string filename = "containers.o"; //filename to delete.
    const char *str = filename.c_str(); //convert string to null-terminated char array.
    remove(str); //deletes file named filename

    std::ifstream in("./README.md", ios::binary);

    std:: string var;
    while (in.good()){
        std::cout << in.good();
        std::getline(in, var);
        std::cout<< var << "\n";
    }
    std::cout << "printing hex to binary: " << 0xF << std::hex << endl;

    cout << "Convert string to String, int, double: \n";
    string t; int a,b; float c;
    string d = "IamaString 2 4.67";
    istringstream ins(d);
    ins >>  t >> a >> b >>c;
    cout << "individually stored variables";
    cout << t << a << b <<c;
}
/*
int main(int argc, char * argv[]){

}
 */

int main(int argc, char * argv[]) {

/*
 *
 */

    testIO();
    MyMacro(1,2);
    MyMacro1(1,2);


}

/*
 *Variable qualifiers - static, const,
 * Type definitions - typedef, auto, decltype(xxx)
 */