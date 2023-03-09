// Varnell 2023 class to read and process file
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
using namespace std;
// class to process file and store some file data
class readFile
{
public:
    // member variables
    int minAge;
    int maxAge;
    // member functions
    // constructor
    readFile(string filename)
    {
        // set iniitial min/max age
        minAge = numeric_limits<int>::max();
        maxAge = numeric_limits<int>::min();
        // create an input file stream
        ifstream ifile(filename);
        // empty string to store each line of the file
        string line;
        // variables to store file data
        string type;
        string name;
        int age;
        // read and process the file line by line
        while (!ifile.eof())
        {
            // store next line of file in "line" variable
            getline(ifile, line);
            // create an input string stream connected to the line string
            istringstream iss(line);
            // extract three data value from the line
            iss >> type;
            iss >> name;
            iss >> age;
            // if necessary, update min and max age
            if (age > maxAge)
            {
                maxAge = age;
            }
            if (age < minAge)
            {
                minAge = age;
            }
        }
    }
};
int main()
{
    readFile rF1("pets.txt");
    cout << rF1.minAge << endl;
    cout << rF1.maxAge << endl;
    return 0;
}