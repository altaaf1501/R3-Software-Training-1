double pot;
int dippy1;
int dippy2;
int dippy3;
int dippy4;


void setup()
{
  pinMode(A0,INPUT); //potentiometer

  pinMode(8,INPUT); //2nd input for chip
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  
  pinMode(4,INPUT); //For Dip Switch
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  pot = map(analogRead(A0),0,1023,0,255);
  Serial.println(pot);
  dippy1 = digitalRead(7);
  dippy2 = digitalRead(6);
  dippy3 = digitalRead(5);
  dippy4 = digitalRead(4);
  delay(25);
  
  if (dippy1 == 0 && dippy2 == 0 && dippy3 == 0 && dippy4 == 0) {	//stop
  	digitalWrite(8, LOW);	//stop
    digitalWrite(9, LOW);	//stop
    digitalWrite(10, pot);	//stop
    digitalWrite(11, pot);	//stop
    delay(25);
  }
  else if (dippy1 == 0 && dippy2 == 0 && dippy3 == 0 && dippy4 == 1) { //left
  	digitalWrite(8, pot);	//stop
    digitalWrite(9, LOW);	//stop
    digitalWrite(10, pot);	//stop
    digitalWrite(11, LOW);	//stop
    delay(25);
  }
  else if (dippy1 == 0 && dippy2 == 0 && dippy3 == 1 && dippy4 == 0) { //right
  	digitalWrite(8, LOW);	//stop
    digitalWrite(9, pot);	//stop
    digitalWrite(10, LOW);	//stop
    digitalWrite(11, pot);	//stop
    delay(25);
  }
  else if (dippy1 == 0 && dippy2 == 1 && dippy3 == 0 && dippy4 == 0) { //reverse
  	digitalWrite(8, LOW);	//stop
    digitalWrite(9, pot);	//stop
    digitalWrite(10, pot);	//stop
    digitalWrite(11, LOW);	//stop
    delay(25);
  }
  else if (dippy1 == 1 && dippy2 == 0 && dippy3 == 0 && dippy4 == 0) { //front
  	digitalWrite(8, pot);	//stop
    digitalWrite(9, LOW);	//stop
    digitalWrite(10, LOW);	//stop
    digitalWrite(11, pot);	//stop
    delay(25);
  }
}