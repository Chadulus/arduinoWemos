#include <Arduino.h>

// Function declaration
void playNote(int rate, float seconds);

// --- Note Frequency Map ---
#define NOTE_A3 220
#define NOTE_A4 440
#define NOTE_A5 880
#define NOTE_B3 247
#define NOTE_B4 494
#define NOTE_B5 988
#define NOTE_Cs4 277
#define NOTE_Cs5 554
#define NOTE_Cs6 1109
#define NOTE_D4 294
#define NOTE_D5 587
#define NOTE_E4 330
#define NOTE_E5 659
#define NOTE_E6 1319
#define NOTE_Fs3 185
#define NOTE_Fs4 370
#define NOTE_Fs5 740
#define NOTE_Gs3 208
#define NOTE_Gs4 415
#define NOTE_Gs5 831
#define REST 0

const int speakerPin = 12;

struct Note
{
  int frequency;
  float duration;
};

Note mySong[] = {
    {NOTE_Fs4, 0.18},
    {REST, 0.36},
    {NOTE_E4, 0.35},
    {NOTE_Cs4, 2.84}};

int songLength = sizeof(mySong) / sizeof(mySong[0]);

void setup()
{
  pinMode(speakerPin, OUTPUT);
}

void loop()
{
  for (int i = 0; i < songLength; i++)
  {
    if (mySong[i].frequency > 0)
    {
      playNote(mySong[i].frequency, mySong[i].duration * 0.8);
    }
    else
    {
      delay(mySong[i].duration * 1000); // 1000);
    }
    delay(20); // Small gap for clarity
  }
  delay(3000);
}

void playNote(int rate, float seconds)
{
  if (rate <= 0)
    return;
  long p_rate = 1000000 / (rate * 2);
  long cycles = (seconds * 1000000) / (p_rate * 2);

  for (long i = 0; i < cycles; i++)
  {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(p_rate);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(p_rate);
  }
}
