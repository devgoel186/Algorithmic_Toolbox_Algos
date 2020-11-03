// To assign max value to a variable/element, using its maximum permitted value is a good method.

#include <limits>
#include <iostream>
// <limits> is used to get max/min limits of data types

using namespace std;

int main()
{
    int a = numeric_limits<int>::max();
    int b = numeric_limits<int>::min();
    cout << "Max = " << a << "\nMin = " << b;
    // Max will normally be equal to 2,147,483,647 and Min = -2,147,483,648

    // If you really need a true "infinite" value, you would have to use a double or a float. Then you can simply do this - 
    float c = std::numeric_limits<float>::infinity();
    float d = -c;
    cout << "\nINFINITY = " << c << "\nNEGATIVE INFINITY = " << d;
}