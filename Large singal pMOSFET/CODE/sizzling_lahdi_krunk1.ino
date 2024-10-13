// C++ code
//
int sensorValue = 0;

int outputValue = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // read the value from the sensor
  sensorValue = analogRead(A0);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(9, outputValue);
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("     output = ");
  Serial.println(outputValue);
  delay(100); // Wait for 100 millisecond(s)
}