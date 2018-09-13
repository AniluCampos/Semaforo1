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
  

  digitalWrite(led_1,HIGH);//El led verde del carro enciende
  digitalWrite(led_5,HIGH);//El led rojo peatonal enciende
 
  parpadeo(led_1);//El led_1 va al método parpadeo
  
  digitalWrite(led_2, HIGH);//Prende el led amarillo
  delay(3000);
  digitalWrite(led_2, LOW);//Apaga el led amarillo
  
  digitalWrite(led_3, HIGH);//Prende el led rojo de los autos
  digitalWrite(led_4, HIGH);//Prende el led verde de los peatones
  digitalWrite(led_5, LOW);//Se apaga el led rojo de los peatones
  delay(10000);
  parpadeo(led_4);//Parpadea el led verde peatonal
  digitalWrite(led_3, LOW);//Se apaga el led rojo de los autos
  digitalWrite(led_4, LOW);//Se apaga el led verde peatonal
  
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
 

  
