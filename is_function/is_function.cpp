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


class A
{
private:
    void operator() (int) {}
};

class B
{
public:
    void(*func(char)) (int) {}
};

class C
{
public:
    void func1() {}
    static void func2() {}
};

template<typename>
struct PM_traits {};

template<class T, class U>
struct PM_traits<U T::*> {
    using member_func = U;
};

int main()
{
    {
        int func1();                // general function
        int(*func2)() = func1;      // method pointer
        int(*func3(int))(char);     // method to return a method pointer

        static_assert(std::is_function<int(char)>::value, "");              // true
        static_assert(std::is_function<decltype(func1)>::value, "");        // true
        static_assert(!std::is_function<decltype(func2)>::value, "");       // false
        static_assert(!std::is_function<decltype(func3(0))>::value, "");    // false
    }

    {
        static_assert(!std::is_function<A>::value, "");                     // false
        B b;
        static_assert(!std::is_function<decltype(b.func('a'))>::value, ""); // false
        C c;
        static_assert(!std::is_function<decltype(&c.func1)>::value, "");    // false
        static_assert(std::is_function<decltype(C::func2)>::value, "");     // true
        static_assert(std::is_function<PM_traits<decltype(&C::func1)>::member_func>::value, "");    // true
        static_assert(!std::is_function < decltype(std::mem_fn(&C::func1))>::value, "");    //false
    }

    {
        auto lambda = [](int) {};
        static_assert(!std::is_function <decltype(lambda)> ::value, "");    // false
    }

    {
        static_assert(!std::is_function <std::function<int()>> ::value, "");// false
    }

    system("PAUSE");
}
