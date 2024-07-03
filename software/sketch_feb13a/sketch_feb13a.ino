#include <WiFi.h>
#include <WebServer.h>



const char* ssid = "ssems";
const char* password = "12345678";

// Configure IP addresses of the local access point
IPAddress local_IP(192,168,1,22);
IPAddress gateway(192,168,1,5);
IPAddress subnet(255,255,255,0);


WebServer server(80); // 80 is the port number

WiFiClient client;

String increamentEmployee,decreamentEmployee,clientReclamation,accident;



void increamentEmployees()
{
  
  server.send(200, "text/html", increamentEmployee);
  Serial.print('i');
  delay(30);
  Serial.print('n');
  delay(30);
  Serial.println('c');
  
}

void decreamentEmployees()
{
  
  server.send(200, "text/html", decreamentEmployee);
  Serial.print('d');
  delay(30);
  Serial.print('e');
  delay(30);
  Serial.println('c');
  
}

void declare_an_accident()
{
  
  server.send(200, "text/html", accident);
  Serial.print('a');
  delay(30);
  Serial.print('c');
  delay(30);
  Serial.println('c');
  
}

void declare_a_client_reclamation()
{
  
  server.send(200, "text/html", clientReclamation);
  Serial.print('r');
  delay(30);
  Serial.print('e');
  delay(30);
  Serial.println('c');
}

void setup() {

  Serial.begin(115200);
  
  
  /*WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)delay(500);

  Serial.print(WiFi.localIP());*/

  /*WiFi.softAP(ssid, password); 

  Serial.println( "" );  
  Serial.println( "WiFi AP is now running" );  
  Serial.println( "IP address: " ); 
   
  Serial.println( WiFi.softAPIP() );*/

  Serial.print("Setting up Access Point ... ");
  Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");

  Serial.print("Starting Access Point ... ");
  Serial.println(WiFi.softAP(ssid, password) ? "Ready" : "Failed!");

  /*Serial.print("IP address = ");
  Serial.println(WiFi.softAPIP());*/

  server.on("/increamentEmployee", increamentEmployees);
  server.on("/decreamentEmployee", decreamentEmployees);
  server.on("/clientReclamation", declare_a_client_reclamation);
  server.on("/accident", declare_an_accident);

  server.begin();


}

void loop()
{
  server.handleClient();
  delay(1);
}
