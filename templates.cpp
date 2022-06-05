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

/*
 Classmember operator [] overloading.
    template <typename T>
    private:
        T * a;
        int _size;
    public:
        buffer(int size) _size(size), a(new T[size]) {}
        ~buffer(void) { delete [] a; }
        T & operator[](int index) { return a[index]; }
    };
*/

    //Buffer template for various types.
    template <typename T> class buffer { // Parameterise buffer with some type T.
        T * a; // pointer to a T
        int _size; // buffer size
    public: // Can declare + implement within class. e.g.
        buffer(int size) : a(new T[size]), _size(size) {} // constructor
        ~buffer(void) { delete [] a; } // destructor
        T & operator[](int index); // Just declare operator[] in class
    };

    // Implementation of operator[] later in the .h - external nonclassmemnber
    template <typename T> T & buffer<T>::operator[](int index)
    { return a[index]; }

    //copy_if stl ACTUAL algorithm - study and understand what happens under the hood.
    template <typename InIterator, typename OutIterator, typename Predicate>
    OutIterator copy_if(InIterator first, InIterator last, OutIterator result, Predicate pred)
    {
        for ( ; first != last; ++first)
            if (pred(*first)) *result++ = *first;
        return result;
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

    //templated functor
    template <typename T>
    class add_to{
    public:
        add_to(const T & value) : ptr(&value) {}
        T operator()(const T & value) const
        { return *ptr + value; } // add value to every element
        const T * ptr;
    };

    class F {
    public:
        bool operator()(int a, int b) const
        { return a < b; }
    };
    class not_equal_to {
    public:
        not_equal_to(int i) : cmp_value(i) {}
        bool operator()(int container_value) const
        { return cmp_value != container_value; }
        int cmp_value;
    };
    //Templated not_equal_to_templated

    template <typename T> class not_equal_to_templated {
    public:
        not_equal_to_templated(const T & cmp_value) : cmp_ptr(&cmp_value) {}
        bool operator()(const T & container_value) const
        { return *cmp_ptr != container_value; }
        const T * cmp_ptr; // Avoid deep copies, store a ptr
    };

    void copy_if_eg() {
        vector<int> data = {0, 1, 2, 3, 4}; // C++11 initializer list
        vector<int> result;
        not_equal_to net(3);// CONSTRUCT Functor. Call not_equal_to(3)
        cout << (net(3) == false); // Call net.operator(3). { return 3 != 3; }
        cout << (net(2) == true); // Call net.operator(2). { return 3 != 2; }
        // Copies everything except 3
        std::copy_if(data.begin(), data.end(),back_inserter(result), not_equal_to(3));
        //TODO printout values b4 and after in one line
    }




    void not_equal_to_eg() {
        vector <string> data = {"AA", "BB", "CC", "DD", "EE"}; // C++11 initializer
        vector <string> result;
        // Copies everything except "DD"
        copy_if(data.begin(), data.end(),
                back_inserter(result), not_equal_to_templated<string>("DD"));
        //TODO printout values b4 and after in one line
    }

    //functor to implement on foreach.
    template <typename T> class bit_examiner {
    public:
        bit_examiner(std::size_t which_bit) : count(0), bit(which_bit) {}
        bit_examiner(const bit_examiner & rhs) : count(rhs.count), bit(rhs.bit) {}
        // Count all occurences of specified bit. here, & and << are bit operators
        void operator()(const T & value)
        { if(value & (0x1 << bit)) ++count; }
        std::size_t count;
        std::size_t bit;
    };
    void for_each_eg() {
        vector<int> data = {0, 1, 2, 3, 4}; // C++11 initializer list
        bit_examiner<int> functor(6); // How many ints have bit 6 set?
        for_each(data.begin(), data.end(), functor);
        cout << functor.count << endl;
    }

    void custom_functor_eg(){
        cout << "TRANSFORM Algorithm: Custom functor tripling input vector elements" << endl;
        vector<int> input = {2,4,5,10};
        vector<int> output;
        std::transform(input.begin(), input.end(), back_inserter(output), custom_functor());
        //std::transform(input.begin(), input.end(), back_inserter(output), add_to<int>());
        for(int a: output){ cout << a << " "; } cout<< endl;

        F f; // create an instance
        if (f('i','j')) cout << "i < j" << endl;

        //In-built functors - greater and less
        std::greater<int> I;
        if (I(3,2)) cout << "3 is greater than 2" << endl;

        less<string> l;
        string s1= "ha", s2="sdfsdfgd";
        if (l(s1,s2)) cout << s1 << " is less than " << s2 << endl;

        //CopyIf example
        copy_if_eg();

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
