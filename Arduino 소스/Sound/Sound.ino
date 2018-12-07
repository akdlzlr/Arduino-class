
int sound_pin = A0;
int led_pin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sound_value = analogRead(sound_pin);
  int light_value = map(sound_value, 0, 1023, 0, 255);

  Serial.print("sound value : ");
  Serial.println(sound_value);

  Serial.print("light value : ");
  Serial.println(light_value);
  delay(200);
}
