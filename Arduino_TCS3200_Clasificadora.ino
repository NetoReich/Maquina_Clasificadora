/*
  Capitulo 61 de Arduino desde cero en Español.
  Visualización por monitor serie de las lecturas del sensor de color
  TCS3200 en microsegundos e intercalando texto al detectar colores
  rojo, verde y azul en base a rango de valores obtenido del programa 1.

  https://www.youtube.com/c/BitwiseAr
  Autor: bitwiseAr  
  Modificado para incluir un buzzer pasivo.
*/

#define S0 4    // S0 a pin 4
#define S1 5    // S1 a pin 5
#define S2 6    // S2 a pin 6
#define S3 7    // S3 a pin 7
#define salidaTCS 8 // salidaTCS a pin 8

// Pines de salida digital para cada color
#define rojoPin 9    // Salida digital para rojo
#define celestePin 10  // Salida digital para celeste
#define verdePin 11   // Salida digital para verde

#define buzzerPin 3 // Definimos el pin del buzzer pasivo

void setup() {
  pinMode(13, OUTPUT);  // PIN 13 en 5V facilitará el diseño y la fabricación del PCB.
  
  pinMode(S0, OUTPUT);    
  pinMode(S1, OUTPUT);    
  pinMode(S2, OUTPUT);    
  pinMode(S3, OUTPUT);    
  pinMode(salidaTCS, INPUT);  

  // Configuración de los pines de salida digital
  pinMode(rojoPin, OUTPUT);    
  pinMode(celestePin, OUTPUT);  
  pinMode(verdePin, OUTPUT);   

  pinMode(buzzerPin, OUTPUT); // Configuramos el buzzer como salida

  digitalWrite(13, HIGH); // PIN 13 nos ayuda a tener 5V del otro lado del Arduino.
  digitalWrite(S0, HIGH);  // Establece frecuencia de salida
  digitalWrite(S1, LOW);   // del módulo al 20 por ciento
  
  Serial.begin(115200);   // Inicializa monitor serie
}

void loop() {
  digitalWrite(S2, LOW);    
  digitalWrite(S3, LOW);    
  int R = pulseIn(salidaTCS, LOW); // Obtiene duración de pulso de salida del sensor
  delay(200);       
  
  digitalWrite(S2, HIGH);    
  digitalWrite(S3, HIGH);    
  int G = pulseIn(salidaTCS, LOW);  
  delay(200);       
  
  digitalWrite(S2, LOW);    
  digitalWrite(S3, HIGH);    
  int B = pulseIn(salidaTCS, LOW); 
  delay(200);       

  Serial.print("R:"); Serial.print(R);
  Serial.print("\tG:"); Serial.print(G);
  Serial.print("\tB:"); Serial.println(B);

  // Apagamos todas las salidas por defecto
  digitalWrite(rojoPin, LOW);
  digitalWrite(celestePin, LOW);
  digitalWrite(verdePin, LOW);

  if (R < 100 && G > 130 && B > 100) {  
    Serial.println("ROJO");
    digitalWrite(rojoPin, HIGH);  
    tone(buzzerPin, 1000); // Sonido de 1000 Hz para rojo
    delay(500);
    noTone(buzzerPin);
    delay(2000); 
  } 
  else if (R > 90 && R < 130 && G > 55 && G < 70 && B > 30 && B < 50) {
    Serial.println("CELESTE");
    digitalWrite(celestePin, HIGH);  
    tone(buzzerPin, 1500); // Sonido de 1500 Hz para celeste
    delay(500);
    noTone(buzzerPin);
    delay(2000); 
  }
  else if (R > 100 && R < 160 && G > 90 && G < 120 && B > 100 && B < 130) {  
    Serial.println("VERDE");
    digitalWrite(verdePin, HIGH);  
    tone(buzzerPin, 2000); // Sonido de 2000 Hz para verde
    delay(500);
    noTone(buzzerPin);
    delay(2000); 
  }
}
