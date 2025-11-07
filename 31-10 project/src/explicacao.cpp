// Pular para o conteúdo principal
// Google Sala de Aula
// Sala de Aula
// 1DI-GOOGLE-25
// Início
// Agenda
// Minhas inscrições
// Pendentes
// 1
// 1DI-GOOGLE-25
// Turmas arquivadas
// Configurações
// 26 - 31/10 - Strings e char
// 26 - 31/10 - Strings e char
// Odirlei Sabella de Assis
// •
// 11:58 (editado: 12:04)
// 1 - O usuário digita um texto pelo (ex: "LED ON" ou "LED OFF").
// Se o texto terminar com "ON" → exiba: LIGAR LED
// Se terminar com "OFF" → exiba: DESLIGAR LED
// Caso contrário → exiba: COMANDO INVÁLIDO

// 2 - Converter texto misto e extrair número
// String mensagem = "Temperatura = 27C";
// Extraia somente o número Converta para inteiro
// Exiba o valor convertido para Fahrenheit


// 3 - Detectar palavra dentro da frase (char[])  
// char frase[] = "ESTAMOS APRENDENDO ARDUINO NA AULA";
// Verifique se a palavra "ARDUINO" está presente.
// Se sim, exiba:
// CONTEÚDO RELACIONADO A ARDUINO DETECTADO
// Caso contrário:
// NÃO ENCONTRADO


// 4 - Alternar maiúsculas e minúsculas   
// String frase = "sEnAi eSp32 ArDuInO";
// Transforme para tudo maiúsculo → exiba
// Depois transforme para tudo minúsculo → exiba
// Depois transforme deixando apenas a primeira letra maiúscula  → exiba
// String() | Arduino Documentation
// https://docs.arduino.cc/language-reference/pt/vari%C3%A1veis/data-types/stringObject/

// char | Arduino Documentation
// https://docs.arduino.cc/language-reference/en/variables/data-types/char/

// main.cpp
// Texto

// Comentários da turma

// Adicionar comentário para a turma...

// Detalhes do material
// #include <Arduino.h>

// // char - mais recomendado para uso profissional
// // String - mais facil

// char palavra[10] = {'O', 'L', 'A', ' ', 'M', 'U', 'N', 'D', 'O', '\0'};
// char palavra2[] = "OLA MUNDO";
// String palavra3 = "OLA MUNDO";

// void setup()
// {
//   Serial.begin(9600);
//   Serial.println();
//   Serial.println(palavra2);

//   //----------------- FUNCOES PARA CHAR -----------------
//   strcpy(palavra2, "SENAI"); // substitui o valor anterior
//   // Serial.println(palavra2);

//   // Serial.println(strcmp(palavra2, "SENAI"));//se for igual retorna 0
//   // if (strcmp(palavra2, "SENAI") == 0)
//   // {
//   //   Serial.println("são iguais");
//   // }else
//   // {
//   //   Serial.println("são diferentes");
//   // }

//   // Serial.println(strncmp(palavra2, "senai", 5));
//   // compara a quantidade de caracteres

//   // if (strncmp(palavra2, "SENAI", 5) == 0)
//   //  if (!strncmp(palavra2, "SENAI", 5))
//   //  {
//   //    Serial.println("Quantidade de caracteres iguais");
//   //  }

//   // strstr();// procura dentro da string pela primeira ocorrencia de uma substring
//   //  if (strstr(palavra2, "NAI"))
//   //  {
//   //    Serial.println("palavra encontrada");
//   //  }

//   // Serial.println(strcat(palavra2, "-SP"));
//   // concatena duas strings, ou seja junta

//   //----------------- FUNCOES PARA STRING -----------------
//   // Serial.println(palavra3.length());//retorna a quantidade de caracteres
//   // Serial.println(palavra3.charAt(2));//retorna o caracter da posição indicada
//   // Serial.println(palavra3.substring(2, 5));//retorna um pedaço da string original
//   // Serial.println(palavra3.indexOf('M'));//retorna a posição do elemento procurado
//   // Serial.println(palavra3.lastIndexOf('O'));//retorna a posição do utlimo elemento procurado

//   // equals() //Compara se é igual
//   //  if (palavra3.equalsIgnoreCase("ola mundo"))
//   //  {Serial.println("iguais");}

//   // if (palavra3.startsWith("OLA"))
//   // {Serial.println("o inicio e igual");}

//   // if (palavra3.endsWith("DO"))
//   // {Serial.println("o fim e igual");}

//   // palavra3.toUpperCase();//converte para caixa alta
//   // palavra3.toLowerCase();//converte para caixa baixa
//   // Serial.println(palavra3);

//   // String valor = "100";
//   //int numero = valor.toInt();
//   // float numeroF = valor.toFloat();

//   // String texto = "texto           ";
//   // texto.trim();

//   // String instrucao = "Led = ON";
//   // instrucao.replace("ON", "OFF");
//     Serial.setTimeout(5000);
//     String texto = Serial.readStringUntil('\n');
//     texto.trim();
//     Serial.printf("voce digitou %s!", texto);
//     //Serial.printf("variavel1 : %s, variavel2 : %i", texto, numero);

// }

// void loop()
// {
// }
