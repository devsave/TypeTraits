#include <iostream>

using namespace std;

// Possible Implementation:
// template<class T>
// struct is_array: std::false_type {};
// 
// template<class T>
// struct is_array<T[]> :std::true_type{};
// 
// template<class T, std::size_t N>
// struct is_array<T[N]>: std::true_type{};

class A{};

int main()
{
    cout << std::is_array<int[]>::value << endl;
    cout << std::is_array<int[3]>::value << endl;
    cout << std::is_array<const int[3]>::value << endl;
    cout << std::is_array<int[][3]>::value << endl;
    cout << std::is_array<int[3][3]>::value << endl;
    cout << std::is_array<A[]>::value << endl;
    cout << std::is_array<int>::value << endl;
    cout << std::is_array<int*>::value << endl;
    cout << std::is_array<std::array<int,3>>::value << endl;

    system("PAUSE");
}
