script = input("Enter your script that you like to type: ").split()


keyboard = {
            'a' : '0x04',
            'A' : '0x04',
            'b' : '0x05',
            'B' : '0x05',
            'c' : '0x06',
            'C' : '0x06',
            'd' : '0x07',
            'D' : '0x07',
            'e' : '0x08',
            'E' : '0x08',
            'f' : '0x09',
            'F' : '0x09',
            'g' : '0x0A',
            'G' : '0x0A',
            'h' : '0x0B',
            'H' : '0x0B',
            'i' : '0x0C',
            'I' : '0x0C',
            'j' : '0x0D',
            'J' : '0x0D',
            'k' : '0x0E',
            'K' : '0x0E',
            'l' : '0x0F',
            'L' : '0x0F',
            'm' : '0x10',
            'M' : '0x10',
            'n' : '0x11',
            'N' : '0x11',
            'o' : '0x12',
            'O' : '0x12',
            'p' : '0x13',
            'P' : '0x13',
            'q' : '0x14',
            'Q' : '0x14',
            'r' : '0x15',
            'R' : '0x15',
            's' : '0x16',
            'S' : '0x16',
            't' : '0x17',
            'T' : '0x17',
            'u' : '0x18',
            'U' : '0x18',
            'v' : '0x19',
            'V' : '0x19',
            'w' : '0x1A',
            'W' : '0x1A',
            'x' : '0x1B',
            'X' : '0x1B',
            'y' : '0x1C',
            'Y' : '0x1C',
            'z' : '0x1D',
            'Z' : '0x1D',
            '1' : '0x1E',
            '2' : '0x1F',
            '3' : '0x20',
            '4' : '0x21',
            '5' : '0x22',
            '6' : '0x23',
            '7' : '0x24',
            '8' : '0x25',
            '9' : '0x26',
            '0' : '0x27',
            "'" : '0x34',
            ';' : '0x33',
            ':' : '0x33',
            '-' : '0x2D',
            '/' : '0x38',
            '.' : '0x37',
            '\\' : '0x31'


        }




for i in range(len(script)):
    for j in range(len(script[i])):
        if(script[i][j].isupper()):
            print("\tkeyboardhid.MODIFIER = 0x02;")
        print(f"\tkeyboardhid.KEYCODE1 = {keyboard[script[i][j]]};")
        print(f"\tUSBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));\t//press {script[i][j]}\n\tHAL_Delay(50);\n\tkeyboardhid.KEYCODE1 = 0x00;\t\t\t\t//release {script[i][j]}")
        
        if(script[i][j].isupper()):
            print("\tkeyboardhid.MODIFIER = 0x00;\n")

        print("\tUSBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));\n\tHAL_DELAY(50);\n")

    print("\tkeyboardhid.KEYCODE1 = 0x2C;\n\tUSBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));\t//press <SPACE>\n\tHAL_Delay(50);\n\tkeyboardhid.KEYCODE1 = 0x00;\t\t\t\t//release <SPACE>\n\tUSBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));\n")

    print("\tHAL_Delay(50);")
    

