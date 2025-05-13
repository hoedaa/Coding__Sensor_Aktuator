#include "DHT.h"
#define DHTPIN 12     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  h = dht.readHumidity();//baca kelembaban
  t = dht.readTemperature();//baca suhu
  if (isnan(humi) || isnan(temp)) { //jika tidak ada hasil
    Serial.println("DHT11 tidak terbaca... !");
    return;
  }
  else{//jika ada hasilnya 
  Serial.print("Suhu=");  //kirim serial "Suhu"
  Serial.print(t);     //kirim serial nilai suhu
  Serial.println("C");    //kirim serial "C" Celcius 
  Serial.print("Humi=");  //kirim serial "Humi"
  Serial.print(h);     //kirim serial nilai kelembaban
  Serial.println("%");  //kirim serial "%"
  }
  delay(1000);            //tunda 1 detik untuk pembacaan berikutnya
}
