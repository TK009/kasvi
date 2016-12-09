#!/bin/bash
set -x -o -e
git submodule init
git submodule update

cd esp8266/tools
python get.py

