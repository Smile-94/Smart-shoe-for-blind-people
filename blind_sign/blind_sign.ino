#define tigger A0
#define echo A1
#define water_sensor A2

#define vib_mot 13
#define buzzer 12

float time=0;
float distance=0;
float water=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tigger,OUTPUT);
  pinMode(echo,INPUT);

  //output vibrater and burzzer
  pinMode(vib_mot, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(tigger,LOW);
  delayMicroseconds(2);
  digitalWrite(tigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(tigger,LOW);
  delayMicroseconds(2);

  //water sensor......
  water=analogRead(water_sensor);
  

  time=pulseIn(echo,HIGH);
  distance=time*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print("\n");
  Serial.print("Water Label: ");
  Serial.println(water);
  delay(2000);

  if(distance<50 || water>400){
    digitalWrite(vib_mot, HIGH);
    tone(buzzer, 1000); 
    delay(1000); 
    digitalWrite(vib_mot, LOW);       
    noTone(buzzer);
    delay(1000);  
    
    }else{
      digitalWrite(vib_mot, LOW);
      digitalWrite(buzzer, LOW);
      
      }

}
