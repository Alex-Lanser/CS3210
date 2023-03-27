#include <iostream>
using namespace std;

class Pet
{
public:
    string name;
    Pet();
    Pet(string name, int num_legs);
    void print_type();
private:
    int num_legs;
};

Pet::Pet()
{
    name = " ";
    cout << "Pet default constructor" << endl;
}

Pet::Pet(string name, int num_legs)
{
    this->name = name;
    cout << "Pet parameterized constructor" << endl;
}

void Pet::print_type()
{
    cout << "Type is Pet" << endl;
}

class Cat : public Pet
{
public:
    int fish;
    Cat();
    Cat(string name, int fish);
};

Cat::Cat()
{
    name = " ";
    fish = 0;
    cout << "Cat default constructor" << endl;
}

Cat::Cat(string name, int fish) : Pet(name, 4), fish(fish)
{
    // this->name = name;
    // this->fish = fish;
    cout << "Cat parameterized constructor" << endl;
}

int main()
{
    Pet p("Spot", 4);
    p.print_type();
    cout << p.name << endl
         << endl;

    Cat c("Kitty", 4);
    cout << c.name << endl;
    cout << c.fish << endl
         << endl;

    Pet *petptr1 = &p;
    Cat *catptr1 = &c;
    Pet *petptr2 = &c; // This works because cat is a pet
    // Cat *catptr2 = &p; // This will not work because a child cannot point to a parent
    // Pet pet1 = c; // This is slicing. Try to avoid. There's no room in pet1 for the c fish.
    // Will only keep the pet part. Removes the things that makes cat unique from pets.
    // Pet *petpointer = &c; // No slicing here

    return 0;
}