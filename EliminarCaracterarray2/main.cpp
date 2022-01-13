#include <iostream>
#include <algorithm>
#include <string>
 
int main()
{
    std::string s = "This is an example";
    std::cout << s << '\n';
 
    //s.erase(0, 1); // Erase "This "
    std::cout << s << '\n';
 
    s.erase(std::find(s.begin(), s.end(), 'a')); // Erase ' '
    std::cout << s << '\n';
 
    s.erase(s.find(' ')); // Trim from ' ' to the end of the string
    std::cout << s << '\n';
}
