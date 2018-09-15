  int led = 13;           // choose the pin for the LED
  int pir1 = 2;           // choose the input pin (for PIR sensor)
  int pir2 = 3;           // choose the input pin (for PIR sensor)
  int pir3 = 4;           // choose the input pin (for PIR sensor)
  int pirState;           // we start, assuming no motion detected
  int Speaker = 10;       //Set up a speaker on a PWM pin (digital 9, 10, or 11)


void setup()
{
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);      // declare LED as output
  pinMode(pir1, INPUT);     // declare sensor as input
  pinMode(pir2, INPUT);     // declare sensor as input
  pinMode(pir3, INPUT);     // declare sensor as input
  pinMode(Speaker, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  pirState = digitalRead(pir1) + digitalRead(pir2) + digitalRead(pir3); // read 3 inputvalues
  if (pirState > 0) // check if input(s) is HIGH
  {
    digitalWrite(led, HIGH);  // turn LED ON
    tone(300,160); // short 'pip'
    Serial.println("Motion detected!");
    delay(150);
  }
  else
  {
    digitalWrite(led, LOW); // turn LED OFF
    delay(300);
  }
}
