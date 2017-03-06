SKETCH=ClockTest.ino

#mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
#current_dir := $(patsubst %/,%,$(dir $(mkfile_path)))
ESP_ROOT=$(HOME)/Arduino/esp8266

LIBS += $(ESP_LIBS)/Servo \
	$(ESP_LIBS)/Wire \
	$(ESP_LIBS)/Ticker \
	$(ESP_LIBS)/ESP8266WiFi \
	esp8266-SNTPClock \
	firmata \
	.

UPLOAD_PORT = /dev/ttyUSB0
BOARD=nodemcu #nodemcuv2

# Didn't like /tmp ???
BUILD_DIR=bin/
FLASH_DEF=4M3M
UPLOAD_SPEED=460800

EXTRAFLAGS=-DDEBUG_ESP_PORT=Serial

include $(HOME)/coding/hacks/makeEspArduino/makeEspArduino.mk
