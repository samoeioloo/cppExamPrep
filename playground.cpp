//
// Created by Chris Kay on 2022/05/29.
//
#include "string"
#include "iostream"
#include "fstream"
//#include <ifstream>
//#include "ostream"
//#include "istream"
#include "sstream"
#include "vector"

struct st {
    st(int a, std::string b): a(a), b(b){};
    int a;
    std::string b;
    int getC() {return c;}
    ~st(){std::cout<<"\ndestruction boiz";}
private:
    int c=89;
protected:
    int d;
};
using namespace std;
/*
int main(int argc, char * argv[]){

//st a = {1,"56"};
//    std::cout<<a.getC();

std::ifstream in("./pointer.cpp", ios::binary);
    //int* pt = 0xFFFFFFA0;//new int(1);//NULL;

    //    int * ptrNull = nullptr;
    //    cout<< (ptrNull);

    char word[4]={'w','o','r','d'};
    for (int i = 0; i < 4; ++i) { //++i faster than i++
            cout << *(word+i);
    }

    for (int i = 0; i < 4; ++i) { //++i faster than i++
        cout << word[i];
    }

    for (char * i = word; i!=word+4; ++i){
        cout << *i;
    }

    char a = 'a';
    char * ptr = &a;
    char ** ptr1 = &ptr;
    char *** ptr2 = &ptr1;
    char ****ptr3 = & ptr2; //pointer 3 to pointer 2 to pointer 1 to pointer to char.

    vector<int> * vect = new vector<int>;
    //int *ptrr = new int [3];

    vect->push_back(4);
    //cout << ptrr[1];

    for (int t: *vect){
        cout<<t;
    }

    delete vect;

    std::unique_ptr<int> A(new int(3));
    //A.release();
    //A.reset(new int(50));
    cout<< "\n" << *A;


//delete pt;
//std:: string var;
//while (in.good()){
//    std::cout << in.good();
//    std::getline(in, var);
//    std::cout<< var << "\n";
//    std::cout << 28 << std::hex;
//}

//string t; int a,b; float c;
//string d = "IamaString 2 4.67";
//istringstream in(d);
//in >>  t >> a >> b >>c;
//cout << t << a << b <<c;

}
 */

int main(int argc, char * argv[]) {

    int arr[4] = {3,4,5,7};

    std::vector<int> vectName(arr, arr+5);

    for(auto it= vectName.begin(); it!=vectName.end(); it++){
        std::cout << *it;
    }

    for (int a: vectName){
        std::cout << a;
    }

}