#include <tuple>
#include <iostream>
using namespace std;
int main()
{
	/*tuple<int, char, bool, float> thing;
	thing = make_tuple(23, 'H', true, 24.3);
	cout << get<0>(thing) << endl;
	cout << get<1>(thing) << endl;
	cout << get<2>(thing) << endl;
	cout << get<3>(thing) << endl;
	*/
	tuple<int, char, bool, float> thing= make_tuple(23, 'H', true, 3.2);
	cout << get<0>(thing) << endl;
	cout << get<1>(thing) << endl;
	cout << get<2>(thing) << endl;
	cout << get<3>(thing) << endl;
}
