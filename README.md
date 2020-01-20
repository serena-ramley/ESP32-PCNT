# ESP32-softAP-PCNT

## Set up your IDE
(i) Download the Arduino IDE: https://www.arduino.cc/en/Main/Software <br>
(ii) Download an FTDI driver: https://learn.sparkfun.com/tutorials/how-to-install-ftdi-drivers/all <br>
(iii) Install the ESP32 board onto your Arduino IDE: https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/ <br><br>
For more background, refer to: https://randomnerdtutorials.com/install-esp32-filesystem-uploader-arduino-ide/

## To upload code:
(0) Open the file or folder in your Arduino IDE. Plug in the board via USB. Select Tools -> Port -> Select the correct COM port and Tools -> Board -> ESP32 Dev Module <br>
(i) Press "Upload" in the Arduino IDE<br>
(ii) After it's done compiling, hold down the "boot" button on the ESP32 board. See Pin Layout section below<br>
(iii) After Connecting... changes to Writing..., release the "boot" button<br>

I would generally recommend not connecting the circuit to the board when uploading, in case any pins may have different input/output settings. After uploading the connect, disconnect the board from USB to remove power, then connect the circuit, then plug the board back into USB (or power).

## Pulse Count References

(i) This is the original documentation: https://docs.espressif.com/projects/esp-idf/en/latest/api-reference/peripherals/pcnt.html <br>
(ii) This is an example recommended by the documentation. Note that it uses RTOS, which is not relevant for us: https://github.com/espressif/esp-idf/blob/647cb628a11a9ebd6952276fb7e6f354d4e3171d/examples/peripherals/pcnt/main/pcnt_example_main.c <br>


## Pin Layout 

ESP32 datasheet: https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf <br>

The pin layout may vary depending on manufacturer, but the pins should be labelled on your board. <br>
This uses GPIO4 as Pulse Input PIN (PCNT_INPUT_SIG_IO in my-pcnt.h) <br>
You can connect an external pulse generator to GPIO4, or ESP32 GPIO18 automatically generates a 1 kHz pulse. <br>

NOTE: Some manufacturers label the push buttons as "EN" and "IOO". Others label them as "RST" and "BOOT", respectively.
