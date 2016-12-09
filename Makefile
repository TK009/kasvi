#SKETCH = 

#mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
#current_dir := $(patsubst %/,%,$(dir $(mkfile_path)))
ESP_ROOT=$(HOME)/Arduino/esp8266

#LIBS += Ticker TickerScheduler

UPLOAD_PORT = /dev/ttyUSB0
BOARD = nodemcuv2

include $(HOME)/coding/hacks/makeEspArduino/makeEspArduino.mk
