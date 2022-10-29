/*
  PIN CONNECTIONS
  -------------------------------
  -------------------------------
  -------------------------------

*/

//= DEFINES ========================================================================================
#if defined(ESP8266)
// interrupt handler and related code must be in RAM on ESP8266, according to issue #46.
#define RECEIVE_ATTR ICACHE_RAM_ATTR
#define VAR_ISR_ATTR
// pins
#define ESP8266_GPIO0 0  // HIGH is 3.3V
#define ESP8266_GPIO1 1  // TX
#define ESP8266_GPIO2 2  // HIGH is 3.3V
#define ESP8266_GPIO3 3  // RX
// Built-In LED: LOW is on and HIGH is off for blue led
#define LED_BUILTIN ESP8266_GPIO2
#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define DEBUG

#define SEC 1000  // 1 second

//= INCLUDES =======================================================================================
#include <AD9833.h>


//= CONSTANTS ======================================================================================
const int LED_INDICATOR_PIN = LED_BUILTIN;  // choose the pin for the LED


//= VARIABLES ======================================================================================
AD9833 gen(10);


//==================================================================================================
//**************************************************************************************************
void setup() {
#ifdef DEBUG
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  Serial.println(":Setup >>>");
#endif
  //..............................
  // initialize digital pin LED_INDICATOR_PIN as an output.
  pinMode(LED_INDICATOR_PIN, OUTPUT);
  //..............................
#ifdef DEBUG
  Serial.println(">>> :Setup");
#endif
}
//**************************************************************************************************
//==================================================================================================
void loop() {
  // put your main code here, to run repeatedly
  ledState = HIGH;
  digitalWrite(LED_INDICATOR_PIN, ledState);
  delay(1 * SEC);

  ledState = LOW;
  digitalWrite(LED_INDICATOR_PIN, ledState);
  delay(4 * SEC);
}
//==================================================================================================