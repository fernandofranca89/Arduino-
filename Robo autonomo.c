#include <Servo.h>    


#define trigPin A0    
#define echoPin A1    
// motor um            
#define enA  11        
#define in1  9        
#define in2  8         
// motor dois          
#define enB  5        
#define in3  7         
#define in4  6       

Servo servoSensor;       


int Procurar (void) {
  float duracao = 0.0;              
  float CM = 0.0;                  
  digitalWrite(trigPin, LOW);       
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);     
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);      
  duracao = pulseIn(echoPin, HIGH); 
  CM = (duracao / 58.8);            
  Serial.print("Distancia em CM: ");
  Serial.println(CM);             
  return CM;                        
}

//Variaveis
int DistanciaDireita, DistanciaEsquerda;  
float Distancia = 0.00;                   


int velocidadeMotorUm = 80;
int velocidadeMotorDois = 95;


void setup() {
  Serial.begin(9600);
  
  
  servoSensor.attach(13); 
  
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
       
  
  pinMode(trigPin, OUTPUT);    
  pinMode(echoPin, INPUT);      
}


  servoSensor.write (90);                           
  delay (100);                                      
  Distancia = Procurar ();                          
  if (Distancia < 40) {                             
   direcao ();                                      
  }
  else if (Distancia >= 40)  {                       
    Frente ();                                      
  }
  
}


void direcao () {        
  Parar ();                                       
  ParaTras ();                                     
  Parar ();                                         
  servoSensor.write (180);                          
  delay (1000);              
  DistanciaEsquerda = Procurar ();                 
  delay (500);               
  servoSensor.write (0);                           
  delay (500);               
  DistanciaDireita = Procurar ();                   
  delay (500);               
  servoSensor.write (90);                          
  delay (500);              
  CompareDistance ();                              
}


void CompareDistance () {                   
  if (DistanciaDireita > DistanciaEsquerda) {      
    Vireadireita ();                               
  }
  else if (DistanciaEsquerda > DistanciaDireita) {  
    VireaEsquerda ();                               
  }
  else {                                            
    Retorne ();                                    
  }
}


{
  Serial.println("Rob�: Parar ");
  digitalWrite(in1, LOW);                          
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(100);                                       
}


{
  Serial.println("Rob�: Frente ");
  digitalWrite(in1, HIGH);                         
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, velocidadeMotorUm);             
  analogWrite(enB, velocidadeMotorDois);                                 
}


{
  Serial.println("Rob�: R� ");
  digitalWrite(in1, LOW);                          
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(300);                                      
  analogWrite(enA, velocidadeMotorUm);              
  analogWrite(enB, velocidadeMotorDois);                                     
}


void Vireadireita()
{
  Serial.println("Rob�: Direita ");
  digitalWrite(in1, LOW);                         
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(300);                                      
  analogWrite(enA, velocidadeMotorUm);             
  analogWrite(enB, velocidadeMotorDois);                                     
}


void VireaEsquerda()
{
  Serial.println("Rob�: Esquerda ");                
  digitalWrite(in1, HIGH);                          
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(300);                                      
  analogWrite(enA, velocidadeMotorUm);             
  analogWrite(enB, velocidadeMotorDois);                                  
}


void Retorne () {    
  Serial.println("Rob�: Girar ");      
  digitalWrite(in1, HIGH);                          
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay (700);                                      
  analogWrite(enA, velocidadeMotorUm);              
  analogWrite(enB, velocidadeMotorDois);                                 
}
