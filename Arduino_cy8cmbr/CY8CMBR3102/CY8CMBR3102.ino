#include <Wire.h>
#include "define.h"

//#define NO_EXTERNAL_INTERRUPT

//Generated config data
unsigned char configData[128] = {
    0x01u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x80u, 0x7Fu, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x01u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x80u,
    0x05u, 0x00u, 0x00u, 0x02u, 0x00u, 0x02u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x1Eu, 0x00u, 0x00u,
    0x00u, 0x1Eu, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x0Fu, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x05u, 0x03u, 0x01u, 0x58u,
    0x00u, 0x37u, 0x06u, 0x00u, 0x00u, 0x0Au, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x08u, 0x16u
};

const int ArduinoUnoInternalLed = 13;
const int InterruptPin = 2;
volatile int readflag=0;

void HostInterrruptISR() {
  readflag=1;
}

void setup()
{
  pinMode(ArduinoUnoInternalLed, OUTPUT); //To blink if needed
  
  #ifndef NO_EXTERNAL_INTERRUPT
  
  pinMode(InterruptPin, INPUT);     
  //attachInterrupt(digitalPinToInterrupt(InterruptPin), HostInterrruptISR, FALLING);  
  //Both edges to know when btn is click released
  attachInterrupt(digitalPinToInterrupt(InterruptPin), HostInterrruptISR, CHANGE);  
   
  #endif
  Wire.begin();  
    
  Serial.begin(115200);  // start serial for output

  //For single chip is need to be call only once.
  //If do not change configuration 
  configCY8CMBR3102();
  
  Serial.print("Device configurated\n");
}

void loop()
{
  #ifndef NO_EXTERNAL_INTERRUPT
  if(readflag) {
   readflag=0;
   ReadAndDisplaySensorStatus();
  }
  #else
  ReadAndDisplaySensorStatus();
  delay(50);
  #endif
}

void configCY8CMBR3102()
{
  int writeerr = 0;
  
  //Write dummy data
  Wire.beginTransmission(SLAVE_ADDR); // transmit to device #0x37
  Wire.write(REGMAP_ORIGIN);          // sends Offset byte 
  Wire.write(00);
  Wire.endTransmission();    // stop transmitting
  
  Wire.beginTransmission(SLAVE_ADDR); // transmit to device #0x37
  Wire.write(REGMAP_ORIGIN);          // sends Offset byte 
  Wire.write(00);
  Wire.endTransmission();    // stop transmitting
  
  //Arduino function can send only 31 bytes of data
  //So whole frame is send in chunks
  //from [0] to [30]
  Wire.beginTransmission(SLAVE_ADDR); 
  Wire.write(REGMAP_ORIGIN);      //0     
  size_t sendedSize = Wire.write(&configData[0],31);        
  Wire.endTransmission();   
  
  writeerr = Wire.getWriteError();
  
  if(writeerr == 0) {
     Serial.print("First packet sended\n");
  }

  //from [31] to [61]
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(BUTTON_LBR);         //31
  sendedSize = Wire.write(&configData[31],31);
  Wire.endTransmission(); 

  writeerr = Wire.getWriteError();
  
  if(writeerr == 0) {
     Serial.print("Second packet sended\n");
  }

  //from [62] to [92]
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(BUZZER_CFG);          //62 
  sendedSize = Wire.write(&configData[62],31);
  Wire.endTransmission();

  writeerr = Wire.getWriteError();
  
  if(writeerr == 0) {
     Serial.print("Third packet sended\n");
  }

  //from [93] to [123]
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(SLIDER_CFG);         //93
  sendedSize = Wire.write(&configData[93],31);
  Wire.endTransmission();

  writeerr = Wire.getWriteError();
  
  if(writeerr == 0) {
     Serial.print("Fourth packet sended\n");
  }

  //from [124] to [127]
  Wire.beginTransmission(SLAVE_ADDR); 
  Wire.write(0x7C);         //124
  sendedSize = Wire.write(&configData[124],4);        
  Wire.endTransmission();    

  writeerr = Wire.getWriteError();
  
  if(writeerr == 0) {
     Serial.print("Fifth packet sended\n");
  }

  /*
  Write 0x02 to 0x86 
  Info from datasheet
  The device calculates a CRC checksum over the configuration data in this register map and
  compares the result with the content of CONFIG_CRC. If the two values match, the device saves
  the configuration and the CRC checksum to nonvolatile memory.
  */
  Wire.beginTransmission(SLAVE_ADDR); // transmit to device #0x37
  Wire.write(CTRL_CMD);
  Wire.write(SAVE_CHECK_CRC);
  Wire.endTransmission();    // stop transmitting
  
  delay(200);

  //Reset
  Wire.beginTransmission(SLAVE_ADDR); 
  Wire.write(CTRL_CMD);
  Wire.write(SW_RESET);
  Wire.endTransmission();    // stop transmitting
  
  delay(200);
}

void ReadAndDisplaySensorStatus()
{
  char readedData[2] = {0x00};
  
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(BUTTON_STATUS);        
  Wire.endTransmission();
  
  int i=0;
  Wire.requestFrom(SLAVE_ADDR, 2); //2 bytes for whole BUTTON_STATUS
  while(Wire.available())  
  { 
    readedData[i] = Wire.read();
    Serial.print("Hex: 0x"); 
    Serial.print(readedData[i], HEX); 
    Serial.print("\n"); 
    i++;
  }
  Wire.endTransmission();
      
  DisplaySensorStatus(&readedData[0]); 
}

void DisplaySensorStatus(char *c)
{
  if((c[0] & 0x00) != 0)
  {
    Serial.print("BTN 0 CHANGE \n");
  }

  //If second btn is used instead of interrupt 
  if((c[0] & 0x01) != 0)
  {
    Serial.print("BTN 1 CHANGE \n");
  }
}
