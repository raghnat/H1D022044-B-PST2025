
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>

const char* ssid = "redmi note 8";       // Nama SSID AP/Hotspot
const char* password = "rabc12345";    // Password Wifi
int LED1 = D1;
int LED2 = D2;
int LED3 = D3;

// const char* sta_ssid = "TEKNIK UNSOED D3 5G";
// const char* sta_password = ""; 

ESP8266WebServer server(80);      //Menyatakan Webserver pada port 80
String webpage;
 
void setup() {
  Serial.begin(9600);
  delay(10);
 
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
 
// Connect to WiFi network ------------------------------------------------
  Serial.println();
  Serial.print("Configuring access point...");
 
// Mengatur WiFi ----------------------------------------------------------
  WiFi.mode(WIFI_AP);                      // Mode Station
  WiFi.begin(ssid, password);               // Mencocokan SSID dan Password
  Serial.print("Access Point SSID: ");
  Serial.println(WiFi.softAPSSID());

// Print status Connect --------------------------------------------------- 
  Serial.println("IP address: ");
  Serial.println(WiFi.softAPIP());
 
// Isi dari Webpage -------------------------------------------------------
  webpage+= "<h1> Web Control ESP8266</h1>";
  webpage+= "<h1> Rayhan Aghnat </h1>";
  webpage+= "<p>LED 1 : ";
  webpage+= "<a href=\"LED1ON\"\"><button>ON</button></a><a href=\"LED1OFF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p>LED 2 : ";
  webpage+= "<a href=\"LED2ON\"\"><button>ON</button></a><a href=\"LED2OFF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p>LED 3 : ";
  webpage+= "<a href=\"LED3ON\"\"><button>ON</button></a><a href=\"LED3OFF\"\"><button>OFF</button></a></p>";
          
// Membuat tampilan Webpage -----------------------------------------------
  server.on("/", []() {
    server.send(200, "text/html", webpage);
   });
 
// Bagian ini untuk merespon perintah yang masuk --------------------------
  server.on("/LED1ON", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(LED1,HIGH);
    delay(1000);
  });
  server.on("/LED2ON", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(LED2,HIGH);
    delay(1000);
  });
  server.on("/LED3ON", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(D2,HIGH);
    delay(1000);
  });
  server.on("/LED1OFF", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(LED1,LOW);
    delay(1000);
  });
  server.on("/LED2OFF", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(LED2,LOW);
    delay(1000);
  });
  server.on("/LED3OFF", []() {
    server.send(200, "text/html", webpage);
    digitalWrite(LED3,LOW);
    delay(1000);
  });
 
  server.begin();
  Serial.println("Webserver dijalankan");
}
 
void loop() {
   server.handleClient();
}
