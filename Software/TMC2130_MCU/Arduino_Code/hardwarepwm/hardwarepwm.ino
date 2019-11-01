void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(46, OUTPUT);
  TCCR5A = B01010111;    // Fast PWM
  TCCR5B = TCCR5B & B11100000 | B00011100;         // Prescaler = 256
  
  TCCR4A = B01010111;    // Fast PWM
  TCCR4B = TCCR4B & B11100000 | B00011100;         // Prescaler = 256

  TCCR3A = B01010111;    // Fast PWM
  TCCR3B = TCCR4B & B11100000 | B00011100;         // Prescaler = 256

  TCCR1A = B01010111;    // Fast PWM
  TCCR1B = TCCR4B & B11100000 | B00011100;         // Prescaler = 256
  
//  TCCR5A = B01010111;    // Fast PWM
//  TCCR5B = TCCR5B & B11100000 | B00011001;         // Prescaler = 1
//  TCCR5A = B01010111;    // Fast PWM
//  TCCR5B = TCCR5B & B11100000 | B00011001;         // Prescaler = 1
  
  OCR5A = 639;
  OCR4A = 1279;
  OCR1A = 65535;
  OCR3A = 65535;
//  OCR5B = 639;                // TOP  frequency=(system clock)/ [2 * prescaler * (TOP +1)]
//  OCR5C = 639;                //
  int i = 0;
  
}

void loop() {
  Serial.begin(115200);
  Serial.println(TCCR5A,BIN);
  Serial.println(TCCR5B,BIN);
  delay(1000);
}

