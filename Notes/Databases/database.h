#ifndef database_h
#define database_h
using namespace std;

class Database
{
public:
    Database(int size);
    ~Database(); // Destructor
    Database(const Database &from);
    Database operator=(const Database &rhs);
    int operator[](int index) const; // Getter
    int &operator[](int index);      // Setter
    void print_first_data() const;
    int *data;
    unsigned int size;
};
#endif