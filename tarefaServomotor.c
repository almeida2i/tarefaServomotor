#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include "hardware/pwm.h"

#define SERVO_PIN 12

// Função para realizar avanço incremental, em ambos os sentidos, com pequenas pausas
void incre_advanc(void)
{
    uint16_t level = 1638;

    while(level < 7864){
        pwm_set_gpio_level(SERVO_PIN,level);
        level += 65535u/4000;
        sleep_ms(10);
    }

    level = 7864;

    while(level > 1638){
        pwm_set_gpio_level(SERVO_PIN,level);
        level -= 65535u/4000;
        sleep_ms(10);
    }
}

int main()
{
    // Inicialização da comunicação serial
    stdio_init_all();

    // Configuração do PWM no GPIO 12 com frequência de 50 Hz e wrap default, 65535
    gpio_set_function(SERVO_PIN,GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_set_clkdiv(slice_num,38.14697);
    pwm_set_gpio_level(SERVO_PIN,0);
    pwm_set_enabled(slice_num,true);

    // Construção dos passos iniciais
    pwm_set_gpio_level(SERVO_PIN,7864); // Duty cycle: 12%
    sleep_ms(5000);
    pwm_set_gpio_level(SERVO_PIN,4817); // Duty cycle: 7,35%
    sleep_ms(5000);
    pwm_set_gpio_level(SERVO_PIN,1638); // Duty cycle: 2,5%
    sleep_ms(5000);

    while (1) {
        // Movimentação periódica do braço
        incre_advanc();
    }
    return 0;
}
