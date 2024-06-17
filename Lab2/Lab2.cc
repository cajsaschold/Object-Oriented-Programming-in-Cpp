#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <ostream>
#include "time.h"

using namespace std;

// Ska vara lösta:
//-----------------------------------------------------------------------------------------------//
// TODO: Complementary work needed: Keep lines below 100 characters

// Comment: You do not need to use std::ostream since you are using "using namespace std;"
// You can use only ostream instead

// Comment: Usually if to_string() take additional arguments they have default values,    
// so that you can call them like 'to_string(something)'. 

// Bra att dubbelkolla denna
// TODO: Complementary work needed: Use your operator== instead of comparing time strings

// Kolla min kommentar ovanför operatorn. Tror du det räcker som dokumentation?
// TODO: Complementary work needed: If your operator>> doesn't work how they usually     
// do, it needs to be documented. Usually it only read the streams until an error occurs.  
//-----------------------------------------------------------------------------------------------//



// Inte lösta
//-----------------------------------------------------------------------------------------------//
// Comment: You can use a stringstream to simplify to_string

// Comment: You could use the method in operator+ in operator-
// This would give better performance
//-----------------------------------------------------------------------------------------------//










// Bytte från Time time till Time const& time och skapade ett nytt 
// Time-objekt "timeNew" som sedan används
Time operator +(Time const& time, int sec){
    Time timeNew{time};

    timeNew.second+=sec;

    int curr_minute=floor(timeNew.second/60);
    timeNew.minute+=curr_minute;

    timeNew.second=timeNew.second%60;

    int curr_hour=floor(timeNew.minute/60);
    timeNew.hour+=curr_hour;

    timeNew.minute=timeNew.minute%60;

    timeNew.hour=timeNew.hour%24;
    return timeNew;
}

Time operator -(Time time, int sec){
    time.second-=sec;
    
    // while time.second is negative the loop removes 1 minute and add 60 to time.second, ends when 
    //time.second is positive or 0
    while (time.second < 0) {
        time.minute-=1;
        time.second+=60;
    }
    
    // if the previous loop resulted in a negative time.minute the loop will remove 
    // 1 hour and add 60 minutes for each interration(?) until time.minute is positive or 0
    while (time.minute < 0) {
        time.hour-=1;
        time.minute+=60;
    }

    //if the hour got a negative value from the previous loop this loop will add 24 until time.hours
    //is bigger or equal to 0
    while (time.hour < 0) {
        time.hour=24+time.hour;
    }


    return time;
}


// prefix increment = return the new value
Time& operator ++(Time& time){
    time=time+1;
    return time;
}


//postfix increment
Time operator ++(Time& time, int){
    Time timeOld {time.hour, time.minute, time.second};
    ++time;
    return timeOld;

}


//prefix increment
Time& operator --(Time& time){
    time=time-1;
    return time;
}

//postfix increment
Time operator --(Time& time, int){
    Time timeOld {time.hour, time.minute, time.second};
    --time;
    return timeOld;
}


bool operator ==(Time const& time, Time const& time2){

    return((to_string(time)==to_string(time2)));
}

bool operator !=(Time const& time, Time const& time2){

    return(!(time==time2));
}

bool operator <(Time const& time, Time const& time2){
    bool check=false;

    if (time.hour < time2.hour) {
        check=true;
    } else if (time.minute < time2.minute){
        check=true;
    } else if (time.second < time2.second) {
        check=true;
    }

    return check;
}

bool operator >(Time const& time, Time const& time2){
    if (time==time2) {
        return false;
    }

    return(!(time<time2));
}

bool operator <=(Time const& time, Time const& time2){
    return(!(time>time2));
}

bool operator >=(Time const& time, Time const& time2){
    if (time==time2) {
        return true;
    }

    return(time>time2);
}


ostream& operator <<(ostream& out, Time const& time){
    out << to_string(time);
    return out;
}

// The >> operator works differently than it normally does. In this case, the input
// needs to be on the format "HH:MM:SS", where HH=hours, MM=minutes and SS=seconds.
// If the input is not in this format the error state flag failbit is sent
istream& operator >>(istream& in, Time& time){
    
    Time timeCheck{};
    char colon;
    in >> timeCheck.hour >> colon >> timeCheck.minute >> colon >> timeCheck.second;
    if(is_valid(timeCheck)) {
        time=timeCheck;
    } else {
        in.setstate(ios_base::failbit);
    }

    return in;
}



bool is_valid(Time const& time){
    return((time.hour<24 && time.hour>=0) && (time.minute < 60 && time.minute >= 0) && 
    (time.second < 60 && time.second >=0));
}

// Bytte från Time time till Time const& time och skapade ett nytt 
// Time-objekt "timeNew" som sedan används
string to_string(Time const& time, bool isContinental){
    string std{};
    string am_pm{};
    Time timeNew{time};

    if (!isContinental) {
        if (is_am(timeNew)) {
            am_pm=" am";
            if (timeNew.hour > 12) {
                timeNew.hour-=12;
            }
        } else {
            am_pm=" pm";
        }
    }

    
    if (timeNew.hour < 10) {
        std = std + "0" + to_string(timeNew.hour) + ":";
    } else {
        std = std + to_string(timeNew.hour) + ":";
    }

    if (timeNew.minute < 10) {
        std = std + "0" + to_string(timeNew.minute) + ":";
    } else {
        std = std + to_string(timeNew.minute) + ":";
    }

    if (timeNew.second < 10) {
        std = std + "0" + to_string(timeNew.second);
    } else {
        std = std + to_string(timeNew.second);
    }

    std=std + am_pm;

    return std;
    }


bool is_am(Time const& time){
    return(time.hour<12);
}

