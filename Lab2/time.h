

// Dessa under kan tas bort och det tror jag löser andra kommentaren
//#include <ostream>
//#include <iostream>

// Löst tror jag
// TODO: Complementary work needed: Include header guards, all includes 
// should be inside the guards. 

// Löst tror jag
// TODO: Complementary work needed: Only include things needed in the 
// header in the header file.
// Everything else should be included in cc files

// Löst tror jag
// Comment: You would normaly use const & for operator+

// Löst tror jag
// TODO: Complementary work needed: to_string should take a const & time

// Detta ska vara header guards tydligen. Tror det är rätt
#ifndef TIME_H
#define TIME_H
#include <sstream>
struct Time {
    int hour{};
    int minute{};
    int second{};
};

// Ändrade Time till Time const&. Tredje kommentaren
Time operator +(Time const& time, int sec);

Time operator -(Time time, int sec);

Time& operator ++(Time& time);

Time operator ++(Time& time, int);

Time& operator --(Time& time);

Time operator --(Time& time, int);

bool operator ==(Time const& time, Time const& time2);

bool operator !=(Time const& time, Time const& time2);

bool operator <(Time const& time, Time const& time2);

bool operator >(Time const& time, Time const& time2);

bool operator <=(Time const& time, Time const& time2);

bool operator >=(Time const& time, Time const& time2);

std::ostream& operator <<(std::ostream& out, Time const& time);

std::istream& operator >>(std::istream& in, Time& time);

std::string to_string(Time const& time, bool isContinental=true);

bool is_am(Time const& time);

bool is_valid(Time const& time);
#endif