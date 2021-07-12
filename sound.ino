const int MIC = 0; //the microphone amplifier output is connected to pin A0
int adc;
int dB, PdB; //the variable that will hold the value read from the microphone each time
void setup() {
Serial.begin(9600); //sets the baud rate at 9600 so we can check the values the microphone is obtaining on the Serial Monitor
  pinMode(8, OUTPUT);
}
void loop(){
  PdB = dB; //Store the previous of dB here
  
adc= analogRead(MIC); //Read the ADC value from amplifer 
//Serial.println (adc);//Print ADC for initial calculation 
dB = (adc+83.2073) / 11.003; //Convert ADC value to dB using Regression values
if (PdB!=dB)
Serial.println (dB);
if (dB>60)
{
  digitalWrite(8, HIGH);// turn the LED on (HIGH is the voltage level)
  Serial.println (dB);
   Serial.println ("High Noise Pollution");
  delay(2000);                       // wait for a second
  digitalWrite(8, LOW); 
}
else
{
  digitalWrite(8, LOW);
}
   Serial.println ("Low Noise Pollution");
//delay(100);
}
