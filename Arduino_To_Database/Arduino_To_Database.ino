#include <ESP8266WiFi.h>

//ssid name of your wifi
#define ssid "subham"

//password for your wifi
#define pass ""

//server ip or Your Domain
#define host "192.168.43.253"

//Port no
#define port 80

//Value to store in database
int value = 0;

void setup() {
  Serial.begin(9600);
  delay(10);

  Serial.print("Connecting to : ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("WiFi Connected");
  Serial.println("IP address : ");
  Serial.println(WiFi.localIP());
}

void loop() {
  delay(500);
  value += 1;

  Serial.print("Connecting to : ");
  Serial.println(host);

  //Creating a client which connect to server and send a request to it
  WiFiClient client;

  //Checking for client to connect to host
  if (!client.connect(host, port)) {
    Serial.println("Problem!!! No Connection");
    return;
  }

  Serial.println("Successful Connection");

  //Request url to send to server by the client
  String url = "/write_data.php?value=";
  url += value;

  Serial.print("Opening URL : ");
  Serial.println(url);
  // Sending the GET request to server to write the value data to database connected in write_data.php file.
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  Serial.println("");
  Serial.println("Successful Call");
  Serial.println("Closing Connection");

  delay(4000);

}
