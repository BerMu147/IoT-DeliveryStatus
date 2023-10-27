// #include <Arduino.h>
#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#endif
#include <Firebase_ESP_Client.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <Adafruit_GFX.h>
#include <HttpClient.h>

// Provide the token generation process info.
#include "addons/TokenHelper.h"
// Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "OG Kolijevka"
#define WIFI_PASSWORD "gengstapasvord"

// Insert Firebase project API Key
#define API_KEY "AIzaSyAm6iQzjDz1E7S-GqrqX0X2Ajt03fQnI54"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://arduinotest-4702d-default-rtdb.europe-west1.firebasedatabase.app/"

// Define Firebase Data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int count = 0;
bool signupOK = false;

ESP8266WebServer server(3000);

int led1 = D1;
int led2 = D3;
int led3 = D7;

// == FIREBASE AND TESTING == //

void setup()
{
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", ""))
  {
    Serial.println("ok");
    signupOK = true;
  }
  else
  {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop()
{
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 7000 || sendDataPrevMillis == 0))
  {
    sendDataPrevMillis = millis();
    // Write an Int number on the database path test/int
    if (Firebase.RTDB.setInt(&fbdo, "test/int", count))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    count++;

    // Write an Float number on the database path test/float
    if (Firebase.RTDB.setFloat(&fbdo, "test/float", 0.01 + random(0, 100)))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }

    // Read status from Firebase
    Firebase.RTDB.getBool(&fbdo, "LED/led_1/turnedOn");
    boolean led_1 = fbdo.boolData();
    Firebase.RTDB.getBool(&fbdo, "LED/led_2/turnedOn");
    boolean led_2 = fbdo.boolData();
    Firebase.RTDB.getBool(&fbdo, "LED/led_3/turnedOn");
    boolean led_3 = fbdo.boolData();

    //Log led status
    Serial.println("LED_1:" + String(led_1));
    Serial.println("LED_2:" + String(led_2));
    Serial.println("LED_3:" + String(led_3));

    //Toggle LED lights
    digitalWrite(led1, led_1 ? LOW : HIGH);
    digitalWrite(led2, led_2 ? LOW : HIGH);
    digitalWrite(led3, led_3 ? LOW : HIGH);
  }
}
