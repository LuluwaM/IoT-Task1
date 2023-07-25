#include <WiFi.h>
#include <HTTPClient.h> 

const char* ssid = "Wokwi-GUEST"; 
const char* password = "";

const String url ="http://localhost/task1_iot/backward.html";
String payload = ""; 

void setup() {
  Serial.begin(115200); 
  WiFi.begin(ssid, password); 
  pinMode(25, OUTPUT);  
  Serial.print("Connecting to WiFi");

   while(WiFi.status() != WL_CONNECTED){
     delay(500); 
     Serial.print("."); 
    }
     Serial.print("OK! IP="); 
     Serial.println(WiFi.localIP()); 
     Serial.print("Fetching "+ url + "...");
}

void loop(){
  HTTPClient http;
  http.begin(url);
  int httpCode=http.GET();
  if (httpCode >0){
    Serial.print("HTTP ");
    Serial.print(httpCode);
    payload=http.getString();
    Serial.println();
    Serial.println(payload);
    if(payload=="found"){
      digitalWrite(25, HIGH);
    }else {
      digitalWrite(25, LOW);
    }
  }
  else{
    Serial.print("Error code:");
    Serial.println(httpCode);
    Serial.println(" :(");
  }
}
