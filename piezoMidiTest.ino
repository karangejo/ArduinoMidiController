
// initialize the midi library
#include<MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

MIDI.begin(MIDI_CHANNEL_OMNI);

// initialize some variables
//int ledPin = 13;
// read from pin Analog Pin 0 ... could be A0...
int knockSensor = 0;               
byte val = 0;
//int statePin = LOW;
int THRESHOLD = 100;



void setup() {
 pinMode(ledPin, OUTPUT); 
 Serial.begin(9600);

}



void loop() {

  val = analogRead(knockSensor);     

  // if piezo sensor value is over the threshold...
  if (val >= THRESHOLD) {

    // light up the led
    //statePin = !statePin;
    //digitalWrite(ledPin, statePin);
    //print "Knock!"
    //Serial.println("Knock!");
    // send a midi note 50 with velocity 60 on channel 1
    MIDI.sendNoteOn(50,60,1);
    delay(500);
    MIDI.sendNoteOff(50,60,1)


  }
 
  delay(100);  // we have to make a delay to avoid overloading the serial port

}
