
#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_TMAG5273_Arduino_Library.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#define PCAADDR 0x70
//#define DEV_I2C Wire
#define SerialPort Serial

// create two instances of the sensor
TMAG5273 hallSensor[4];
//, mag2, mag3, mag4;
uint8_t i2cAddress = 0X35;
uint8_t avgMode = 0x1;

void pcaselect(uint8_t i) {
  if (i > 3) return;

  Wire.beginTransmission(PCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

void readHallSensor(int index) {
  // define port on the PCA9546
  pcaselect(index);
  float data_raw[4];

  // Assuming hallSensor1, mag2, mag3, and mag4 are instances of your magnetometer class
  switch (index) {
    case 0:
      data_raw[0] = hallSensor[0].getXData();
      data_raw[1] = hallSensor[0].getYData();
      data_raw[2] = hallSensor[0].getZData();
      //data_raw[3] = hallSensor[0].getTemp();
      break;
    case 1:
      data_raw[0] = hallSensor[1].getXData();
      data_raw[1] = hallSensor[1].getYData();
      data_raw[2] = hallSensor[1].getZData();
      //data_raw[3] = hallSensor[1].getTemp();
      break;
    case 2:
      data_raw[0] = hallSensor[2].getXData();
      data_raw[1] = hallSensor[2].getYData();
      data_raw[2] = hallSensor[2].getZData();
      //data_raw[3] = hallSensor[2].getTemp();
      break;
    case 3:
      data_raw[0] = hallSensor[3].getXData();
      data_raw[1] = hallSensor[3].getYData();
      data_raw[2] = hallSensor[3].getZData();
      //data_raw[3] = hallSensor[3].getTemp();
      break;
    default:
      // Handle error
      return;
  }
  char report[100];
  snprintf(report, sizeof(report), "Mag %d - X = %f, Y = %f, Z = %f\r\n", index, data_raw[0], data_raw[1], data_raw[2]);
  SerialPort.println(report);
}

// standard Arduino setup()
void setup()
{
  while (!Serial);
  delay(1000);

  Wire.begin();
  Wire.setClock(1e6);

  Serial.begin(115200);
  Serial.println("\nMultiSensor PCA9546");

  for (int i = 0; i < 4; i++) {
    pcaselect(i);
    hallSensor[i].begin(i2cAddress, Wire);
  }
}
void loop()
{
  uint8_t status;
  long int t1 = millis();

  for (int i = 0; i < 4; i++)
    readHallSensor(i);

  long int t2 = millis();
  Serial.print("Time taken: ");
  Serial.println(t2 - t1);

  delay(500);

}
