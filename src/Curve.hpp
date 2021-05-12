/**
 * @file Curve.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-05-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <inttypes.h>
#include <time.h>
#include "map.h"
#include "Interval.hpp"

#define DEFAULT_SIZE 10

class Curve
{
private:
    int size;
    int *points;
    Interval interval;
public:
    Curve() {}

    Curve(int *points, Interval interval){
        this->size = DEFAULT_SIZE;
        this->points = points;
        this->interval = interval;
    }

    Curve(int *points, time_t tStart, int duration){
        this->size = DEFAULT_SIZE;
        this->points = points;
        this->interval = Interval(tStart, duration);
    }

    Curve(int size, int *points, Interval interval){
        this->size = size;
        this->points = points;
        this->interval = interval;
    }

    Curve(int size, int *points, time_t tStart, int duration){
        this->size = size;
        this->points = points;
        this->interval = Interval(tStart, duration);
    }

    int getInterpolation(time_t t){
        if(size == 0) return 0;

        time_t minInterval = interval.getDt() / size;
        if(minInterval == 0) return 0;

        if(t < interval.getStart()) return points[0];
        if(t > interval.getEnd()) return points[size - 1];

        long p1 = (t - interval.getStart()) / minInterval;
        long p2 = p1 + 1;

        time_t t1 = interval.scale(p1, 0, size);
        time_t t2 = interval.scale(p2, 0, size);

        return map(t, t1, t2, points[p1], points[p2]);
    }
};