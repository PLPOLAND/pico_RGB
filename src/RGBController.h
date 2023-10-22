#ifndef RGBCONTROLLER_H
#define RGBCONTROLLER_H

#pragma once
#include <Arduino.h>
#include "Color.h"
#include "Task.h"
#include "Stale.h"
#include "Timers.h"

/** @brief class for controlling RGB LED strip */
class RGBController
{
public:
    RGBController();
    ~RGBController();
    RGBController(byte redPin, byte greenPin, byte bluePin);
    RGBController(byte redPin, byte greenPin, byte bluePin, Color color);

    /**
     * @brief Sets the color of the RGB controller. 
     * 
     */
    void setColor(Color color);

    

    /** @brief Sets the target color for the RGB controller.
     * 
     * @param color The target color to set.
     * @param updateBrightness Whether or not to update the brightness of the color.
     */
    void setTargetColor(Color color, bool updateBrightness = false);
    Color getColor();
    void updatePins();
    void turnOnOff();

        /** @brief Set task to be executed */
    void setTask(Task* task);

    /** @brief Removes current task and set old task as task to be executed */
    void bringBackOldTask();


    /** @brief Set old task as current task and clear current task */
    void clearTask();

    void tick();


private:

    /** @brief Color that is currently set */
    Color currentColor;
    /** @brief Color that is target for current change */
    Color targetColor;

    byte redPin;
    byte greenPin;
    byte bluePin;
    
    bool shouldUpdateCurrentColor;

    /** @brief Task that is currently executed */
    Task* task;
    /** @brief Task that was executed before current task */
    Task* oldTask;
    
    bool isOn;
    /** @brief Time multiplier for task execution time */
    int timeMultiplier;

    Timer timer;
    Timer offTimer;

    void setRedPinValue(byte red);
    void setGreenPinValue(byte green);
    void setBluePinValue(byte blue);

    void updateColor();
};

#endif