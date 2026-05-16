const int carRedPin    = 2;
const int carYellowPin = 3;
const int carGreenPin  = 4;
const int buttonPin    = 5;
const int pedRedPin    = 6;
const int pedGreenPin  = 7;

void setup() {
  pinMode(carRedPin,    OUTPUT);
  pinMode(carYellowPin, OUTPUT);
  pinMode(carGreenPin,  OUTPUT);
  pinMode(pedRedPin,    OUTPUT);
  pinMode(pedGreenPin,  OUTPUT);
  pinMode(buttonPin,    INPUT_PULLUP);

  estadoNormal();
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    delay(50); // debounce
    if (digitalRead(buttonPin) == LOW) {
      iniciarTravessia();
    }
  }
}

void estadoNormal() {
  digitalWrite(carGreenPin,  HIGH);
  digitalWrite(carYellowPin, LOW);
  digitalWrite(carRedPin,    LOW);
  digitalWrite(pedRedPin,    HIGH);
  digitalWrite(pedGreenPin,  LOW);
}

void iniciarTravessia() {
  delay(3000); // aguarda 3 segundos antes de iniciar
    
  // Amarelo — aviso para carros
  digitalWrite(carGreenPin,  LOW);
  digitalWrite(carYellowPin, HIGH);
  delay(2000);

  // Vermelho carro + Verde pedestre — travessia
  digitalWrite(carYellowPin, LOW);
  digitalWrite(carRedPin,    HIGH);
  digitalWrite(pedRedPin,    LOW);
  digitalWrite(pedGreenPin,  HIGH);
  delay(7000);

  // Fecha travessia
  digitalWrite(pedGreenPin,  LOW);
  digitalWrite(pedRedPin,    HIGH);
  delay(2000);

  // Volta ao normal
  estadoNormal();
}
