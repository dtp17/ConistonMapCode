#include <Wire.h>
#include <RTClib.h>  // Include the Adafruit DS3231 library

RTC_PCF8523 rtc;
char daysOfTheWeek[7][12] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };


const int allPinsSize = 8;
const int allPins[] = { 1, 2, 3, 6, 7, 8, 9, 10 };
// Lakebank(1), Fir Island(2), Parkamoor(3), Mile Marker(6), RPC(7), Brantwood(8), Coniston(9), and Monk Coniston(10).

DateTime heartTimes1[6];
DateTime heartTimes2[6];
const int heartPinsSize = 6;
const int heartPins[] = { 9, 7, 3, 2, 8, 9 };
// Coniston, RPC, Parkamoor, Fir Island, Brantwood, and Coniston.

DateTime northTimes[7];
const int northPinsSize = 7;
const int northPins[] = { 9, 7, 6, 2, 8, 10, 9 };
// Coniston, RPC, Mile Marker, Fir Island, Brantwood, Monk Coniston, and Coniston.

DateTime fullTimes[8];
const int fullPinsSize = 8;
const int fullPins[] = { 9, 7, 1, 3, 2, 8, 10, 9 };
// Coniston, RPC, Lakebank, Parkamoor, Fir Island, Brantwood, Monk Coniston, and Coniston.

DateTime now;  // Declare 'now' globally

void setup() {
  Serial.begin(9600);

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1) delay(10);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // Set the specified pins as outputs
  for (int i = 0; i < allPinsSize; i++) {
    pinMode(allPins[i], OUTPUT);
  }

  rtc.start();
  DateTime now = rtc.now();
  /*
  heartTimes1[0] = DateTime(now.year(), now.month(), now.day(), 10, 45, 0);  // Coniston
  heartTimes1[1] = DateTime(now.year(), now.month(), now.day(), 11, 7, 0);   // RPC
  heartTimes1[2] = DateTime(now.year(), now.month(), now.day(), 11, 23, 0);  // Parkamoor
  heartTimes1[3] = DateTime(now.year(), now.month(), now.day(), 11, 54, 0);  // Fir Island
  heartTimes1[4] = DateTime(now.year(), now.month(), now.day(), 11, 55, 0);  // Brantwood
  heartTimes1[5] = DateTime(now.year(), now.month(), now.day(), 11, 56, 0);  // Coniston

  northTimes[0] = DateTime(now.year(), now.month(), now.day(), 12, 0, 0);   // Coniston
  northTimes[1] = DateTime(now.year(), now.month(), now.day(), 12, 15, 0);  // RPC
  northTimes[2] = DateTime(now.year(), now.month(), now.day(), 12, 25, 0);  // Mile Marker
  northTimes[3] = DateTime(now.year(), now.month(), now.day(), 15, 25, 0);  // Fir Island
  northTimes[4] = DateTime(now.year(), now.month(), now.day(), 12, 40, 0);  // Brantwood
  northTimes[5] = DateTime(now.year(), now.month(), now.day(), 12, 55, 0);  // Monk Coniston
  northTimes[6] = DateTime(now.year(), now.month(), now.day(), 13, 0, 0);   // Coniston

  heartTimes2[0] = DateTime(now.year(), now.month(), now.day(), 13, 40, 0);  // Coniston
  heartTimes2[1] = DateTime(now.year(), now.month(), now.day(), 13, 55, 0);  // RPC
  heartTimes2[2] = DateTime(now.year(), now.month(), now.day(), 14, 15, 0);  // Parkamoor
  heartTimes2[3] = DateTime(now.year(), now.month(), now.day(), 14, 22, 0);  // Fir Island
  heartTimes2[4] = DateTime(now.year(), now.month(), now.day(), 14, 35, 0);  // Brantwood

  fullTimes[0] = DateTime(now.year(), now.month(), now.day(), 14, 50, 0);  // Coniston
  fullTimes[1] = DateTime(now.year(), now.month(), now.day(), 15, 5, 0);   // RPC
  fullTimes[2] = DateTime(now.year(), now.month(), now.day(), 15, 35, 0);  // Lakebank
  fullTimes[3] = DateTime(now.year(), now.month(), now.day(), 15, 50, 0);  // Parkamoor
  fullTimes[4] = DateTime(now.year(), now.month(), now.day(), 16, 0, 0);   // Fir Island
  fullTimes[5] = DateTime(now.year(), now.month(), now.day(), 16, 10, 0);  // Brantwood
  fullTimes[6] = DateTime(now.year(), now.month(), now.day(), 16, 20, 0);  // Monk Coniston
  fullTimes[7] = DateTime(now.year(), now.month(), now.day(), 16, 25, 0);  // Coniston
                                                                           */
  int minuteIncrement = 1;
  heartTimes1[0] = DateTime(now.year(), now.month(), now.day(), 15, 53, 0) + TimeSpan(0, 0, minuteIncrement * 0, 0);  // Coniston
  heartTimes1[1] = DateTime(now.year(), now.month(), now.day(), 15, 54, 0) + TimeSpan(0, 0, minuteIncrement * 1, 0);  // RPC
  heartTimes1[2] = DateTime(now.year(), now.month(), now.day(), 15, 55, 0) + TimeSpan(0, 0, minuteIncrement * 2, 0);  // Parkamoor
  heartTimes1[3] = DateTime(now.year(), now.month(), now.day(), 15, 56, 0) + TimeSpan(0, 0, minuteIncrement * 3, 0);  // Fir Island
  heartTimes1[4] = DateTime(now.year(), now.month(), now.day(), 15, 57, 0) + TimeSpan(0, 0, minuteIncrement * 4, 0);  // Brantwood
  heartTimes1[5] = DateTime(now.year(), now.month(), now.day(), 15, 58, 0) + TimeSpan(0, 0, minuteIncrement * 5, 0);  // Coniston

  northTimes[0] = DateTime(now.year(), now.month(), now.day(), 15, 59, 0) + TimeSpan(0, 0, minuteIncrement * 6, 0);  // Coniston
  northTimes[1] = DateTime(now.year(), now.month(), now.day(), 16, 0, 0) + TimeSpan(0, 0, minuteIncrement * 7, 0);   // RPC
  northTimes[2] = DateTime(now.year(), now.month(), now.day(), 16, 1, 0) + TimeSpan(0, 0, minuteIncrement * 8, 0);   // Mile Marker
  northTimes[3] = DateTime(now.year(), now.month(), now.day(), 16, 2, 0) + TimeSpan(0, 0, minuteIncrement * 9, 0);   // Fir Island
  northTimes[4] = DateTime(now.year(), now.month(), now.day(), 16, 3, 0) + TimeSpan(0, 0, minuteIncrement * 10, 0);  // Brantwood
  northTimes[5] = DateTime(now.year(), now.month(), now.day(), 16, 4, 0) + TimeSpan(0, 0, minuteIncrement * 11, 0);  // Monk Coniston
  northTimes[6] = DateTime(now.year(), now.month(), now.day(), 16, 5, 0) + TimeSpan(0, 0, minuteIncrement * 12, 0);  // Coniston

  heartTimes2[0] = DateTime(now.year(), now.month(), now.day(), 16, 6, 0) + TimeSpan(0, 0, minuteIncrement * 13, 0);   // Coniston
  heartTimes2[1] = DateTime(now.year(), now.month(), now.day(), 16, 7, 0) + TimeSpan(0, 0, minuteIncrement * 14, 0);   // RPC
  heartTimes2[2] = DateTime(now.year(), now.month(), now.day(), 16, 8, 0) + TimeSpan(0, 0, minuteIncrement * 15, 0);   // Parkamoor
  heartTimes2[3] = DateTime(now.year(), now.month(), now.day(), 16, 9, 0) + TimeSpan(0, 0, minuteIncrement * 16, 0);   // Fir Island
  heartTimes2[4] = DateTime(now.year(), now.month(), now.day(), 16, 10, 0) + TimeSpan(0, 0, minuteIncrement * 17, 0);  // Brantwood

  fullTimes[0] = DateTime(now.year(), now.month(), now.day(), 16, 11, 10) + TimeSpan(0, 0, minuteIncrement * 18, 0);  // Coniston
  fullTimes[1] = DateTime(now.year(), now.month(), now.day(), 16, 12, 20) + TimeSpan(0, 0, minuteIncrement * 19, 0);  // RPC
  fullTimes[2] = DateTime(now.year(), now.month(), now.day(), 16, 13, 30) + TimeSpan(0, 0, minuteIncrement * 20, 0);  // Lakebank
  fullTimes[3] = DateTime(now.year(), now.month(), now.day(), 16, 14, 40) + TimeSpan(0, 0, minuteIncrement * 21, 0);  // Parkamoor
  fullTimes[4] = DateTime(now.year(), now.month(), now.day(), 16, 15, 50) + TimeSpan(0, 0, minuteIncrement * 22, 0);  // Fir Island
  fullTimes[5] = DateTime(now.year(), now.month(), now.day(), 16, 16, 10) + TimeSpan(0, 0, minuteIncrement * 23, 0);  // Brantwood
  fullTimes[6] = DateTime(now.year(), now.month(), now.day(), 16, 17, 20) + TimeSpan(0, 0, minuteIncrement * 24, 0);  // Monk Coniston
  fullTimes[7] = DateTime(now.year(), now.month(), now.day(), 16, 18, 30) + TimeSpan(0, 0, minuteIncrement * 25, 0);  // Coniston


  //testLEDS(100, 500);
}

void loop() {
  now = rtc.now();

  checkAndLightUp(heartPins, heartPinsSize, heartTimes1);
  checkAndLightUp(northPins, northPinsSize, northTimes);
  checkAndLightUp(heartPins, heartPinsSize, heartTimes2);
  checkAndLightUp(fullPins, fullPinsSize, fullTimes);
  Serial.print("checked");
  if ((now.hour() == 16 && now.minute() == 58 && now.second() == 0) || (now.hour() == 10 && now.minute() == 49) || (now.hour() == 12 && now.minute() == 34)) {
    gentlePulseRandomLights(allPins, allPinsSize, 3);
  }
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  delay(1000);
}

void checkAndLightUp(const int pins[], int size, DateTime triggerTimes[]) {
  static int lastTriggeredIndex = -1;

  // Check if any LED should be turned on
  int indexOfTriggeredLED = -1;
  for (int i = 0; i < size; i++) {
    // Adjust the threshold time (e.g., 5 seconds before and after the trigger time)
    DateTime adjustedTriggerTime = triggerTimes[i] - TimeSpan(0, 0, 5, 0);  // 5 seconds before
    DateTime adjustedEndTime = triggerTimes[i] + TimeSpan(0, 0, 5, 0);      // 5 seconds after

    // Debugging prints
    // Serial.print("Current time: ");
    // Serial.println(now.timestamp());
    // Serial.print("Adjusted Trigger time: ");
    // Serial.println(adjustedTriggerTime.timestamp());
    // Serial.print("Adjusted End time: ");
    // Serial.println(adjustedEndTime.timestamp());
    // Serial.println();

    // Check if the current time is between adjustedTriggerTime and adjustedEndTime
    if (now >= adjustedTriggerTime && now < adjustedEndTime) {
      indexOfTriggeredLED = i;
      break;  // Exit the loop when the LED is triggered
    }
  }

  // Turn off all LEDs if a new LED is triggered
  if (indexOfTriggeredLED != -1 && lastTriggeredIndex != indexOfTriggeredLED) {
    for (int j = 0; j < size; j++) {
      digitalWrite(pins[j], LOW);
    }
    Serial.print("-------------------------> Turning off all LEDs");
    lastTriggeredIndex = indexOfTriggeredLED;  // Update lastTriggeredIndex to the current LED
  }

  // Turn on the current LED
  if (indexOfTriggeredLED != -1) {
    digitalWrite(pins[indexOfTriggeredLED], HIGH);
    Serial.print("-------------------------> Turning on LED ");
    Serial.println(pins[indexOfTriggeredLED]);
  }
}






  void gentlePulseRandomLights(const int pins[], int size, int numPulses) {
    for (int pulseCount = 0; pulseCount < numPulses; pulseCount++) {
      // Select 4 random lights
      int selectedLights[4];
      for (int i = 0; i < 4; i++) {
        selectedLights[i] = random(size);
      }

      // Pulse the selected lights gently on and off
      for (int j = 0; j < 255; j++) {
        for (int i = 0; i < 4; i++) {
          analogWrite(pins[selectedLights[i]], j);
        }
        delay(3);  // Adjust the delay for pulse speed
      }

      for (int j = 255; j >= 0; j--) {
        for (int i = 0; i < 4; i++) {
          analogWrite(pins[selectedLights[i]], j);
        }
        delay(3);  // Adjust the delay for pulse speed
      }
    }
  }


  void testLEDS(int wait, int pause) {
    Serial.println();
    Serial.print("all HIGH - ");
    for (int i = 0; i < allPinsSize; i++) {
      digitalWrite(allPins[i], HIGH);
      Serial.print(allPins[i]);
      Serial.print(",");
      delay(wait);
    }
    delay(pause);
    Serial.println();
    Serial.print("all LOW  - ");
    for (int i = 0; i < allPinsSize; i++) {
      digitalWrite(allPins[i], LOW);
      Serial.print(allPins[i]);
      Serial.print(",");
      delay(wait);
    }

    Serial.println();
    Serial.print("north HIGH - ");
    for (int i = 0; i < northPinsSize; i++) {
      digitalWrite(northPins[i], HIGH);
      Serial.print(northPins[i]);
      Serial.print(",");
      delay(wait);
    }
    delay(pause);
    Serial.println();
    Serial.print("north LOW  - ");
    for (int i = 0; i < northPinsSize; i++) {
      digitalWrite(northPins[i], LOW);
      Serial.print(northPins[i]);
      Serial.print(",");
      delay(wait);
    }

    Serial.println();
    Serial.print("heart HIGH - ");
    for (int i = 0; i < heartPinsSize; i++) {
      digitalWrite(heartPins[i], HIGH);
      Serial.print(heartPins[i]);
      Serial.print(",");
      delay(wait);
    }
    delay(pause);
    Serial.println();
    Serial.print("heart LOW  - ");
    for (int i = 0; i < heartPinsSize; i++) {
      digitalWrite(heartPins[i], LOW);
      Serial.print(heartPins[i]);
      Serial.print(",");
      delay(wait);
    }

    Serial.println();
    Serial.print("full HIGH - ");
    for (int i = 0; i < fullPinsSize; i++) {
      digitalWrite(fullPins[i], HIGH);
      Serial.print(fullPins[i]);
      Serial.print(",");
      delay(wait);
    }
    delay(pause);
    Serial.println();
    Serial.print("full LOW  - ");
    for (int i = 0; i < fullPinsSize; i++) {
      digitalWrite(fullPins[i], LOW);
      Serial.print(fullPins[i]);
      Serial.print(",");
      delay(wait);
    }
  }
