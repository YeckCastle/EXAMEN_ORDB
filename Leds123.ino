int ledVerde = 11;
int ledAmarillo = 12;
int ledRojo = 13;
int buzzer = 10;
int sensor = A1; 
String comando = "";

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 
  int valorSensor = analogRead(sensor);
  Serial.println(valorSensor);

  if (valorSensor > 500) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }

  if (Serial.available()) {
    comando = Serial.readStringUntil('\n');

    if (comando == "1") {
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledRojo, LOW);
      digitalWrite(ledAmarillo, LOW);
    } 
    else if (comando == "2") {
      digitalWrite(ledRojo, HIGH);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarillo, LOW);
    } 
    else if (comando == "3") {
      digitalWrite(ledVerde, HIGH);
      delay(500);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarillo, HIGH);
      delay(500);
      digitalWrite(ledAmarillo, LOW);
      digitalWrite(ledRojo, HIGH);
      delay(500);
      digitalWrite(ledRojo, LOW);
    }
  }

  delay(100); 
}
