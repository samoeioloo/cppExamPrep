//
// Created by Chris Kay on 2022/06/03.
//
#include <iostream>
#include <vector>
#include <numeric> //to use accumulate - not algorithm.

using namespace std;
namespace templates {

    template<typename T>
    T MyMax(T a, T b) {
        return (a > b) ? a : b;
    }

    //template specialization for char. Specialized case prioritized over generalized case.
    template<>
    char MyMax<char>(char a, char b) {
        cout << " The larger char is " << ((a > b) ? a : b);
        return (a > b) ? a : b;
    }

    //dependant typenames.
    template<typename T, int Size>
    auto createContainter() {
        using it = typename std::vector<T>::iterator;
        std::vector <T> a(Size);
        return a;
    }

    // concepts - requires

    template<typename T, typename U>
    concept SameType = std::is_same_v<T, U>;
    //concept SameType =  requires(T,U){ std::is_same_v<T,U>;}; //can be defined this way to accomodate other constraints.

    template<typename T, typename U> requires (SameType<T, U> ) // ensure types are same and are integral types.
    //add inbuilt constraints of && std::is_integral<T> && std::is_integral<U>
    T Sum(T a, U b) {
        return a + b;
    }
}

    //TODO more examples impelementing consepts from scratch, implementing built-in concepts etc.
    //another example writing concepts / implementing them



namespace stl{

    void STLAlgos() {
        cout << "FILL with 77 STL Algo" << endl;
        vector<int> myVect0 = {2,9,3,8,5,7};
        std::fill(myVect0.begin(), myVect0.end(), 77);
        for (int a : myVect0){ cout << a << " "; } cout << endl << endl; //All filled with 77.

        cout << "REMOVE 55 from vector STL Algo" << endl;
        vector<int> myVect1 = {2,9,3,8,55,7};
        //std::remove(myIntVect.begin(), myIntVect.end(), 77); //does not remove as ecxpected.
        std::remove(myVect1.begin(), myVect1.end(), 55); //does not remove as ecxpected.
        for (int a : myVect1) { cout << a << " "; } cout << endl << endl;;

        cout << "FIND iterator with value 9 in vector STL Algo" << endl;
        vector<int> myVect2 = {2,9,3,8,55,7};
        vector<int>::iterator it = std::find(myVect2.begin(), myVect2.end(), 9);
        auto *ptr  = &(*it);  cout << "address: " << ptr << " value: " << *it << endl << endl; //Find 33 and print address and value.

        cout << "SORT vector STL Algo" << endl;
        vector<int> myVect3 = {2,9,3,8,55,7};
        std::sort(myVect3.begin(), myVect3.end()); //does not remove as ecxpected.
        for (int a : myVect3) { cout << a << " "; } cout << endl << endl;

        cout << "SUM vector STL Algo" << endl;
        int sum = std::accumulate(myVect3.begin(), myVect3.end(), 1000); //does not remove as ecxpected.
        cout << "Sum with initial value of 1000 is: " << sum << endl << endl;
    }

    //Functors - class object that can optionally be instantiable with overloaded () operator.
    //Predefined functors and also you can make custom ones.

    class custom_functor{
    public:
        int operator()(const int & x) const{ // TODO does this const enable us to use the const variable? I know const functions woul dbe needd to accept the const variable.
            return x*3;
        }
    };

    void custom_functor_eg(){
        cout << "TRANSFORM Algorithm: Custom functor tripling input vector elements" << endl;
        vector<int> input = {2,4,5,10};
        vector<int> output;
        std::transform(input.begin(), input.end(), back_inserter(output), custom_functor());
        for(int a: output){ cout << a << " "; } cout<< endl;
    }

}

int main(){
    //templates, functors, lambdas, concepts (requires) - built in and own., traits.
    //different parameter types, specialization,
    //stl algorithms
    //exceptions.
    cout << templates::MyMax<int>(2,4) << endl;
    cout << templates::MyMax<char>('r','t') << endl;
    cout << templates::Sum(2.0,4.2) <<endl;
    //cout << templates::Sum(2,4.0); //will fail because Sum has a sameType concept constraint.
    stl::STLAlgos();
    stl::custom_functor_eg();


}
