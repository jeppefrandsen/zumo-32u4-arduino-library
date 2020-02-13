/** This example uses the Zumo's line sensors to detect the white
border around a sumo ring.  When the border is detected, it
backs up and turns. */

#include <Zumo32U4.h>

Zumo32U4 zumo;

void setup()
{
  zumo.ledYellow.on();
  zumo.lcd.clear();
  zumo.lcd.print(F("Press A"));
  zumo.buttonA.wait();

  zumo.ledYellow.off();
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

void loop()
{
  if (zumo.buttonA.isPressed())
  {
    zumo.motors.stop();
    zumo.buttonA.waitForRelease();
    setup();
  }

  if (zumo.lineSensors.isLeftSensorWhite())
  {
    zumo.motors.reverse(50);
    delay(200);
    zumo.motors.turnRight(50);
    delay(300);
  }
  else if (zumo.lineSensors.isRightSensorWhite())
  {
    zumo.motors.reverse(50);
    delay(200);
    zumo.motors.turnLeft(50);
    delay(300);
  }

  zumo.motors.forward(100);
}
