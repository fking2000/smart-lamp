
// libraries we use
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

IPAddress    apIP(55, 55, 55, 55);
const char* ssid = "MySmartHub"; 
const char* password = "88888888";

ESP8266WebServer server(80);

void wifi_Setup() {
    //set-up the custom IP address
    WiFi.mode(WIFI_AP_STA);
    WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));   // subnet FF FF FF 00  

    /* You can remove the password parameter if you want the AP to be open. */
    WiFi.softAP(ssid, password);
   // WiFi.softAP(ssid, password);
   WiFi.softAP(ssid);
    Serial.print("creating ssid=");
    Serial.println(ssid);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
    server.on("/", handleRoot);
    server.onNotFound(handleNotFound);
    server.begin();
    Serial.println("HTTP server started");
}

void wifi_loop() {
    server.handleClient();//.server is defined at this tab
    delay(10);
}
void handleNotFound() {
    String message = "File Not Found\n\n";
    message += "URI: ";
    message += server.uri();
    message += "\nMethod: ";
    message += (server.method() == HTTP_GET) ? "GET" : "POST";
    message += "\nArguments: ";
    message += server.args();
    message += "\n";

    for (uint8_t i = 0; i < server.args(); i++) {
        message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
    }

    server.send(404, "text/plain", message);
}

void handleRoot() {
  
  String set;
if (server.hasArg("pro")) {
     set=server.arg("pro");
        color_converter(set);
        } 
    if (server.hasArg("stop")) {
       digitalWrite(red,LOW);
          digitalWrite(green,LOW);
              digitalWrite(blue,LOW);
        }
   
    char tmp[3];
    char html[2000];
    strcat(html, "<html>");
    strcat(html, "<head>");
 // strcat(html, "<meta http-equiv=\"refresh\" content=\"3; URL=/\">");
    strcat(html, "<meta charset='UTF-8'>");
    strcat(html, "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
    strcat(html, "<meta http-equiv=\"X-UA-Compatible\" content=\"ie=edge\">");
    strcat(html, "<title>My Smart Hub</title>");
    strcat(html, "<style>");
    strcat(html, ".f,.B{width: 46%;margin: 1%;padding: 1%;}");
    strcat(html, ".f{ margin - left: 0; margin - right: 4 %; background - color: pink; }");
    strcat(html, ".B{ margin - right: 0; background - color: springgreen; }");
    strcat(html, ".stop{ width:98 %; padding: 2 % 0; text - align: center; }");
    strcat(html, "</style>");
    strcat(html, "</head>");
    strcat(html, "<body>");
    strcat(html, "<h2>set color of led: </h2>");
    strcat(html, "<form action = \"\" method = \"get\">");
    strcat(html, "<input name = \"pro\" value=\"#ff0000\" type=\"color\">");
    strcat(html, "<input type=\"submit\">");
    strcat(html, "<button name = \"stop\">stop</button>");
    strcat(html, "</form>"); 
    strcat(html, "</body>");
    strcat(html, "</html>");
    server.send(200, "text/html", html);
}
