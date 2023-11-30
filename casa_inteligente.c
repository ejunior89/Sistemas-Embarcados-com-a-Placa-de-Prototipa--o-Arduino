int ledSala = 2;
int ledCozinha = 3;
int ledQuarto = 4;
int sensorMovimento = 5;

unsigned long ultimaAtivacao = 0;
int duracaoAtivacao = 5000;

void setup() {
  pinMode(ledSala, OUTPUT);
  pinMode(ledCozinha, OUTPUT);
  pinMode(ledQuarto, OUTPUT);
  pinMode(sensorMovimento, INPUT);
}

void loop() {
  if (digitalRead(sensorMovimento) == HIGH) {
    acenderLampadas();
    ultimaAtivacao = millis();
  }

  if (millis() - ultimaAtivacao >= duracaoAtivacao) {
    apagarLampadas();
  }

  // Controles individuais (ajuste conforme necessário)
  if (/* Condição para acionar lâmpada da sala */) {
    digitalWrite(ledSala, !digitalRead(ledSala));
  }

  if (/* Condição para acionar lâmpada da cozinha */) {
    digitalWrite(ledCozinha, !digitalRead(ledCozinha));
  }

  if (/* Condição para acionar lâmpada do quarto */) {
    digitalWrite(ledQuarto, !digitalRead(ledQuarto));
  }
}

void acenderLampadas() {
  digitalWrite(ledSala, HIGH);
  digitalWrite(ledCozinha, HIGH);
  digitalWrite(ledQuarto, HIGH);
}

void apagarLampadas() {
  digitalWrite(ledSala, LOW);
  digitalWrite(ledCozinha, LOW);
  digitalWrite(ledQuarto, LOW);
}
