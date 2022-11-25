int M1_gaz = 6;
int M1_so = 7;
int M2_gaz = 3;
int M2_so = 8;
int led = 13;

char command;

void setup() {
  pinMode(M1_gaz, OUTPUT);
  pinMode(M1_so, OUTPUT);
  pinMode(M2_gaz, OUTPUT);
  pinMode(M2_so, OUTPUT);
  pinMode(led, OUTPUT);
  
  Serial.begin(9600);
}

#define turn(_M1_gaz, _M2_gaz) \
  analogWrite(M1_gaz, (int)_M1_gaz); \
  analogWrite(M2_gaz, (int)_M2_gaz); \

#define _move(_M1_so, _M2_so) \
  digitalWrite(M1_so, (int)_M1_so); \
  digitalWrite(M2_so, (int)_M2_so); \

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) command = Serial.read();
  
  if (command == 'F') { _move(0, 0); turn(190, 200); } // Move forward
  else if (command == 'B') { _move(1, 1); turn(190, 200); } // Move back
  else if (command == 'R') { _move(1, 1); turn(190, 0); } // Turn right
  else if (command == 'L') { _move(1, 1); turn(0, 200); } // Turn left
  else if (command == 'S') { _move(1, 1); turn(0, 0); } // Stop
  else if (command == 'W') { digitalWrite(led, HIGH); } // Turn on head light
  else if (command == 'w') { digitalWrite(led, LOW); } // Turn off head light
}
