//Luis Fernando Arellano Zaragoza 27/05/22
//UdeG Space
#include <Servo.h>
//Base
int in1_Base = 2;    //Pin que controla el sentido
int in2_Base = 3;    //Pin que controla el sentido
//Hombro
int PUL=4;           //Pin para la señal de pulso
int DIR=5;           //define Direction pin
int EN=6;            //define Enable Pin
//Codo
int in1_Codo = 7;    //Pin que controla el sentido
int in2_Codo = 8;    //Pin que controla el sentido
//Muñeca
int in3_Muneca = 9;  //Pin que controla el sentido
int in4_Muneca = 10;  //Pin que controla el sentido
//Mano
Servo Servo_Mano;     //Servomotor Mano
//Pinza
Servo Servo_Pinza;     //Servomotor Pinza
int estado = 'l';

void setup() {
Serial.begin(9600);
//Motor Base
pinMode(in1_Base, OUTPUT);
pinMode(in2_Base, OUTPUT);
//Motor Hombro
pinMode (PUL, OUTPUT);
pinMode (DIR, OUTPUT);
pinMode (EN, OUTPUT);
digitalWrite(EN,HIGH);
//Motor Codo
pinMode(in1_Codo, OUTPUT);
pinMode(in2_Codo, OUTPUT);
//Muñeca
pinMode(in3_Muneca, OUTPUT);
pinMode(in4_Muneca, OUTPUT);
//Mano
Servo_Mano.attach(11);
//Pinza
Servo_Pinza.attach(12);
} 

void loop() {
  if(Serial.available()>0){      //Lee el bluetooth y almacena en estado
    estado = Serial.read();
  }
  //Motor Base
  if(estado=='a'){               //Boton Izquierda
  digitalWrite(in1_Base, LOW);
  digitalWrite(in2_Base, HIGH);
  }
  if(estado=='b'){               //Boton Derecha
  digitalWrite(in1_Base, HIGH);
  digitalWrite(in2_Base, LOW);
  }
  //Motor Hombro
  if(estado=='c'){               //Boton Arriba 
  digitalWrite(DIR,HIGH);
  for (int i=0; i<80; i++)   
  {
    digitalWrite(PUL,HIGH);
    delayMicroseconds(600);
    digitalWrite(PUL,LOW);
    delayMicroseconds(600);
  }  
  }
  if(estado=='d'){               //Boton Abajo
  digitalWrite(DIR,LOW);
  for (int i=0; i<80; i++) 
  {
    digitalWrite(PUL,HIGH);
    delayMicroseconds(600);
    digitalWrite(PUL,LOW);
    delayMicroseconds(600);
  }  
  } 
  //Motor codo
  if(estado=='e'){               //Boton Arriba
  digitalWrite(in1_Codo, LOW);
  digitalWrite(in2_Codo, HIGH);       
  }
  if(estado=='f'){               //Boton Abajo
  digitalWrite(in1_Codo, HIGH);
  digitalWrite(in2_Codo, LOW);          
  }
  //Motor Muñeca
  if(estado=='g'){               //Boton Arriba 
  digitalWrite(in3_Muneca, LOW);
  digitalWrite(in4_Muneca, HIGH);        
  }
  if(estado=='h'){               //Boton Abajo
  digitalWrite(in3_Muneca, HIGH);
  digitalWrite(in4_Muneca, LOW);        
  }
  //Motor Mano
  if(estado=='i'){               //Boton Izquierda
  Servo_Mano.write(45);        
  }
  if(estado=='j'){               //Boton Derecha
  Servo_Mano.write(135);       
  }
  //Motor Pinza
  if(estado=='k'){               //Boton Abrir 
  Servo_Pinza.write(30);        
  }
  if(estado=='l'){               //Boton Cerrar
  Servo_Pinza.write(100); 
  }
  //ALTO
  if(estado=='s'){          // Stop 
  digitalWrite(in1_Base, LOW);
  digitalWrite(in2_Base, LOW);       
  digitalWrite(in1_Codo, LOW);
  digitalWrite(in2_Codo, LOW);
  digitalWrite(in3_Muneca, LOW);
  digitalWrite(in4_Muneca, LOW);
  }
 
}
