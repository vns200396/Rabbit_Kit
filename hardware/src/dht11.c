#include "dht11.h"
#include "dwt_stm32_delay.h"
#include "bsp_debug_usart.h"

uint8_t DHT11_Init()
{
	GPIO_InitTypeDef GPIO_DHT11TypDef;

	DHT11_CLK_ENABLE();

	GPIO_DHT11TypDef.Pin=DHT11;
	GPIO_DHT11TypDef.Mode= GPIO_MODE_OUTPUT_PP;
	GPIO_DHT11TypDef.Pull = GPIO_PULLUP;
	GPIO_DHT11TypDef.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIO_DHT11, &GPIO_DHT11TypDef);
	HAL_GPIO_WritePin(GPIO_DHT11, DHT11, GPIO_PIN_SET);

	DHT11_Rst();
	return DHT11_Check();
}

void DHT11_Rst()
{
	DHT11_IO_OUT();
    DHT11_DQ_OUT=0;
    HAL_Delay(18);
    DHT11_DQ_OUT=1;
	delay_us(30);
}

uint8_t DHT11_Check()
{
	uint8_t retry=0;
	DHT11_IO_IN();//SET INPUT
    while (DHT11_DQ_IN&&retry<100)
	{
		retry++;
		delay_us(1);
	};
	if(retry>=100)return 1;
	else retry=0;
    while (!DHT11_DQ_IN&&retry<100)
	{
		retry++;
		delay_us(1);
	};
	if(retry>=100)return 1;
	return 0;
}

uint8_t DHT11_Read_Bit(void)
{
	uint8_t retry=0;
	while(DHT11_DQ_IN&&retry<100)
	{
		retry++;
		delay_us(1);
	}
	retry=0;
	while(!DHT11_DQ_IN&&retry<100)
	{
		retry++;
		delay_us(1);
	}
	delay_us(40);
	if(DHT11_DQ_IN)return 1;
	else return 0;
}

uint8_t DHT11_Read_Byte(void)
{
	uint8_t i,dat;
    dat=0;
	for (i=0;i<8;i++)
	{
   		dat<<=1;
	    dat|=DHT11_Read_Bit();
    }
    return dat;
}


uint8_t DHT11_Read_Data(uint8_t *temp,uint8_t *humi)
{
	uint8_t buf[5];
	uint8_t i;
	DHT11_Rst();
	if(DHT11_Check()==0)
	{
		for(i=0;i<5;i++)
		{
			buf[i]=DHT11_Read_Byte();
		}
		if((buf[0]+buf[1]+buf[2]+buf[3])==buf[4])
		{
			*humi=buf[0];
			*temp=buf[2];
		}

	}else return 1;
	return 0;
}

void DHT11_IO_OUT(void)
{
	GPIO_InitTypeDef GPIO_DHT11TypDef;
	GPIO_DHT11TypDef.Pin =DHT11;
	GPIO_DHT11TypDef.Mode= GPIO_MODE_OUTPUT_PP;
	GPIO_DHT11TypDef.Pull = GPIO_PULLUP;
	GPIO_DHT11TypDef.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIO_DHT11, &GPIO_DHT11TypDef);
}


void DHT11_IO_IN(void)
{
	GPIO_InitTypeDef GPIO_DHT11TypDef;
	GPIO_DHT11TypDef.Pin =DHT11;
	GPIO_DHT11TypDef.Mode = GPIO_MODE_INPUT;
	GPIO_DHT11TypDef.Pull = GPIO_PULLUP;
	GPIO_DHT11TypDef.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIO_DHT11, &GPIO_DHT11TypDef);
}


void dht11_test()
{
	uint8_t temp;
	uint8_t humi;
	uint8_t temp_buf[3],humi_buf[3];

	static uint32_t last;

	if(!last)
	{
		last = HAL_GetTick();
	}


	if(HAL_GetTick() - last > 10)
	{
		last = HAL_GetTick();
		DHT11_Read_Data(&temp,&humi);

		temp_buf[0]=temp/10+0x30;
		temp_buf[1]=temp%10+0x30;
		temp_buf[2]='\0';

		printf("[DHT11 Temperature]: %s \r\n",temp_buf);

		humi_buf[0]=humi/10+0x30;
		humi_buf[1]=humi%10+0x30;
		humi_buf[2]='\0';

		printf("[DHT11 Humidity]: %s \r\n",humi_buf);
	}
}
