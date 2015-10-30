#include "ESP8266WiFi.h"
#include <Ticker.h>
#include "Matrix32x32.h"
#include "PubNub.h"
#include "NTP.h"

extern const char* ssid2;
extern const char* password2;
extern const char* ssid1;
extern const char* password1;

extern const char* pubKey;
extern const char* subKey;

PubNub pubnub(pubKey, subKey);

Ticker tick;

void setup() {
  int loop = 0;
  // put your setup code here, to run once:
  //Serial.begin(115200);

  WiFi.begin(ssid1, password1);
  while ((WiFi.status() != WL_CONNECTED) && (loop++ < 20)) {
    delay(500);
    //Serial.print(".");
  }

if (WiFi.status() != WL_CONNECTED) {
  //Serial.print("2");
  WiFi.begin(ssid2, password2);

  loop=0;
  while ((WiFi.status() != WL_CONNECTED) && (loop++ < 20)) {
    delay(500);
    //Serial.print(".");
  }
}

  //pubnub.publish("Matrix", "\"OK\"");

  Ntp.sendNTPpacket(NTP::timeServer); // send an NTP packet to a time server

/*
  // Start the server
  server.begin();
  Serial.println("Server started");
*/

  M.init();
  // 0.0010 OK visuellement mini
  // 0.0015 OK visuellement
  // 0.0020 bof
  //tick.attach_ms(2, update);
  tick.attach(0.0015, update);

  // Print the IP address
  IPAddress ip = WiFi.localIP();
  //Serial.println(ip);
  //Serial.end();


  M.display(0, 0b00000111, "Fablab Robert-Houdin");
  //M.display(1, 0b00000100, "IP: "+ip);

}

//bool dosubscribe = 0;
int substate=0;
byte demult = 0;
void update()
{
  M.update();
  
  if (++demult > 100) {
    demult = 0;
    if (!M.write(0)) {
        String line = "  Fablab Robert-Houdin  ";
        //line = line + timetoken;
        M.display(0, 0b00000111, line); // White
    }
    
    if (!M.write(1)) {
      //dosubscribe = 1;
      substate = 1;
        //M.display(1, 0b00000100, "TBD...");
    }
    
    if (!M.write(3)) {
      char line[10];
      Ntp.update();
      //String t = "" + Ntp._h + ":" + Ntp._m + ":" + Ntp._s;
      strcpy(line, "__:__:__\0\0");
      int x;
      x = Ntp._h; // (t % 86400L) / 3600; // hour
      line[0] = '0'+(x/10);
      line[1] = '0'+(x % 10);
      x = Ntp._m; // (t % 3600) / 60; // min
      line[3] = '0'+(x/10);
      line[4] = '0'+(x % 10);
      x = Ntp._s; // (t % 60); // sec
      line[6] = '0'+(x/10);
      line[7] = '0'+(x % 10);
      M.display(3, 0b00000010, String(line)); // Green
    }
  }
}

WiFiClient subsciber;
void loop()
{
  if (!Ntp.parsed) {
    Ntp.checkPacket();
        M.display(1, 0b00000100, "Time OK"); // Blue
  } else {
      if (substate==1) {
        String line = pubnub.subscribe("Matrix");
        M.display(1, 0b00000001, line); // Red
        substate++;

/*
      } else if (substate==10) {
      if (subsciber.available()>1) {
          String line = subsciber.readString();
          //M.display(1, 0b00000100, "read:"+line.length());
          int l = line.length();
          int i = line.indexOf("\r\n\r\n");
          line = line.substring(i+4);
          line.substring(line.length()-19).toCharArray(timetoken, 18);
          timetoken[18] = '\0';
          M.display(1, 0b00000001, line); // Red
        substate++;
      } else {
        //M.display(1, 0b00000100, "tbd");
      }
*/
      
    }

/*
    if (substate==0) {
      //tick.detach();
      if (subsciber.connect("pubsub.pubnub.com", 80)) {
          subsciber.print("GET /subscribe/sub-c-27e78ea8-9b24-11e4-91be-02ee2ddab7fe/ESP/0/");
          subsciber.print(timetoken);
          subsciber.print(" HTTP/1.0\r\n\r\n");
        substate++;
        M.display(1, 0b00000100, "-"); // Blue
      }
      //tick.attach(0.0015, update);
    }
*/
  }

  


/*
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  //Serial.println("new client");
  while(!client.available()){
    delay(1);
  }

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  //Serial.println(req);
  // Copy request to line !!!
      //strcpy(line, req);
      // GET /msg=XXXX HTTP/1.1
      M.display(1, 0b00000001, req.substring(10, req.length()-8));
      
  client.flush();

  // Send the response to the client
  client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>");
  client.print("<form method='GET'>Message: <input type='text' name='msg'/></form>");
  client.print("</html>");
  //client.close();
*/
}



