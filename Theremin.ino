/* Theremin: Corporate Edition */

#include <stdio.h>
#include <math.h>

int pitchDistanceSensorPin = 0;
int volumeDistanceSensorPin = 1;
int speakerPin = 2;

int pitchSensorDistance = 0;
int volumeSensorDistance = 0;

/* Configuration */

/* Set the lowest note possible, in hertz https://pages.mtu.edu/~suits/notefreqs.html */
double lowestNoteFrequency = 110;

/* Set the highest note possible, in hertz https://pages.mtu.edu/~suits/notefreqs.html */
double highestNoteFrequency = 1046.5;

/* Set the max usage range, in centimetres, should be set to a comfortable length. Maximum is 500 cm. */
double maxDistanceRange = 50;


/* Automatically generated, they will be overwritten during setup */

/* Sets how many centimetres the hand needs to move in order to change the pitch by one note */
double distancePitchScaleFactor = 0;

void setup() {
  /* Setup pins */
  pinMode(pitchDistanceSensorPin, INPUT);
  pinMode(volumeDistanceSensorPin, INPUT);
  pinMode(speakerPin, OUTPUT);

  /* Calculates values to determine the factor between pitch and distance, in centimetres */
  distancePitchScaleFactor = maxDistanceRange/(12*(log(highestNoteFrequency/lowestNoteFrequency)/log(2)));
  
}

void loop() {
  /* */
  
}

double volume(double distance) {
  return ln(distance);
}

/* Generates pitch based on distance */
double pitch(double distance) {
  return lowestNoteFrequency*pow(2, (pitchSensorDistance*distancePitchScaleFactor)/12)
}

