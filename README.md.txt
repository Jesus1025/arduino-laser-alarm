Alarma Perimetral con Barrera Láser - Arduino 🚨
Este repositorio contiene el código y la documentación para un prototipo funcional de un sistema de alarma perimetral simple, basado en Arduino. El sistema utiliza un rayo láser y una fotorresistencia (LDR) para crear una barrera que, al ser interrumpida, activa una alarma audiovisual.

Es un excelente proyecto práctico para aprender sobre sensores, gestión de estados y control de componentes digitales.

Demostración en Video 🎬
Características ⚙️
Detección de Luz: La alarma se activa cuando el nivel de luz (láser interrumpido) supera un umbral definido.

Control de Armado/Desarmado: Un pulsador permite armar y desarmar el sistema.

Indicadores de Estado Visuales: LEDs de estado que muestran claramente si el sistema está armado (LED azul fijo) o desarmado (LED rojo fijo).

Alarma Acústica y Visual: Al activarse, un buzzer emite un sonido rítmico y el LED azul parpadea.

Desactivación Inteligente: La alarma puede ser silenciada durante un breve periodo con el pulsador o mediante un sonido ambiente que supere un umbral (como un aplauso).

Componentes Necesarios 🛠️
1x Placa Arduino UNO

1x Cable USB

1x Módulo Láser o puntero láser (para la barrera)

1x Fotorresistencia (LDR)

1x Módulo Sensor de Sonido (con salida analógica AO)

1x Pulsador

1x Zumbador (Buzzer)

1x LED Verde

1x LED Azul

1x Resistencia de 10kΩ (para el LDR)

2x Resistencias de 220Ω (una para cada LED)

1x Protoboard

Varios Cables de Conexión (Jumpers)

Diagrama de Conexiones 🔌
Asegúrate de que la alimentación (5V y GND) del Arduino estén conectadas a los rieles del protoboard.

Componente	Pin en Arduino
Sensor de Luz (LDR)	A5
Sensor de Sonido (AO)	A2
Pulsador	2
Zumbador	8
LED Verde	9
LED Rojo (Estado Desarmado)	10
LED Azul (Estado Armado/Alarma)	11

Exportar a Hojas de cálculo
Modo de Uso 🕹️
Encendido: Al energizar el circuito, el sistema se inicia por defecto en modo Armado (LED azul fijo encendido).

Activación de Alarma: Si el rayo láser que apunta al LDR es interrumpido (el valor de luz cae por debajo del umbral de 40), la alarma se dispara (el buzzer suena y el LED azul parpadea).

Desarmado del Sistema: Para apagar la alarma y desarmar el sistema, tienes dos opciones durante la fase de parpadeo del LED azul (3 segundos):

Opción 1: Presiona el pulsador.

Opción 2: Genera un sonido que supere el umbralDeSonido (ej. 40).
Una vez desarmado, el LED rojo se encenderá de forma fija.

Re-armado del Sistema: Con el sistema desarmado (LED rojo fijo), presiona el pulsador una vez más para re-armarlo. El LED rojo se apagará y el LED azul se encenderá fijo, listo para detectar.

Calibración de Umbrales 🎯
Los valores de umbral (umbralDeLuz y umbralDeSonido) pueden necesitar ajustes según tu entorno. Para ello:

Abre el Monitor Serial en el IDE de Arduino (a 9600 baudios).

Observa los valores de "Luz" y "Sonido" que se muestran.

Ajusta las variables umbralDeLuz (ej. si la luz ambiental con láser apuntando es 900 y sin láser es 100, un buen umbral sería 500) y umbralDeSonido (ej. si el silencio es 50 y una palmada es 200, un buen umbral sería 100) en el código.

Vuelve a subir el código después de cada ajuste.

