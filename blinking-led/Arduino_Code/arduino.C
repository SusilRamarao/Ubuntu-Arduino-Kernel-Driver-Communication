`#define LED 13`
`void setup() {`
  `pinMode(LED, OUTPUT);`
  `Serial.begin(9600);  // Start serial communication at 9600 baud rate`
`}`

`void loop() {`
  
  `if (Serial.available()) {         // Check if there is serial data available`
    `char command = Serial.read();   // Read the command`
    `if (command == '1') {           // Command to turn the LED ON`
      `digitalWrite(LED, HIGH);   // Turn the LED on`
    `}` 
    `else if (command == '0') {      // Command to turn the LED OFF`
      `digitalWrite(LED, LOW);    // Turn the LED off`
    `}`
  `}`
`}`