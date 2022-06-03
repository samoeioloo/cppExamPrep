//
// Created by Chris Kay on 2022/05/28.
//

#include <iostream>

namespace Inheritance {

    class Base {
    public:
        int x;
        Base(int x, int y, int z) : x(x), y(y), z(z) {};
        int getY(void) { //public getter method
            return this->y; //explicit else just y would do or (*this).y
        }
        std::string getSecretVault() { return bestySecretVault; }
    private:
        int y;
        std::string bestySecretVault;
    protected:
        int z;
    };

    class Child : virtual public Base {
    public:
        std::string name;

        Child(int x, int y, int z, std::string name) : Base(x, y, z), name(name) {
            //NOTE: child class can only access public and protected (x,z) but not private members (y).
            //Though it can instantiate the private variable and access through a getter.
            std::cout << "Child initialized with parent x,y: " << Base::x << ";" << Base::z << " and name: "
                      << this->name << std::endl;
            std::cout << "Access Parent's private members through getter:" << Base::getY() << std::endl;
            std::cout << "Address and sizes:" << &(this->x) << " " << sizeof(this->name) << " " << &(this->z)
                      << std::endl; //Debugging statements
        }
    };

    class GrandChild : virtual public Base, public Child {
    public:
        std::string totem;

        GrandChild(int x, int y, int z, std::string name, std::string totem) : Base(x,y,z), Child(x, y, z, name), totem(totem) {
            //NOTE: child class can only access public and protected (x,z) but not private members (y).
            //Though it can instantiate the private variable and access through a getter.
            std::cout << "GrandChild initialized with parent x,y: " << Child::x << ";" << Child::z << " and name: "
                      << this->name << std::endl;
            std::cout << "Access Parent's private members through getter:" << Child::getY() << std::endl;
            std::cout << "Address and sizes:" << &(this->x) << " " << sizeof(this->name) << " " << &(this->z)
                      << std::endl; //Debugging statements
        }
    };

    class student{
    public:
        int gpa;
        student(int gpa): gpa(gpa){}
    };

    class employee{
    public:
        int salary;
        std::string jobTitle;
        employee(int salary, std::string title): salary(salary), jobTitle(title){}
    };
    class tutor: public student, protected employee{
    public:
        std::string course;
        tutor(int gpa, int salary, std::string title, std::string course): student(gpa), employee(salary, title), course(course){}

        void getSalaryTitle(){
            std::cout << "salary: "<< salary << " "<< employee::jobTitle << std::endl; // can access inherited via employee::salary or salary since you've inherited it duh!
        };

        //if u try directly access salary / title, it will refuse as its been inherited with protected.
        //if you try access course or gpa, those will be directly accessible.
    };

    void multipleInheritance(){
        tutor KCK(90, 50, "Head Tutor", "CSC3022F");
        std::cout << "course: " << KCK.course << " gpa: " << KCK.gpa << std::endl;
        KCK.getSalaryTitle();

    }

    // Virtual added to both classes as the grandchild inherits from both the Child and the base.
    void inheritanceExample() {
        Child i(10,20, 30,"Johanna");
        GrandChild j(10,20, 30,"Johanna", "kl");
    }
    //multiple inheritence example.
    //static vs dynamic polymophysm : upcast/ downcast runtime vs compiletime. static is default. override function?
    //notes on preventing duplicate inheritance - virtual virtual.


}

int main(){
    //Inheritance::inheritanceExample();
    Inheritance::multipleInheritance();
}