
#include <iostream>

using namespace std;
// Base Class declaration
class student {
private:
  int nr_of_marks;
  int * marks;
public:
  student(int n) :
    nr_of_marks(n),
    marks(new int[n]) {}
    virtual ~student(void) // need to make destructor virtual
    { delete [] marks; }
};

// Derived class declaration
class msc : public student {
private:
  std::string * papers;
public:
  msc(void) : student(10),
    papers(new std::string[3]) {}
     ~msc(void) { delete [] papers; } 
};
// Driver Code
int main()
{
	student * s = dynamic_cast<student *>(new msc);
    if(s == nullptr){
        cout << "s is null" << endl;

    }
    else{
        cout << "not null" << endl;
    }
    delete s;

	return 0;
}
