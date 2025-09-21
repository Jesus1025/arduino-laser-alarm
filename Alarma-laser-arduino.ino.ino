// --- CONFIGURACIÓN DE PINES ---
const int LDR_PIN = A5;
const int BUZZER_PIN = 8;
const int BUTTON_PIN = 2;
const int RED_LED_PIN = 10;   "Desarmado"
const int BLUE_LED_PIN = 11;  "Armado"

// --- UMBRAL ---
int umbralLaser = 1000;          --1023 es un laser estandar--

// --- VARIABLES DE ESTADO ---
bool sistemaArmado = true; 
bool alarmaSonando = false;
bool estadoBotonAnterior = HIGH;

// --- FUNCIÓN SETUP ---
void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RED_LED_PIN, OUTPUT); 
  pinMode(BLUE_LED_PIN, OUTPUT); 

  // Estado inicial al encender
  Serial.println("Sistema Armado");
  digitalWrite(BLUE_LED_PIN, HIGH); 
  digitalWrite(RED_LED_PIN, LOW);   
}

// --- FUNCIÓN LOOP ---
void loop() {
  // --- LÓGICA DEL BOTÓN (para armar/desarmar) ---
  bool estadoBotonActual = digitalRead(BUTTON_PIN);

  if (estadoBotonAnterior == HIGH && estadoBotonActual == LOW) {
    sistemaArmado = !sistemaArmado;

    // NUEVA LÓGICA PARA CONTROLAR LOS LEDS DE ESTADO
    if (sistemaArmado) {
      digitalWrite(BLUE_LED_PIN, HIGH); // Se prende el LED azul
      digitalWrite(RED_LED_PIN, LOW);   // Se apaga el LED rojo
      Serial.println("Sistema Armado");
    } else {
      digitalWrite(BLUE_LED_PIN, LOW);    // Se apaga el LED azul
      digitalWrite(RED_LED_PIN, HIGH);  // Se prende el LED rojo
      alarmaSonando = false; 
      noTone(BUZZER_PIN);    
      Serial.println("Sistema Desarmado");
    }
    delay(50); 
  }
  estadoBotonAnterior = estadoBotonActual;

  // --- LÓGICA DEL SENSOR LÁSER ---
  if (sistemaArmado) {
    int valorLuz = analogRead(LDR_PIN);
    Serial.print("Valor LDR: ");
    Serial.println(valorLuz);

    if (valorLuz < umbralLaser) {
      alarmaSonando = true;
    }
  }

  // --- LÓGICA DE LA ALARMA ---
  if (alarmaSonando) {
    tone(BUZZER_PIN, 2500, 150);
  }

  delay(100);
}
