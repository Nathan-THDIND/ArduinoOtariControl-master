#include <MIDI.h>  // Add Midi Library

#define LED 12    // record out
int play=52;      // play out
int stopC=53;     //stop
int state=7;
// Below is my function that will be called by the Midi Library
// when a MIDI NOTE ON message is received.
// It will be passed bytes for Channel, Pitch, and Velocity
void MyHandleNoteOn(byte channel, byte pitch, byte velocity) {
  digitalWrite(LED,HIGH);  //Turn LED on
  digitalWrite(play,HIGH);
  digitalWrite(stopC,HIGH);
  if (velocity == 39  ) {//go into record
    digitalWrite(LED,LOW);//pull pin low 
  }
  if (velocity == 7){//go into play
    digitalWrite(play,LOW);//pull pin low
  }
 if(velocity== 8){// stop machine
  digitalWrite(stopC,LOW);//pull pin low
  
 }
}

void setup() {
  pinMode (LED, OUTPUT);    // Set Arduino board pin 12 to output
  pinMode(play,OUTPUT);    // Set Arduino board pin 52 to output
  pinMode(stopC,OUTPUT);  // Set Arduino board pin 53 to output
  pinMode(state,INPUT);
  
  MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
// OMNI sets it to listen to all channels.. MIDI.begin(2) would set it
// to respond to channel 2 notes only.
  MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  // tells the Midi Library which function I want called when a Note ON command
  // is received. in this case it's "MyHandleNoteOn".
}

void loop() { // Main loop
  if(state=HIGH){
  MIDI.read(); // Continually check what Midi Commands have been received.
  }
  else
  digitalWrite(LED,HIGH);
  digitalWrite(play,HIGH);
  digitalWrite(stopC,HIGH);
  
}
