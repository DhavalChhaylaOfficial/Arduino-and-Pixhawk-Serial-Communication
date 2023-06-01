#include <SoftwareSerial.h>

// Create a SoftwareSerial object for communication with Pixhawk
SoftwareSerial pixhawkSerial(10, 11); // RX, TX

void setup() {
  // Initialize Arduino's primary serial port for communication with the serial monitor
  Serial.begin(115200);
  
  // Initialize secondary serial port (SoftwareSerial) for communication with Pixhawk
  pixhawkSerial.begin(57600);

  // Wait for the serial ports to initialize
  delay(1000);
}

void loop() {
  // Send a test message from Arduino to Pixhawk
  sendMessage("Hello Pixhawk!");

  // Receive messages from Pixhawk
  while (pixhawkSerial.available()) {
    String receivedMessage = readMessage();
    Serial.println("Received message from Pixhawk: " + receivedMessage);
  }

  delay(1000);
}

void sendMessage(String message) {
  pixhawkSerial.println(message);
}

String readMessage() {
  String message = "";
  while (pixhawkSerial.available()) {
    char character = pixhawkSerial.read();
    message += character;
    delayMicroseconds(100);
  }
  return message;
}
