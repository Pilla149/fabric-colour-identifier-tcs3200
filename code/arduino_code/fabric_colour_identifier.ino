#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

// Structure for colour dataset
struct ColourData {
  int r;
  int g;
  int b;
  String colourName;
};

// CSV-like dataset stored in Arduino
ColourData colours[] = {
  {255, 0, 0, "Red"},
  {0, 255, 0, "Green"},
  {0, 0, 255, "Blue"},
  {255, 255, 0, "Yellow"},
  {255, 165, 0, "Orange"},
  {128, 0, 128, "Purple"},
  {0, 0, 0, "Black"},
  {255, 255, 255, "White"},
  {0, 255, 255, "Cyan"},
  {255, 192, 203, "Pink"}
};

int totalColours = sizeof(colours) / sizeof(colours[0]);

void setup() {

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Frequency scaling 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
}

void loop() {

  // Read RED value
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redFrequency = pulseIn(sensorOut, LOW);

  // Read GREEN value
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);

  // Read BLUE value
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);

  // Convert frequency to approximate RGB range
  int redValue = map(redFrequency, 25, 72, 255, 0);
  int greenValue = map(greenFrequency, 30, 90, 255, 0);
  int blueValue = map(blueFrequency, 25, 70, 255, 0);

  redValue = constrain(redValue, 0, 255);
  greenValue = constrain(greenValue, 0, 255);
  blueValue = constrain(blueValue, 0, 255);

  // Variables for closest match
  int minimumDistance = 100000;
  String detectedColour = "Unknown";

  // Compare with dataset values
  for (int i = 0; i < totalColours; i++) {

    int distance = sqrt(
      pow(redValue - colours[i].r, 2) +
      pow(greenValue - colours[i].g, 2) +
      pow(blueValue - colours[i].b, 2)
    );

    if (distance < minimumDistance) {

      minimumDistance = distance;
      detectedColour = colours[i].colourName;
    }
  }

  // Final Output
  Serial.print("Detected Fabric Colour : ");
  Serial.println(detectedColour);

  delay(1000);
}
