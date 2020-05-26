


void setup() {
  // put your setup code here, to run once:
pinMode(D1,OUTPUT);//1st led
pinMode(D0,OUTPUT);//2nd led
pinMode(D2,INPUT);
pinMode(D7,INPUT);
pinMode(D5,INPUT);
pinMode(D6,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int x1,x2,y1,y2,flag,cnt;
flag=0;
x1=0;
x2=0;
y1=0;
y2=0;
cnt=0;
x1=digitalRead(D2);
x2=digitalRead(D7);
y1=digitalRead(D5);
y2=digitalRead(D6);
while(x1==HIGH&&x2==HIGH)
  {
    x1=digitalRead(D2);
    x2=digitalRead(D7);
    delay(1000);
    cnt=cnt+1;
    if(cnt>=2)
    {
      flag=1;
      break;
    }
    else
    {
      continue;
    }
  }

while(y1==HIGH&&y2==HIGH)
  {
    y1=digitalRead(D5);
    y2=digitalRead(D6);
    delay(1000);
    cnt=cnt+1;
    if(cnt>=2)
    {
      flag=2;
      break;
    }
    else
    {
      continue;
    }
  }
switch(flag)
{
  case 0: {
           digitalWrite(D1,LOW);
           digitalWrite(D0,LOW);
           break;
          }
  case 1: {
          Serial.println("sabse jyada time ");
          digitalWrite(D1,HIGH);
          break;
          }
  case 2: {
          Serial.println("thoda less jyada time ");
          digitalWrite(D0,HIGH);
          //digitalWrite(D1,HIGH);
          break;
          }
}
}
