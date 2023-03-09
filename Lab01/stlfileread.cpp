#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstring>
using namespace std;

class readSTLfile
{
public:
    double minX;
    double minY;
    double minZ;
    double maxX;
    double maxY;
    double maxZ;
    int numFacets;

    readSTLfile(string filename)
    {
        // Set initial mins and maxs
        minX = numeric_limits<double>::max();
        minY = numeric_limits<double>::max();
        minZ = numeric_limits<double>::max();
        maxX = numeric_limits<double>::min();
        maxY = numeric_limits<double>::min();
        maxZ = numeric_limits<double>::min();
        // Set initial number of facets to 0
        numFacets = 0;

        ifstream ifile(filename);
        // Empty string to store line from stl file
        string line;
        // Variables to store x,y,z file data in
        double x;
        double y;
        double z;
        string type;

        // Read lines of the stl file until the last one is reached
        while (!ifile.eof())
        {
            // Store next line of file
            getline(ifile, line);
            // Create input string stream connected to line string
            istringstream iss(line);
            // Extract data from file
            iss >> type;

            int vertexR = type.compare("vertex");
            if (vertexR == 0)
            {
                iss >> x;
                iss >> y;
                iss >> z;
                cout << x << endl;
                // Change min and max values
                if (x < minX)
                {
                    minX = x;
                }
                else if (x > maxX)
                {
                    maxX = x;
                }
                if (y < minY)
                {
                    minY = y;
                }
                else if (y > maxY)
                {
                    maxY = y;
                }
                if (z < minZ)
                {
                    minZ = z;
                }
                else if (z > maxZ)
                {
                    maxZ = z;
                }
            }
            int facetR = type.compare("facet");
            if (facetR == 0)
            {
                numFacets++;
            }
        }
    }
};

int main()
{
    string fileInput;
    cout << "Which STL file to read? " << endl;
    cin >> fileInput;
    readSTLfile f1(fileInput);
    cout << "The number of facets is: " << f1.numFacets << endl;
    cout << "The min X is: " << f1.minX << endl;
    cout << "The min Y is: " << f1.minY << endl;
    cout << "The min Z is: " << f1.minZ << endl;
    cout << "The max X is: " << f1.maxX << endl;
    cout << "The max Y is: " << f1.maxY << endl;
    cout << "The max Z is: " << f1.maxZ << endl;
}