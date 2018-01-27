const int contactInputPin = 2;
const int speakerPin = 8;

void setup() {
  Serial.begin(9600);
  log("start");
  pinMode(contactInputPin, INPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  checkContactInputs();
  gameLogic();  
  controlSoundOutputs();
}

bool isCircuit1Closed = false;
void checkContactInputs() {
  isCircuit1Closed = digitalRead(contactInputPin) == HIGH;
}

bool wasCircuit1Closed = false;
void gameLogic() {
  if (isCircuit1Closed && !wasCircuit1Closed) {
    wasCircuit1Closed = true;
    startSound();
  }
}

unsigned long soundStartTime = 0;
int soundPeriod = 0;
void startSound() {
  soundStartTime = micros();
  soundPeriod = 1000000 / 1000; // microseconds
}

void stopSound() {
  soundPeriod = 0;
  digitalWrite(speakerPin, LOW);
}

void controlSoundOutputs() {
  if (soundPeriod == 0) return;
  unsigned long now = micros();
  if ( ((now - soundStartTime) / soundPeriod) % 2 == 0) {
    digitalWrite(speakerPin, HIGH);
  } else {
    digitalWrite(speakerPin, LOW);
  }
}

void log(char* message) {
    Serial.println(message);
}

void log(int message) {
    Serial.println(message);
}
