---
parent: Harmony 3 peripheral library application examples for PIC32MM family
title: CCP Compare Mode
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# CCP Compare Mode

This example shows how to use the CCP module in compare mode to generate an dual edge, active high, and toggle output on compare match.

## Description

Three TC channels are configured in compare mode. Each channel generates different output waveform depending upon configured action on compare match and period match.
- Dual Edge output: Output is set high on compare A match and is set low on compare B match.
- Active high output: Output is set high on compare A match and remains high.
- Toggle output: Output toggles on compare A match.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32mm) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/ccp/ccp_compare_mode/firmware** .

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| pic32mm_usb_curiosity.X | MPLABX project for [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107) |
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32mm_usb_curiosity.X | [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107) |
|||

### Setting up [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107)

- Connect micro USB cable to the 'USB1' connector on the board to the computer

## Running the Application

1. Build and program the application project using its IDE
2. Observe generated waveforms on the oscilloscope

| OC Pin   | Port Pin      | Observable characteristic of the waveform
| ----------------| ---------| -----------------------------------------|
| OCM1A | RA12 (Pin on J12)  | Dual Edge ouptut with 5 kHz frequency |
| OCM4 | RA7 (Pin on J12)  | Active high output |
| OCM2D | RB1 (Pin on J4) | Toggle output with 2.5 kHz frequency |
||||
