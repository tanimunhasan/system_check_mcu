
// Define system states using an enumeration
typedef enum {
  STATE_INIT,
  STATE_RUNNING,
  STATE_ERROR
} SystemState;

// Define a structure to hold the system state and LED pin
typedef struct {
  SystemState state;
  int ledPin;
} SystemInfo;

SystemInfo systemInfo;  // Create an instance of SystemInfo

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Initialize the system info
  systemInfo.state = STATE_INIT;
  systemInfo.ledPin = 13;  // Use the built-in LED pin on Arduino

  // Initialize the LED pin as an output
  pinMode(systemInfo.ledPin, OUTPUT);

  // Update the system state
  updateSystemState(STATE_INIT);
}

void loop() {
  // Example logic to change states
  if (systemInfo.state == STATE_INIT) {
    // Simulate initialization
    delay(2000);
    updateSystemState(STATE_RUNNING);
  } else if (systemInfo.state == STATE_RUNNING) {
    // Simulate running state
    delay(5000);
    updateSystemState(STATE_ERROR);
  } else if (systemInfo.state == STATE_ERROR) {
    // Simulate error state
    delay(3000);
    updateSystemState(STATE_INIT);
  }
}

// Function to update the system state
void updateSystemState(SystemState newState) {
  systemInfo.state = newState;
  switch (systemInfo.state) {
    case STATE_INIT:
      Serial.println("System State: INIT");
      digitalWrite(systemInfo.ledPin, LOW);  // LED off
      break;
    case STATE_RUNNING:
      Serial.println("System State: RUNNING");
      digitalWrite(systemInfo.ledPin, HIGH);  // LED on
      break;
    case STATE_ERROR:
      Serial.println("System State: ERROR");
      // Blink the LED to indicate an error
      for (int i = 0; i < 10; i++) {
        digitalWrite(systemInfo.ledPin, HIGH);
        delay(100);
        digitalWrite(systemInfo.ledPin, LOW);
        delay(100);
      }
      break;
  }
}
