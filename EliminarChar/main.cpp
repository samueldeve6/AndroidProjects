    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        string str("b%ab&me#$ba@b");
        string a, b;
        a = str.replace(str.find("%"),1,"*");
             cout << a << endl; // salida b * ab & me # $ ba @ b
        string s("take you fly");
        b = s.replace(s.find("you"),1,"");
             cout << b << endl; // salida llévame a volar
        return 0;
    }
