#ifndef IRDIODE_H
#define IRDIODE_H

// #pragma once
#define USE_IRREMOTE_HPP_AS_PLAIN_INCLUDE
#include <Arduino.h>
#include <IRremote.hpp>

class IRDiode{
public:
    IRDiode(byte pin);
    ~IRDiode();

    void operator()();

private:

};

#endif