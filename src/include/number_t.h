#ifndef NUMBER_T_H
#define NUMBER_T_H
#include <iostream>

extern int numeric_type;

// Numeric type
struct number_t {
public:
    __float128 a;
    long double b;

    // Constructors
    number_t(){
    }

    number_t(number_t& num) {
        if(numeric_type == 0) a = num.a;
        if(numeric_type == 1) b = num.b;
    }

    number_t(volatile number_t& num) {
        if(numeric_type == 0) a = num.a;
        if(numeric_type == 1) b = num.b;
    }

    number_t(const number_t& num) {
        if(numeric_type == 0) a = num.a;
        if(numeric_type == 1) b = num.b;
    }

    template<typename T>
    number_t(T num) {
        if(numeric_type == 0) a = num;
        if(numeric_type == 1) b = num;
    }

    // Start operator overloading

    // Arithmetic Operators
    template<typename T>
    number_t operator-(T num) {
        number_t mynum(num);
        if(numeric_type == 0) mynum.a = a - mynum.a;
        if(numeric_type == 1) mynum.b = b - mynum.b;
        return mynum;
    }

    template<typename T>
    number_t operator+(T num) {
        number_t mynum(num);
        if(numeric_type == 0) mynum.a = a + mynum.a;
        if(numeric_type == 1) mynum.b = b + mynum.b;
        return mynum;
    }

    template<typename T>
    number_t operator*(T num) {
        number_t mynum(num);
        if(numeric_type == 0) mynum.a = a * mynum.a;
        if(numeric_type == 1) mynum.b = b * mynum.b;
        return mynum;
    }

    template<typename T>
    number_t operator/(T num) {
        number_t mynum(num);
        if(numeric_type == 0) mynum.a = a / mynum.a;
        if(numeric_type == 1) mynum.b = b / mynum.b;
        return mynum;
    }

    template<typename T>
    number_t operator*=(T num) {
        number_t mynum(num);
        if(numeric_type == 0) a = a * mynum.a;
        if(numeric_type == 1) b = b * mynum.b;
        return *this;
    }

    template<typename T>
    number_t operator+=(T num) {
        number_t mynum(num);
        if(numeric_type == 0) a = a + mynum.a;
        if(numeric_type == 1) b = b + mynum.b;
        return *this;
    }

    template<typename T>
    number_t operator-=(T num) {
        number_t mynum(num);
        if(numeric_type == 0) a = a - mynum.a;
        if(numeric_type == 1) b = b - mynum.b;
        return *this;
    }

    template<typename T>
    number_t operator/=(T num) {
        number_t mynum(num);
        if(numeric_type == 0) a = a / mynum.a;
        if(numeric_type == 1) b = b / mynum.b;
        return *this;
    }

    template<typename T>
    number_t operator=(T num) {
        number_t mynum(num);
        if(numeric_type == 0) a = mynum.a;
        if(numeric_type == 1) b = mynum.b;
        return *this;
    }

    // Arithmetic volatile operators

    // Arithmetic Operators
    template<typename T>
    number_t operator-(T num) volatile{
        number_t mynum(num);
        if(numeric_type == 0) mynum.a = a - mynum.a;
        if(numeric_type == 1) mynum.b = b - mynum.b;
        return mynum;
    }

    template<typename T>
    number_t operator+(T num) volatile{
        number_t mynum(num);
        if(numeric_type == 0) mynum.a = a + mynum.a;
        if(numeric_type == 1) mynum.b = b + mynum.b;
        return mynum;
    }

    template<typename T>
    number_t operator*(T num) volatile{
        number_t mynum(num);
        if(numeric_type == 0) mynum.a = a * mynum.a;
        if(numeric_type == 1) mynum.b = b * mynum.b;
        return mynum;
    }

    template<typename T>
    number_t operator/(T num) volatile{
        number_t mynum(num);
        if(numeric_type == 0) mynum.a = a / mynum.a;
        if(numeric_type == 1) mynum.b = b / mynum.b;
        return mynum;
    }

    template<typename T>
    number_t operator*=(T num) volatile{
        number_t mynum(num);
        if(numeric_type == 0) a = a * mynum.a;
        if(numeric_type == 1) b = b * mynum.b;
        return *this;
    }

    template<typename T>
    number_t operator+=(T num) volatile{
        number_t mynum(num);
        if(numeric_type == 0) a = a + mynum.a;
        if(numeric_type == 1) b = b + mynum.b;
        return *this;
    }

    template<typename T>
    number_t operator-=(T num) volatile{
        number_t mynum(num);
        if(numeric_type == 0) a = a - mynum.a;
        if(numeric_type == 1) b = b - mynum.b;
        return *this;
    }

    template<typename T>
    number_t operator/=(T num) volatile{
        number_t mynum(num);
        if(numeric_type == 0) a = a / mynum.a;
        if(numeric_type == 1) b = b / mynum.b;
        return *this;
    }

    template<typename T>
    number_t operator=(T num) volatile{
        number_t mynum(num);
        if(numeric_type == 0) a = mynum.a;
        if(numeric_type == 1) b = mynum.b;
        return *this;
    }

    // Relational Operators
    template<typename T>
    bool operator>(T num) {
        number_t temp(num);
        if(numeric_type == 0) return a > temp.a;
        if(numeric_type == 1) return b > temp.b;
        return false;
    }

    template<typename T>
    bool operator<(T num) {
        number_t temp(num);
        if(numeric_type == 0) return a < temp.a;
        if(numeric_type == 1) return b < temp.b;
        return false;
    }

    template<typename T>
    bool operator!=(T num) {
        number_t temp(num);
        if(numeric_type == 0) return a != temp.a;
        if(numeric_type == 1) return b != temp.b;
        return false;
    }

    template<typename T>
    bool operator==(T num) {
        number_t temp(num);
        if(numeric_type == 0) return a == temp.a;
        if(numeric_type == 1) return b == temp.b;
        return false;
    }

    template<typename T>
    bool operator>=(T num) {
        number_t temp(num);
        if(numeric_type == 0) return a >= temp.a;
        if(numeric_type == 1) return b >= temp.b;
        return false;
    }

    template<typename T>
    bool operator<=(T num) {
        number_t temp(num);
        if(numeric_type == 0) return a <= temp.a;
        if(numeric_type == 1) return b <= temp.b;
        return false;
    }

    // Const relational operators
    // Relational Operators
    template<typename T>
    bool operator>(T num) const{
        number_t temp(num);
        if(numeric_type == 0) return a > temp.a;
        if(numeric_type == 1) return b > temp.b;
        return false;
    }

    template<typename T>
    bool operator<(T num) const{
        number_t temp(num);
        if(numeric_type == 0) return a < temp.a;
        if(numeric_type == 1) return b < temp.b;
        return false;
    }

    template<typename T>
    bool operator!=(T num) const{
        number_t temp(num);
        if(numeric_type == 0) return a != temp.a;
        if(numeric_type == 1) return b != temp.b;
        return false;
    }

    template<typename T>
    bool operator==(T num) const{
        number_t temp(num);
        if(numeric_type == 0) return a == temp.a;
        if(numeric_type == 1) return b == temp.b;
        return false;
    }

    template<typename T>
    bool operator>=(T num) const{
        number_t temp(num);
        if(numeric_type == 0) return a >= temp.a;
        if(numeric_type == 1) return b >= temp.b;
        return false;
    }

    template<typename T>
    bool operator<=(T num) const{
        number_t temp(num);
        if(numeric_type == 0) return a <= temp.a;
        if(numeric_type == 1) return b <= temp.b;
        return false;
    }

    // Typecasting
    template<typename T>
    operator T() const {
        if(numeric_type == 0) return (T)a;
        if(numeric_type == 1) return (T)b;
        return 0;
    }

    template<typename T>
    operator T() volatile {
        if(numeric_type == 0) return (T)a;
        if(numeric_type == 1) return (T)b;
        return 0;
    }

    template<typename T>
    operator T() {
        if(numeric_type == 0) return (T)a;
        if(numeric_type == 1) return (T)b;
        return 0;
    }

    //Minus unary operator
    number_t operator-() {
        number_t num(*this);
        if(numeric_type == 0) num.a = -a;
        if(numeric_type == 1) num.b = -b;
        return num;
    }

};

#include <math.h>

using namespace std;

template<typename T>
inline number_t operator*(T d, struct number_t num) {
    if(numeric_type == 0) return d * num.a;
    if(numeric_type == 1) return d * num.b;
    return 0;
}

template<typename T>
 number_t operator+(T d, struct number_t num) {
    if(numeric_type == 0) return d + num.a;
    if(numeric_type == 1) return d + num.b;
    return 0;
}

template<typename T>
 number_t operator-(T d, struct number_t num) {
    if(numeric_type == 0) return d - num.a;
    if(numeric_type == 1) return d - num.b;
    return 0;
}

template<typename T>
 number_t operator/(T d, struct number_t num) {
    if(numeric_type == 0) return d / num.a;
    if(numeric_type == 1) return d / num.b;
    return 0;
}

template<typename T>
 bool operator>(T d, struct number_t num) {
    if(numeric_type == 0) return d > num.a;
    if(numeric_type == 1) return d > num.b;
    return false;
}

template<typename T>
inline bool operator<(T d, struct number_t num) {
    if(numeric_type == 0) return d < num.a;
    if(numeric_type == 1) return d < num.b;
    return false;
}

#endif // NUMBER_T_H
