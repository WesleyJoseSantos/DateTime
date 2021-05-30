/**
 * @file Interval.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include "time.h"
#include "map.h"

class Interval
{
private:
    time_t start;
    time_t end;
public:
    Interval(){

    }

    Interval(String timeStart, String timeEnd){
        this->start = TimeClock::fromShortString(timeStart).toTimestamp();
        this->end = TimeClock::fromShortString(timeEnd).toTimestamp();
    }

    Interval(TimeClock timeStart, TimeClock timeEnd){
        setInterval(timeStart.toTimestamp(), timeEnd.toTimestamp());
    }

    Interval(time_t start, time_t end) {
        setInterval(start, end);
    }

    Interval(time_t start, int duration){
        setInterval(start, start + duration*60);
    }

    void setInterval(time_t start, time_t end){
        this->start = start;
        this->end = end;
    }

    void setStart(time_t start){
        this->start = start;
    }

    void setEnd(time_t end){
        this->end = end;
    }

    time_t getStart(){
        return start;
    }

    time_t getEnd(){
        return end;
    }

    time_t getDt(){
        return end - start;
    }

    time_t scale(long x, long min, long max){
        return map(x, min, max, start, end);
    }
};