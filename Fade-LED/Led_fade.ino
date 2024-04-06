//initializing pins
const int led = 3;
const int led_b = 5;
const int led_c = 6;

//setting ouput for pins
void setup(){
  pinMode(led,OUTPUT);
  pinMode(led_b,OUTPUT);
  pinMode(led_c,OUTPUT);
}

//fade function for ease on-ff
void fade(int a){
  //brightness increasing
    for(int b = 0;b<=255;b++){ //loop for brightness
    delay(1);
    analogWrite(a,b);
  }
  delay(0.2);
  //brightness decreasing
  for(int b = 255;b>=0;b--){
    delay(1.3);
    analogWrite(a,b);
  } 
}
//main function
void loop(){
  fade(led_c); //calling function
  // delay(5); 
  fade(led_b);
  // delay(5);
  fade(led);
  // delay(5);
}