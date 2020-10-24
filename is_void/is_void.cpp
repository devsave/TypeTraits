#include <iostream>

using namespace std;

// Possible Implementation:
// template<class T>
// struct is_void: std::is_same<void, typename std::remove_cv<T>::type> {};

int main()
{
    cout << std::is_void<void>::value << endl;
    cout << std::is_void<const void>::value << endl;
    cout << std::is_void<volatile void>::value << endl;
    cout << std::is_void<const volatile void>::value << endl;
    cout << std::is_void<bool>::value << endl;

    system("PAUSE");
}
