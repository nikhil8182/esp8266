#include "onwords.h"



int lightGet( int _identification1){
  int lightStatus;
  String payload;

  WiFiClient client;
  HTTPClient http;
  String ip  = "http://192.168.1.18/";
  int id = _identification1;
  String slash = "/";
  String url = ip + id + slash;
  http.begin(client, url);
  int code = http.GET();
  // Serial.println(code);
  payload =  http.getString();
  DynamicJsonDocument doc(6000);
  DeserializationError error = deserializeJson(doc, payload);
  // Serial.println(payload);
  lightStatus = doc["Device_Status"];
  return lightStatus;
  http.end();


}


void lightPut( int _id,int Status){

  WiFiClient client;
  HTTPClient http;
  String ip  = "http://192.168.1.18/";
  int id = _id;
  String slash = "/";
  String url = ip + id + slash;
  http.begin(client, url);
  String a = "{\"Device_Status\":";
  String b = "}";
  //  String x = "false"
  http.addHeader("Content-Type", "application/json");
  int httpResponseCode = http.PUT(a + Status + b);
  //    Serial.println(httpResponseCode);
  http.end();
}
