#include "my9291_led_rbg.h"
#include "bsp_debug_usart.h"
#include "dwt_stm32_delay.h"

static MY9291_CMD_TypDef _command;
static unsigned char _channels = 4;
static bool _state = false;
static MY9291_COLOR_TypDef  _color = {0, 0, 0, 0, 0};

#define debug_rbg


static void di_pulse(unsigned int times) {
	for (unsigned int i = 0; i < times; i++)
	{
		DI =1;
		DI =0;
	}
}

static void dcki_pulse(unsigned int times) {
	for (unsigned int i = 0; i < times; i++)
	{
		DCKI =1;
		DCKI =0;
	}
}

static void write(unsigned int data, unsigned char bit_length)
{

    unsigned int mask = (0x01 << (bit_length - 1));

    for (unsigned int i = 0; i < bit_length / 2; i++) {
		DCKI =0;
		HAL_GPIO_WritePin(DI_PORT, DI_PIN, (data & mask));
		DCKI =1;
        data = data << 1;
		HAL_GPIO_WritePin(DI_PORT, DI_PIN, (data & mask));
		DCKI =0;
        DI =0;
        data = data << 1;
    }
}


static void set_cmd(MY9291_CMD_TypDef command)
{

	// ets_intr_lock();

    // TStop > 12us.
	delay_us(12);

    // Send 12 DI pulse, after 6 pulse's falling edge store duty data, and 12
	// pulse's rising edge convert to command mode.
	di_pulse(12);

    // Delay >12us, begin send CMD data
	delay_us(12);

    // Send CMD data
    unsigned char command_data = *(unsigned char *) (&command);
    write(command_data, 8);

	// TStart > 12us. Delay 12 us.
	delay_us(12);

    // Send 16 DI pulse，at 14 pulse's falling edge store CMD data, and
	// at 16 pulse's falling edge convert to duty mode.
	di_pulse(16);

    // TStop > 12us.
	delay_us(12);

    // ets_intr_unlock();

}

static void send()
{

	// Color to show
	unsigned int duty[6] = {0};
	if (_state) {
        if (_channels == 4) {
            duty[0] = _color.red;
            duty[1] = _color.green;
            duty[2] = _color.blue;
            duty[3] = _color.white;
            duty[4] = 0;
            duty[5] = 0;
        } else {
            duty[0] = _color.white;
            duty[1] = _color.warm;
            duty[2] = 0;
            duty[3] = _color.green;
            duty[4] = _color.red;
            duty[5] = _color.blue;
        }
    }

    unsigned char bit_length = 8;
	switch (_command.bit_width) {
		case MY9291_CMD_BIT_WIDTH_16:
			bit_length = 16;
			break;
		case MY9291_CMD_BIT_WIDTH_14:
			bit_length = 14;
			break;
		case MY9291_CMD_BIT_WIDTH_12:
			bit_length = 12;
			break;
		case MY9291_CMD_BIT_WIDTH_8:
			bit_length = 8;
			break;
		default:
			bit_length = 8;
			break;
	}

	// ets_intr_lock();

    // TStop > 12us.
	delay_us(12);

    // Send color data
    unsigned int length = (_channels == 4) ? 4 : 6;
    for (unsigned char channel = 0; channel < length; channel++) {
        write(duty[channel], bit_length);
	}

	// TStart > 12us. Ready for send DI pulse.
	delay_us(12);

	// Send 8 DI pulse. After 8 pulse falling edge, store old data.
	di_pulse(8);

	// TStop > 12us.
	delay_us(12);

	// ets_intr_unlock();

}



void setColor(MY9291_COLOR_TypDef color)
{
    _color.red = color.red;
    _color.green = color.green;
    _color.blue = color.blue;
    _color.white = color.white;
    _color.warm = color.warm;

#ifdef debug_rbg
    	printf("[MY9291] setColor: %d, %d, %d, %d, %d \r\n", _color.red, _color.green, _color.blue, _color.white, _color.warm);
#endif

    if (_state) send();
}



bool getState(void)
{
    return _state;
}

void setState(bool state)
{
    _state = state;
#ifdef debug_rbg
    printf("[MY9291] setState: %s \r\n", _state ? "true" : "false");
#endif
    send();
}

void my9291_led_rbg_init(unsigned char channels)
{
	  GPIO_InitTypeDef GPIO_LedInit = {0};

	  /* GPIO Ports Clock Enable */
	  DI_CLK_ENABLE();
	  DCKI_CLK_ENABLE();


	  /*Configure GPIO pins : DCKI_PIN */
	  GPIO_LedInit.Pin = DI_PIN;
	  GPIO_LedInit.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_LedInit.Pull = GPIO_NOPULL;
	  GPIO_LedInit.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(DI_PORT, &GPIO_LedInit);

	  /*Configure GPIO pins : DCKI_PIN */
	  GPIO_LedInit.Pin = DCKI_PIN;
	  GPIO_LedInit.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_LedInit.Pull = GPIO_NOPULL;
	  GPIO_LedInit.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(DCKI_PORT, &GPIO_LedInit);


	  /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(DI_PORT, DI_PIN, GPIO_PIN_RESET);

	  /*Configure GPIO pin Output Level */
	  HAL_GPIO_WritePin(DCKI_PORT, DCKI_PIN, GPIO_PIN_RESET);


	_command.scatter = MY9291_CMD_SCATTER_APDM;
	_command.frequency = MY9291_CMD_FREQUENCY_DIVIDE_1;
	_command.bit_width = MY9291_CMD_BIT_WIDTH_8;
	_command.reaction = MY9291_CMD_REACTION_FAST;
	_command.one_shot = MY9291_CMD_ONE_SHOT_DISABLE;
	_command.resv =0;

	if (channels == 4 || channels == 5) _channels = channels;

	// Clear all duty register
	if (_channels == 4) {
		dcki_pulse(32);
	} else {
		dcki_pulse(64);
	}

	// Send init command
	set_cmd(_command);

#ifdef debug_rbg
	printf("[MY9291] Initialized \r\n");
#endif

	setState(true);
}


//------------------ function test ###############################
void rainbow(unsigned char index)
{

    if (index < 85) {
        setColor((MY9291_COLOR_TypDef) { (unsigned int) index * 3, (unsigned int) 255 - index * 3, 0, 0, 0 });
    } else if (index < 170) {
        index -= 85;
       setColor((MY9291_COLOR_TypDef) { (unsigned int) 255 - index * 3, 0, (unsigned int) index * 3, 0, 0 });
    } else {
        index -= 170;
        setColor((MY9291_COLOR_TypDef) { 0, (unsigned int) index * 3, (unsigned int) 255 - index * 3, 0, 0 });
    }

}

void test_rbg(void)
{
	static unsigned char count = 0;
	static uint32_t last = 0;

	if(!last)
	{
		last = HAL_GetTick();
	}

	if(HAL_GetTick() - last > 10)
	{
		last = HAL_GetTick();
		rainbow(count++);
	}
}
