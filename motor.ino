int M1_gaz = 6;
int M1_so = 7;
int M2_gaz = 3;
int M2_so = 8;

void setup() {
  pinMode(M1_gaz, OUTPUT);
  pinMode(M1_so, OUTPUT);
  pinMode(M2_gaz, OUTPUT);
  pinMode(M2_so, OUTPUT);

  digitalWrite(M1_so, 1);
  digitalWrite(M2_so, 1);
  analogWrite(M1_gaz, 190);
  analogWrite(M2_gaz, 200);

  delay(200);
  //Turn left
  analogWrite(M1_gaz, 0);

  delay(500);
  analogWrite(M1_gaz, 190);

  delay(5000);
  analogWrite(M1_gaz, 0);
  analogWrite(M2_gaz, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
}
