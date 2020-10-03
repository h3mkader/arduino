int value1;
int value2;
int counter=0;
int count=0;
int led1=3;
int led2=13;
int btn_state=0;
int button=7;
int buzzer=11;
boolean on = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(button,INPUT);
  pinMode(buzzer,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  btn_state=digitalRead(button);
  if (btn_state==HIGH)
  {
    if(on==true)
    {
      on=false;
    }
    else
    {
      on=true;
    }
  }
  if (on==true)
  {
    value1=analogRead(A5);
    value2=analogRead(A0);
    if( value1<40 || value2<40)
     {
      if(value1<value2)
       {
        counter++;
        Serial.println(counter);
        digitalWrite(led1,HIGH);
        delay(1000);
        digitalWrite(led1,LOW); 
       }
      else if(value1>value2)
       {
        counter--;
        Serial.println(counter);
        digitalWrite(led2,HIGH);
        delay(1000);
        digitalWrite(led2,LOW);
       }
     if (counter==5)
      { 
        digitalWrite(buzzer,HIGH);
        digitalWrite(led1,HIGH);
        digitalWrite(led2,HIGH);
        delay(1000);
        digitalWrite(buzzer,LOW);
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        delay(500);
        on=false;
      }
    }

  }
}
