# TMAG5273_mux
Solution to read x4 TMAG5273 hall sensors using only 1 i2c port and multiplexing

## Components Used

- [Teensy 4.0](https://www.pjrc.com/store/teensy40.html)
- [Adafruit PCA9546 4-Channel I2C Multiplexer](https://www.adafruit.com/product/5663#description)
- [TMAG5273A Hall Sensor](https://www.ti.com/lit/ds/symlink/tmag5273.pdf)

## Wiring

![circuit img](https://github.com/ntnu-arl/TMAG5273_mux/blob/master/tmag_mux_circuit.png)

## Dependencies

- [TMAG5273 Arduino Library](https://github.com/sparkfun/SparkFun_TMAG5273_Arduino_Library)

## Run

- Connect the Teensy via USB to your laptop
- Upload the 4tmag_mux.ino script. By default the multiplexer is connected to the Teensy using i2c-0
- Open the Serial Monitor (ctrl + shift + M) and check the output.


#### Notes
- This is a basic working package. More info, settings, functions and features can be found on the tmag5273 datasheet.
- In this configuration it is possible to read 4 sensors in less than 2ms.
- Soldering directly on the IC requires some skills. Be sure to know what you are doing!


#### Example of output
```
Mag 0 - X = 0.826581, Y = 0.662716, Z = 0.581293

Mag 1 - X = 0.742188, Y = 0.468750, Z = 0.273438

Mag 2 - X = 0.039062, Y = -0.429688, Z = 0.156250

Mag 3 - X = 0.898438, Y = -0.546875, Z = 0.039062

Time taken: 2
```