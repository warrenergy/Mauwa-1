#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <SoftwareSerial.h>
#include <secrets.h>

ESP8266WebServer server(80);
SoftwareSerial wifiSerial(7, A0);
SoftwareSerial arduinoSerial(D2, D1);


void setup() {
  Serial.begin(115200);
  Serial.println("DEBUT");
  WiFi.begin(ssid, password);
  arduinoSerial.begin(9600);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println("...");
  }
  Serial.println();
  Serial.print("Connected ! Adresse IP: ");
  Serial.println(WiFi.localIP());
server.on("/", []() {

  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Robot Controller</title>
</head>
<body>
<h1>Robot Controller</h1>
<p>
<button onclick="sendCommand('/forward')">Fahren</button>
</p>
<p>
<button onclick="sendCommand('/left')">Links</button>
<button onclick="sendCommand('/stop')">Stop</button>
<button onclick="sendCommand('/right')">Rechts</button>
</p>
<p>
<button onclick="sendCommand('/back')">Rueckfahren</button>
</p>
<p>
<button onclick="sendCommand('/manual')">Manuell</button>
<button onclick="sendCommand('/auto')">Automatik</button>
</p>

<script>

      function sendCommand(command) {

        fetch(command);

      }
</script>
</body>
</html>

  )rawliteral";

  server.send(200, "text/html", page);

});
 
 
    server.on("/forward", []() {
  Serial.println("Commande : FORWARD");
  arduinoSerial.write('F');
    server.send(200, "text/plain", "FORWARD");
  });
    server.on("/back", []() {
  Serial.println("Commande : BACK");
  arduinoSerial.write('B');
    server.send(200, "text/plain", "BACK");
  });
    server.on("/left", []() {
  Serial.println("Commande : LEFT");
  arduinoSerial.write('L');
    server.send(200, "text/plain", "LEFT");
  });
    server.on("/right", []() {
  Serial.println("Commande : RIGHT");
  arduinoSerial.write('R');
    server.send(200, "text/plain", "RIGHT");
  });
  server.on("/stop", []() {
  Serial.println("Commande : STOP");
  arduinoSerial.write('S');
   server.send(200, "text/plain", "STOP");
  });
  //Modus auswählen
    server.on("/manual", []() {
  Serial.println("Commande : MANUELL");
  arduinoSerial.write('M');
    server.send(200, "text/plain", "MANUELL");
  });
    server.on("/auto", []() {
  Serial.println("Commande : AUTOMATIK");
  arduinoSerial.write('A');
    server.send(200, "text/plain", "AUTOMATIK");
  });
  server.begin();
}

void loop() {
  server.handleClient();
  if (wifiSerial.available()){
    char commande = wifiSerial.read();
    Serial.print("Erhalten: ");
    Serial.println(commande);
  }
}
