#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"

#define OUTPUT_PIN GPIO_PIN_6
#define OUTPUT_PORT GPIOA
#define INPUT_PIN GPIO_PIN_7
#define INPUT_PORT GPIOB

void SystemClock_Config(void);
void GPIO_Init(void);

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  GPIO_Init();

  while (1)
  {
    // Set the outputPin high
    HAL_GPIO_WritePin(OUTPUT_PORT, OUTPUT_PIN, GPIO_PIN_SET);

    // Delay for 0.25 seconds
    HAL_Delay(250);

    // Set the outputPin low
    HAL_GPIO_WritePin(OUTPUT_PORT, OUTPUT_PIN, GPIO_PIN_RESET);

    // Delay for another 0.25 seconds
    HAL_Delay(250);

    // Read the inputPin value
    GPIO_PinState inputPinState = HAL_GPIO_ReadPin(INPUT_PORT, INPUT_PIN);

    // Use the inputPinState as needed (e.g., perform actions based on its value)
  }
}

void SystemClock_Config(void)
{
  // Configure system clock as needed
}

void GPIO_Init(void)
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitTypeDef GPIO_InitStruct;

  // Configure the outputPin as digital output
  GPIO_InitStruct.Pin = OUTPUT_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OUTPUT_PORT, &GPIO_InitStruct);

  // Configure the inputPin as digital input
  GPIO_InitStruct.Pin = INPUT_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(INPUT_PORT, &GPIO_InitStruct);
}
