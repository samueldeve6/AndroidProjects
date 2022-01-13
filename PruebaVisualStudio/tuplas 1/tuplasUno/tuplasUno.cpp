#include <iostream>
#include <tuple>
using namespace std;

int main() {
	tuple <int, char> t1(20, 'T');
	tuple <char, char,short> t2('R', 'r',43);
	auto t3 = tuple_cat(t1, t2);
	cout << get<0>(t3) << endl;
	cout << get<1>(t3) << endl;
	cout << get<2>(t3) << endl;
	cout << get<3>(t3) << endl;
	cout << get<4>(t3) << endl;
}