#include "RGBController.h"

RGBController::RGBController()
{
    currentColor.set(0, 0, 0);
    redPin = 0;
    greenPin = 1;
    bluePin = 2;
}

RGBController::~RGBController()
{
    delete task;
}

RGBController::RGBController(byte redPin, byte greenPin, byte bluePin)
{
    this->redPin = redPin;
    this->greenPin = greenPin;
    this->bluePin = bluePin;
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    this->currentColor.set(0, 0, 0);
    this->updatePins();
    this->task = nullptr;
    this->oldTask = nullptr;
    this->timeMultiplier = TIME_MULTIPLIER_BASE;
    timer.time(1);//TODO check if value is correct
    offTimer.time(TIMER_TIME_OFF_BASE);
    shouldUpdateCurrentColor = false;
}

RGBController::RGBController(byte redPin, byte greenPin, byte bluePin, Color color)
{
    this->redPin = redPin;
    this->greenPin = greenPin;
    this->bluePin = bluePin;
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    this->currentColor.set(color);
    this->updatePins();
    this->task = nullptr;
    this->oldTask = nullptr;
    this->timeMultiplier = TIME_MULTIPLIER_BASE;
    timer.time(1);//TODO check if value is correct
    offTimer.time(TIMER_TIME_OFF_BASE);
    shouldUpdateCurrentColor = false;
}


void RGBController::setColor(Color color)
{
    this->currentColor.set(color);
    this->updatePins();
}

void RGBController::setTargetColor(Color color, bool updateBrightness)
{
    if (!updateBrightness)
    {
        color.setBrightness(this->currentColor.getBrightness());//keep brightness of current color
    }
    this->targetColor.set(color);//set target color
    this->shouldUpdateCurrentColor = true;
}

Color RGBController::getColor()
{
    return this->currentColor;
}

void RGBController::updatePins()
{
    setRedPinValue(this->currentColor.getRed());
    setGreenPinValue(this->currentColor.getGreen());
    setBluePinValue(this->currentColor.getBlue());
}

void RGBController::setTask(Task* task)
{
    clearTask();
    this->task = task;
}

void RGBController::bringBackOldTask()
{
    if (oldTask != nullptr)
    {
        delete task;
        task = oldTask;
        oldTask = nullptr;
    }
}

void RGBController::clearTask()
{
    if (oldTask != nullptr)
    {
        delete oldTask;
    }

    if (task != nullptr)
    {
        oldTask = task;
    }
    task = nullptr;
}

void RGBController::tick()
{
    if (task == nullptr)
    {
        Serial.println(F("Task is null"));
    }

    if (offTimer.available())
    {
        this->turnOnOff();
    }
    if (shouldUpdateCurrentColor && !(this->targetColor == this->currentColor) )
    {
        this->updateColor();
    }
    
    
    if (task != nullptr)
    {
        // Serial.println(F("Task is not null"));
        // Serial.println(task->toString().c_str());
        if (task->isChangeColor())
        {
            if (!targetColor.RGBEqual(task->getColor())){
                this->setTargetColor(task->getColor());
                this->shouldUpdateCurrentColor = true;
                }

        }
        else if (task->isOnOff())
        {
            this->turnOnOff();
            this->clearTask();
        }
        else if (task->isBrighter())
        {
            this->currentColor.setBrightness(this->currentColor.getBrightness() + 10);
            this->targetColor.setBrightness(this->targetColor.getBrightness() + 10);
            this->updatePins();
            this->bringBackOldTask();
        }
        else if (task->isDarker())
        {
            this->currentColor.setBrightness(this->currentColor.getBrightness() - 10);
            this->targetColor.setBrightness(this->targetColor.getBrightness() - 10);
            this->updatePins();
            this->bringBackOldTask();
        }
        else if (task->isRedUp())
        {
            this->currentColor.setRed(this->currentColor.getRed() + 1);
            this->updatePins();
            this->clearTask();
        }
        else if (task->isRedDown())
        {
            this->currentColor.setRed(this->currentColor.getRed() - 1);
            this->updatePins();
            this->clearTask();
        }
        else if (task->isGreenUp())
        {
            this->currentColor.setGreen(this->currentColor.getGreen() + 1);
            this->updatePins();
            this->clearTask();
        }
        else if (task->isGreenDown())
        {
            this->currentColor.setGreen(this->currentColor.getGreen() - 1);
            this->updatePins();
            this->clearTask();
        }
        else if (task->isBlueUp())
        {
            this->currentColor.setBlue(this->currentColor.getBlue() + 1);
            this->updatePins();
            this->clearTask();
        }
        else if (task->isBlueDown())
        {
            this->currentColor.setBlue(this->currentColor.getBlue() - 1);
            this->updatePins();
            this->clearTask();
        }
        else if (task->isQuick())
        {
            this->timeMultiplier = TIME_MULTIPLIER_FAST;
            this->bringBackOldTask();
        }
        else if (task->isSlow())
        {
            this->timeMultiplier = TIME_MULTIPLIER_BASE;
            this->bringBackOldTask();
        }
        else if (task->isPause()){
            //TODO
        }
        else if(task->isRainbow()){
            if (currentColor.getRed() != 0 && currentColor.getGreen() != 0 && currentColor.getBlue() != 0)
            {
                //set min from R G B to 0;
                if (currentColor.getRed() <= currentColor.getBlue() && currentColor.getRed() <= currentColor.getGreen())
                {
                    currentColor.setRed(0);
                }
                else if (currentColor.getGreen() <= currentColor.getBlue() && currentColor.getGreen() <= currentColor.getRed())
                {
                    currentColor.setGreen(0);
                }
                else if (currentColor.getBlue() <= currentColor.getRed() && currentColor.getBlue() <= currentColor.getGreen())
                {
                    currentColor.setBlue(0);
                }
                else //if something went wrong then set red to 0
                {
                    currentColor.setRed(0);
                }
                // set max from R G B to 255;
                if (currentColor.getRed() >= currentColor.getBlue() && currentColor.getRed() >= currentColor.getGreen())
                {
                    currentColor.setRed(255);
                }
                else if (currentColor.getGreen() >= currentColor.getBlue() && currentColor.getGreen() >= currentColor.getRed())
                {
                    currentColor.setGreen(255);
                }
                else if (currentColor.getBlue() >= currentColor.getRed() && currentColor.getBlue() >= currentColor.getGreen())
                {
                    currentColor.setBlue(255);
                }
                else //if something went wrong then set red to 255
                {
                    currentColor.setRed(255);
                }
                updatePins();
            }
            else
            {
                if (currentColor.getRed() == 0 && currentColor.getBlue() < 255)
                {
                    currentColor.setBlue(currentColor.getBlue() + 1);
                    currentColor.setGreen(currentColor.getGreen() - 1);
                }
                if(currentColor.getBlue() == 0 && currentColor.getGreen() < 255){
                    currentColor.setRed(currentColor.getRed() - 1);
                    currentColor.setGreen(currentColor.getGreen() + 1);
                }
                if(currentColor.getGreen() == 0 && currentColor.getRed() < 255){
                    currentColor.setBlue(currentColor.getBlue() - 1);
                    currentColor.setRed(currentColor.getRed() + 1);
                }
                updatePins();
            }
            
        }
        else if(task->isBlink()){
            Color tmpColor = this->currentColor;
            // if (currentColor.distance(Color::Red()) < 10)
            // {
                Color newColor = Color::Black();
                setColor(newColor);
                delay(200);
                newColor = Color::Red();
                setColor(newColor);
                delay(200);
                newColor = Color::Black();
                setColor(newColor);
                delay(200);
                setColor(tmpColor);//TODO maybe should be target color
            // }
            // else{

            // }
            
            
        }
        else if (task->isFade3()) {
            //TODO timer
            static byte num = 0;
            if (num == 0)
            {
                this->shouldUpdateCurrentColor = true;
                this->setTargetColor(Color::fromHex("FF0600"));
                num++;
            }
            else if (num == 1)
            {
                this->shouldUpdateCurrentColor = true;
                this->setTargetColor(Color::fromHex("02FF02"));
                num++;
            }
            else
            {
                this->shouldUpdateCurrentColor = true;
                this->setTargetColor(Color::fromHex("1010FF"));
                num = 0;
            }
        }
        else if(task->isFade7()){
            //TODO timer
            static byte num = 0;
            if (num == 0)
            {

                this->shouldUpdateCurrentColor = true;
                this->setTargetColor(Color::fromHex("FF0600"));
                num++;
            }
            else if (num == 1)
            {

                this->shouldUpdateCurrentColor = true;
                this->setTargetColor(Color::fromHex("FF1601"));
                num++;
            }
            else if (num == 2)
            {

                this->shouldUpdateCurrentColor = true;
                this->setTargetColor(Color::fromHex("FFA601"));
                num++;
            }
            else if (num == 3)
            {

                this->shouldUpdateCurrentColor = true;
                this->setTargetColor(Color::fromHex("02FF02"));
                num++;
            }
            else if (num == 4)
            {

                this->shouldUpdateCurrentColor = true;
                this->setTargetColor(Color::fromHex("02FF10"));
                num++;
            }
            else if (num == 5)
            {

                this->shouldUpdateCurrentColor = true;
                this->setTargetColor(Color::fromHex("02FFA2"));
                num++;
            }
            else if (num == 6)
            {

                this->shouldUpdateCurrentColor = true;
                this->setTargetColor(Color::fromHex("1010FF"));
                num = 0;
            }
        }
        else if (task->isJump3()) {
            //TODO timer
            static byte num = 0;
            if (num == 0)
            {
                this->shouldUpdateCurrentColor = false;
                this->setColor(Color::fromHex("FF0600"));
                num++;
            }
            else if (num == 1)
            {
                this->shouldUpdateCurrentColor = false;
                this->setColor(Color::fromHex("02FF02"));
                num++;
            }
            else
            {
                this->shouldUpdateCurrentColor = false;
                this->setColor(Color::fromHex("1010FF"));
                num = 0;
            }
        }
        else if (task->isJump7()) {
            //TODO timer
            static byte num = 0;
            if (num == 0)
            {
                
                this->shouldUpdateCurrentColor = false;
                this->setColor(Color::fromHex("FF0600"));
                num++;
            }
            else if (num == 1)
            {
                
                this->shouldUpdateCurrentColor = false;
                this->setColor(Color::fromHex("FF1601"));
                num++;
            }
            else if (num == 2)
            {
                
                this->shouldUpdateCurrentColor = false;
                this->setColor(Color::fromHex("FFA601"));
                num++;
            }
            else if (num == 3)
            {
                
                this->shouldUpdateCurrentColor = false;
                this->setColor(Color::fromHex("02FF02"));
                num++;
            }
            else if (num == 4)
            {
                
                this->shouldUpdateCurrentColor = false;
                this->setColor(Color::fromHex("02FF10"));
                num++;
            }
            else if (num == 5)
            {
                
                this->shouldUpdateCurrentColor = false;
                this->setColor(Color::fromHex("02FFA2"));
                num++;
            }
            else if (num == 6)
            {
                
                this->shouldUpdateCurrentColor = false;
                this->setColor(Color::fromHex("1010FF"));
                num = 0;
            }
            
        }
        else if (task->isDIY1()) {
            //TODO timer?
            Color newColor = Color::fromHSV(rand() % 360, 255, currentColor.getBrightness());
            this->setTargetColor(newColor);
        }
        else if(task->isDIY2()){

            //TODO timer?
            static bool adding = true;
            this->shouldUpdateCurrentColor = true;
            if (adding)
            {
                this->targetColor.setBrightness(this->targetColor.getBrightness() + 1);
            }
            else
            {
                this->targetColor.setBrightness(this->targetColor.getBrightness() - 1);
            }
            if (this->targetColor.getBrightness() == 100)
            {
                adding = false;
            }
            else if (this->targetColor.getBrightness() == 0)
            {
                adding = true;
            }
            
        }
        else if(task->isDIY3()){
            offTimer.restart();
            this->bringBackOldTask();
            this->setTask(Task::Blink());
        }
        else if(task->isDIY4()){
            //TODO
        }
        else if(task->isDIY5()){
            //TODO
        }
        else if(task->isDIY6()){
            //TODO
        }
        

    }
}

void RGBController::turnOnOff()
{
    if (this->isOn)
    {
        delete task;
        task = nullptr;
        this->setBluePinValue(0);
        this->setGreenPinValue(0);
        this->setRedPinValue(0);
        this->isOn = false;
    }
    else{
        this->setColor(this->currentColor);
        this->isOn = true;
    }
    
}

void RGBController::setRedPinValue(byte red)
{
    analogWrite(this->redPin, red);
}

void RGBController::setGreenPinValue(byte green)
{
    analogWrite(this->greenPin, green);
}

void RGBController::setBluePinValue(byte blue)
{
    analogWrite(this->bluePin, blue);
}

void RGBController::updateColor(){
    if(timer.available()){
        timer.restart();
        if (this->currentColor.getRed() < this->targetColor.getRed())
        {
            this->currentColor.setRed(this->currentColor.getRed() + 1);
        }
        else if (this->currentColor.getRed() > this->targetColor.getRed())
        {
            this->currentColor.setRed(this->currentColor.getRed() - 1);
        }
        if (this->currentColor.getGreen() < this->targetColor.getGreen())
        {
            this->currentColor.setGreen(this->currentColor.getGreen() + 1);
        }
        else if (this->currentColor.getGreen() > this->targetColor.getGreen())
        {
            this->currentColor.setGreen(this->currentColor.getGreen() - 1);
        }
        if (this->currentColor.getBlue() < this->targetColor.getBlue())
        {
            this->currentColor.setBlue(this->currentColor.getBlue() + 1);
        }
        else if (this->currentColor.getBlue() > this->targetColor.getBlue())
        {
            this->currentColor.setBlue(this->currentColor.getBlue() - 1);
        }
        if ( this->currentColor.getRed() == this->targetColor.getRed() &&
            this->currentColor.getGreen() == this->targetColor.getGreen() &&
            this->currentColor.getBlue() == this->targetColor.getBlue())
        {
            this->shouldUpdateCurrentColor = false;
        }
    }
    else{
        return;
    }
}