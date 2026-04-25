#define PWM_PIN 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // pinMode(PWM_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  uint32_t lapse = 1;
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    analogWrite(LED_BUILTIN, dutyCycle);
    delay(lapse);
    Serial.printf("Valor PWM: %u%%\n", (dutyCycle));
  };
  for (int dutyCycle = 255; dutyCycle > 0; dutyCycle--) {
    analogWrite(LED_BUILTIN, dutyCycle);
    delay(lapse);
    Serial.printf("Valor PWM: %u%%\n", (dutyCycle));
  };
}
