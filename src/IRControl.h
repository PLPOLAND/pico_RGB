#ifndef IRREMOTE_H
#define IRREMOTE_H

#pragma once

#include <Arduino.h>

#define USE_IRREMOTE_HPP_AS_PLAIN_INCLUDE
#include <IRremote.hpp>
#include "IRControlCode.h"
#include "Task.h"


class IRControl
{
public:
    IRControl(int pin);
    ~IRControl();
    Task* tick();
    
private:

};

#endif