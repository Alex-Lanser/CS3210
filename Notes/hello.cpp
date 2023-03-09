// Varnell 2023 Hello World
// compile with: g++ -o hello hello.cpp
// run with: ./hello
#include <iostream>
using namespace std;
namespace ns1{
void f(){std::cout << "ns1" << std::endl;}
}
namespace ns2{
void f(){std::cout << "ns2" << std::endl;}
}
using namespace ns2;
int main(){
std::cout << "Hello World" << std::endl;
f();
return 0;
}