// This #include statement was automatically added by the Particle IDE.
#include <blynk.h>


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "5487a1b9f1f34f2ab1d5872ec64e35f6";
int resist_aVal = 0;
int blynk_sVal = 0;
int onoff = 0;

BlynkTimer timer;

BLYNK_WRITE(V1){
  blynk_sVal = param.asInt();
}

BLYNK_WRITE(V2){
  onoff = param.asInt();
}

void sendResistVal()
{
  Blynk.virtualWrite(V0, resist_aVal);
}

void setup()
{
  delay(500); // Allow board to settle

  Particle.variable("resistVal", &resist_aVal, INT); //register real resistor measured value
  Particle.variable("blynkVal", &blynk_sVal, INT); //register blynk slider Value

  Blynk.begin(auth); //begin Blynk
  timer.setInterval(1000L, sendResistVal); //every 1000ms, execute sendResistVal(){}

  pinMode(A4, INPUT); // Analog resistor input

  pinMode(D7, OUTPUT); //control LED with Blynk

  //Output steady voltage on A0
  pinMode(A0, OUTPUT);
  digitalWrite(A0, HIGH);
}

void loop()
{
  Blynk.run();
  timer.run();
  resist_aVal = analogRead(A4); //regular analogread on A4

  Blynk.virtualWrite(V3, onoff*255); //write to the virtual LED

  if (onoff)
  {
      digitalWrite(D7, HIGH);

  }
  else
  {
      digitalWrite(D7, LOW);
  }

  delay(200);
}










// end
