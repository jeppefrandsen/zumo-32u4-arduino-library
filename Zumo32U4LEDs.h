// Copyright Pololu Corporation.  For more information, see http://www.pololu.com/

/*! \file Zumo32U4LEDs.h */

#pragma once

#include <FastGPIO.h>

/*! \brief Turns the red user LED (RX) on or off.

The red user LED is on pin 17, which is also known as PB0, SS, and RXLED.  The
Arduino core code uses this LED to indicate when it receives data over USB, so
it might be hard to control this LED when USB is connected. */
class Zumo32U4LEDRed
{
public:
    Zumo32U4LEDRed() = default;

    void on() { FastGPIO::Pin<17>::setOutput(false); }
    void off() { FastGPIO::Pin<17>::setOutput(true); }
};

/*! \brief Turns the yellow user LED on pin 13 on or off. */
class Zumo32U4LEDYellow
{
public:
    Zumo32U4LEDYellow() = default;

    void on() { FastGPIO::Pin<13>::setOutput(true); }
    void off() { FastGPIO::Pin<13>::setOutput(false); }
};

/*! \brief Turns the green user LED (TX) on or off.

The green user LED is pin PD5, which is also known as TXLED.  The Arduino core
code uses this LED to indicate when it receives data over USB, so it might be
hard to control this LED when USB is connected. */
class Zumo32U4LEDGreen
{
public:
    Zumo32U4LEDGreen() = default;

    void on() { FastGPIO::Pin<IO_D5>::setOutput(false); }
    void off() { FastGPIO::Pin<IO_D5>::setOutput(true); }
};
