/*Ana Luisa Campos Magallanes
 * Instituto Tecnologico de León
 * Ingeniería en Sistemas Computacionales
 * Sistemas Programables 
 * 
 * Semaforo Interactivo
 */

 
const int led_1 = 2; //Led Verde Carro
const int led_2 = 3; //Led Amarillo Carro
const int led_3 = 4; //Led Rojo Carro
const int led_4 = 5; //Led Verde Peaton
const int led_5 = 6; //Led Rojo Peaton
const int boton_1 = 0; //Botón
const int pot = A0;//Potenciometro
const int buzzer = 9;//Bocina

int tiempoVerde=0;
int tiempo2=0;
int valorPot=0;
int nDelay=0;

void setup(){
  Serial.begin(9600);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(boton_1, INPUT);

}
void loop(){
  
  valorPot=analogRead(pot);//Leemos el valor del potenciometro y lo asignamos a la variable
  nDelay=map(valorPot, 0, 655, 10, 30)*1000;//Mapeamos el valor del potenciometro
  
  if(digitalRead(boton_1)==HIGH)
  {
    digitalWrite(led_1,HIGH);//El led verde del carro enciende
    digitalWrite(led_5,HIGH);//El led rojo peatonal enciende
    tiempoVerde=millis()-tiempo2; //Asignamos a la variable tiempoVerde el tiempo que el led verde lleva encendido
    Serial.println(tiempoVerde);//Imprimimos el tiempoVerde
  }
  else //Al ser presionado el botón comienza esta parte del ciclo
  {
  Serial.println(tiempoVerde);
  Serial.println(nDelay);
  
  if(tiempoVerde<nDelay){
  Serial.println(nDelay-tiempoVerde);
  delay(nDelay-tiempoVerde);
  }//Si el semaforo de los autos no ha cumplido el tiempo rquerido mínimo establecido por el potenciometro lo cumple
  parpadeo(led_1);//El led_1 va al método parpadeo
  
  digitalWrite(led_2, HIGH);//Prende el led amarillo
  delay(3000);
  digitalWrite(led_2, LOW);//Apaga el led amarillo
  
  digitalWrite(led_3, HIGH);//Prende el led rojo de los autos
  digitalWrite(led_4, HIGH);//Prende el led verde de los peatones
  digitalWrite(led_5, LOW);//Se apaga el led rojo de los peatones
  tone(buzzer,440);//Inicia a sonar la bocina
  delay(10000);
  parpadeo2(led_4,buzzer);//Parpadea el led verde peatonal y el sonido
  digitalWrite(led_3, LOW);//Se apaga el led rojo de los autos
  digitalWrite(led_4, LOW);//Se apaga el led verde peatonal
  tiempo2=millis();//Guardamos el tiempo transcurrido en una variable
  }
}
  void parpadeo(int pin){

    for(int i=0; i<4; i++){ //Ciclo que se repite 4 veces
      digitalWrite(pin,HIGH);
      delay(400);
      digitalWrite(pin,LOW);
      delay(400);
    }
  }

  void parpadeo2(int pin, int pin2){//Ciclo que incluye una intermitencia en el sonido y el led

    for(int i=0; i<4; i++){ //Ciclo que se repite 4 veces
      digitalWrite(pin,HIGH);
      tone(pin2,440);
      delay(400);
      digitalWrite(pin,LOW);
      noTone(pin2);
      delay(400);
    }
  }
 

  
