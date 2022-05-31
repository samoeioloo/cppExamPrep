//
// Created by Chris Kay on 2022/05/27.
//
//Source definition file.
#include <memory>
#include <iostream>
#include <stdint.h>
//int64_t -> 64 bit int.
class MyInt {
private:
    int i;
public:
    MyInt(int i): i(i){};
    MyInt(){}
    friend std::ostream & operator<<(std::ostream & os, const MyInt & in);
};
std::ostream & operator<<(std::ostream & os, const MyInt & in){
    os << in.i;
    return os;
}

void sharedPointersExample(){
//        std::shared_ptr<int>(new int(10)); //make_shared
//        int *ptr = new int(20)
//        std::shared_ptr<int> ptr = std::make_shared<int>(10);

    std::shared_ptr<int> bar = std::make_shared<int> (10);
    std::shared_ptr<MyInt> bar1 = std::make_shared<MyInt> (100);
    //std::shared_ptr<T> varName = make_shared<T>(constructorArgs);

    // same as:
    std::shared_ptr<int> foo2 (new int(10));
    auto baz = std::make_shared<std::pair<int,int>> (30,40);

    std::cout << "*bar: " << *bar << '\n' << bar.use_count();
    std::cout << "*baz: " << baz->first << ' ' << baz->second << '\n';

    // add passing of shared pointer by value, reference, check use_count.
    //move pointer in a function

}
void uniquePointersExample() {
    //moving between unique_ptrs
    std::unique_ptr<int> lhs(new int(20));
    std::unique_ptr<int> rhs(new int(207));
    rhs = std::move(lhs);
    std::cout << *rhs << std::endl; //rhs now points to 20, lhs now nullptr

    //unique_ptr to shared_ptr
    std::unique_ptr<std::string> name = std::make_unique<std::string>("sdfsdssd");
    std::shared_ptr<std::string> name1 = std::move(name);
    void * p = nullptr;
    std::cout << "Name now nullptr: " << p << " same as: " << name << std::endl;
    std::cout << "Unique pointer moved to shared: " << &name1 << std::endl;

    rhs.release(); //now nullptr
    rhs.reset(new int(10)); //lhs reset to new ptr

    std::shared_ptr<int> number1 = std::make_shared<int>(111); //explicit decl. //HEAP OR NOT?
    auto number3 = std::make_shared<int>(333); // no use of new. uses auto
    std::shared_ptr<int> number2(new int(222)); // direct instantiation (preferred)
    std::cout << *number1 << " " << *number2 << " " << *number3 << " " << std::endl ;

    int c(3);
    int &pt = c;

}
void weakPointersExample() {
    std::cout << "To be implemented";
}
void pointerRefExample (){
    std::cout << "POINTERS & REFs EXAMPLE \n";
    // &ref, pointer, initialization.
    int j(10);
    int *k = &j;
    int & l = j;
    std::cout << "j, k & l same: \n" << "j:" << &j << "\nk:" << k << "\nl:" << &l << std::endl;

    int b(10); int *intPointer = &b;
    int *heapPtr = new int(10);
    std::cout << "Comparison of hex digits / bits: \nStck size: " << sizeof(intPointer) << std::dec << std::endl << "Heap size: " << sizeof(heapPtr) << std::dec << std::endl;
    std::cout << "\nYou can get the the address a pointer stores: " << intPointer << "\nThe value of that address:" << *intPointer <<" \nThe address of the pointer variable itself on the stack: "<< &intPointer << std::endl;

}
void pointerArithmeticExample (){
    std::cout << "POINTER ARITHMETIC EXAMPLE \n";
    int arr[5] = {1,2,3,4,5}; //4Bytes each
    // int arr[5] = {1,2,3,4,5}; //8Bytes each
    // NB: 0x16d2a7708 - 0x16d2a7710 = 0x8 - 8,9,a,b,c,d,e,0
    std::cout << "Element and address:\n";
    for (int i=0; i<5; i++){
        std::cout << *(arr+i) << " Address:" << arr+i << " Size(B):"  << sizeof(*(arr+i))<< std::endl;
    }

    std::cout << "Method 1:\n";
    for (int i=0; i<5; i++){
        std::cout << *(arr+i) << " ";
    }
    std::cout << "\nMethod 2:\n";
    for (int a: arr){
        std::cout << a << " ";
    }
    std::cout << "\nMethod 3:\n";
    for (int i=0; i<5; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    sharedPointersExample();
    uniquePointersExample();
    weakPointersExample();
    pointerRefExample();
    pointerArithmeticExample();
}