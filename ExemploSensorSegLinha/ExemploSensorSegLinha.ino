int SegLinha = 7;

void setup() {
  Serial.begin(9600);
  pinMode(SegLinha, INPUT); //DEFINE O PINO COMO ENTRADA
}

void loop() {
  int val = digitalRead (SegLinha); 
  if (val == LOW) //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
    Serial.println("Branco...");
  else
    Serial.println("Preto...");
  delay(100);
}
