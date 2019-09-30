//
// Created by elektron on 29/09/2019.
//
#import "Arduino.h"

#define GREENPIN 9
#define ORANGEPIN 10
#define REDPIN 11

#define TIME 1000
#define MILLITIME 100

void compteEndroit();
void compteEnvers();
void breath();
void rolling();

void setup() {
    pinMode(GREENPIN, OUTPUT);
    pinMode(ORANGEPIN, OUTPUT);
    pinMode(REDPIN, OUTPUT);
    pinMode(13, OUTPUT);
}

void loop() {
    compteEndroit();
    compteEnvers();
    for (int i=0; i<10; i++) {
        rolling();
    }
}

void convert(int nb) {
    digitalWrite(GREENPIN, nb&1);
    digitalWrite(ORANGEPIN, nb&2);
    digitalWrite(REDPIN, nb&4);
}

void compteEndroit() {
    for (int i=0; i<8; i++) {
        convert(i);
        delay(TIME);
    }
}

void compteEnvers() {
    for (int i=7; i>=0; i--) {
        convert(i);
        delay(TIME);
    }
}

void breath() {
    for (int i=0; i<255; i++) {
        analogWrite(REDPIN, i);
        analogWrite(GREENPIN, i);
        analogWrite(ORANGEPIN, i);
        analogWrite(13, i);
        delay(MILLITIME);
    }
    for (int i=255; i>=0; i--) {
        analogWrite(REDPIN, i);
        analogWrite(GREENPIN, i);
        analogWrite(ORANGEPIN, i);
        analogWrite(13, i);
        delay(MILLITIME);
    }
}

void rolling() {
    int compt = 1;
    while (compt < 8) {
        convert(compt);
        delay(MILLITIME);
        compt *= 2;
    }
}