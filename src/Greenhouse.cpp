// Incluir as bibliotecas necessárias
#include <Arduino.h>
#include <Wire.h>
#include <DHT.h> // Incluir a biblioteca do sensor DHT11
#include <RTClib.h> // Incluir a biblioteca do RTC

// Definir os pinos ao qual o sensor de umidade, os relés, o sensor DHT11, o potenciômetro e o interruptor estão conectados
#define SENSOR_PIN   34  // Exemplo de pino GPIO para o sensor de umidade do solo
#define RELE_UM_PIN  26  // Exemplo de pino GPIO para o relé 1
#define RELE_DOIS_PIN 27  // Exemplo de pino GPIO para o relé 2
#define RELE_TRES_PIN 28  // Exemplo de pino GPIO para o relé 3
#define RELE_QUATRO_PIN 29 // Exemplo de pino GPIO para o relé 4 (para o sistema de irrigação por aspersão)
#define RELE_CINCO_PIN  30 // Exemplo de pino GPIO para o relé 5 (para umidade do solo abaixo de 70%)
#define DHT_PIN      25  // Exemplo de pino GPIO para o sensor DHT11
#define POT_PIN      32  // Exemplo de pino GPIO para o potenciômetro
#define SWITCH_PIN   31  // Exemplo de pino GPIO para o interruptor switch
#define LED_PIN      33  // Exemplo de pino GPIO para a fita de LED

// Definir o tipo de sensor DHT e o pino de conexão
#define DHT_TYPE DHT11

// Inicializar o objeto do sensor DHT11
DHT dht(DHT_PIN, DHT_TYPE);

// Inicializar o objeto do RTC
RTC_DS3231 rtc;

void setup() {
  // Inicializar a comunicação serial com uma taxa de transmissão de 9600 bps
  Serial.begin(9600);

  // Configurar os pinos como entrada ou saída
  pinMode(RELE_UM_PIN, OUTPUT);
  pinMode(RELE_DOIS_PIN, OUTPUT);
  pinMode(RELE_TRES_PIN, OUTPUT);
  pinMode(RELE_QUATRO_PIN, OUTPUT); // Novo pino para o sistema de irrigação por aspersão
  pinMode(RELE_CINCO_PIN, OUTPUT);  // Novo pino para a umidade do solo abaixo de 70%
  pinMode(LED_PIN, OUTPUT);
  pinMode(POT_PIN, INPUT);
  pinMode(SWITCH_PIN, INPUT_PULLUP); // Usar resistor pull-up interno
  
  // Inicializar o sensor DHT11
  dht.begin();

  // Inicializar o RTC
  Wire.begin();
  if (!rtc.begin()) {
    Serial.println("Erro ao iniciar o RTC!");
    while (1);
  }

  // Verificar se o RTC foi iniciado corretamente
  if (!rtc.begin()) {
    Serial.println("RTC não encontrado! Verifique a conexão.");
    while (1);
  }
}

void loop() {
  // Ler o valor analógico do sensor de umidade do solo
  int soilSensorValue = analogRead(SENSOR_PIN);
  
  // Converter o valor do sensor de umidade para porcentagem (0-100%)
  float humidityPercent = map(soilSensorValue, 0, 4095, 100, 0); // Inversão dos valores
  
  // Exibir a porcentagem de umidade do solo no Serial Monitor
  Serial.print("Umidade do Solo: ");
  Serial.print(humidityPercent);
  Serial.println("%");

  // Ler a temperatura e umidade do ar do sensor DHT11
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  // Exibir a temperatura e umidade do ar no Serial Monitor
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Umidade do Ar: ");
  Serial.print(humidity);
  Serial.println("%");

  // Ler o valor do potenciômetro
  int potValue = analogRead(POT_PIN);
  
  // Mapear o valor do potenciômetro para o intervalo de 0 a 255 (para PWM)
  int brightness = map(potValue, 0, 4095, 0, 255);
  
  // Ajustar a intensidade luminosa da fita de LED
  analogWrite(LED_PIN, brightness);

  // Verificar o estado do interruptor switch
  bool switchState = digitalRead(SWITCH_PIN);

  // Obter o tempo atual do RTC
  DateTime now = rtc.now();

  // Verificar se o interruptor está na posição 1 (16 horas)
  if (switchState == HIGH) {
    if (now.hour() < 16) {
      // Ligar a lâmpada
      digitalWrite(RELE_UM_PIN, HIGH);
    } else {
      // Desligar a lâmpada
      digitalWrite(RELE_UM_PIN, LOW);
    }
  }
  // Verificar se o interruptor está na posição 2 (14 horas)
  else {
    if (now.hour() < 14) {
      // Ligar a lâmpada
      digitalWrite(RELE_UM_PIN, HIGH);
    } else {
      // Desligar a lâmpada
      digitalWrite(RELE_UM_PIN, LOW);
    }
  }

  // Acionar o relé 2 quando a temperatura estiver abaixo de 22°C
  if (temperature < 22) {
    digitalWrite(RELE_DOIS_PIN, HIGH);
  } else {
    digitalWrite(RELE_DOIS_PIN, LOW);
  }

  // Acionar o relé 3 quando a temperatura estiver acima de 28°C
  if (temperature > 28) {
    digitalWrite(RELE_TRES_PIN, HIGH);
  } else {
    digitalWrite(RELE_TRES_PIN, LOW);
  }

  // Acionar o relé 4 para o sistema de irrigação por aspersão quando a umidade do ar estiver abaixo de 60%
  if (humidity < 60) {
    digitalWrite(RELE_QUATRO_PIN, HIGH); // Ligar a bomba de água ou abrir a válvula solenóide
  } else {
    digitalWrite(RELE_QUATRO_PIN, LOW); // Desligar a bomba de água ou fechar a válvula solenóide
  }

  // Acionar o relé 5 quando a porcentagem de umidade do solo estiver abaixo de 70%
  if (humidityPercent < 70) {
    digitalWrite(RELE_CINCO_PIN, HIGH); // Ligar o relé 5
  } else {
    digitalWrite(RELE_CINCO_PIN, LOW); // Desligar o relé 5
  }

  // Verificar se passaram 24 horas desde o último reinício
  if (now.hour() == 0 && now.minute() == 0) {
    // Reiniciar o RTC
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // Aguardar um curto período antes de realizar uma nova leitura
  delay(1000);
}
