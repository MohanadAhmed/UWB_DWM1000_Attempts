#include <SPI.h>
#include <DW1000.h>


// connection pins
const uint8_t PIN_RST = 9; // reset pin
const uint8_t PIN_IRQ = A3; // irq pin
const int PIN_SS = A5; // Chip select pin for SPI communication

const byte READ_DEV_ID = 0x00; // Opcode for reading device ID

void setup() {
  Serial.begin(9600); // Initialize serial communication
  delay(2000);
//  DW1000.begin(PIN_IRQ, PIN_RST);
  pinMode(PIN_SS, OUTPUT); // Set SS_PIN as output
  SPI.begin(); // Initialize SPI communication
  DW1000.select(PIN_SS);
  Serial.println("Start");
}


void loop() {
  char msgInfo[128];
  // byte dev_id[4]; // Create array to store device ID
  uint32_t dev_id;
  byte* data = (byte*) &dev_id;

  digitalWrite(PIN_SS, LOW); // Select DWM1000 module
  SPI.transfer(READ_DEV_ID); // Send opcode to read device ID

  for(int i=0; i<4; i++) {
    data[i] = SPI.transfer(0x00); // Read device ID byte by byte
  }
  digitalWrite(PIN_SS, HIGH); // Deselect DWM1000 module
  Serial.print("Device ID using direct approach: ");
  Serial.println(dev_id, HEX);
 
  DW1000.getPrintableDeviceIdentifier(msgInfo);
  Serial.print("Device ID using library function: "); Serial.println(msgInfo);
  
  Serial.println();
  delay(2000); // Wait for a second before reading again
}
