/**
 * @file TimeClock.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "Arduino.h"
#include <inttypes.h>
#include "time.h"
#include <WString.h>
#include <stdio.h>

class TimeClock
{
private:
    int8_t h;
    int8_t m;
    int8_t s;
public:
    TimeClock() {
        time_t now = 0;
        time(&now);
        fromTimestamp(now);        
    }

    TimeClock(time_t time) {
        fromTimestamp(time);
    }

    TimeClock(int8_t hours, int8_t minutes, int8_t seconds){
        h = hours;
        m = minutes;
        s = seconds;
    }

    bool operator<(const TimeClock& tc){
        if(h < tc.h){
            return true;
        }
        if (h == tc.h && m < tc.m)
        {
            return true;
        }
        if (h == tc.h && m == tc.m && s < tc.s)
        {
            return true;
        }
        return false;
    }

    bool operator>(const TimeClock& tc){
        if(h > tc.h){
            return true;
        }
        if (h == tc.h && m > tc.m)
        {
            return true;
        }
        if (h == tc.h && m == tc.m && s > tc.s)
        {
            return true;
        }
        return false;
    }

    bool operator==(const TimeClock& tc){
        return h == tc.h && m == tc.m && s == tc.s;
    }
    
    TimeClock operator+(const TimeClock& tc){
        int hours = h + tc.h;
        int mins = m + tc.m;
        int secs = s + tc.s;

        if(secs > 60){
            mins++;
            secs = 60 - secs;
        }

        if(mins > 59){
            hours++;
            mins =  60 - mins;
        }

        return TimeClock(hours, mins, secs);
    }

    void operator=(const TimeClock& tc){
        h = tc.h;
        m = tc.m;
        s = tc.s;
    }

    void reset(){
        h = 0;
        m = 0;
        s = 0;
    }

    void fromY2K(time_t time){
        struct tm timeinfo = { 0 };
        localtime_r(&time, &timeinfo);
        h = timeinfo.tm_hour;
        m = timeinfo.tm_min;
        s = timeinfo.tm_sec;
    }

    void fromTimestamp(time_t timestamp){
        h = timestamp / 3600;
        m = (timestamp - (h * 3600)) / 60;
        s = ((timestamp - (h * 3600)) - m * 60);
    }

    time_t toTimestamp(){
        return s + m * 60 + h * 3600;
    }

    String toString(){
        char timeStr[10];
        sprintf(timeStr, "%02d:%02d:%02d", h, m, s);
        return timeStr;
    }
};