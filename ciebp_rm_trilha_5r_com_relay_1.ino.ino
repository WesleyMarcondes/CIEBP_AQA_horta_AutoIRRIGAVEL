// C++ code
/*
 *    Última atualização: 2023-09-14.
 *    AUTOR:   CIEBP Araraquara - Espaço 6 Robótica e Modelagem
 *    LINK:    
 *    SKETCH:  Arduino - Horta auto irrigavel - 
 *    DATA:    14/09/2023
 * 
 *    Ideia geral do código: A horta utiliza um sensor de umidade de solo que faz leituras a cada 11h,
 *    caso SENSOR >= 780 a horta faz a rega por 12 segundos e aguarda 11h até a proxima leitura
 */

int SENSOR = 0;

#define rele 3 // define pino do rele
#define led 8 // define pino do LED
#define nova_leitura  40000000 // tempo em milisegundos - tempo para proxima leitura 
#define irrigacao  12000 // Tempo de que a bomba fica ligada
  
void setup() {
  pinMode(A1, INPUT); //Porta definida como entrada
  pinMode(3, OUTPUT); // Portas definidas como saida
  pinMode(8, OUTPUT); // portas definidas como saida
  
  Serial.begin(9600); // Ativa a leitura Seria  
}
// Loop rodando codigo atual 
void loop() {
  SENSOR = analogRead(A1); // variavel sensor recebe leitura do pino A1
  Serial.println(SENSOR); // Imprime no munitor serial   
  Serial.println(digitalRead(4)); // Imprime no munitor serial a leitura do pinoi 4 
  regar(); // Chama a função regar
    }

 // Função regar   
 void regar(){
  
  if (SENSOR > 750) { // se Avariavel for maior que 750, Roda o codigo dentro das chaves. 
    digitalWrite(led, HIGH); // liga pino do LED
    delay(30000); // aguarda tempo 30 s
    digitalWrite(rele, HIGH); // Liga rele
    delay(irrigacao); // aguarda tempo em s
    digitalWrite(led, LOW); // Desliga LED
    digitalWrite(rele, LOW); // Desliga Rele 
  }
  delay(nova_leitura); // Tempo para nova leitura
    }
  
