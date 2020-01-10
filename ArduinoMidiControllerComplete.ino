/* 
 *  This is a MIDI controller for 14 buttons connected to pins 0-13
 *  and 6 potentiometers connect to pins A0-A5
 *  for use as a loop pedal and mixer
*/
#include <MIDI_Controller.h> // Include the library


//set the velocity
const uint8_t velocity = 0b1111111; // Maximum velocity (0b1111111 = 0x7F = 127)

// Set the MIDI trigger notes
const uint8_t R1 = 60;              
const uint8_t S1 = 61; 
const uint8_t R2 = 62; 
const uint8_t S2 = 63; 
const uint8_t R3 = 64; 
const uint8_t S3 = 65; 
const uint8_t R4 = 66; 
const uint8_t S4 = 67; 
const uint8_t R5 = 68; 
const uint8_t S5 = 69; 
const uint8_t R6 = 70; 
const uint8_t S6 = 71; 
const uint8_t R7 = 72; 
const uint8_t S7 = 73; 
/*
const uint8_t R8 = 74; 
const uint8_t S8 = 75;
*/

// set the digital buttons
// Create a new instance of the class 'Digital', called 'button', 
// that sends MIDI messages with note 'R1' on channel 1, with velocity 127
Digital button(0, R1, 1, velocity);
Digital button(1, S1, 1, velocity);
Digital button(2, R2, 1, velocity);
Digital button(3, S2, 1, velocity);
Digital button(4, R3, 1, velocity);
Digital button(5, S3, 1, velocity);
Digital button(6, R4, 1, velocity);
Digital button(7, S4, 1, velocity);
Digital button(8, R5, 1, velocity);
Digital button(9, S5, 1, velocity);
Digital button(10, R6, 1, velocity);
Digital button(11, S6, 1, velocity);
Digital button(12, R7, 1, velocity);
Digital button(13, S7, 1, velocity);
/*
Digital button(18, R8, 1, velocity);
Digital button(19, S8, 1, velocity);
*/


// set the analog potentiometers
// Create a new instance of the class 'Analog', called 'potentiometer', on pin A0, 
// that sends MIDI messages with controller 7 (channel volume) on channel 1
// might have to change the channel for each pot...
Analog potentiometer(A0, MIDI_CC::Channel_Volume, 1);
Analog potentiometer(A1, MIDI_CC::Channel_Volume, 2);
Analog potentiometer(A2, MIDI_CC::Channel_Volume, 3);
Analog potentiometer(A3, MIDI_CC::Channel_Volume, 4);
Analog potentiometer(A4, MIDI_CC::Channel_Volume, 5);
Analog potentiometer(A5, MIDI_CC::Channel_Volume, 6);


// let it run and update!
void setup() {
  // set the pull up resistors for the digital pins so we don't need them in the circuit
  for (int i=0; i <= 13; i++){
    pinMode(i,INPUT);
    digitalWrite(i,HIGH);    
  }
}

void loop() {
  // Refresh the button (check whether the button's state has changed since last time, if so, send it over MIDI)
  MIDI_Controller.refresh();
}
