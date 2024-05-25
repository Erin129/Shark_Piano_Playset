// C++ code
//
int switchState1 = 0;
int switchState2 = 0;
int switchState3 = 0;
int notes[] = {261, 294, 330, 349, 392};
const int buzzer = 12;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
  //LEDs
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);  
  
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);  
}

void first(){
  int keyVal = analogRead(A1);
  Serial.println(keyVal);
}

void lights(int array[], int count){
  
  digitalWrite(4, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
   
  for (int i = 0; i< count; i++){
    //if note is a c, light up LED1
    if(array[i] == 261){
      digitalWrite(2, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      delay(1000);
    }
    //if note is a d, light up LED2
  	else if(array[i] == 294){
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(2, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      delay(1000);
  }
    //if note is a e, light up LED3
    else if(array[i] == 330){
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(2, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      delay(1000);
  }
  	//if note is a f, light up LED4
  	else if(array[i] == 349){
      digitalWrite(5, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
      digitalWrite(6, LOW);
      delay(1000);
  } 
  //if note is a g, light up LED5
  else{
     digitalWrite(6, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(2, LOW);
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
      delay(1000);
  	}
  }
}

void loop()
{ 
  switchState1 = analogRead(A0);
  if (switchState1 == 1023) {
    //play song 1
    ///wil iterate thru an array of lights
    int mary[] = {330, 294, 261, 294, 330, 330, 330,
                294, 294, 294, 330, 392, 392, 
                330, 294, 261, 294, 330, 330, 330,
                330, 294, 294, 330, 294, 261};
    lights(mary, 26);
    
  }
  else if (switchState1 ==1001) {
    //play song 2
    int rowBoat[] = {261, 261, 261, 294, 330,
                     330, 294, 330, 349, 392,
                    261, 261, 261, 392, 392, 392, 330, 330, 330, 261, 261, 261,
                    392, 349, 330, 294, 261};
    lights(rowBoat, 27);
  }
  else if (switchState1 ==512) {
    //play song 3
    /*D E G G G G G G G 
    D E G G G G G G G 
    D E G G G G G G G 
    G G F*/
    int babyShark[] = {294, 330, 392, 392, 392, 392, 392, 392, 392,
                       294, 330, 392, 392, 392, 392, 392, 392, 392,
                       294, 330, 392, 392, 392, 392, 392, 392, 392,
                      392, 392, 349};
    lights(babyShark,30);
  }
  else if (switchState1 ==10) {
    //play song 4
    /*G C C C D E E
    E D C D E C
    E E F G
    G F E F G E
    C C D E
    E D C D E C
    G G CC C D EE
    E D C  D E C*/
    int itsySpider[] = {392, 261, 261, 261, 294, 330, 330,
                        330, 294, 261, 294, 330, 261,
                       330, 330, 349, 392,
                       392, 349, 330, 349, 392, 330,
                       261, 261, 294, 330,
                       330, 294, 261, 294, 330, 261,
                       392, 392, 261, 261, 261, 294, 330, 330,
                       330, 294, 261, 294, 330, 261};
    lights(itsySpider, 47);
  }

  //bottom 5 pushbuttons just for notes!
  switchState2 = analogRead(A1);
  if (switchState2 ==1023) {
    //1023
    //play c
    tone(buzzer, notes[0]);
    delay(1000);
  }
  else if (switchState2 ==44) {
    //44
    //play d
    tone(buzzer, notes[1]);
    delay(1000);
  }
  else if (switchState2 ==512) {
    //512
    //play e
    tone(buzzer, notes[2]);
    delay(1000);
  }
  else if (switchState2 ==10) {
    //10
    //play f
    tone(buzzer, notes[3]);
    delay(1000);
  }
  else if (switchState2 ==5) {
    //55
    //play g
    tone(buzzer, notes[4]);
    delay(1000);
  }
  else{
    noTone(buzzer);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
