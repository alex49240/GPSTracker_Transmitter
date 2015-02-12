#include <SoftwareSerial.h>
#include <TinyGPS.h>

#define wait 3000
TinyGPS shield;
 
 void getgps(TinyGPS &gps)
{
  // Define the variables that will be used
  float latitude, longitude;
  // Then call this function
  shield.f_get_position(&latitude, &longitude);
  char charlat[10];    
  char charlon[10]; 
  dtostrf(latitude, 3, 5, charlat);
  dtostrf(longitude, 3, 5, charlon);
 Serial.println("{\"latitude\":\" "+ String(charlat) +"\", \"longitude\":\"" + String(charlon) +"\"}");

  
}
void setup()
{  

  Serial.begin(38400);
}

void loop()
{

  byte a;
  if ( Serial.available() > 0 ) // if there is data coming from the GPS shield
  {
    a = Serial.read(); // get the byte of data
    if(shield.encode(a)) // if there is valid GPS data...
    {
      getgps(shield); 
      delay(wait);
        
    }
  }
  
}
