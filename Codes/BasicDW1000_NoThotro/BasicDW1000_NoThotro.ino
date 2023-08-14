#include <SPI.h>

// connection pins
const uint8_t PIN_RST = 9; // reset pin
const uint8_t PIN_IRQ = A3; // irq pin
const int PIN_SS = A5; // Chip select pin for SPI communication
const byte READ_DEV_ID = 0x00; // Opcode for reading device ID

const SPISettings fastSPI = SPISettings(2000000L, MSBFIRST, SPI_MODE0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Starting to Talk to DW1000 ... ");
  pinMode(PIN_SS, OUTPUT);
  SPI.begin();
  SPI.beginTransaction(fastSPI);
  SPI.endTransaction();
}

// device id register
#define DEV_ID 0x00
#define LEN_DEV_ID 4

// extended unique identifier register
#define EUI 0x01
#define LEN_EUI 8


void loop() {
  // put your main code here, to run repeatedly:
  uint32_t dev_id;
  uint32_t euid[2];
  byte* data = (byte*) &dev_id;
  byte* data2 = (byte*) &euid;

  digitalWrite(PIN_SS, LOW); // Select DWM1000 module
  SPI.transfer(READ_DEV_ID); // Send opcode to read device ID
  for(int i=0; i<LEN_DEV_ID; i++) {
    data[i] = SPI.transfer(0x00); // Read device ID byte by byte
  }
  digitalWrite(PIN_SS, HIGH); // Deselect DWM1000 module
  delay(10);
  digitalWrite(PIN_SS, LOW); // Select DWM1000 module
  SPI.transfer(EUI); // Send opcode to read device ID
  for(int i=0; i<LEN_EUI; i++) {
    data2[i] = SPI.transfer(0x00); // Read device ID byte by byte
  }
  digitalWrite(PIN_SS, HIGH);

  Serial.print("Device ID using direct approach: ");
  Serial.println(dev_id, HEX);

  Serial.print("Extended Device: ");
  Serial.println(euid[0], HEX);
  Serial.println(euid[1], HEX);
  delay(500);
}
