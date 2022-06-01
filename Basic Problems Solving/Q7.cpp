// 7.	WAP to find out Area of a circle(radius value user given) 

#include <iostream>
#include <cmath>
#define PI 3.141592654

int main()
{
    float radius, area;
    std::cout << "Enter radius: " << "\n";
    std::cin >> radius;

    area = PI * std::pow(radius, 2);

    std::cout << "Area of the circle is: " << area << "\n";
    return 0;
}