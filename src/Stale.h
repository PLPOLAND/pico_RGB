#ifndef STALE_H
#define STALE_H

#pragma once

    #ifdef DEBUG
        #define OUT(x) Serial.print(x); Serial.flush();
        #define OUT_LN(x) Serial.println(x); Serial.flush();
    #else
        #define OUT(x)
        #define OUT_LN(x)
    #endif // DEBUG



#define SECS(t) (unsigned long)(t * 1000L)
#define MINS(t) SECS(t) * 60
#define HOURS(t) MINS(t) * 60

#define CZAS_ODSWIERZANIA_TEMPERATURY 0.1 //w minutach

#define TIME_MULTIPLIER_BASE 50
#define TIME_MULTIPLIER_FAST 1
#define TIMER_BASE 10
#define TIMER_TIME_OFF_BASE SECS(10)



#endif // !STALE_H