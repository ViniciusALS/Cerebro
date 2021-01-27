#include "RoboticArm.h"

const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data
String previousData = "";
boolean newData = false;
 
int choice;

RoboticArm myRoboticArm;

void setup() {
    Serial.begin(57600);
 
    // Sets components initial values
    myRoboticArm.init();

    Serial.println("<Arduino is ready>");
}

void loop() {

    recvWithEndMarker();
    showNewData();

//    if (Serial.available()) {
//        // Receives either the integer 0, 1, 2, or 3 from serial connection
//        // to signify "await", "turnLeft", "turnRight", or "toggle" respectively.
//        choice = Serial.parseInt();
//
//        myRoboticArm.movementChoice(choice);
//    }
}

//Recieve data and look for the endMarker '\n' (new line)
void recvWithEndMarker() {
    static byte ndx = 0;
    char endMarker = '\n';
    char rc;
    
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (rc != endMarker) {
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
}

void showNewData() {
    if (newData == true) {
        //Convert char array into string
        String s = receivedChars;
        //Only perform an action when the incoming data changes
        if (!s.equals(previousData)) {

            myRoboticArm.movementChoice(3);
        }
        newData = false;
        previousData = s;
    }
}
