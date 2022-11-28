//引入头文件 Arduino ESP8266 ESPAsyncTCP ESPAsyncWebServer 需要相关库
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h> 
#include <WiFiClient.h>

//WIFI名和密码
const char* ssid     = "ESP8266-Access-Point";
const char* password = "123456789";

//在80端口创建AsyncWebServer对象
//AsyncWebServer server(80);

ESP8266WebServer server(80);


const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>

</body>
</html>
)=====";

void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

void setup(){
  Serial.begin(115200);

IPAddress wifi_ap_ip = IPAddress(192,168,0,1);
IPAddress wifi_ap_gw = IPAddress(192,168,0,1);
IPAddress wifi_ap_sn = IPAddress(255,255,255,0);

WiFi.softAPConfig(wifi_ap_ip, wifi_ap_gw, wifi_ap_sn);
WiFi.mode(WIFI_AP);

server.on("/", handleRoot);
server.begin();

}

 //在loop中循环点亮LED
void loop(){ 
  server.handleClient();
}
