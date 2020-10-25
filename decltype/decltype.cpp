#include <iostream>

using namespace std;

int main()
{
    {
        class A
        {
        public:
            char mem = 0;
            void func(char) {}
            static void staticFunc(int) {}
        };

        A a;
        int x = 0;
        const int y = 0;
        volatile const int z = 0;
        int & xx = x;
        int && xxx = 0;

        decltype(x) x1;                         // int
        decltype(y) y1 = 0;                     // const int
        decltype(z) z1 = 0;                     // const volatile int
        decltype(xx) xx1 = xx;                  // int &
        decltype(xxx) xxx1 = 10;                // int &&
        decltype(1) l1;                         // int
        decltype("hello") l2 = "world";         // const char[6]&


        decltype(A::mem) k;     // char
        decltype(a.mem) k1;     // char


        // error C3867: 'A::func': non-standard syntax; use '&' to create a pointer to member
        // decltype(A::func) f2;
        decltype(A::staticFunc) f1; // void (int)
    }

    {
        int x = 0, y = 0;
        decltype(x + y) v1;             // int
        decltype(x += y) v2 = x;        // int&
        decltype(static_cast<int&&>(x)) v3 = 0;  // int&&
    }

    {
        int func1();
        int& func2();
        int && func3();
        const volatile int&& func4();

        decltype(func1()) v1;           // int
        decltype(func2()) v2 = v1;      // int&
        decltype(func3()) v3 = 0;       // int&&
        decltype(func4()) v4 = 0;       // const volatile int&&

        class A{};
        const A funcA1();
        const A& funcA2();
        const A && funcA3();
        decltype(funcA1()) vA1;         // A
        decltype(funcA2()) vA2 = vA1;   // const A&
        decltype(funcA3()) vA3 = A();   // const A&&
    }


    {
        int x1 = 0;
        int &x2 = x1;
        int && x3 = 0;
        decltype((1)) y1;                   // int
        decltype(x1) y2;                    // int
        decltype((x1)) y3 = y1;             // int&
        decltype((x2)) y4 = y1;             // int&
        decltype((x3)) y5 = y1;             // int&
        decltype((std::move(x1))) y6 = 0;   // int&&
    }

}


