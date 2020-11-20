// Load Wi-Fi library
#include <WiFi.h>
#include <WebServer.h>
#include "DHT.h"

// Uncomment one of the lines below for whatever DHT sensor type you're using!
#define DHTTYPE DHT11   // DHT 11
// Replace with your network credentials
const char* ssid = "INFINITUM460F_2.4";  // Enter SSID here
const char* password = "2XeELbf64H";  //Enter Password here

// Set web server port number to 80
WiFiServer server(80);
// DHT Sensor
uint8_t DHTPin = 4; 
               
// Initialize DHT sensor.
DHT dht(DHTPin, DHTTYPE);                

float Temperature;
float Humidity;
// Variable to store the HTTP request
String header;

// Auxiliar variables to store the current output state
String output18State = "off";
String output19State = "off";
String output20State = "off";
String output21State = "off";
String output22State = "off";
// Assign output variables to GPIO pins
const int output18 = 18;
const int output19 = 19;
const int output20 = 12;
const int output21 = 21;
const int output22 = 22;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
    pinMode(DHTPin, INPUT);

  // Initialize the output variables as outputs
  pinMode(output18, OUTPUT);
  pinMode(output19, OUTPUT);
    pinMode(output20, OUTPUT);
  pinMode(output21, OUTPUT);
    pinMode(output22, OUTPUT);

  // Set outputs to LOW
  digitalWrite(output18, LOW);
  digitalWrite(output19, LOW);
  digitalWrite(output20, LOW);
  digitalWrite(output21, LOW);
    digitalWrite(output22, LOW);

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /18/on") >= 0) {
              Serial.println("GPIO 18 on");
              output18State = "on";
              digitalWrite(output18, HIGH);
            } else if (header.indexOf("GET /18/off") >= 0) {
              Serial.println("GPIO 18 off");
              output18State = "off";
              digitalWrite(output18, LOW);
            } else if (header.indexOf("GET /19/on") >= 0) {
              Serial.println("GPIO 19 on");
              output19State = "on";
              digitalWrite(output19, HIGH);
            } else if (header.indexOf("GET /19/off") >= 0) {
              Serial.println("GPIO 19 off");
              output19State = "off";
              digitalWrite(output19, LOW);
            } else if (header.indexOf("GET /20/on") >= 0) {
              Serial.println("GPIO 20 on");
              output20State = "on";
              digitalWrite(output20, HIGH);
            } else if (header.indexOf("GET /20/off") >= 0) {
              Serial.println("GPIO 20 off");
              output20State = "off";
              digitalWrite(output20, LOW);
            } else if (header.indexOf("GET /21/on") >= 0) {
              Serial.println("GPIO 21 on");
              output21State = "on";
              digitalWrite(output21, HIGH);
            } else if (header.indexOf("GET /21/off") >= 0) {
              Serial.println("GPIO 21 off");
              output21State = "off";
              digitalWrite(output21, LOW);
            } else if (header.indexOf("GET /22/on") >= 0) {
              Serial.println("GPIO 22 on");
              output22State = "on";
              digitalWrite(output22, HIGH);
            } else if (header.indexOf("GET /22/off") >= 0) {
              Serial.println("GPIO 22 off");
              output22State = "off";
              digitalWrite(output22, LOW);
            } 
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>ESP32 Web Server</h1>");
            
            // Display current state, and ON/OFF buttons for GPIO 18  
            client.println("<p>GPIO 18 - State " + output18State + "</p>");
            // If the output18State is off, it displays the ON button       
            if (output18State=="off") {
              client.println("<p><a href=\"/18/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/18/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO 19  
            client.println("<p>GPIO 19 - State " + output19State + "</p>");
            // If the output19State is off, it displays the ON button       
            if (output19State=="off") {
              client.println("<p><a href=\"/19/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/19/off\"><button class=\"button button2\">OFF</button></a></p>");
            }


            client.println("<p>GPIO 20 - State " + output20State + "</p>");
            if (output20State=="off") {
              client.println("<p><a href=\"/20/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/20/off\"><button class=\"button button2\">OFF</button></a></p>");
            }


            client.println("<p>GPIO 21 - State " + output21State + "</p>");
            if (output21State=="off") {
              client.println("<p><a href=\"/21/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/21/off\"><button class=\"button button2\">OFF</button></a></p>");
            }


            client.println("<p>GPIO 22 - State " + output22State + "</p>");
            if (output22State=="off") {
              client.println("<p><a href=\"/22/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/22/off\"><button class=\"button button2\">OFF</button></a></p>");
            }



            Temperature = dht.readTemperature(); // Gets the values of the temperature
            Humidity = dht.readHumidity(); // Gets the values of the humidity 
            client.println("<div id=\"webpage\">\n<h1>ESP32 Weather Report</h1>\n<p>Temperature: " + String((int)Temperature) + "°C</p><p>Humidity: "+String((int)Humidity) + "%</p></div>\n");
           
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}