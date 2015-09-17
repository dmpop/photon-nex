
// ----------------------------------------------
// Program to control Photon-based shutter release
// for SONY NEX and Alpha cameras
// ----------------------------------------------

int focusPin = D1;
int releasePin = D3;

void setup()
{

   pinMode(focusPin, OUTPUT);
   pinMode(releasePin, OUTPUT);

   Spark.function("shutter", shutterRelease);

   digitalWrite(focusPin, LOW);
   digitalWrite(releasePin, LOW);

}

void loop()
{

}

int shutterRelease(String command) {

    if (command=="release") {
        digitalWrite(focusPin,HIGH);
        delay(500);
        digitalWrite(releasePin,HIGH);
        delay(500);
        digitalWrite(releasePin,LOW);
        digitalWrite(focusPin,LOW);
        return 1;
    }
    else {
        return -1;
    }
}
