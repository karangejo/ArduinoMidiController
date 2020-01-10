#include <MIDI_Controller.h>

const uint8_t velocity = 0b01111111; // The velocity of the buttons (0b01111111 = 127 = 100%)

Analog faders[] = {
    {A0, MIDI_CC::General_Purpose_Controller_1, 1}, // Create a new instance of class 'Analog' on pin A0, controller number 0x07 (channel volume), on MIDI channel 1.
    {A1, MIDI_CC::General_Purpose_Controller_2, 1},
    {A2, MIDI_CC::General_Purpose_Controller_3, 1},
    {A3, MIDI_CC::General_Purpose_Controller_4, 1},
    {A4, MIDI_CC::General_Purpose_Controller_5, 1},
    {A5, MIDI_CC::General_Purpose_Controller_6, 1},
    {A6, MIDI_CC::General_Purpose_Controller_7, 1},
};

Digital buttons[] = {
    {0, 0x10, 1, velocity}, // Create a new instance of class 'Digital' on pin 0, note number 16 (mute) on MIDI channel 1
    {1, 0x11, 1, velocity},
    {2, 0x12, 1, velocity},
    {3, 0x14, 1, velocity},
    {4, 0x15, 1, velocity},
    {5, 0x16, 1, velocity},
    {6, 0x17, 1, velocity},
    {7, 0x18, 1, velocity},
    {8, 0x19, 1, velocity},
    {9, 0x1A, 1, velocity},
    {10, 0x1B, 1, velocity},
    {11, 0x1C, 1, velocity},

};

// create a bank with one channel
Bank bank(1);

// single toggle switch on pin 12 and use builtin led to see which bank we are on
BankSelector bankSelector(bank, 12, LED_BUILTIN, BankSelector::TOGGLE);

void setup()
{
  // add the control elements to the bank
    bank.add(faders, Bank::CHANGE_CHANNEL); 
    bank.add(buttons, Bank::CHANGE_ADDRESS);
}


void loop() // Refresh all inputs
{
    MIDI_Controller.refresh();
}
