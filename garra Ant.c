//Programa: Controle de garra robotica com Arduino
//Autor: Arduino e Cia

#include <Servo.h>

Servo myservo_base;
Servo myservo_garra;

//Pinos analogicos dos potenciometros
int potpin_base = A0;
int potpin_garra = A2;

//Variavei para armazenamento dos valores dos potenciometros
int val_base;
int val_garra;

void setup()
{
  Serial.begin(9600);
  //Define que o servo da base esta ligado na porta 5
  myservo_base.attach(5);

  //Define que o servo da garra esta ligado na porta 7
  myservo_garra.attach(7);
}

void loop()
{
  //Leitura do valor do potenciometro da base
  val_base = analogRead(potpin_base);

  //Converte o valor pra ser usado no servo (valores entre 0 e 180)
  val_base = map(val_base, 0, 1023, 0, 119);

  //Move o eixo do servo, de acordo com o angulo
  myservo_base.write(val_base);
  
  delay(10);

  //Leitura do valor do potenciometro da garra
  val_garra = analogRead(potpin_garra);

  //Converte o valor pra ser usado no servo (valores entre 0 e 180)
  val_garra = map(val_garra, 0, 1023, 0, 78);

  //Move o eixo do servo, de acordo com o angulo
  myservo_garra.write(val_garra);

  delay(10);
}
