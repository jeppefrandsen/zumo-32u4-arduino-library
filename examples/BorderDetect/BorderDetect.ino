/** This example uses the Zumo's line sensors to detect the white
border around a sumo ring.  When the border is detected, it
backs up and turns. */

#include <Zumo32U4.h>

#define LINE_SENSOR_THRESHOLD 1000

Zumo32U4 zumo;

void waitForButtonAndCountDown()
{
  ledYellow(true);
  zumo.lcd.clear();
  zumo.lcd.print(F("Press A"));

  zumo.buttonA.waitForButton();

  ledYellow(false);
  zumo.lcd.clear();

  for (int i = 0; i < 3; i++)
  {
    delay(1000);
    zumo.buzzer.playNote(NOTE_G(3), 200, 15);
  }
  delay(1000);
  zumo.buzzer.playNote(NOTE_G(4), 500, 15);
  delay(1000);
}

void setup()
{
  waitForButtonAndCountDown();
}

void loop()
{
  static unsigned int lineSensorValues[3];

  if (zumo.buttonA.isPressed())
  {
    zumo.motors.stop();
    zumo.buttonA.waitForRelease();
    waitForButtonAndCountDown();
  }

  zumo.lineSensors.read(lineSensorValues);

  if (lineSensorValues[0] < LINE_SENSOR_THRESHOLD)
  {
    zumo.motors.reverse(50);
    delay(200);
    zumo.motors.turnRight(50);
    delay(300);
    zumo.motors.forward(50);
  }
  else if (lineSensorValues[2] < LINE_SENSOR_THRESHOLD)
  {
    zumo.motors.reverse(50);
    delay(200);
    zumo.motors.turnLeft(50);
    delay(300);
    zumo.motors.forward(50);
  }
  else
  {
    zumo.motors.forward(50);
  }
}
