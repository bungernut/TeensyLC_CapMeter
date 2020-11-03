volatile uint32_t counts;
IntervalTimer myTimer;
volatile double capF;
const double indH = 0.001;
const double twoPi = 6.283185;
uint32_t currTime = 0;
uint32_t prevTime = 0;
const uint32_t refresh_period = 1000;

void setup() {
  Serial.begin(115200);
  /* //myTimer.begin(function, microseconds); */
  myTimer.priority(128);
  myTimer.begin(dispCounts, 1000000);  // run every 1 seconds

  pinMode(20, INPUT);
  attachInterrupt(digitalPinToInterrupt(20), doCount, FALLING);
}

void doCount()
{
  counts++;
}

void dispCounts()
{
  capF = 1.0 / (pow( (double)counts/1000000.0 * twoPi ,2) * indH) ; 
  counts = 0;
  
}

void loop()
{
  currTime = millis();
  if (currTime - prevTime > refresh_period)
  {
    Serial.println(capF);
    prevTime = currTime;
  }
}
