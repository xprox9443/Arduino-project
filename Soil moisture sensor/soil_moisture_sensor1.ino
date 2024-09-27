// C++ code
//
int moisture = 0;

void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  digitalWrite(A0, HIGH);
  delay(10); // Wait for 10 millisecond(s)
  moisture = analogRead(A1);
  digitalWrite(A0, LOW);
  Serial.println(moisture);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(6, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  if (moisture < 200) {
    digitalWrite(2, HIGH);
    digitalWrite(6, HIGH);
  } else {
    if (moisture < 400) {
      digitalWrite(3, HIGH);
    } else {
      if (moisture < 600) {
        digitalWrite(4, HIGH);
      } else {
        if (moisture < 800) {
          digitalWrite(5, HIGH);
          digitalWrite(6, LOW);
        } else {
          digitalWrite(1, HIGH);
        }
      }
    }
  }
}