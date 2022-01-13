
#include <tuple>
#include <iostream>
using namespace std;
typedef std::tuple<int, double, int, double> Mytuple;
int main() {
    typedef tuple<int, char, float> tp;
    tp t1(1, 'c', 1.1);
    tp t2(2, 'd', 2.2);
    tp t3 = make_tuple(3, 'd', 3.3);
    cout<<tuple_size<tp>::value<<endl;
    
    int first;
    char second;
    float third;
    
    tie(first, second, third)=make_tuple(100, 'c', 100.100);
    cout<<first<<endl;
    cout<<second<<endl;
    cout<<third<<endl;
    return (0);
}
