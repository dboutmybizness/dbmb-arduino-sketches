const int butt1Pin = 12;
const int butt2Pin = 11;
const int butt3Pin = 10;
const int butt4Pin = 9;
const int butt5Pin = 8;
const int ledPin =  13;      // the number of the LED pin

int b1State = 0;
int b2State = 0;
int b3State = 0;
int b4State = 0;
int b5State = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  //LED

  // initialize the pushbutton pin as an input:
  pinMode(butt1Pin, INPUT);
  pinMode(butt2Pin, INPUT);
  pinMode(butt3Pin, INPUT);
  pinMode(butt4Pin, INPUT);
  pinMode(butt5Pin, INPUT);
}

void loop(){
  b1State = digitalRead(butt1Pin);
  b2State = digitalRead(butt2Pin);
  b3State = digitalRead(butt3Pin);
  b4State = digitalRead(butt4Pin);
  b5State = digitalRead(butt5Pin);

  int any_pressed = 0;
  any_pressed = (
    b1State + b2State + b3State + b4State + b5State
  );

  if ( any_pressed > 0){
    Serial.println("1 pressed");
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

/*
  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  button2State = digitalRead(but2Pin);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH || button2State == HIGH) {
    if ( buttonState == HIGH && button2State == HIGH){
      Serial.println("both pressed");
      digitalWrite(ledPin, LOW);
    } else {
    // turn LED on:
      Serial.println("1 pressed");
      digitalWrite(ledPin, HIGH);  
    }
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }
*/
}
