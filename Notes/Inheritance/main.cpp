#include <iostream>
using namespace std;

class Pet
{
public:
    string name;
    Pet();
    Pet(string name, int num_legs);
    // virtual void print_type();
    virtual void print_type() = 0; // When = 0, it is now a pure virtual function. Means that the child class must have this function
    // Also makes the class abstract
    virtual Pet *clone() = 0;
    ~Pet();

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

Pet::~Pet()
{
    cout << "In pet destructor" << endl;
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
    void print_type();
    ~Cat();
    Pet *clone();
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

void Cat::print_type()
{
    cout << "Type is Cat" << endl;
}

Cat::~Cat()
{
    cout << "In cat destructor" << endl;
}

Pet *Cat::clone()
{
    return new Cat(*this);
}

int main()
{
    // Pet p("Spot", 4);
    // p.print_type();
    // cout << p.name << endl
    //      << endl;

    // Cat c("Kitty", 4);
    // cout << c.name << endl;
    // cout << c.fish << endl
    //      << endl;

    // Pet *petptr1 = &p;
    // Cat *catptr1 = &c;
    // Pet *petptr2 = &c; // This works because cat is a pet
    // petptr2->print_type();
    // // Child class may override a virtual function
    // // But it does not have to

    // Pet *petptr3 = new Cat();
    // delete petptr3;

    // Pet *pets[3];
    // pets[0] = new Cat("Tom", 10);
    // pets[1] = new Cat("Jerry", 3);
    // pets[2] = new Cat("Whiskers", 6); // Can put whatever pet into here if there are more pets... Like fish

    // Pet *petsCopy[3];
    // // for (int i = 0; i < 3; i++)
    // // {
    // //     petsCopy[i] = pets[i]; // Shallow copy
    // // }

    // // for (int i = 0; i < 3; i++)
    // // {
    // //     petsCopy[i] = new Pet(*pets[i]); // Does not work because slicing issue
    // // }

    // for (int i = 0; i < 3; i++)
    // {
    //     petsCopy[i] = pets[i]->clone();
    // }

    //     for (int i = 0; i < 3; i++)
    //     {
    //         delete pets[i];
    //         delete petsCopy[i];
    //     }
    // delete[] pets <-- Do not need since it is on the stack. "Pet* pets[3];"

    // Cat *catptr2 = &p; // This will not work because a child cannot point to a parent
    // Pet pet1 = c; // This is slicing. Try to avoid. There's no room in pet1 for the c fish.
    // Will only keep the pet part. Removes the things that makes cat unique from pets.
    // Pet *petpointer = &c; // No slicing here

    vector<Pet *> grogle;
    cout << grogle.size() << endl; // Size is 0
    grogle.push_back(new Cat("Tom", 10));
    cout << grogle.size() << endl; // Size is 1
    grogle.push_back(new Cat("Jerry", 3));
    grogle.push_back(new Cat("Jorge", 1));
    cout << grogle.size() << endl; // Size is now 3

    
    vector<Pet *> grogleCopy;
    // Shallow copy
    for (int i = 0; i < grogle.size(); i++)
    {
        grogleCopy[i].push_back(grogle[i]);
    }

    // Deep copy
    for (int i = 0; i < grogle.size(); i++)
    {
        grogleCopy[i].push_back(grogle[i]->clone());
    }

    // How to clear the vector
    // delete grogle[0];
    // grogle.clear();

    for (int i = 0; i < grogle.size(); i++)
    {
        delete grogle[i];
    }
    grogle.clear();
    cout << grogle.size() << endl; // Should be 0

    return 0;
}