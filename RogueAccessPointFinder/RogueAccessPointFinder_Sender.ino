#include <ESP8266WiFi.h>

#include <espnow.h>
int numberOfNetworks;
// REPLACE WITH RECEIVER MAC Address
uint8_t broadcastAddress[] = { 0xE8, 0xDB, 0x84, 0xDD, 0x42 , 0x39};
// Set your Board ID (ESP32 Sender #1 = BOARD_ID 1, ESP32 Sender #2 = BOARD_ID 2,
etc)
#define BOARD_ID 2
// Structure example to send data
// Must match the receiver structure
typedef struct struct_message {
int id;
int r;
int a;
} struct_message;
// Create a struct_message called test to store variables to be sent
struct_message myData;
const char* ssid = "ssid"; //Enter SSID
const char* password = "password"; //Enter Password

// Callback when data is sent
void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
Serial.print("\r\nLast Packet Send Status: ");
if (sendStatus == 0){
Serial.println("Delivery success");
}
else{
Serial.println("Delivery fail");
}
}
void setup() {
// Init Serial Monitor
Serial.begin(115200);
// Set device as a Wi-Fi Station
WiFi.mode(WIFI_STA);
WiFi.disconnect();
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED)
{
delay(500);
Serial.print("*");

}
// Init ESP-NOW
if (esp_now_init() != 0) {
Serial.println("Error initializing ESP-NOW");
return;
}
// Set ESP-NOW role
esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
// Once ESPNow is successfully init, we will register for Send CB to
// get the status of Trasnmitted packet
esp_now_register_send_cb(OnDataSent);
// Register peer
esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}
void loop() {
myData.id = BOARD_ID;
myData.a = 0;
//numberOfNetworks = WiFi.scanNetworks();

Serial.println(myData.r);
esp_now_send(0, (uint8_t *) &myData, sizeof(myData));
//*pow(10,(17.5-(20*log10(2412))+abs(rssi))/20)
}