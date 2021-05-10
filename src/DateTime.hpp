/**
 * @file DateTime.hpp
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
#include "compile_time.h"
#include "WString.h"

class DateTime
{
private:
    struct tm timeinfo;
public:

    DateTime() {
        time_t now = 0;
        timeinfo = { 0 };
        time(&now);
        localtime_r(&now, &timeinfo);
    }

    DateTime(time_t time) {
        timeinfo = { 0 };
        localtime_r(&time, &timeinfo);
    }

    String toString(){
        return asctime(&timeinfo);
    }
};