#include <Arduino.h>  // Wajib untuk PlatformIO + ESP32
#include <WiFi.h>

// Deklarasi pin LED
int lampu = 25;
int lampu2 = 33;

void setup() {
    Serial.begin(115200);


    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
  
  
    Serial.println("Pemindaian Jaringan Wi-Fi Dimulai...");

    Serial.begin(115200);  // Inisialisasi komunikasi Serial
    Serial.println("ESP32 Blinking LED");




    // Atur pin sebagai OUTPUT
    pinMode(lampu, OUTPUT);
    pinMode(lampu2, OUTPUT);
}

void loop() {
    // Nyalakan kedua LED
    digitalWrite(lampu, HIGH);
    digitalWrite(lampu2, HIGH);
    Serial.println("LED ON");
   
    delay(1000); // Tunggu 1 detik




    // Matikan kedua LED
    digitalWrite(lampu, LOW);
    digitalWrite(lampu2, LOW);
    Serial.println("LED OFF");
   
    delay(1000); // Tunggu 1 detik sebelum mengulang

    int n = WiFi.scanNetworks();
  Serial.println("Pemindaian Selesai");
  if (n == 0) {
    Serial.println("Tidak ada jaringan Wi-Fi yang ditemukan.");
  } else {
    Serial.print(n);
    Serial.println(" jaringan Wi-Fi ditemukan:");
    for (int i = 0; i < n; ++i) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print("dBm)");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
      delay(10);
    }
  }
  Serial.println("");


  delay(5000); // Lakukan pemindaian setiap 5 detik
}
