char t;
 
void setup() {
pinMode(13,OUTPUT);   //leftA motors forward
pinMode(12,OUTPUT);    //leftA motors reverse
pinMode(11, OUTPUT);  //rightB motor forward
pinMode(10, OUTPUT);  //rightB motr reverse 


pinMode(6, OUTPUT); //ENB
pinMode(5, OUTPUT); //ENA
Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);

  analogWrite(5, 255);
  analogWrite(6, 255);
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(13,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);

  analogWrite(5, 255);
  analogWrite(6, 255);
}
 
else if(t == 'L'){      //turn LEFT (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);

  analogWrite(5, 255);
  analogWrite(6, 0);
}
 
else if(t == 'R'){      //turn RIGHT (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(13,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(10,LOW);

  analogWrite(5, 0);
  analogWrite(6, 255);
}

else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(10,LOW);
}
delay(100);
}
