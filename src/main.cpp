#include <Arduino.h>
#include "Esp.h"
#include "FS.h"
#include <LittleFS.h>
      
    FS* filesystem =      &LittleFS;   
    #define FileFS        LittleFS
    #define FS_Name       "LittleFS"
    
    #define LED_BUILTIN 2
    #define LED_ON            HIGH
    #define LED_OFF           LOW
    
    bool success = false;
    bool FileSystemWasNewFormatted = false;

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
  
 if (!FileFS.begin(false, "/littlefs", 10, "spiffs")) 
 {
    FileFS.format();
    FileSystemWasNewFormatted = true;
 }

if (!FileFS.begin(true, "/littlefs", 10, "spiffs"))
  {
    success = false;
  }
  else
  {
    success = true;
  }
  Serial.begin(115200);
  //while (!Serial);

  if (success)
  {
    Serial.println("\r\n\r\nSuccess: LittleFS is working!.");
  }
  else
  {
    Serial.println("\r\n\r\nLittleFS failed! Already tried formatting.");
  }
  if (FileSystemWasNewFormatted)
  {
    Serial.println("\r\nLittleFS was newly formatted.");
  }
  else
  {
    Serial.println("\r\nLittleFS didn't need to be formatted.");
  }
  while (true)
  {
    digitalWrite(LED_BUILTIN, LED_ON);
    delay (1000);
    digitalWrite(LED_BUILTIN, LED_OFF);
    delay (1000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}