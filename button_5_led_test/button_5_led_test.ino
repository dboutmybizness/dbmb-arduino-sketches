const int butt1Pin = 6;
const int butt2Pin = 5;
const int butt3Pin = 4;
const int butt4Pin = 3;
const int butt5Pin = 2;
const int ledPin =  13;      // the number of the LED pin
const int aPin = A0;


int b1State = 0;
int b2State = 0;
int b3State = 0;
int b4State = 0;
int b5State = 0;

int aValue = 0;
int whichPressed = 0;
int live_package = 0;
int last_package = 999;

int b1,b2,b3,b4,b5 = 0;


void setup() {
  Serial.begin(9600);
  Keyboard.begin();
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
  //determine which package to use
  live_package = getLivePackage(aValue);
  //sPrinter("live Pkg: " + String(live_package));
  
  whichPressed = chkWhichPressed();
  //sPrinter("Pressing " + String(whichPressed));
  
  prepButton(whichPressed);
  ledHIGH();
  delay(300);
}



/** Functions **/

//should be a text file or a library that holds these values
void pushButtonAction(int item){
  switch (item) {
    case 1:
      sPrinter("Blue");
      Keyboard.write(65);
      break;
    case 2:
      sPrinter("Yellow");
      Keyboard.write(64);
      break;
    case 3:
      sPrinter("Black");
      Keyboard.write(66);
      break;
    case 4:
      sPrinter("Green");
      Keyboard.write(68);
      break;
    default:
      sPrinter("Negro");
      Keyboard.write(70);
      break;
  }
}

void prepButton(int pbutton){
  switch (pbutton){
    case 1:
      pushButtonAction(b1);
      break;
    case 2:
      pushButtonAction(b2);
      break;
    case 3:
      pushButtonAction(b3);
      break;
    case 4:
      pushButtonAction(b4);
      break;
    case 5:
      pushButtonAction(b5);
      break;
  }

}

// update buttons
void setUpLivePKG(int live_p){
  if ( live_p == 0 ){
    setButtons(0,1,2,3,4);
  } else if ( live_p == 1 ){
    setButtons(2,4,2,3,4);
  } else if ( live_p == 2 ){
    setButtons(4,1,2,2,4);
  } else if ( live_p == 3 ){
    setButtons(1,1,2,1,4);
  } else if ( live_p == 4 ){
    setButtons(3,1,2,3,4);
  }
  
}
void setButtons(int b1val, int b2val, int b3val, int b4val, int b5val){
   b1 = b1val;
   b2 = b2val;
   b3 = b3val;
   b4 = b4val;
   b5 = b5val;
}

void sPrinter(String str){
  Serial.println(str); 
}

int getLivePackage(int aVal){
  int pkg = live_package;
  
  if ( aVal <= 204 ) pkg = 0;
  else if ( aVal >= 205 && aVal <= 410 ) pkg = 1;
  else if ( aVal >= 411 && aVal <= 614 ) pkg = 2;
  else if ( aVal >= 615 && aVal <= 819 ) pkg = 3;
  else if ( aVal >= 820 ) pkg = 4;
  
  if (last_package != pkg){
    setUpLivePKG(pkg);
    last_package = pkg;
    sPrinter("New Package ---- "+ String(pkg));
   
  }
  
  return pkg;
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
