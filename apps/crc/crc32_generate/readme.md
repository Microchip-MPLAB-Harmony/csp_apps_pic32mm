---
parent: Harmony 3 peripheral library application examples for PIC32MM family
title: CRC-32 Generation
has_children: false
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# CRC-32 Generation

This example application demonstrates how to use the CRC peripheral to compute 32-bit Cyclic Redundancy Checksum (CRC).

## Description

The CRC unit provides support for calculating a CRC-8, CRC-16 and CRC-32 value on a user buffer or Flash memory without CPU intervention.

This example application computes the 32-bit CRC value for the poynomial **(0x04C11DB7)** using the CRC peripheral.

Once the hardware CRC is generated, it is validated using a software-calculated CRC value.

## Downloading and building the application

To clone or download this application from Github, go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/csp_apps_pic32mm) and then click **Clone** button to clone this repository or download as zip file.
This content can also be downloaded using content manager by following these [instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki).

Path of the application within the repository is **apps/crc/crc32_generate/firmware**

To build the application, refer to the following table and open the project using its IDE.

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| pic32mm_curiosity.X | MPLABX project for [PIC32MM Curiosity Development Board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320101)|
|||

## Setting up the hardware

The following table shows the target hardware for the application projects.

| Project Name| Board|
|:---------|:---------:|
| pic32mm_curiosity.X | MPLABX project for [PIC32MM Curiosity Development Board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320101)|
|||

### Setting up [PIC32MM Curiosity Development Board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320101)
- To run the demo, the following additional hardware are required:
  - [USB UART click board](https://www.mikroe.com/usb-uart-click)

- Connect micro USB cable to the 'USB1' connector on the board to the computer
- Install an [USB UART click board](https://www.mikroe.com/usb-uart-click) on to the mikroBUS socket J4
- Connect mini USB cable between PC and the [USB UART click board](https://www.mikroe.com/usb-uart-click)
  - *Note: Ensure that the series resistors on the mikroBUS headers are of value 0 Ohms*

## Running the Application

1. Open the Terminal application (Ex.:Tera term) on the computer
2. Connect to the "USB to UART" COM port and configure the serial settings as follows:
    - Baud : 115200
    - Data : 8 Bits
    - Parity : None
    - Stop : 1 Bit
    - Flow Control : None
3. Build and Program the application project using its IDE

4. Following message is output on console:
   - Expected CRC Value for the polynomial **(0x04C11DB7)** is **(0xcbf43926)**

   ![output_crc32_generate](images/output_crc32_generate.png)

5. The LED indicates the success or failure:
   - LED1 is turned ON when the hardware CRC value matches with the software calculated CRC value

Following table provides LED names:

| Board | LED name |
| ----- | -------- |
| [PIC32MM Curiosity Development Board](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320101) | LED1|
|||
