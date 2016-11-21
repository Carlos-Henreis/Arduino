/*
	autor: Carlos Henrique Reis - 2016
	Ideia: Teste o componente HC-SR04 (Ultrasonic Sensor)
	Calcula a distancia e o tempo  e imprime o resultado na porta serial 
	com um deley de 0,1 segundos  
	Não foi utilizado nenhuma biblioteca externa, pois o objetivo deste
	projeto é entender como funciona o componente sensor ultrassonico
*/

#define trigPin 12 //Pino 12 envia o pulso para gerar o echo 
#define echoPin 13 //Pino 13 recebe o pulso do echo 

unsigned long time;
double vel;

void setup() 
{ 
  Serial.begin(9600); //inicia a porta serial 
  pinMode(echoPin, INPUT); // define o pino 13 como entrada (recebe) 
  pinMode(trigPin, OUTPUT); // define o pino 12 como saida (envia) 
  vel = 0.0;
} 

void loop() 
{ 
    //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0 
    digitalWrite(trigPin, LOW); 
    // delay de 2 microssegundos 
    delayMicroseconds(2); 
    //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1 
    digitalWrite(trigPin, HIGH); 
    //delay de 10 microssegundos 
    delayMicroseconds(10); 
    //seta o pino 12 com pulso baixo novamente 
    digitalWrite(trigPin, LOW); 
    //pulseInt lê o tempo entre a chamada e o pino entrar em high 
    long duration = pulseIn(echoPin,HIGH); 
    //Esse calculo é baseado em s = v . t, lembrando que o tempo vem dobrado 
    //porque é o tempo de ida e volta do ultrassom 
    double distancia = duration /29.4 /2.0; 
    time = millis();
    
    Serial.print("[t(ms),d(cm)]: "); 
    Serial.print(time);
    Serial.print(","); 
    Serial.println(distancia);   

    
    delay(1000); //espera 0,1 segundo para fazer a leitura novamente 
}
