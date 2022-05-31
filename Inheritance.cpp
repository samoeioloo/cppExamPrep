//
// Created by Chris Kay on 2022/05/28.
//

#include <iostream>

namespace Inheritance {

    class Base {
    public:
        //public class members
        int x;

        //constructor
        Base(int x, int y, int z) : x(x), y(y), z(z) {};

        // public operator overloading
//        int operator()(int i, int j) {
//            return x + y;; // (x,y) overload
//        };
//
//        Base operator+(const Base &rhs) {
//            this->x = this->x - rhs.x;
//            this->y = this->y + rhs.y;
//            return *this;
//        }

        //public getter method
        int getY(void) {
            return this->y; //explicit else just y would do or (*this).y
        }

        std::string getSecretVault() {
            return bestySecretVault;
        }

        //hommies declaration both function and class.
        //A hommie can access the private and protected members of the class in which it is declared as a friend.
//        friend void bff(Base &base);
//
//        friend class Besty;
        //Note 1=> friend Base & operator+( Base & lhs, const Base & rhs);

    private:
        int y;
        std::string bestySecretVault;

    protected:
        int z;
    };

    class Child : public Base {
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

    class GrandChild : public Child {
    public:
        std::string totem;

        GrandChild(int x, int y, int z, std::string name, std::string totem) : Child(x, y, z, name), totem(totem) {
            //NOTE: child class can only access public and protected (x,z) but not private members (y).
            //Though it can instantiate the private variable and access through a getter.
            std::cout << "GrandChild initialized with parent x,y: " << Child::x << ";" << Child::z << " and name: "
                      << this->name << std::endl;
            std::cout << "Access Parent's private members through getter:" << Child::getY() << std::endl;
            std::cout << "Address and sizes:" << &(this->x) << " " << sizeof(this->name) << " " << &(this->z)
                      << std::endl; //Debugging statements
        }
    };
    //add virtual and import the Base too.

    void inheritanceExample() {
        Child i(10,20, 30,"Johanna");

        //GrandChild j(10,20, 30,"Johanna", "kl");
        //notes on preventing duplicate inheritance - virtual virtual.

        //multiple inheritence example.
        //static vs dynamic polymophysm : upcast/ downcast runtime vs compiletime. static is default. override function?
    }


}

int main(){
    Inheritance::inheritanceExample();
}