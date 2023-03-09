#include <iostream>
using namespace std;

class Dog{
    public: // Creates the class to be public Anything after public is public
    int age;
    //private: //Anything after private is private
    string name;
    int humanAge(){
        return 7 * age;
    }
    Dog(int age, string name){ // Constructor
    this->age = age;
    this->name = name;
    }
};


int main(){
    //Dog d;
    Dog d(3, "Bark");
    //d.age = 4;
    //d.name = "Spot";
    cout << "Age of " << d.name << " is " << d.age << endl;
    cout << d.humanAge() << endl;
};
