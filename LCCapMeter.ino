volatile uint32_t counts;
IntervalTimer myTimer;
double capF;
const double indH = 0.001;
const double twoPi = 6.283185;

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
  Serial.println(capF);
  counts = 0;
  
}

void loop()
{
  while (1);
}
