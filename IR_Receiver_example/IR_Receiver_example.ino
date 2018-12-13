/*
The button codes match the remote provided in the Elegoo starter kit.
https://www.elegoo.com/product/elegoo-uno-project-super-starter-kit/
*/

#include "IRremote.h"

int RECV_PIN = 11;


IRrecv irrecv(RECV_PIN);     

decode_results results;      


unsigned long getIR()
{
  if (irrecv.decode(&results))
  {
    unsigned long valueToReturn = results.value;
    
    // resume watching for inputs
    irrecv.resume();

    return valueToReturn;
  }
  else
  {
    return 0;
  }
} 


#define BTN_POWER   0xFFA25D
#define BTN_FUNC_STOP  0xFFE21D
#define BTN_VOL_UP  0xFF629D
#define BTN_FAST_BACK   0xFF22DD 
#define BTN_PAUSE   0xFF02FD 
#define BTN_FAST_FORWARD  0xFFC23D 
#define BTN_DOWN   0xFFE01F 
#define BTN_VOL_DOWN   0xFFA857 
#define BTN_UP   0xFF906F 
#define BTN_EQ   0xFF9867 
#define BTN_ST_REPT   0xFFB04F 
#define BTN_0   0xFF6897 
#define BTN_1   0xFF30CF 
#define BTN_2   0xFF18E7 
#define BTN_3   0xFF7A85 
#define BTN_4   0xFF10EF 
#define BTN_5   0xFF38C7 
#define BTN_6   0xFF5AA5 
#define BTN_7   0xFF42BD 
#define BTN_8   0xFF4AB5 
#define BTN_9   0xFF52AD 
// this one is special - it means you're holding down a button
#define BTN_REPEAT  0xFFFFFFFF





void setup()  
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}


void loop()   
{
  unsigned long irSig = getIR();
  
  // zero means no signal
  if (irSig > 0)     
  {
    
    Serial.println(irSig, HEX);
    
    if (irSig == BTN_POWER) 
    {
      Serial.println("Power button");
    }
    else if (irSig == BTN_VOL_UP)
    {
      Serial.println("Volume up button");
    }
    else if (irSig == BTN_REPEAT)
    {
      Serial.println("you're still holding the same button");
    }
    else 
    {
      Serial.println("other button (sometimes this is a misread)");
    }
  }

}
