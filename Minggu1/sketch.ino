int lampu=26;
int lampu2=33;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(lampu, OUTPUT);
pinMode(lampu2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(lampu, HIGH);
digitalWrite(lampu2, HIGH);

  delay(1000); // this speeds up the simulation
  digitalWrite(lampu, LOW);
  digitalWrite(lampu2, LOW);
}
