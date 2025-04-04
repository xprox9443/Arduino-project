int LED=2;
int LDR=A0;
int LDRval = 0;
int LightStatus=0;

void setup(){
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);

}

void loop(){
  LDRval=analogRead(A0);
  if (LDRval <=100) {
    digitalWrite(2, HIGH);
    LightStatus=100;
  }
  else{
    digitalWrite(2, LOW);
    LightStatus=0;
  }
}