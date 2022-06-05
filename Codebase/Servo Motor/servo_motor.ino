/*****************************************************
 * SERVO MOTOR CONFIG CODE
 * Author: Bhavesh Asanabada
 * Micro-controller: NodeMCU
* ***************************************************/

// <-------- Initialize required libraries (Begin) --------> 
#include <ESP8266WiFi.h>
#include <Servo.h>
// <-------- Initialize required libraries (END) -------->

Servo servo;
 
const char* ssid = "Your WiFi ID";
const char* password = "Enter WiFi password";  

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
  servo.attach(2); //Gpio-2 of nodemcu with pwm pin of servo motor
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address on serial monitor
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");    //URL IP to be typed in mobile/desktop browser
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  int value = 0;
  // Match the request

  if (request.indexOf("/Req=0") != -1)  {
    servo.write(0); //Moving servo to 0 degree
    value=0;
  }
  if (request.indexOf("/Req=20") != -1)  {
    servo.write(20); //Moving servo to 0 degree
    value=20;
  }
  if (request.indexOf("/Req=40") != -1)  {
    servo.write(40); //Moving servo to 0 degree
    value=40;
  }
  if (request.indexOf("/Req=60") != -1)  {
    servo.write(60); //Moving servo to 0 degree
    value=60;
  }
  if (request.indexOf("/Req=80") != -1)  {
    servo.write(80); //Moving servo to 0 degree
    value=80;
  }
  if (request.indexOf("/Req=90") != -1)  {
    servo.write(90); //Moving servo to 0 degree
    value=90;
  }
  if (request.indexOf("/Req=120") != -1)  {
    servo.write(120); //Moving servo to 0 degree
    value=120;
  }
  if (request.indexOf("/Req=140") != -1)  {  
    servo.write(140); //Moving servo to 90 degree
    value=140;
  }
  if (request.indexOf("/Req=160") != -1)  { 
    servo.write(160); //Moving servo to 180 degree
    value=160;
  }
  if (request.indexOf("/Req=180") != -1)  {
    servo.write(180); //Moving servo to 0 degree
    value=180;
  }

  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<h1 align=center>Positioning the receiver module over WiFi</h1><br><br>");
  client.print("<align=center>Current position =");
  client.print(value); 
  client.println("<br><br>");
  client.println("<a href=\"/Req=0\"\"><button>Move to = 0 degree</button></a>");
  client.println("<a href=\"/Req=20\"\"><button>Move to = 20 degree</button></a>");
  client.println("<a href=\"/Req=40\"\"><button>Move to = 40 degree</button></a>");
  client.println("<a href=\"/Req=60\"\"><button>Move to = 60 degree</button></a>");
  client.println("<a href=\"/Req=80\"\"><button>Move to = 80 degree</button></a>");
  client.println("<a href=\"/Req=120\"\"><button>Move to = 120 degree</button></a>");
  client.println("<a href=\"/Req=140\"\"><button>Move to = 140 degree</button></a>");
  client.println("<a href=\"/Req=160\"\"><button>Move to = 160 degree</button></a>");
  client.println("<a href=\"/Req=180\"\"><button>Move to = 180 degree</button></a><br/>");

  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
