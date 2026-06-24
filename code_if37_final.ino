const int PIN_BOUTON_TEST = 1;
const int PIN_BOUTON_ALERTE = 2;
const int PIN_BUZZER = 43;
const int PIN_MOTEUR_VIBRANT = 4;
const int PIN_LED = 6;


bool alerteActive = false; // État global de l'alerte


// Variables pour le chronométrage sans délai
unsigned long dernierChangement = 0;
bool etatToggle = false;
const long intervalle = 100; // Fréquence de clignotement


void setup() {
  pinMode(PIN_BOUTON_TEST, INPUT_PULLUP);
  pinMode(PIN_BOUTON_ALERTE, INPUT_PULLUP);
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_MOTEUR_VIBRANT, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
}


void loop() {
  // Test haptique
  if (digitalRead(PIN_BOUTON_TEST) == LOW && !alerteActive) {
    digitalWrite(PIN_MOTEUR_VIBRANT, HIGH);
    delay(400);
    digitalWrite(PIN_MOTEUR_VIBRANT, LOW);
    while(digitalRead(PIN_BOUTON_TEST) == LOW);
  }


  // Bascule l'état d'alerte
  if (digitalRead(PIN_BOUTON_ALERTE) == LOW) {
    alerteActive = !alerteActive;
    if (!alerteActive) {
      noTone(PIN_BUZZER);
      digitalWrite(PIN_LED, LOW);
    }
    while(digitalRead(PIN_BOUTON_ALERTE) == LOW);
    delay(50);
  }


  // Exécution de l'alerte par machine à états (non bloquant)
  if (alerteActive) {
    if (millis() - dernierChangement >= intervalle) {
      dernierChangement = millis();
      etatToggle = !etatToggle;
     
      if (etatToggle) {
        tone(PIN_BUZZER, 4100);
        digitalWrite(PIN_LED, HIGH);
      } else {
        tone(PIN_BUZZER, 3500);
        digitalWrite(PIN_LED, LOW);
      }
    }
  } else {
    // État de repos forcé
    noTone(PIN_BUZZER);
    digitalWrite(PIN_LED, LOW);
  }
}

