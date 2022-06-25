#define echoPin 2 //Defining which port echoPin is connected to
#define trigPin 3 //Defining which port trigPin is connected to

//Define variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); //Set trigPin as output
  pinMode(echoPin, INPUT); //Set echoPin as input
  Serial.begin(9600); //Starting serial communication
}
void loop() {
  digitalWrite(trigPin, LOW); //Resetting trigPin
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //Turning on trigPin
  delayMicroseconds(10); //Waiting 10 microseconds
  digitalWrite(trigPin, LOW); //Turning off trigPin
  duration = pulseIn(echoPin, HIGH); //The time it takes to get the signal back - duration
  distance = duration * 0.034 / 2; //Calculating the distance
  Serial.print("Distance: "); //Printing distance in centimeters
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 100)
  {
    Serial.println ("DETECTED"); //If the distance is less than 100cm, the serial monitor will report "Detected"
  }
}
