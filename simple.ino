/*
Este programa foi inspirado no exemplo disponível pela proprioa biblioteca DallasTemperature
Segue o link, do código exemplo:
https://github.com/DerGraff/DallasTemperature/blob/master/examples/Simple/Simple.ino
Esse programa tem a intenção de ser autoexplicatico através de 
comentários simplificados e em portguês.
*/

#include <OneWire.h>
#include <DallasTemperature.h>

// O cabo de dados do sensor está plugado no porta 8 do arduino
#define ONE_WIRE_BUS 8
//Se necessário pode mudar o cabo de porta e alterar o número "8" para a respectiva porta.


//Cria e configura uma instância para comunicar com dispositivos do tipo OneWire
//OneWire é o protocolo que o sensor DS18B20 utiliza para recolher os dados
OneWire oneWire(ONE_WIRE_BUS);

//Aqui você passa a referencia oneWire para a biblioteca DallasTemperature
DallasTemperature sensors(&oneWire);
float temp=0;
/*
 * A função setup, configura o sensor de temperatura
 */
void setup(void)
{
  //Inicializa a porta Serial com baud Rate em 9600
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Inicializa da Biblioteca do sensor
  sensors.begin();
}

/*
 * Abaixo an função loop iremos pegar a temperatura e exibir ela no Monito
 */
void loop(void)
{
  // Execute sensors.requestTemperatures() para requisitar as temperaturas
  // dessa maneira, a biblioteca pede as temperaturas para todos os sensores conectados na barra
  //nesse exemplo temos somente o sensor de Temperatura...
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures(); // Envia o comando para recolher as temperaturas
  Serial.println("DONE");
  // Depois de recolher as temperaturas podemos "printar" elas na tela
  // BNós usaremoes a função "getTempByIndex", 
  temp = sensors.getTempCByIndex(0);

  //Aqui checamos se a leitura foi válida
  if (tempC != DEVICE_DISCONNECTED_C)
  {
    Serial.print("Temperatura lida: ");
    Serial.println(temp);
  }
  else
  {
    Serial.println("Erro: Não foi possível ler a temperatura");
  }
}
