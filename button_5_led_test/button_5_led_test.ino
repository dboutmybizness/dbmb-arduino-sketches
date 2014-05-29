const int butt1Pin = 12;
const int butt2Pin = 11;
const int butt3Pin = 10;
const int butt4Pin = 9;
const int butt5Pin = 8;
const int ledPin =  13;      // the number of the LED pin
const int aPin = A0;


int b1State = 0;
int b2State = 0;
int b3State = 0;
int b4State = 0;
int b5State = 0;

int aValue = 0;
int whichPressed = 0;

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
  aValue = analogRead(aPin);
  b1State = digitalRead(butt1Pin);
  b2State = digitalRead(butt2Pin);
  b3State = digitalRead(butt3Pin);
  b4State = digitalRead(butt4Pin);
  b5State = digitalRead(butt5Pin);

  int any_pressed = 0;
  whichPressed = 0;
  any_pressed = buttPressed();

  if ( any_pressed < 1){
    ledLOW();
    return;
  }
  
  whichPressed = chkWhichPressed();
  //Serial.println("Pressing " + String(whichPressed));
  
  if ( aValue > 512 ){
    Serial.println("holla -- " + String(aValue));
  } else {

  }
  Serial.println("1 pressed");
  ledHIGH();

}

int chkWhichPressed(){
  int pressed = 0;
  //check voltage for each to determine which is pressed
  if ( b1State == HIGH ) pressed = 1;
  else if ( b2State == HIGH ) pressed = 2;
  else if ( b3State == HIGH ) pressed = 3;
  else if ( b4State == HIGH ) pressed = 4;
  else if ( b5State == HIGH ) pressed = 5;
  return pressed;
} 

int buttPressed(){
  return b1State + b2State + b3State + b4State + b5State;
}

void ledLOW(){
  digitalWrite(ledPin, LOW);
}
void ledHIGH(){
  digitalWrite(ledPin, HIGH);
}
