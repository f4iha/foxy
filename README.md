# Foxy, a radio beacon based on SI5351

Based on the SI5351 clock generator, this is a simple VHF beacon with the target to be used for "Fox hunt". It explains its name : foxy.

To know more about the projet : [the article in french](https://www.f4iha.fr/2024/12/04/foxy-un-module-de-chasse-au-renard-pour-quelques-euros/)

## Hardware

The harware is based on an Arduino Nano, a SI5351 and a filter based on LC components.
The Kicad project (schema and PCB) are available in the electronics folder. Fabrication files are available in the electronics/foxy/Gerber folder.

## Software

Very simple software here which relying on the SI5351 library from https://github.com/etherkit/Si5351Arduino
The code can be built and deployed with platform.io