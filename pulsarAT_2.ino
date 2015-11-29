#define trigPin 0  
#define echoPin 1

int distMax = abs (15);
int distMin = abs (5);
int distMed = abs (10);
int centro = 20; // Distance from the sensor to the center of the light beam
int ledExterior = A3;
int ledInterior = A2;
int ledNucleo = A1;
int duracion, distancia, control, sensor;

void setup() {
  pinMode(ledNucleo, OUTPUT);  
  pinMode(ledExterior, OUTPUT);
  pinMode(ledInterior, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Initiate all LEDs
  analogWrite (ledNucleo, 255); 
  analogWrite (ledInterior, 255);
  analogWrite (ledExterior, 255);
}

void loop() {
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  
  // Converts time into distance (cm)
  duracion = pulseIn(echoPin, HIGH);
  distancia = (duracion/2) / 29.1;
  
  // Middle point so the sensor works both ways
  sensor = distancia - centro;
  control = abs (sensor); 
  
  // Check distance value and turn LEDs accordingly
  if (control >= distMed && control <= distMax){
    // Prevents interaction from outside the lamp area
    analogWrite (ledNucleo, 255); 
    analogWrite (ledInterior, 255);
    analogWrite (ledExterior, 255);
    // max intensity, 19 LEDs
    suspension ();
  } if (control >= distMin && control <= distMed){
    analogWrite (ledNucleo, 255); 
    analogWrite (ledInterior, 255);
    analogWrite (ledExterior, 0);
    // medium intensity, 7 LEDs
    suspension ();
  } if (control < distMin){
    analogWrite (ledNucleo, 255); 
    analogWrite (ledInterior, 0);
    analogWrite (ledExterior, 0);
    // minimum intensity, 1 LED
    suspension ();
  }
}

// Delay to turn LEDs to avoid flickering
void suspension (){
  boolean suspension = true;
  delay(400);
  suspension = false;
}
  
    

