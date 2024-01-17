# STM32-BAD-USB

STM32-BAD-USB is a DIY USB rubber ducky implementation using an STM32 microcontroller.

## Overview

The project aims to replicate the functionality of a [USB rubber ducky](https://shop.hak5.org/products/usb-rubber-ducky) using an STM32 microcontroller. By emulating a keyboard, this device can automate keystrokes for security testing and penetration testing purposes.

The project presents itself as a keyboard upon connection via the USB port, executing a rapid sequence that includes launching PowerShell, installing, and running a PowerShell reverse shell, all accomplished in 4 seconds.






## Hardware Requirements

- stm32F103C8 (We used the Blue Pill board)

