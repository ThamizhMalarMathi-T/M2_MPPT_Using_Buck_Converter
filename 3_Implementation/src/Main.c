#include <stdio.h>
#include<PWM program.c>
#include<Loop.h>

void main()
 {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  TCCR0B = TCCR0B & B11111000 | B00000010;
}