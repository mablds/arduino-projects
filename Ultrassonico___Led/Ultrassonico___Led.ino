//Carrega a biblioteca do sensor ultrassonico
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup(){
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  pinMode(13, OUTPUT);  
}
 
void loop(){

  
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  
  if(cmMsec > 30.0){
    Serial.println("Obstáculo afrente");
    digitalWrite(13, HIGH);
  } else {
    Serial.println("Fechou"); // Envia mensagem pela serial
    digitalWrite(13, LOW);
  }
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);
  delay(1000);
}
