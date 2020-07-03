#ifndef CONFIG_H
#define CONFIG_H

// XaoS release
#define XaoS_VERSION "4.1"

// URLs
#define HELP_URL "https://github.com/xaos-project/XaoS/wiki"
#define WEB_URL "http://xaos.sourceforge.net/"
#define DOWNLOAD_URL "https://github.com/xaos-project/XaoS/releases"
#define FEEDBACK_URL "https://github.com/xaos-project/XaoS/issues"
#define FORUM_URL "https://groups.google.com/d/forum/xaos-users"

// File locations
#define DATAPATH "/usr/share/XaoS"
#define TUTORIALPATH DATAPATH "/tutorial/"
#define EXAMPLESPATH DATAPATH "/examples/"
#define CATALOGSPATH DATAPATH "/catalogs/"
#define HELPPATH DATAPATH "/help/xaos.hlp"

// Config file name
#ifdef _WIN32
#define CONFIGFILE "XaoS.cfg"
#else
#define CONFIGFILE ".XaoSrc"
#endif

// Optional features
#define USE_PTHREAD

// Numeric type
struct number_t {
    double a;
    long double b;

    // Constructors
    number_t(){
        a = 0; b=0;
    }
    template<typename T>
    number_t(T num){
        a = num; b=num;
    }

    // Start operator overloading

    // Arithmetic Operators
    template<typename T>
    number_t operator-(T num) const{
        number_t mynum(num);
        number_t temp(0);
        temp.a = a - mynum.a;
        temp.b = b - mynum.b;
        return temp;
    }

    template<typename T>
    number_t operator+(T num) const{
        number_t mynum(num);
        number_t temp(0);
        temp.a = a + mynum.a;
        temp.b = b + mynum.b;
        return temp;
    }

    template<typename T>
    number_t operator*(T num) const{
        number_t mynum(num);
        number_t temp(0);
        temp.a = a * mynum.a;
        temp.b = b * mynum.b;
        return temp;
    }

    template<typename T>
    number_t operator/(T num) const{
        number_t mynum(num);
        number_t temp(0);
        temp.a = a / mynum.a;
        temp.b = b / mynum.b;
        return temp;
    }

    template<typename T>
    number_t operator*=(T num) const{
        number_t mynum(num);
        number_t temp(0);
        temp.a = a * mynum.a;
        temp.b = b * mynum.b;
        return temp;
    }

    template<typename T>
    number_t operator+=(T num) const{
        number_t mynum(num);
        number_t temp(0);
        temp.a = a + mynum.a;
        temp.b = b + mynum.b;
        return temp;
    }

    template<typename T>
    number_t operator-=(T num) const{
        number_t mynum(num);
        number_t temp(0);
        temp.a = a - mynum.a;
        temp.b = b - mynum.b;
        return temp;
    }

    template<typename T>
    number_t operator/=(T num) const{
        number_t mynum(num);
        number_t temp(0);
        temp.a = a / mynum.a;
        temp.b = b / mynum.b;
        return temp;
    }

    template<typename T>
    number_t operator=(T num) const{
        number_t mynum(num);
        number_t temp(0);
        temp.a = mynum.a;
        temp.b = mynum.b;
        return temp;
    }

    // Relational Operators
    template<typename T>
    bool operator>(T num) const{
        if(num > a)return true;
        else return false;
    }

    template<typename T>
    bool operator<(T num) const{
        if(num < a)return true;
        else return false;
    }

    template<typename T>
    bool operator!=(T num) const{
        if(num == a)return true;
        else return false;
    }

    template<typename T>
    bool operator==(T num) const{
        if(num == a)return true;
        else return false;
    }

    template<typename T>
    bool operator>=(T num) const{
        if(num >= a)return true;
        else return false;
    }

    template<typename T>
    bool operator<=(T num) const{
        if(num <= a)return true;
        else return false;
    }

    number_t myabs(number_t num){
        if(num.a<0) { num.a = -num.a; return num; }
        else return num;
    }

    // Typecasting
    template<typename T>
    operator T() const {
        return (T)a;
    }

    //Minus unary operator
    number_t operator-() {
        number_t num;
        num.a = -a;
        num.b = -b;
        return num;
    }
};

#include<math.h>
double atan2(number_t num1, number_t num2){
    return atan2((double)num1.a, (double)num2.a);
}

int atan(number_t num){
    return atan((double)num.a);
}

double sin(number_t num1){
    return sin((double)num1.a);
}

double cos(number_t num1){
    return cos((double)num1.a);
}

double log(number_t num){
    return log(num.a);
}

number_t myabs(number_t num){
    if(num.a<0) { num.a = -num.a; return num; }
    else return num;
}

number_t fabs(number_t num){
    num.a = fabs(num.a);
    return num;
}

number_t sqrt(number_t num){
    return sqrt(num.a);
}

template<typename T>
T operator*(T d, number_t num) {
    return d * num.a;
}

template<typename T>
T operator+(T d, number_t num) {
    return d + num.a;
}

template<typename T>
T operator-(T d, number_t num) {
    return d - num.a;
}

template<typename T>
T operator/(T d, number_t num) {
    return d/num.a;
}

// Supported color depths
#define STRUECOLOR
#define STRUECOLOR16 // required for edge detection and pseudo 3d

// Fractal defaults
#define DEFAULT_MAX_ITER 1000
#define DEFAULT_BAILOUT 4
#define MAXSTEP (0.008 * 3)
#define STEP (0.0006 * 3)
#define ROTATIONSPEED 30
#define FRAMERATE 20
#define SPEEDUP 1.05

// Autopilot configuration
#define LOOKSIZE 2 // size explored by autopilot
#define RANGE1 30
#define NGUESSES (RANGE1 * RANGE1 / 2)
#define MAXTIME 10     // maximum zooming time to one direction
#define NGUESSES1 10   // maximum number of guesses using first method
#define NGUESSES2 1000 // maximum number of guesses using second method

// Default user formula
// #define USER_FORMULA "z^log(c)*p"
// #define USER_FORMULA "c^z+im(p)*{0;1}"
#define USER_FORMULA "(abs(re(z))+i*abs(im(z)))^2+c"

// Disable optional statistics collection and reporting
//#define STATISTICS
#undef STAT
#ifdef STATISTICS
#define STAT(x) x
#else
#define STAT(x)
#endif

#define NUMBER_BIG ((number_t)INT_MAX)
#endif // CONFIG_H
