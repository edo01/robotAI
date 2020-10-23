/*
 * PROGETTO ROBOT INTELLIGENTE
 * 
 * Sviluppato da Giacomo Pieri, Luca Ferrari, Edoardo Carrà.
 */
#include <ESP8266WiFi.h>

#include "motor.h"

  
short robotID = 1; 
  
const char ssid[] = "";
const char pass[] = ""; 

const int port = 8080;
  
// Creazione di un server in ascolto sulla porta 80 
WiFiServer server(port);  

int pinLed = LED_BUILTIN;

void setup(){
  Serial.begin(115200);     
  delay(10);  

  pinMode(pinLed, OUTPUT);           
  digitalWrite(pinLed, LOW);
  
  // Connessione alla rete WiFi  
  Serial.println();  
  Serial.println();  
  Serial.println("------------- Avvio connessione ------------");  
  Serial.print("Tentativo di connessione alla rete: ");  
  Serial.println(ssid);  
  
  /*  
   * Il WeMos è settato come wifi station 
   */  
    
  WiFi.mode(WIFI_STA);  
  
  WiFi.begin(ssid, pass);  
  
  /*  
   *  fino a quando lo non si è connessi alla WiFi 
   *  compariranno a distanza di 250 ms dei puntini che 
   *  evidenziano lo stato di avanzamento della connessione 
  */    
  while (WiFi.status() != WL_CONNECTED) {  
    delay(250);  
    Serial.print(".");  
  }  
  
  // se connesso alla WiFi stampa sulla serial monitor  
  // nome della rete e stato di connessione  
  Serial.println("");  
  Serial.print("Connessione riuscita alla rete: ");  
  Serial.println(ssid);  
  Serial.println("WiFi connessa");  
  
  // Avvia il server  
  server.begin();  
  Serial.print("Server in ascolto sulla porta: ");
  Serial.println(port);  
  
  // Stampa l'indirizzo IP  
  Serial.print("IP ATTUALE :");   
  Serial.println(WiFi.localIP()); // Restituisce i'IP della scheda  
 
  // Avvio del sistema
  digitalWrite(pinLed, LOW);
  setPins();
  setPower(200);
  stopMotors();
}

/*
_____________________________________________________________________
_____________________________________________________________________
_____________________________________________________________________
_____________________________loop____________________________________
_____________________________________________________________________
_____________________________________________________________________
_____________________________________________________________________
*/

void loop(){
  // Aspetta che il client sia connesso 
  WiFiClient client = server.available();  
  if (!client) {  
    return;  
  }  
  
  // Aspetta fino a quando il client invia dei dati  
  Serial.println("Nuova richiesta");  
  while (!client.available()) {  
    delay(1);  
  }  
  
  // Legge la prima richiesta  
    
  /*  
   * readStringUntil() legge i caratteri dallo stream 
   * fino a quando non riceve il carattere \r 
   * oppure si verivica un time out 
   */  
     
  String request = client.readStringUntil('\r');  
  Serial.println(request);  
  client.flush(); // svuota il buffer

  //TODO: pulisci la richiesta
  
  // Verifica quale richiesta e' stata fatta  
  if (request == "f") forward();
  else if(request == "b") backward();
  else if(request == "s") stopMotors();
  else if(request == "r") right();
  else if(request == "l") left();
  else stopMotors();

  
  /*
	risposta al client 
	client.println("something");  
  */
  delay(1);   
}
