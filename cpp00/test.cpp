#include <iostream>
#include <iomanip>

int main()
{
    std::cout << std::right << std::setw(10) << "Hello welcome" << std::setw(10) << "World\n";
    std::cout << std::setw(10) << "again" << std::endl;
    return 0;
}
