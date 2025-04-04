#include <SoftwareSerial.h>
SoftwareSerial wifi(5,6);
#define SSID
#define PASS
int LED=2;
int LDR=A0;
int LDRval = 0;
int LightStatus=10;
void SendAT (String command, const int timeout) {
String response = "" ;
wifi.print(command);
long int time=millis();
while((time+timeout)>millis()){
while(wifi.available()){
char c=wifi.read();
response+=c;
}
}
Serial.print(response);
return response;
}
void updatethingspeak (String l, String stat){
Serial.print("");
SendAT("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n", 2000);
String CMDLEN;
String CMD="GET https://api.thingspeak.com/update?api_key=3D9DV67QKPYLPV3T&field1="+1+"&field2="+stat+"\r\n";
CMDLEN=CMD.length();
SendAT("AT+CIPSEND="+CMDLEN+"\r\n", 2000);
wifi.print(CMD);
Serial.println("");
SendAT ("AT+CIPCLOSE\r\n", 2000);
Serial.println("");
}
void setup() {
// put your setup code here, to run once:
pinMode(LDR, INPUT);
Serial.begin(9600);
pinMode(LED, OUTPUT);
wifi.begin(9600);
SendAT ("AT+RST\r\n", 2000);
SendAT ("AT\r\n", 2000);
SendAT("AT+CWMODE=1\r\n", 2000);
SendAT("AT+CWJAP=\""SSID"\", \""PASS"\"\r\n", 2000);
while(wifi.find("OK")){
Serial.print("....");
}
SendAT("AT+CIFSR\r\n", 2000);
SendAT("AT+CIMUX=0\r\n", 2000);
}
void loop() {
// put your main code here, to run repeatedly:
LDRval-analogRead(LDR);
int data = map (LDRval, 0, 1023,0,100);
if (LDRval<=100) {
digitalWrite(LED, HIGH);
LightStatus=100;
}
else{
digitalWrite(LED, LOW);
LightStatus=10;
}
String SensorValue = String(data);
Serial.print("Light intesity = ");
Serial.println(data);
String LightStatus1 = String(LightStatus);
Serial.print("Light Status = ");
Serial.println(LightStatus);
updatethingspeak(SensorValue,LightStatus1);
delay(2000);
}