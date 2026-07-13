#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9      // MFRC522 reset pin
#define SS_PIN          10     // MFRC522 SDA/SS pin

#define GREEN_LED       7      // Access granted (D7)
#define RED_LED         6      // Access denied (D6)

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

// Authorized UID (RFID Tag): D0 73 37 5F
byte authorizedUID[] = {0xD0, 0x73, 0x37, 0x5F};

void setup() {
  Serial.begin(9600);     // Start serial communication
  SPI.begin();            // Init SPI bus
  mfrc522.PCD_Init();     // Init RFID reader
  Serial.println("Scan RFID Card/Tag...");

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
}

void loop() {
  // Wait for new card
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;

  Serial.print("Scanned UID: ");
  printUID(mfrc522.uid.uidByte, mfrc522.uid.size);

  // Check UID
  if (isAuthorized(mfrc522.uid.uidByte, mfrc522.uid.size)) {
    Serial.println("✅ ACCESS GRANTED");
    Serial.println("Green LED ON (D7)");
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  } else {
    Serial.println("❌ ACCESS DENIED");
    Serial.println("Red LED ON (D6)");
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }

  delay(5000);

  // Turn LEDs off after delay
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  Serial.println("LEDs OFF");
  Serial.println("--------------------------------");

  mfrc522.PICC_HaltA();     // Stop reading
  mfrc522.PCD_StopCrypto1();
}

// Print UID
void printUID(byte *uid, byte length) {
  for (byte i = 0; i < length; i++) {
    if (uid[i] < 0x10) Serial.print("0");
    Serial.print(uid[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
}

// Check UID
bool isAuthorized(byte *uid, byte length) {
  if (length != 4) return false;
  for (byte i = 0; i < 4; i++) {
    if (uid[i] != authorizedUID[i]) return false;
  }
  return true;
}