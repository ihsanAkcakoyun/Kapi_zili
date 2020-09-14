#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "YourAuthtoken";


char ssid[] = "WifiAdı";
char pass[] = "WifiSifren";

boolean zilDurum;
boolean zilAyar;
boolean zilAktif;
boolean milisDurum ;
boolean modulAktif;
#define zil 0
#define button 2
String a;

unsigned long sonrakiZaman;

BLYNK_WRITE_DEFAULT() {
  Serial.print("input V");
  Serial.print(request.pin);
  Serial.println(":");

  for (auto i = param.begin(); i < param.end(); ++i) {
    Serial.print("* ");
    Serial.println(i.asString());
    if ( request.pin == 0)
    {
      a = i.asString();
      zilAyar = a.toInt();
    }
    else if (request.pin == 1)
    {
      a = i.asString();
      zilAktif = a.toInt();
    }
  }
}

void setup()
{
  pinMode(zil, OUTPUT);
digitalWrite(zil, LOW);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(button, INPUT_PULLUP);
  
  
  zilAktif = 0;
  zilAyar = 0;
 
}

void loop()
{

  

  Blynk.run();


  
    if (zilAyar == 1)
    {
      digitalWrite(zil, LOW);
      zilDurum = !digitalRead(button);
      if (zilDurum == 1) {
        Serial.println("Button is pressed.");
        Blynk.notify("KAPI CALIYOOOOOOO!!! KAPIYA BAK!!!");
        delay(1000);

      }
    }
    if (zilAktif == 1)
    {
      zilDurum = !digitalRead(button);
      if (zilDurum == 1) {
        Serial.println("Button is pressed.");
        Blynk.notify("KAPI CALIYOOOOOOO!!! KAPIYA BAK!!!");
      }
      digitalWrite(zil, zilDurum);
      delay(500);
    }
    else if ( zilAyar == 0 && zilAktif == 0)
    {
      zilDurum = !digitalRead(button);
      digitalWrite(zil, zilDurum);

    }

  }
