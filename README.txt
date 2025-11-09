Plataforma: Arduino UNO/Nano (ATmega328P)
Autor original: Frank Martínez (basado en BitwiseAr, Cap. 61)
Modificaciones: se añadió buzzer pasivo y salidas digitales por color.

¿Qué hace?

Lee el sensor TCS3200 (frecuencia del 20%) y mide los pulsos R/G/B con pulseIn().
Según rangos definidos, identifica ROJO, CELESTE o VERDE, enciende una salida por color y hace sonar un buzzer con diferentes tonos.

Serial (115200): imprime R:___ G:___ B:___ y el color detectado.

Buzzer (pin 3): 1000 Hz (rojo), 1500 Hz (celeste), 2000 Hz (verde).

Conexiones:
TCS3200 → Arduino
Señal TCS3200	Pin Arduino
S0	4
S1	5
S2	6
S3	7
OUT	8 (entrada)
VCC/GND	5V / GND

El código pone S0=HIGH, S1=LOW ⇒ salida del sensor al 20%.

Salidas por color y buzzer
Función	Pin Arduino
LED Rojo	9
LED Celeste	10
LED Verde	11
Buzzer pasivo	3

Origen del código:
Frank Martínez, adaptado del canal BitwiseAr
 – Capítulo 61 de Arduino desde cero en Español.
Modificaciones y documentación: Johann Haeussler (septiembre 2025).
