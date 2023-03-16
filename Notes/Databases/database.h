#ifndef database_h
#define database_h
using namespace std;

class Database
{
public:
    Database(int size);
    ~Database(); // Destructor
    void print_first_data() const;
    int *data;
    unsigned int size;
};
#endif