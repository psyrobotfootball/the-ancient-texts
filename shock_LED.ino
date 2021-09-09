/******************************************
 *Website: www.elegoo.com
 * 
 *Time:2017.12.12
 *
 ******************************************/
int Led=13;//define LED port
int buttonpin=3; //define switch port
;int  val;//define digital variable val
void  setup()
{
pinMode(4,OUTPUT);//define LED as a output port
pinMode(7,OUTPUT);
pinMode(buttonpin,INPUT);//define switch as a output port
//Serial.begin(9600);
}
void  loop(){
digitalWrite(4,LOW);
digitalWrite(7,LOW);
//Serial.write(val);
 val=digitalRead(buttonpin);//read the value of the digital interface 3 assigned to val
 
if(val==HIGH)//when the switch sensor have signal, LED blink
{
digitalWrite(4,HIGH);
Serial.write("HIGH");
Serial.println();
delay(500);
}
else
{
digitalWrite(7,HIGH);
Serial.write("LOW");
Serial.println();
delay(500);
}
}
