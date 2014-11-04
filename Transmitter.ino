#include <SoftwareSerial.h>
#include <TinyGPS.h>

#define wait 30000
char inData[1024];
char inChar=-1;
TinyGPS shield;
 
 void getgps(TinyGPS &gps)
{
  // Define the variables that will be used
  float latitude, longitude;
  // Then call this function
  shield.f_get_position(&latitude, &longitude);
  String str;
  char string[30];
  char charlat[10];    
  char charlon[10]; 
  int i=0;
  dtostrf(latitude, 3, 5, charlat);
  dtostrf(longitude, 3, 5, charlon);
  /*for(int j=0;j<sizeof(charlat);j++)
  {
    string[i]=charlat[j];
    i++;
  }*/
  
  //string[i]=';';
  /*for(int j=0;j<sizeof(charlon);j++)
  {
    string[i]=charlon[j];
    i++;
  }*/
  //string[i]='\0';
  sprintf(string,"%s;%s",charlat,charlon);
  
  
  Serial.println(string);
  
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
  //
}
