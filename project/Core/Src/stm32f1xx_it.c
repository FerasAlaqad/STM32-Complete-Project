/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */


ADC_HandleTypeDef hadc1;
TIM_HandleTypeDef htim3;
I2C_HandleTypeDef hi2c1;
ADC_HandleTypeDef hadc1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
UART_HandleTypeDef huart1;




/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

uint8_t EpromGelen[100];
uint8_t RData[20];
uint8_t RDataKopya[20];
char transmitData[100]="  ";


int j1=0;
int j2=0;
int sayac1=0;
int i=0;
int i1=0;
int i2=0;
int i3=0;
int i5=0;
int i6=0;
int kontrolInter=0;
uint8_t i4=0;
uint8_t num1=0;
uint8_t num2=0;
uint8_t EpSayac=0;
uint8_t EpTimkontrol=0;
int32_t TimerSayac=0;
int16_t AdcValue;


//////////Mpu Variabels /////////

#define MPU6050_ADDR 0xD0
#define SMPLRT_DIV_REG 0x19


#define GYRO_CONFIG_REG 0x1B
#define ACCEL_CONFIG_REG 0x1C
#define ACCEL_XOUT_H_REG 0x3B
#define TEMP_OUT_H_REG 0x41
#define GYRO_XOUT_H_REG 0x43
#define PWR_MGMT_1_REG 0x6B
#define WHO_AM_I_REG 0x75


int16_t Accel_X_RAW=0;
int16_t Accel_Y_RAW=0;
int16_t Accel_Z_RAW=0;

int16_t Gyro_X_RAW=0;
int16_t Gyro_Y_RAW=0;
int16_t Gyro_Z_RAW=0;

float Ax,Ay,Az,Gx,Gy,Gz;




////////////bitti///////////////////////


void MPU6050_Init(void){
uint8_t check, Data;
// check device id
HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, WHO_AM_I_REG,1, &check, 1, 1000);
if (check == 0x68){ // boyle bir cihaz varsa
 // power management regisgter 0x6b power up
Data = 0;
HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR,
PWR_MGMT_1_REG,1, &Data, 1, 1000);
//
Data = 0x07;
HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR,
SMPLRT_DIV_REG,1, &Data, 1, 1000);
// set acc. meter configuration in ACCEL_CONFIG reg.

Data = 0x00;
HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR,
ACCEL_CONFIG_REG,1, &Data, 1, 1000);
// Set Gyroscopic configuration in GYRO_CONFIG
//Register
// XG_ST=0,YG_ST=0,ZG_ST=0, FS_SEL=0 -> ? 250 ?/s
Data = 0x00;
HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR,
GYRO_CONFIG_REG, 1, &Data, 1, 1000);
}
}
void MPU6050_Read_Accel (void)
{
uint8_t Rx_data[6];
// Read 6 BYTES of data starting from ACCEL_XOUT_H register
HAL_I2C_Mem_Read (&hi2c1, MPU6050_ADDR, ACCEL_XOUT_H_REG,1, Rx_data, 6,1000);
Accel_X_RAW = (int16_t)(Rx_data[0] << 8 | Rx_data [1]);
Accel_Y_RAW = (int16_t)(Rx_data[2] << 8 | Rx_data [3]);
Accel_Z_RAW = (int16_t)(Rx_data[4] << 8 | Rx_data [5]);
Ax = Accel_X_RAW/16384.0;
Ay = Accel_Y_RAW/16384.0;
Az = Accel_Z_RAW/16384.0;
}
void MPU6050_Read_Gyro (void)
{
uint8_t Rx_data[6];
// read 6 bytes of data starting from GYRO_XOUT_H reg.
HAL_I2C_Mem_Read (&hi2c1, MPU6050_ADDR, GYRO_XOUT_H_REG,1, Rx_data,6, 1000);
Gyro_X_RAW = (int16_t)(Rx_data[0] << 8 | Rx_data [1]);
Gyro_Y_RAW = (int16_t)(Rx_data[2] << 8 | Rx_data [3]);
Gyro_Z_RAW = (int16_t)(Rx_data[4] << 8 | Rx_data [5]);

Gx = Gyro_X_RAW/131.0;
Gy = Gyro_Y_RAW/131.0;
Gz = Gyro_Z_RAW/131.0;
}	


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern UART_HandleTypeDef huart1;
/* USER CODE BEGIN EV */


/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles ADC1 and ADC2 global interrupts.
  */
void ADC1_2_IRQHandler(void)
{
  /* USER CODE BEGIN ADC1_2_IRQn 0 */
  /* USER CODE END ADC1_2_IRQn 0 */
  HAL_ADC_IRQHandler(&hadc1);
  /* USER CODE BEGIN ADC1_2_IRQn 1 */

  /* USER CODE END ADC1_2_IRQn 1 */
}

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void) //8 Scnd timer
{ 
  /* USER CODE BEGIN TIM2_IRQn 0 */
	MPU6050_Init();  
	MPU6050_Read_Accel();
	MPU6050_Read_Gyro();
	AdcValue= (HAL_ADC_GetValue(&hadc1)/16);// change Adc to max 255
	
	sprintf(transmitData,"X:%f,Y:%f,Z:%f,ADC:%d \n \r",Ax,Ay,Az,(int)(AdcValue));
	HAL_UART_Transmit(&huart1,(uint8_t*)transmitData,strlen(transmitData),15 );
	
	RemoveArray(); // array bosalt
	
  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void) //3 Scnd timer
{
  /* USER CODE BEGIN TIM3_IRQn 0 */
	AdcValue= (HAL_ADC_GetValue(&hadc1)/16);
	EpTimkontrol=1;

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */

  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */
  HAL_UART_Receive_IT(&huart1,(uint8_t*) &RData,20);


  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */
	//__HAL_UART_ENABLE_IT(&huart1,UART_IT_RXNE);
	

		
 j1=0;
 j2=0;
 sayac1=0;
 i3=0;
 i1=0;
 i2=0;
 num1=0;
 num2=0;
 kontrolInter=1;

	
  for(i3=0; i3<=15;i3++){
		if(RData[i3]== '<'){
		j1=i3;
		}
		
		if(RData[i3]== '>'){
		j2=i3;
		}		
	 }
	
	
	if (j2<j1){
		sayac1=j2+14-j1;
		i3=0;
		i1=j1+1;
		for(i3=0; i3<sayac1;i3++){
			
		if(i1==15){
		i1=0;		
		}
		
		RDataKopya[i3]=RData[i1];
		i1++;
		}
		}else {
			
	  i2=0;		
	  for(i3=j1+1; i3<j2;i3++){
	  RDataKopya[i2]=RData[i3];
		i2++;
	}
		
		}

		
    __HAL_UART_ENABLE_IT(&huart1,UART_IT_RXNE);

		

	
	
	
	

  /* USER CODE END USART1_IRQn 1 */
}

/* USER CODE BEGIN 1 */
int  RemoveArray(void){
	i=0;		
  while(i<20){ 
	RData[i]=0;
	i++;	
	}
	return 0;
}

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
