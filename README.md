# STM32-BAD-USB

STM32-BAD-USB is a DIY USB [rubber ducky](https://shop.hak5.org/products/usb-rubber-ducky) implementation using an STM32 microcontroller.This project was developed as part of our microcontroller course during the Winter-Fall semester of 2023 at Isfahan University of Technology. It was created and developed by [Yasin](https://github.com/Orgonah) and [me:)](https://github.com/alidakik).

## Overview

The project aims to replicate the functionality of a USB [rubber ducky](https://shop.hak5.org/products/usb-rubber-ducky) using an STM32 microcontroller. By emulating a keyboard, this device can automate keystrokes for security testing and penetration testing purposes.

The chip presents itself as a keyboard upon connection via the USB port, executing a rapid sequence that includes launching PowerShell, installing, and running a PowerShell reverse shell, all accomplished in 4 seconds.






## Hardware Requirements

- stm32F103C8 (We used the Blue Pill board)




![Example GIF](https://github.com/alidakik/STM32-BAD-USB/blob/main/example.gif)
