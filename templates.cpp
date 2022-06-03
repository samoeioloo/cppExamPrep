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

    //TODO more examples impelementing consepts from scratch, implementing built-in concepts etc.
    //another example writing concepts / implementing them



namespace stl{


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


}
