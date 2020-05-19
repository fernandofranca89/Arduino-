int ledpin1 = 7;
  int ledpin2 = 8;
  int ledpin3 = 9;
 
void setup(){
  pinMode(ledpin1,OUTPUT);
  pinMode(ledpin2,OUTPUT);
  pinMode(ledpin3,OUTPUT);  
}
void loop(){
  digitalWrite(ledpin1,HIGH);
  delay(1000);
  digitalWrite(ledpin1,LOW);
  
  
  digitalWrite(ledpin2,HIGH);
  delay(1000);
  digitalWrite(ledpin2,LOW);
  
  digitalWrite(ledpin3,HIGH);
  delay(1000);
  digitalWrite(ledpin3,LOW);
  
  digitalWrite(ledpin1,HIGH);
  digitalWrite(ledpin2,HIGH);
  digitalWrite(ledpin3,HIGH);
  delay(1000);
  digitalWrite(ledpin1,LOW);
  digitalWrite(ledpin2,LOW);
  digitalWrite(ledpin3,LOW);
  
  digitalWrite(ledpin1,HIGH);
  digitalWrite(ledpin2,HIGH);
  digitalWrite(ledpin3,LOW);
  delay(1000);
  digitalWrite(ledpin1,LOW);
  digitalWrite(ledpin2,LOW);
  digitalWrite(ledpin3,LOW);
  
  digitalWrite(ledpin1,HIGH);
  digitalWrite(ledpin2,LOW);
  digitalWrite(ledpin3,HIGH);
  delay(1000);
  digitalWrite(ledpin1,LOW);
  digitalWrite(ledpin2,LOW);
  digitalWrite(ledpin3,LOW);
  
  digitalWrite(ledpin1,LOW);
  digitalWrite(ledpin2,HIGH);
  digitalWrite(ledpin3,HIGH);
  delay(1000);
  digitalWrite(ledpin1,LOW);
  digitalWrite(ledpin2,LOW);
  digitalWrite(ledpin3,LOW);
  
  
}
 
