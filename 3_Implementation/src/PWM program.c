#include<stdio.h>



void setup()
 {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  TCCR0B = TCCR0B & B11111000 | B00000010;
}


void loop() 
{
//Current
int pwmnew=0;
unsigned int x = 0;
float AcsValue = 0.0, Samples = 0.0, AvgAcs = 0.0, AcsValueF = 0.0, valu=0;
for (int x = 0; x < 150; x++) 
{             //Get 150 samples
    AcsValue = analogRead(A1);      //Read current sensor values
    Samples = Samples + AcsValue;   //Add samples together
    delay (3);          //sample 3ms
  }
  AvgAcs = Samples / 150.0;
  AcsValueF = (((2.5 - (AvgAcs * (5.0 / 1024.0)) )/0.066));
  Serial.print("current");
  Serial.print(AcsValueF);        //Print the current value
  delay (50);
  
 adc_value = analogRead(A0);      //Voltage
  adc_voltage  = (adc_value * ref_voltage) / 1024.0;
  in_voltage = adc_voltage / (R2 / (R1 + R2));
  Serial.println("Input Voltage = ");
  Serial.print(in_voltage, 2);
  delay(500);
  voltageValue=in_voltage;
  currentValue=AcsValueF;
  Power_now = abs(voltageValue * currentValue);
  if (Power_now > Power_anc)      //Power and duty
  { 
if (voltageValue > voltage_anc)
          pwm = pwm + delta;
      else
        pwm = pwm - delta;
  }
  else
  {
      if (voltageValue > voltage_anc)
          pwm = pwm - delta;
      else
          pwm = pwm + delta;
  }
  Power_anc = Power_now;
  voltage_anc = voltageValue;
if (pwm < 40)
        pwm = 40;
if (pwm > 250)
        pwm = 250;
analogWrite (5, pwm);
}
