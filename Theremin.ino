/* Theremin: Corporate Edition */
/* Uses NewPing (https://playground.arduino.cc/Code/NewPing) and toneAC (https://playground.arduino.cc/Code/ToneAC) */

#include <stdio.h>
#include <math.h>
#include <toneAC.h>
#include <NewPing.h>

/* ? Configuration */
/* Make sure the speaker is connected to the proper pins, in the case of the UNO it is PWM pins 9 & 10, toneAC will automatically push to those without logical configuration */

int pitchDistanceSensorInputPin = 0;
int pitchDistanceSensorOutputPin = 0;
int volumeDistanceSensorInputPin = 1;
int volumeDistanceSensorOutputPin = 1;

int pitchSensorDistance = 0;
int volumeSensorDistance = 0;


/* ? Configuration */

/* Set the lowest note possible, in hertz https://pages.mtu.edu/~suits/notefreqs.html */
double lowestNoteFrequency = 110;

/* Set the highest note possible, in hertz https://pages.mtu.edu/~suits/notefreqs.html */
double highestNoteFrequency = 1046.5;

/* Set the max usage range, in centimetres, should be set to a comfortable length. Maximum is 500 cm. */
double maxDistanceRange = 50;


/* Automatically generated, they will be overwritten during setup */

/* Sets how many centimetres the hand needs to move in order to change the pitch by one note */
double distancePitchScaleFactor = 0;

NewPing pitchDistanceSensor = NewPing(pitchDistanceSensorOutputPin, pitchDistanceSensorInputPin, maxDistanceRange);
NewPing volumeDistanceSensor = NewPing(volumeDistanceSensorOutputPin, volumeDistanceSensorInputPin, maxDistanceRange);

void setup() {

  Serial.begin(9600);
/*  
  / Setup pins /
  pinMode(pitchDistanceSensorPin, INPUT);
  pinMode(volumeDistanceSensorPin, INPUT);
  pinMode(speakerPin, OUTPUT);
*/

  /* Calculates values to determine the factor between pitch and distance, in centimetres */
  distancePitchScaleFactor = maxDistanceRange/(12*(log(highestNoteFrequency/lowestNoteFrequency)/log(2)));
 
   
}

void loop() {
  /* */

  toneAC(pitch(pitchDistanceSensor.ping_cm()),volume(volumeDistanceSensor.ping_cm()));

  
}

int volume(int distance) {
  return int(10-(((float)distance/maxDistanceRange)*10));
}

/* Generates pitch based on distance */
int pitch(int distance) {
  if (distance <= maxDistanceRange) {
    return (int)(lowestNoteFrequency*pow(2, ((double)distance)/12));
  }
  else {
    return 0;
  }
  
}

