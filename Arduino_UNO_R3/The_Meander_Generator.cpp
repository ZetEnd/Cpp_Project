// buttons used to activate each type of wave
#define input_signal   8  // Digital pin where the button to activate the rectangular pulse is connected
#define output_signal  9  // Digital pin where the button to activate the triangular wave is connected


uint32_t eps = 100;
uint32_t TimeRN, Time;
int i = 0;

bool flag = true, flag2 = true, flag3 = false,flag4 = true;
void setup()
{
  Serial.begin(115200); //Command to start Serial Port at 115200 baud rate
  //DDRD = 0b11111100;  // PORT D [2..7] as digital outputs
  /* port D [2..7] as digital outputs
 0b indicates that the data will be written in binary; 
  1 to leave the pin as OUTPUT and 0 for INPUT, 
  in this case pins 0 and 1 are 0 because they were not used.
 */
 
 /* the buttons are configured as input pullup,
 to use the internal pullup resistor in the MCU
 instead of an external resistor
 */
  
  pinMode(input_signal, INPUT);  
  pinMode(output_signal, OUTPUT);
}

void loop()
{
  if (flag){
  Time = millis();
    flag = false;
  }
// if  button_rectangular  was pressed, a rectangular pulse is displayed on the oscilloscope

  if(i == 3) {
        //eps = i*eps;
  //flag3 = false;
  //flag2 = true;
  }
      TimeRN = millis();
      if (TimeRN - Time >= eps  && flag2){
        digitalWrite(output_signal, HIGH);
        Time = TimeRN;
        flag2 = false;
        flag3 = true;
      }
      if(i == 3 && flag4 && flag3) 
      {eps = eps*i;
       flag4 = false;
      }
      TimeRN = millis();
      if (TimeRN - Time >= eps && flag3){
        digitalWrite(output_signal, LOW);
        Time = TimeRN;
        flag3 = false;
        flag2 = true;
        i++;
      }
  if(i == 4) 
  {i = 0; flag = true; eps = eps/3; flag4 = true;}
  /*
    for (int i = 0; i <= 1000; i++) // 100 is the time line
    {
      PORTD = 255;                // 255 means a high level during 64 cycles 
      delayMicroseconds(30);     //  10us delay
    }
    for (int i = 0; i <= 1000; i++)
    {
      PORTD = 0;                  // 0 means a low level during other 64 cycles to show the rectangular pulse
      delayMicroseconds (30);
    }
    num_section++;
    
    if(num_section == 3){
      
        for (int i = 0; i <= 3000; i++) // 100 is the time line
        {
          PORTD = 255;                // 255 means a high level during 64 cycles 
          delayMicroseconds(30);     //  10us delay
        }
        for (int i = 0; i <= 1000; i++)
        {
          PORTD = 0;                  // 0 means a low level during other 64 cycles to show the rectangular pulse
          delayMicroseconds (30);
        }
      
      num_section = 0;
  	}*/
  }