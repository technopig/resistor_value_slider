// This #include statement was automatically added by the Particle IDE.
#include <blynk.h>


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "5487a1b9f1f34f2ab1d5872ec64e35f6";
int resist_aVal = 0;
int blynk_sVal = 0;

void setup()
{
  // Debug console

  delay(500); // Allow board to settle
  //Blynk.begin(auth);
  pinMode(A4, INPUT); // Resistor input
  pinMode(A5, INPUT); // Blynk slider input
  pinMode(A0, OUTPUT); //output steady voltage
  digitalWrite(A0, HIGH);
  Particle.variable("analogvalue", &resist_aVal, INT);
  Particle.variable("blynkVal", &blynk_sVal, INT);
}

void loop()
{
  resist_aVal = analogRead(A4);
  blynk_sVal = analogRead(A5);
  delay(200);
}









// end
