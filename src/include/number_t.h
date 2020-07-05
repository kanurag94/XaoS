#ifndef NUMBER_T_H
#define NUMBER_T_H
#include<iostream>

// Numeric type
struct number_t {
public:
    double a;
    double b;

    // Constructors
    number_t(){
    }

    number_t(number_t& num) {
        a = num.a; b = num.b;
    }

    number_t(volatile number_t& num) {
        a = num.a; b = num.b;
    }

    number_t(const number_t& num) {
        a = num.a; b = num.b;
    }

    template<typename T>
    number_t(T num) {
        a = num; b = num;
    }

    // Start operator overloading

    // Arithmetic Operators
    template<typename T>
    number_t operator-(T num) {
        number_t mynum(num);
        mynum.a = a - mynum.a;
        mynum.b = b - mynum.b;
        return mynum;
    }

    template<typename T>
    number_t operator+(T num) {
        number_t mynum(num);
        mynum.a = a + mynum.a;
        mynum.b = b + mynum.b;
        return mynum;
    }

    template<typename T>
    number_t operator*(T num) {
        number_t mynum(num);
        mynum.a = a * mynum.a;
        mynum.b = b * mynum.b;
        return mynum;
    }

    template<typename T>
    number_t operator/(T num) {
        number_t mynum(num);
        mynum.a = a / mynum.a;
        mynum.b = b / mynum.b;
        return mynum;
    }

    template<typename T>
    number_t operator*=(T num) {
        number_t mynum(num);
        a = a * mynum.a;
        b = b * mynum.b;
        return *this;
    }

    template<typename T>
    number_t operator+=(T num) {
        number_t mynum(num);
        a = a + mynum.a;
        b = b + mynum.b;
        return *this;
    }

    template<typename T>
    number_t operator-=(T num) {
        number_t mynum(num);
        a = a - mynum.a;
        b = b - mynum.b;
        return *this;
    }

    template<typename T>
    number_t operator/=(T num) {
        number_t mynum(num);
        a = a / mynum.a;
        b = b / mynum.b;
        return *this;
    }

    template<typename T>
    number_t operator=(T num) {
        number_t mynum(num);
        a = mynum.a;
        b = mynum.b;
        return *this;
    }

    // Arithmetic volatile operators

    // Arithmetic Operators
    template<typename T>
    number_t operator-(T num) volatile{
        number_t mynum(num);
        mynum.a = a - mynum.a;
        mynum.b = b - mynum.b;
        return mynum;
    }

    template<typename T>
    number_t operator+(T num) volatile{
        number_t mynum(num);
        mynum.a = a + mynum.a;
        mynum.b = b + mynum.b;
        return mynum;
    }

    template<typename T>
    number_t operator*(T num) volatile{
        number_t mynum(num);
        mynum.a = a * mynum.a;
        mynum.b = b * mynum.b;
        return mynum;
    }

    template<typename T>
    number_t operator/(T num) volatile{
        number_t mynum(num);
        mynum.a = a / mynum.a;
        mynum.b = b / mynum.b;
        return mynum;
    }

    template<typename T>
    number_t operator*=(T num) volatile{
        number_t mynum(num);
        a = a * mynum.a;
        b = b * mynum.b;
        return *this;
    }

    template<typename T>
    number_t operator+=(T num) volatile{
        number_t mynum(num);
        a = a + mynum.a;
        b = b + mynum.b;
        return *this;
    }

    template<typename T>
    number_t operator-=(T num) volatile{
        number_t mynum(num);
        a = a - mynum.a;
        b = b - mynum.b;
        return *this;
    }

    template<typename T>
    number_t operator/=(T num) volatile{
        number_t mynum(num);
        a = a / mynum.a;
        b = b / mynum.b;
        return *this;
    }

    template<typename T>
    number_t operator=(T num) volatile{
        number_t mynum(num);
        a = mynum.a;
        b = mynum.b;
        return *this;
    }

    // Relational Operators
    template<typename T>
    bool operator>(T num) {
        number_t temp(num);
        if(a > temp.a || b > temp.b) return true;
        else return false;
    }

    template<typename T>
    bool operator<(T num) {
        number_t temp(num);
        if(a < temp.a || b < temp.b) return true;
        else return false;
    }

    template<typename T>
    bool operator!=(T num) {
        number_t temp(num);
        if(a != temp.a || b != temp.b) return true;
        else return false;
    }

    template<typename T>
    bool operator==(T num) {
        number_t temp(num);
        if(a == temp.a || b == temp.b) return true;
        else return false;
    }

    template<typename T>
    bool operator>=(T num) {
        number_t temp(num);
        if(a >= temp.a || b >= temp.b) return true;
        else return false;
    }

    template<typename T>
    bool operator<=(T num) {
        number_t temp(num);
        if(a <= temp.a || b <= temp.b) return true;
        else return false;
    }

    // Const relational operators
    // Relational Operators
    template<typename T>
    bool operator>(T num) const{
        number_t temp(num);
        if(a > temp.a || b > temp.b) return true;
        else return false;
    }

    template<typename T>
    bool operator<(T num) const{
        number_t temp(num);
        if(a < temp.a || b < temp.b) return true;
        else return false;
    }

    template<typename T>
    bool operator!=(T num) const{
        number_t temp(num);
        if(a != temp.a || b != temp.b) return true;
        else return false;
    }

    template<typename T>
    bool operator==(T num) const{
        number_t temp(num);
        if(a == temp.a || b == temp.b) return true;
        else return false;
    }

    template<typename T>
    bool operator>=(T num) const{
        number_t temp(num);
        if(a >= temp.a || b >= temp.b) return true;
        else return false;
    }

    template<typename T>
    bool operator<=(T num) const{
        number_t temp(num);
        if(a <= temp.a || b <= temp.b) return true;
        else return false;
    }

    // Typecasting
    template<typename T>
    operator T() const {
        return (T)a;
    }

    template<typename T>
    operator T() volatile {
        return (T)a;
    }

    template<typename T>
    operator T() {
        return (T)a;
    }

    //Minus unary operator
    number_t operator-() {
        number_t num(*this);
        num.a = -a;
        num.b = -b;
        return num;
    }

};

#include <math.h>
#include <iostream>

using namespace std;

template<typename T>
double operator*(T d, struct number_t num) {
    return d * num.a;
}

template<typename T>
double operator+(T d, struct number_t num) {
    return d + num.a;
}

template<typename T>
double operator-(T d, struct number_t num) {
    return d - num.a;
}

template<typename T>
double operator/(T d, struct number_t num) {
    return d/num.a;
}

template<typename T>
bool operator>(T d, struct number_t num) {
    return d > num.a || d>num.b;
}

template<typename T>
bool operator<(T d, struct number_t num) {
    return d < num.a || d<num.b;
}

#endif // NUMBER_T_H
