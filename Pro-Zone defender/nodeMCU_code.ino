#define BLYNK_TEMPLATE_ID "TMPL3QftWpSvM"
#define BLYNK_TEMPLATE_NAME "Gas sensor"
#define BLYNK_AUTH_TOKEN "Ocy1aqhZGls8oXcLzW5ldf62W_q0R-HD"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <bits/stdc++.h>
#include<string.h>
#include <string>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "TP-Link_B9A9";  // type your wifi name
char pass[] = "csmls@1005";    // type your wifi password

BlynkTimer timer;

void air(){
  String firstValue, secondValue, thirdValue, fourthValue, fifthValue;
  if(Serial.available()>0){
    String inputString = Serial.readStringUntil('\n');
    Serial.println(inputString);

    // String inputString = "28.30,40.00,118,51,0"; // The string value saved in a variable

  int firstComma = inputString.indexOf(',');
  int secondComma = inputString.indexOf(',', firstComma + 1);
  int thirdComma = inputString.indexOf(',', secondComma + 1);
  int fourthComma = inputString.indexOf(',', thirdComma + 1);
  
  // Extract values between commas
  firstValue = inputString.substring(0, firstComma);
  secondValue = inputString.substring(firstComma + 1, secondComma);
  thirdValue = inputString.substring(secondComma + 1, thirdComma);
  fourthValue = inputString.substring(thirdComma + 1, fourthComma);
  fifthValue = inputString.substring(fourthComma + 1);
  
  // Convert String values to float or integer if needed
  float firstFloat = firstValue.toFloat();
  float secondFloat = secondValue.toFloat();
  int thirdInt = thirdValue.toInt();
  int fourthInt = fourthValue.toInt();
  int fifthInt = fifthValue.toInt();
  
  // Print the separated values
  Serial.print("First Value: ");
  Serial.println(firstFloat);
  Serial.print("Second Value: ");
  Serial.println(secondFloat);
  Serial.print("Third Value: ");
  Serial.println(thirdInt);
  Serial.print("Fourth Value: ");
  Serial.println(fourthInt);
  Serial.print("Fifth Value: ");
  Serial.println(fifthInt);
  Blynk.virtualWrite(V0,fifthInt);
  Blynk.virtualWrite(V1,firstFloat);
  Blynk.virtualWrite(V2,secondFloat);
  Blynk.virtualWrite(V3,thirdInt);
  Blynk.virtualWrite(V4,fourthInt);
    
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, air);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
}