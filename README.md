# RFID Based System Access Control System

## 📖 Project Overview
The RFID Based System Access Control System is a security project developed using an Arduino Uno and the MFRC522 RFID module. It allows only authorized RFID cards to access the system. When a valid RFID tag is scanned, the system grants access by turning on a green LED. If an unauthorized card is scanned, access is denied, and a red LED indicates rejection.

This project demonstrates the practical use of RFID technology for secure access control in homes, offices, laboratories, and educational institutions.

---

## ✨ Features
- RFID-based authentication
- Authorized and unauthorized card detection
- Green LED indicates access granted
- Red LED indicates access denied
- Fast and reliable card verification
- Easy to modify by adding new RFID card IDs

---

## 🛠 Hardware Requirements
- Arduino Uno
- MFRC522 RFID Reader
- RFID Tags/Cards
- Green LED
- Red LED
- Resistors
- Jumper Wires
- Breadboard
- USB Cable

---

## 💻 Software Requirements
- Arduino IDE
- MFRC522 Library
- SPI Library

---

## 🔌 Circuit Connections

| MFRC522 Pin | Arduino Uno Pin |
|-------------|-----------------|
| SDA (SS) | D10 |
| SCK | D13 |
| MOSI | D11 |
| MISO | D12 |
| RST | D9 |
| GND | GND |
| 3.3V | 3.3V |

### LEDs
- Green LED → D7
- Red LED → D6

---

## ⚙️ How It Works

1. The Arduino initializes the RFID reader.
2. The user scans an RFID card.
3. The system reads the card's unique UID.
4. The UID is compared with the authorized UID stored in the program.
5. If the UID matches:
   - Green LED turns ON.
   - Access is granted.
6. If the UID does not match:
   - Red LED turns ON.
   - Access is denied.

---

## 📁 Project Structure

```
RFID-Based-System-Access-Control-System/
│── RFID_Based_Access_Control.ino
│── code.docx
│── report.docx
│── README.md
```

---

## 🚀 Applications

- Office Access Control
- College Laboratories
- Library Entry Systems
- Home Security
- Attendance Systems
- Restricted Area Access

---

## 🔮 Future Enhancements

- LCD Display Integration
- Buzzer Notification
- Servo Motor Door Lock
- IoT-based Remote Monitoring
- Cloud Database Integration
- Mobile App Control

---

## 📸 Project Images

You can add:
- Circuit Diagram
- Hardware Setup
- Working Demonstration
- Arduino Connections

---

## 👩‍💻 Author

**Safa Fathima**

Bachelor of Engineering (Computer Engineering)

KVG College of Engineering

Visvesvaraya Technological University (VTU)

---

## 📜 License

This project is developed for educational and learning purposes.
