---
parent: Harmony 3 peripheral library application examples for PIC32MM family
title: CLC Manchester Encoder
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# CLC Manchester Encoder

This example application shows how to use the CLC peripheral library and generate a Manchester-encoded output.

## Description

This demonstrates a way to generate a Manchester-encoded output using a SPI port and the CLC. The SPI port is sending out a predefined buffer of data in a circular fashion. Data is sent out LSB first, with CLCOUT being the Manchester-encoded output. Pins are configured such that a logic analyzer can be attached to see the input (MOSI and REFCLKO) and the output (CLCOUT) simultaneously.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32mm) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/clc/manchester_encoder/firmware**.

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
|pic32mm_usb_curiosity.X| MPLABX project for [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107)|


## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
|pic32mm_usb_curiosity.X|[PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107)|


### Setting up [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107)
- RB15 (on mikrobus socket J4) has REFCLKO output, which is internally connected to CLC
- RD0 (pin 5 on J10) has MOSI output, which is internally connected to CLC
- RB0 (on mikrobus socket J12) has CLC output (CLC1OUT)
- Connect the Debug USB port on the board to the computer using a micro USB cable


## Running the Application

1. Connect a logic analyzer to MOSI pin
2. Connect a logic analyzer to REFCLKO pin
3. Connect a logic analyzer to the Manchester-encoded output CLC1OUT pin
4. Refer to the following table for pin details:

    |Board| MOSI pin | REFCLKO pin  | CLCOUT pin |
    |-----|----------|----------|-------------|
    | [PIC32MM USB Curiosity board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320107) | RD0 (pin 5 on J10)| RB15 (on mikrobus socket J4)| RB0 (on mikrobus socket J12) |
    ||||

5. Build and Program the application using its IDE
6. Observe the output on logic analyzer, it should follow the truth table as shown in the following diagram:

    ![output](images/truth_table_manchester_encoder.png)
