
#define photoresistor A4
float adc;
float voltage;
int ledRed = 11;  
int ledGreen = 10;
int ledBlue = 9;
int step = 10;
int button = 2;
bool buttonState = 0;
int num1 = 0;
int num2 = 0;
float dtc = 0;

void voltagePrint() {
  adc = analogRead(photoresistor);
  Serial.println(adc);    
  voltage = adc * 0.00489;   
  Serial.println("Vrednost izlaznog napona je: ");
  Serial.print(voltage);
}

void setup() { 

  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(button, INPUT); 
  pinMode(photoresistor, INPUT);
  Serial.begin(9600);
  
  analogWrite(ledRed, 0);    
  analogWrite(ledGreen, 0);   
  analogWrite(ledBlue, 0); 
}

void loop()  { 
  buttonState = digitalRead(button);
  if (buttonState == HIGH) {
    delay(300);
    if(num1 < 10) {
      num1++;
      dtc = map(num1 * step,0,100,0,255);
    }
    else {
      num1 = 0;
      dtc = map(num1 * step,0,100,0,255);
    }
    if(num2 < 32) {
      num2++;
    }
    else {
    num2 = 0;
    }
    if(num2 < 11 ) {
      analogWrite(ledRed, dtc);
      analogWrite(ledGreen, 0);
      analogWrite(ledBlue, 0);
    }
    if(num2 >= 11 && num2 < 22 ) {
      analogWrite(ledRed, 0);
      analogWrite(ledGreen, dtc);
      analogWrite(ledBlue, 0);
    }
    if(num2 >= 22 && num2 < 33) {
      analogWrite(ledRed, 0);
      analogWrite(ledGreen, 0);
      analogWrite(ledBlue, dtc);
    }
  delay(300);
  voltagePrint();
  }  
}