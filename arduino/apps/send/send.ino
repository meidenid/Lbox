#include <XBee.h>

XBee xbee = XBee();
uint8_t sendDataT[] = { 'T' };
uint8_t sendDataS[] = { 'S' };

XBeeAddress64 allAddress = XBeeAddress64(0x00000000, 0x0000ffff);
ZBTxRequest T = ZBTxRequest(allAddress, sendDataT, sizeof(sendDataT));
ZBTxRequest S = ZBTxRequest(allAddress, sendDataS, sizeof(sendDataS));

int p;

void setup() {
  Serial.begin(9600);
  xbee.setSerial(Serial);
}

void loop() {
  while (Serial.available() > 0) {
    p = Serial.read();
    if (p == 'T') { xbee.send(T); }
    else if (p == 'S') { xbee.send(S); }
  }
}
