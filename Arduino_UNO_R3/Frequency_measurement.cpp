#define input_signal    2  // Digital pin where the button to activate the triangular wave is connected
#define output_signal   4  // Digital pin where the button to activate the triangular wave is connected


int val = 0;

float Ttime;            // переменная для хранения длительности периода
float frequency;        // переменная для хранения значения частоты

int Htime_before;
int Htime_now;
float Deltime;

uint32_t myTimer, TimeRN,TimeBFR, timerSIGNAL, TimeBIG = 0;
double freq;
bool flag = true, flagSIGNAL = false;

void setup(){
  
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
  
  Htime_before = 999999999;
  TimeBFR = 999999;
  
}

void loop(){
  
	//Serial.print(millis());
 // Serial.print("\n");
  
  val = digitalRead(input_signal);
  
  if (val == 1 && flag == true)
  {
    myTimer = millis();
    flag = false;
  }
  
  	//Serial.print(millis());
  //Serial.print("\n");
  
  
  if (val == 0 && flag == false)
  {
    TimeRN = millis() - myTimer;
    flag = true;
    //Serial.print(TimeRN);
    //Serial.print("\n now ");
    
    Deltime = TimeRN/TimeBFR; 
    Serial.print(Deltime);
    Serial.print("\n");
    
    //if (Deltime < 2)
      TimeBFR = TimeRN;
  }
             
	//Serial.print(millis());
  	//Serial.print("\n");
  
  if (Deltime > 1.5  && flagSIGNAL == false){
      digitalWrite(output_signal, HIGH);
      timerSIGNAL = millis();
      flagSIGNAL = true;
    	Deltime = 1;
    
/*      Serial.print("\n now ");
      Serial.print(Htime_now);
      Serial.print("\n before ");
      Serial.print(Htime_before);
      Serial.print(" \n del \n");
      Serial.print(Htime_now/Htime_before);
*/      //
    TimeBFR = TimeRN;
    
    Serial.print("\n T = ");
    Serial.print((float)myTimer - (float)TimeBIG);
    Serial.print("\n");
    
    freq = 1000 / ((float)myTimer - (float)TimeBIG);
    TimeBIG = myTimer;
    
    Serial.print("\n f = ");
    Serial.print(freq);
    Serial.print("\n");
    
    }
    else{
      //TimeBFR = TimeRN;
      //digitalWrite(output_signal, 0);
    }
    
  //Serial.print(millis());
  	//Serial.print("\n");


  if((millis() - timerSIGNAL > 10) && flagSIGNAL == true){
        digitalWrite(output_signal, LOW);
  		flagSIGNAL = false;
  }
  
  //Serial.print(millis());
  	//Serial.print("\n RNNNN");
}