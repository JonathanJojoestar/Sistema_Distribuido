const int triggerPin = 2; // Pin del sensor de ultrasonidos conectado al pin TRIGGER
const int echoPin = 3; // Pin del sensor de ultrasonidos conectado al pin ECHO
const int motorPin = 8; // Pin del motor vibrador conectado

long duration, distance;

void setup() {
  pinMode(triggerPin, OUTPUT); // Configuramos el pin TRIGGER como salida
  pinMode(echoPin, INPUT); // Configuramos el pin ECHO como entrada
  pinMode(motorPin, OUTPUT); // Configuramos el pin del motor vibrador como salida
  Serial.begin(9600); // Inicializamos la comunicación serial para mostrar la distancia medida en el monitor serial
}

void loop() {
  digitalWrite(triggerPin, LOW); // Ponemos el pin TRIGGER a LOW
  delayMicroseconds(200); // Esperamos 2 microsegundos
  digitalWrite(triggerPin, HIGH); // Ponemos el pin TRIGGER a HIGH
  delayMicroseconds(100); // Esperamos 10 microsegundos
  digitalWrite(triggerPin, LOW); // Ponemos el pin TRIGGER a LOW

  duration = pulseIn(echoPin, HIGH); // Medimos el tiempo que tarda en llegar el eco
  distance = duration * 0.034 / 2; // Convertimos el tiempo en distancia (la velocidad del sonido es de 340 m/s)

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 60) { // Si la distancia es menor a 10 cm
    digitalWrite(motorPin, LOW  ); // Encendemos el motor vibrador
  } else {
    digitalWrite(motorPin, HIGH); // Apagamos el motor vibrador
  }

  delay(100); // Esperamos 100 milisegundos antes de realizar una nueva medición
}
