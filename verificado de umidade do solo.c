//Leitura de umidade do solo
//trabalho Algoritmos e Programacao
//Professor: Luiz Cala?a
//Aluno: Luiz Fernando de Fran?a



#define entradaanalogica 0
#include <LiquidCrystal.h>

bool dsensor;
int asensor;


LiquidCrystal lcd(13,12,5,4,3,2);


void setup(){
  Serial.begin(9600);
    lcd.begin(16,2); 
  lcd.clear();  

 pinMode(entradaanalogica, INPUT);

 
  }

  void loop(){
   
    asensor = analogRead(entradaanalogica);
    Serial.print("leitura entrada digital: ");
    Serial.println(dsensor);
    Serial.print("leitura entrada analogica: ");
    Serial.println(asensor);
    Serial.println();
    
    float saida = analogRead(A0);
    saida  = (saida/1000);
    saida = saida* 100.;
  
if ( saida <=40 ) {
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Precisa molhar");  
     lcd.setCursor(0,1);
     lcd.print(saida);
     lcd.print("% umidade  ");
     delay(1000);
}


if ( saida > 40 && saida <= 75)  {
       
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Ainda com sede");    
       lcd.setCursor(0,1);
       lcd.print(saida);
       lcd.print("% umidade  ");
  delay (1000);
}
    if (saida >75 && saida ){
  lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("vai me afogar? ");    
       lcd.setCursor(0,1);
       lcd.print(saida);
       lcd.print("% CHEGA!!! ");
  delay (1000);
  }
  }
