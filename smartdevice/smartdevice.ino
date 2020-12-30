#define BLYNK_PRINT Serial


#include "lib/smarthome/smarthome.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[30];
char pass[100];
char auth[100];

#include <DHT.h>
#define DHTPIN D6          // What digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
smarthome myhome;
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
}

void setup()
{   
    Serial.begin(9600);
    
    
    //reset saved settings
    //myhome.resetSettings();   

    //set custom ip for portal
    myhome.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));
    myhome.autoConnect("smarthome V1", "lampuiot");

    //Initialize for Blynk
    //get ssid, pass, and token
    String wifiSSID = myhome.initialize("SSID");
    String wifiPASS = myhome.initialize("PASS");
    String AUTH = myhome.initialize("AUTH");
  
    //copy-ing string to array char
    strcpy(auth, AUTH.c_str());
    strcpy(ssid, wifiSSID.c_str());
    strcpy(pass, wifiPASS.c_str());
  
    Blynk.begin(auth, ssid, pass);

    dht.begin();

    // Setup a function to be called every second
    timer.setInterval(5000L, sendSensor);
}

void loop()
{
    Blynk.run();
    timer.run();
}
