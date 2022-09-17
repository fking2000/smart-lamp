int red= D1;
int green = D2;
int blue= D3;
void setup() {
 wifi_Setup();
pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
wifi_loop();
}
