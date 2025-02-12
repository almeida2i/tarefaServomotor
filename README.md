**Breve descrição**

Este projeto tem por objetivo utilizar a Raspberry Pi Pico W para realizar o controle do servomotor contido no Wokwi com PWM, de modo que este execute inicialmente uma sequência de passos, antes de começar a executar periodicamente movimentos suaves e contínuos. Além disso, o mesmo sinal de controle PWM foi utilizado para controlar a luminosidade do LED RGB de cor azul contido na placa BitDogLab, razão pela qual foi utilizado o GPIO 12, ao invés do GPIO 22, como saída do referido sinal PWM.


**Instruções de uso**

O sistema de controle não tem entrada de dados. Portanto, ao ligar a Raspberry, o microcontrolador executa automaticamente os movimentos supracitados.


Vídeo: https://youtu.be/nFut-4nawzQ