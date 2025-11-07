//  #include <Arduino.h>
// #include <BluetoothSerial.h>

// BluetoothSerial BT;

//   //65:0B:54:A3:86
// uint8_t endSlave[] = {0x14, 0x33, 0x5C, 0x0B, 0x2B, 0x76};

// void setup(){
//     Serial.begin(9600);
//     Serial.setTimeout(5000);

//     if (BT.begin("EspMasterOdirlei", true))
//     {
//         Serial.println("Bluetooth iniciado com sucesso");
//     }else
//     {
//         Serial.println("Erro ao iniciar o bluetooth");
//     }

//     if (BT.connect(endSlave))
//     {
//         Serial.println("Conectado com sucesso");
//     }else{
//         Serial.println("Erro ao conectar");
//     }    
// }

// void loop(){
//     if (BT.available())
//     {
//         String mensagemRecebida = BT.readStringUntil('\n');
//         mensagemRecebida.trim();
//         Serial.printf("Mensagem recebida: %s", mensagemRecebida);
//     }

//     if (Serial.available())
//     {
//         String mensagemEnviar = Serial.readStringUntil('\n');
//         mensagemEnviar.trim();
//         BT.println(mensagemEnviar);
//     }
// }
