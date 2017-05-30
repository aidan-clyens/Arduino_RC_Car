// Aidan Clyens
// Bluetooth Controlled RC Car

const int backMotor = 9;
const int frontMotor = 6;
const int frontBackToggle = 3;
const int rightLeftToggle = 5;
const int redLEDs = 11;
const int whiteLEDs = 12;
const int horn = 10;

int state;
int Speed;

void setup()
{
  pinMode(backMotor, OUTPUT);
  pinMode(frontMotor, OUTPUT);
  pinMode(frontBackToggle, OUTPUT);
  pinMode(rightLeftToggle, OUTPUT);
  pinMode(redLEDs, OUTPUT);
  pinMode(whiteLEDs, OUTPUT);
  pinMode(horn, OUTPUT);
  Serial.begin(9600);
  digitalWrite(whiteLEDs, HIGH);
  delay(50);
  digitalWrite(whiteLEDs, LOW);
  delay(50);
}

void loop()
{
  state = Serial.read();
  switch (state)
  {
    case 0:
      Speed = 0;
      break;
    case 'q':
      Speed = 255;
      break;
    case 'S':
      stopall();
      break;
    case 'F':
      forwards();
      break;
    case 'B':
      backwards();
      break;
    case 'L':
      left();
      break;
    case 'R':
      right();
      break;
    case 'G':
      frontleft();
      break;
    case 'I':
      frontright();
      break;
    case 'H':
      backleft();
      break;
    case 'J':
      backright();
      break;
    case 'W':
      digitalWrite(whiteLEDs, HIGH);
      break;
    case 'w':
      digitalWrite(whiteLEDs, LOW);
      break;
    case 'V':
      tone(horn, 150);
      break;
    case 'v':
      digitalWrite(horn, LOW);
      break;
  }
}

void stopall()
{
  digitalWrite(rightLeftToggle, LOW);
  digitalWrite(frontMotor, LOW);
  digitalWrite(frontBackToggle, LOW);
  analogWrite(backMotor, 0);
  digitalWrite(redLEDs, LOW);
}
void forwards()
{
  digitalWrite(rightLeftToggle, LOW);
  digitalWrite(frontMotor, LOW);
  digitalWrite(frontBackToggle, LOW);
  analogWrite(backMotor, Speed);
}
void backwards()
{
  digitalWrite(rightLeftToggle, LOW);
  digitalWrite(frontMotor, LOW);
  digitalWrite(frontBackToggle, HIGH);
  analogWrite(backMotor, Speed);
  digitalWrite(redLEDs, HIGH);
}
void right()
{
  digitalWrite(rightLeftToggle, LOW);
  digitalWrite(frontMotor, HIGH);
  digitalWrite(frontBackToggle, LOW);
  analogWrite(backMotor, 0);
}
void left()
{
  digitalWrite(rightLeftToggle, HIGH);
  digitalWrite(frontMotor, HIGH);
  digitalWrite(frontBackToggle, LOW);
  analogWrite(backMotor, 0);
}
void frontright()
{
  digitalWrite(rightLeftToggle, LOW);
  digitalWrite(frontMotor, HIGH);
  digitalWrite(frontBackToggle, LOW);
  analogWrite(backMotor, Speed);
}
void frontleft()
{
  digitalWrite(rightLeftToggle, HIGH);
  digitalWrite(frontMotor, HIGH);
  digitalWrite(frontBackToggle, LOW);
  analogWrite(backMotor, Speed);
}
void backright()
{
  digitalWrite(rightLeftToggle, LOW);
  digitalWrite(frontMotor, HIGH);
  digitalWrite(frontBackToggle, HIGH);
  analogWrite(backMotor, Speed);
  digitalWrite(redLEDs, HIGH);
}
void backleft()
{
  digitalWrite(rightLeftToggle, HIGH);
  digitalWrite(frontMotor, HIGH);
  digitalWrite(frontBackToggle, HIGH);
  analogWrite(backMotor, Speed);
  digitalWrite(redLEDs, HIGH);
}

