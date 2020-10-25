#include <functional>
#include <iostream>
#include <type_traits>
#include <typeinfo>

using namespace std;

//// Possible Implementation:
//template<class>
//struct is_function : std::false_type { };
//
//// 对常规函数的特化
//template<class Fn, class... Args>
//struct is_function<Fn(Args...)> : std::true_type {};
//
//// 对变参数函数，如 std::printf 的特化
//template<class Fn, class... Args>
//struct is_function<Fn(Args......)> : std::true_type {};
//
//// 对拥有 cv 限定符的函数类型的特化
//template<class Fn, class... Args>
//struct is_function<Fn(Args...) const> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args...) volatile> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args...) const volatile> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args......) const> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args......) volatile> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args......) const volatile> : std::true_type {};
//
//// 对拥有引用限定符的函数类型的特化
//template<class Fn, class... Args>
//struct is_function<Fn(Args...) &> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args...) const &> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args...) volatile &> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args...) const volatile &> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args......) &> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args......) const &> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args......) volatile &> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args......) const volatile &> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args...) && > : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args...) const &&> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args...) volatile &&> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args...) const volatile &&> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args......) && > : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args......) const &&> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args......) volatile &&> : std::true_type {};
//template<class Fn, class... Args>
//struct is_function<Fn(Args......) const volatile &&> : std::true_type {};

int func1() { return 0; }
int(*func2)() = func1;
int(*func3(int))(char) { return nullptr; }

class A 
{
private:
    void operator() (int) {}
};

class B
{
public:
    void(* func(char)) (int){}
};

class C
{
public:
    void func(){}
};

template<typename>
struct PM_traits{};

template<class T, class U>
struct PM_traits<U T::*> {
    using member_func = U;
};


int main()
{
//     cout << "int(char):" << std::is_function<int(char)>::value << endl;
//     cout << "decltype(func1):" << std::is_function<decltype(func1)>::value << endl;
//     cout << "decltype((func1)):" << std::is_function<decltype((func1))>::value << endl;
// 
//     cout << "decltype(func2):" << std::is_function<decltype(func2)>::value << endl;
//     cout << "decltype(*func2):" << std::is_function<decltype(*func2)>::value << endl;
//     cout << "decltype(func3(0)):" << std::is_function<decltype(func3(0))>::value << endl;
//     cout << "std::function<int(char)>:" << std::is_function<std::function<int(char)>>::value << endl;
//     auto lambda = [](int) {};
//     cout << "decltype(lambda):" << std::is_function <decltype(lambda)> ::value << endl;
//     cout << "A" << std::is_function<A>::value << endl;
//     B b;
//     cout << "decltype(b.func('a')):" << std::is_function<decltype(b.func('a'))>::value << endl;
//     C c;
//     cout << "decltype(&C::func):" << std::is_function<decltype(c.func)>::value << endl;
//     cout << "decltype(&C::func):" << std::is_function<decltype(&C::func)>::value << endl;
//     cout << "PM_traits<decltype(&C::func)>::member_func:" << std::is_function<PM_traits<decltype(&C::func)>::member_func>::value << endl;
// 
//     const type_info& t1 = typeid(decltype(func1));
//     const type_info& t2 = typeid(decltype(func2));
// 
    system("PAUSE");
}
