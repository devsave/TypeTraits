#include <iostream>

using namespace std;

// Possible Implementation:
// template<class T, class U>
// struct is_same : std::false_type{};
// 
// template<class T>
// struct is_same<T, T>: std::true_type{};

typedef int Integer1;
using Integer2 = int;

class A{};
class B : public A{};

int main()
{
    cout << std::is_same<int, int>::value << endl;
    cout << std::is_same<int, const int>::value << endl;
    cout << std::is_same<int, volatile int>::value << endl;
    cout << std::is_same<int, Integer1>::value << endl;
    cout << std::is_same<int, Integer2>::value << endl;
    cout << std::is_same<int, short>::value << endl;
    cout << std::is_same<int, long>::value << endl;
    cout << std::is_same<A, A>::value << endl;
    cout << std::is_same<B, A>::value << endl;

    system("PAUSE");
}
