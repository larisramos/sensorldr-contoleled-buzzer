/* 
========================================================================
TÍTULO: Controle de leds e ativação do buzzer por meio do Sensor LDR
=========================================================================
AUTOR: LARISSA RAMOS
LinkedIn: https://www.linkedin.com/in/lariramos/  
GitHub: https://github.com/larisramos
Link do circuito no TinkerCAD: https://www.tinkercad.com/things/jZriqgBq9AL-copy-of-ligar-e-desligar-um-led-utilizando-sensor-ldr/editel?sharecode=VEnljwr0uNiPwxsqJCHgaVmOz7kXljxFA5I_rOBSICA
========================================================================
*/

int buzzer = 6;
int ledAzul = 12; //Atribui o valor 12 a variável ledAzul
int ledVermelho = 13; //Atribui o valor 13 a variável ledVermelho
int ldr = A0; //Atribui A0 a variável ldr
int valorldr = 0;//Declara a variável valorldr como inteiro


void setup() {
  pinMode (buzzer, OUTPUT); // Define o buzzer (pino digital 6) como saída
  pinMode (ledAzul, OUTPUT); //Define ledAzul (pino digital 12) como saída
  pinMode (ledVermelho, OUTPUT); //Define ledVermelho (pino digital 13) como saída
  pinMode (ldr, INPUT); //Define ldr (pino analógico A0) como saída  
  Serial.begin(9600); //Inicialização da comunicação serial, com velocidade de comunicação de 9600
}

void loop() {
   valorldr = analogRead (ldr);//Lê o valor do sensor ldr e armazena na variável valorldr
   
   if((valorldr) < 100) { //Se o valor de valorldr for menor que 100 OU SEJA SE ESTIVER ESCURO:
    digitalWrite(ledAzul, HIGH); //Coloca led Azul em alto para acioná-lo
        tone(buzzer, 1500);//Ligando o buzzer com uma frequência de 1500 Hz.
        delay(500);//Intervalo de 500 milissegundos
        noTone(buzzer);//Desligando o buzzer.
        delay(500); //Intervalo de 500 milissegundos   
    Serial.println ("---- Atencao! Presenca detectada ----"); // Escreve no terminal a mensagem
    Serial.print ("Valor capturado pelo sensor LDR = ");
    Serial.println(valorldr); //Imprime na serial os dados de valorldr
    delay (1000); // Espera 1 segundo
  }  
  else{ //Senão: 
    digitalWrite(ledAzul, LOW); //Coloca led Azul em baixo para que o mesmo desligue ou permaneça desligado
    digitalWrite(buzzer, LOW); //Coloca buzzer em alto para acioná-lo
	  digitalWrite(ledVermelho, HIGH); //Coloca led Vermelho em alto para acioná-lo  
    Serial.println ("---- MONITORANDO O AMBIENTE ----"); // Escreve no terminal a mensagem
    Serial.print ("Valor capturado pelo sensor LDR = ");
    Serial.println(valorldr); //Imprime na serial os dados de valorldr
    delay (1000);
  }  
}