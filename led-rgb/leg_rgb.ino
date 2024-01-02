int vermelho = 10; 
int verde = 11;   
int azul = 12;   


void Vermelho() {
  digitalWrite(vermelho, HIGH);
  delay(1000);
  digitalWrite(vermelho, LOW);
  delay(1000);
}
void Verde() {
  digitalWrite(verde, HIGH);
  delay(1000);
  digitalWrite(verde, LOW);
  delay(1000);
}
void Azul() {
  digitalWrite(azul, HIGH);
  delay(1000);
  digitalWrite(azul, LOW);
  delay(1000);
}
void Branco() {
  digitalWrite(azul, HIGH);
  digitalWrite(vermelho, HIGH);
  digitalWrite(verde, HIGH);
  delay(1000);
  digitalWrite(azul, LOW);
  digitalWrite(vermelho, LOW);
  digitalWrite(verde, LOW);
  delay(1000);
}
void Magenta() {
  digitalWrite(azul, HIGH);
  digitalWrite(vermelho, HIGH);
  delay(1000);
  digitalWrite(azul, LOW);
  digitalWrite(vermelho, LOW);
  delay(1000);
}
void Amarelo() {
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, HIGH);
  delay(1000);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, LOW);
  delay(1000);
}
void Ciano() {
  digitalWrite(verde, HIGH);
  digitalWrite(azul, HIGH);
  delay(1000);
  digitalWrite(verde, LOW);
  digitalWrite(azul, LOW);
  delay(1000);
}

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
}

void loop() {
  Vermelho();
  Verde();
  Azul();
  Branco();
  Ciano();
  Magenta();
  Amarelo();
}
