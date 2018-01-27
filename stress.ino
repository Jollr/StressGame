const int speakerPin = 8;

void setup() {
  Serial.begin(9600);
  log("start");
  pinMode(speakerPin, OUTPUT);
  playSound();
}

void loop() {
  log("loop");
  controlSound();
}

bool playingSound = false;
unsigned long soundStartTime = 0;
int soundPeriod = 0;
void playSound() {
  if (playingSound) return;

  playingSound = true;
  soundStartTime = micros();
  soundPeriod = 1000000 / 196; // microseconds
}

void stopSound() {
  playingSound = false;
  soundPeriod = 0;
  digitalWrite(speakerPin, LOW);
}

void controlSound() {
  log("1");
  if (soundPeriod == 0) return;
log("2");
  unsigned long now = micros();
  if ( ((now - soundStartTime) / soundPeriod) % 2 == 0) {
    digitalWrite(speakerPin, HIGH);
    log("high");
  } else {
    digitalWrite(speakerPin, LOW);
    log("low");
  }
}

void log(char* message) {
    Serial.println(message);
}

void log(int message) {
    Serial.println(message);
}
