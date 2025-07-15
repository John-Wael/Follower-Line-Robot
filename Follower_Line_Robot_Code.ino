#define enA 10 // Enable1 L298 Pin enA
#define in1 9   // Motor1 L298 Pin in1
#define in2 8   // Motor1 L298 Pin in1
#define in3 7   // Motor2 L298 Pin in1
#define in4 6   // Motor2 L298 Pin in1
#define enB 5   // Enable2 L298 Pin enB

#define R_S A0 // ir sensor Right
#define L_S A1 // ir sensor Left

void setup()
{
  pinMode(R_S, INPUT); // declare right sensor as input
  pinMode(L_S, INPUT); // declare left sensor as input

  pinMode(enA, OUTPUT); // declare as output for L298 Pin enA
  pinMode(in1, OUTPUT); // declare as output for L298 Pin in1
  pinMode(in2, OUTPUT); // declare as output for L298 Pin in2
  pinMode(in3, OUTPUT); // declare as output for L298 Pin in3
  pinMode(in4, OUTPUT); // declare as output for L298 Pin in4
  pinMode(enB, OUTPUT); // declare as output for L298 Pin enB

  analogWrite(enA, 255); // Increase the speed for Motor1 to maximum
  analogWrite(enB, 255); // Increase the speed for Motor2 to maximum
  delay(1000);
}

void loop()
{
  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 0))
  {
    forward(); // Both sensors are at White color, move forward
  }

  if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 0))
  {
    turnRight(); // Right sensor is Black, move right
  }

  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 1))
  {
    turnLeft(); // Left sensor is Black, move left
  }

  if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1))
  {
    Stop(); // Both sensors are at Black color, stop
  }
}

void forward()
{
  digitalWrite(in1, HIGH); // Right Motor forward Pin
  digitalWrite(in2, LOW);  // Right Motor backward Pin
  digitalWrite(in3, LOW);  // Left Motor backward Pin
  digitalWrite(in4, HIGH); // Left Motor forward Pin
}

void turnRight()
{
  digitalWrite(in1, LOW);  // Right Motor forward Pin
  digitalWrite(in2, HIGH); // Right Motor backward Pin
  digitalWrite(in3, LOW);  // Left Motor backward Pin
  digitalWrite(in4, HIGH); // Left Motor forward Pin
}

void Stop()
{
  digitalWrite(in1, LOW); // Right Motor forward Pin
  digitalWrite(in2, LOW); // Right Motor backward Pin
  digitalWrite(in3, LOW); // Left Motor backward Pin
  digitalWrite(in4, LOW); // Left Motor forward Pin
}

void turnLeft()
{
  digitalWrite(in1, HIGH); // Right Motor forward Pin
  digitalWrite(in2, LOW);  // Right Motor backward Pin
  digitalWrite(in3, HIGH); // Left Motor backward Pin
  digitalWrite(in4, LOW);  // Left Motor forward Pin
}

