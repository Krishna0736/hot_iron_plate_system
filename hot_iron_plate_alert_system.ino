// --- Pin Definitions ---
const int irPin1 = 9;         // Original IR Sensor
const int irPin2 = 8;         // New IR Sensor
const int buzzerPin = 6;  
const int yellowled = 5;  
const int redled = 7;   
const int thermistorPin = A0; 
const int buttonPin = 4;      

// --- Thermistor Constants ---
const float R_DIVIDER = 10000.0; 
const float BETA = 3950.0;       
const float ROOM_TEMP = 298.15;  
const float R_NOMINAL = 10000.0; 

// --- Settings ---
const float TEMP_THRESHOLD = 45.0; 

void setup() {
  pinMode(irPin1, INPUT);
  pinMode(irPin2, INPUT);     // Initialize second IR sensor
  pinMode(buzzerPin, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); 
  
  Serial.begin(9600);
}

void loop() {
  // 1. Read All Sensors
  int analogValue = analogRead(thermistorPin);
  int buttonState = digitalRead(buttonPin); 
  int ir1 = digitalRead(irPin1);  
  int ir2 = digitalRead(irPin2);

  // 2. Temperature Calculation
  float resistance = R_DIVIDER / (1023.0 / (float)analogValue - 1.0);
  float steinhart;
  steinhart = resistance / R_NOMINAL;     
  steinhart = log(steinhart);             
  steinhart /= BETA;                      
  steinhart += 1.0 / ROOM_TEMP;           
  steinhart = 1.0 / steinhart;            
  steinhart -= 273.15;                    

  // 3. Logic Control
  if (steinhart > TEMP_THRESHOLD) {
    digitalWrite(yellowled, HIGH);
    
    // ALARM LOGIC:
    // Trigger if (IR1 sees object OR IR2 sees object) AND button is NOT pressed
    // Note: IR sensors output LOW when they detect something.
    if ((ir1 == LOW || ir2 == LOW) && buttonState == HIGH) { 
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(redled, HIGH); 
    } 
    else {
      // Turn off if button is pressed OR if both IR sensors see nothing
      digitalWrite(buzzerPin, LOW); 
      digitalWrite(redled, LOW);
    }
  } else {
    // System Safe
    digitalWrite(yellowled, LOW);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(redled, LOW);
  }

  // Debugging (Monitoring both IR sensors)
  Serial.print("Temp: "); Serial.print(steinhart);
  Serial.print(" | IR1: "); Serial.print(ir1 == LOW ? "OBJ" : "CLR");
  Serial.print(" | IR2: "); Serial.println(ir2 == LOW ? "OBJ" : "CLR");}
  