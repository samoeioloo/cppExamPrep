# C++ ExamPrep Repo
Examples on various CPP topics

A file serving as practical revision to a practical C++ course.

### 1. Topics in each file, can be separated by a namespace.
### 2. Add more topics or examples by forking repo and making a PR.
### 3. Feel free to open issues on potential bugs.
### 4. makefile contains targets compiling and running files independently. There is a make all target that compiles and runs all the files. This is done for simplicity as managing header files would have been a nightmare and additional code signatures to write.

# Notes

### 1. C++ Types

Fundamental types in C++ are divided into three categories: integral, floating point, and void. Integral types are capable of handling whole numbers. Floating point types are capable of specifying values that may have fractional parts. The void type describes an empty set of values.

The category integral includes the following datatypes -
```c++
char
bool
short
int
long
long long
wchar_t, __wchar_t
```

The category floating point includes the following datatypes -
```c++
float
double
long double
```

### 2. C++ Concepts

Trivial example:

```c++
template <typename T, typename U, int z >
concept myConcept = std::is_class<T, U> &&
        std::is_integral<z>;

```

### 3. Operator overloading


* OO can be done as class-member (1 argument rhs) or non-member (lhs & rhs) - depending on type of operator. 
* When there is a pvt member involved, use friend.
* += can be returned by reference of modified lhs obj or value of created temp.
* Unary operator takes the format ```void operator~(void){ // body }```
  