#include <Dabble.h>

Motor Motor1(MOTOR1_D1, MOTOR1_D2, MOTOR1_EN);

Motor Motor2(MOTOR2_D1, MOTOR2_D2, MOTOR2_EN);

Servo Servo3;
void setup()
{
  pinMode(10, OUTPUT);
  Dabble.begin(115200);
  Servo3.attach(3);
  pinMode(0, INPUT);
  digitalWrite(10, true);
}
void loop()
{
  Dabble.processInput();
  if (GamePad.isPressed(0)) {
    Motor1.moveMotor(2.55 * 100);
    Motor2.moveMotor(2.55 * 100);
    Dabble.print("Straight");
  }
  else {
    if (GamePad.isPressed(1)) {
      Motor1.moveMotor(-2.55 * 100);
      Motor2.moveMotor(-2.55 * 100);
      Dabble.print("Backward");
    }
    else {
      if (GamePad.isPressed(2)) {
        Motor1.moveMotor(-2.55 * 100);
        Motor2.moveMotor(2.55 * 100);
        Dabble.print("Left    ");
      }
      else {
        if (GamePad.isPressed(3)) {
          Motor1.moveMotor(2.55 * 100);
          Motor2.moveMotor(-2.55 * 100);
          Dabble.print("Right   ");
        }
        else {
          if (GamePad.isPressed(6)) {
            Servo3.write(0);
            delay(2 * 1000);
            if ((analogRead(0) > 800)) {
              digitalWrite(10, false);
              delay(1.5 * 1000);
              digitalWrite(10, true);
            }
          }
          else {
            if (GamePad.isPressed(8)) {
              Servo3.write(90);
            }
            else {
              Motor1.lockMotor();
              Motor2.lockMotor();
              Dabble.print("Brake   ");
            }
          }
        }
      }
    }
  }
}
