# Tarea-1-Comunicacion-Datos-Redes

## Descripcion

El siguente programa busca implementar lo aprendido en el ramo de Comunicación de datos y redes de la Universidad del Biobio y lo aprendido de manera autonoma.
Para esto se espera crear un software basado en el popular juego de batalla naval, el cual consiste basicamente en posicionar diferentes naves maritimas de 
diferentes tamaños en un tablero junto con otro jugador que sera tu contrincante, pero este no puede ver en que lugar del tablero se pusieron tus barcos.
Luego cada jugar podra disparar a una posicion del tablero una vez por turno, intentando adivinar en que posicion del tablero tiene sus barcos, el jugador que
logre destruir todos los barcos del contrario gana.

Este famoso juego sera programado en el lenguaje C++ y sera implementado mediante el modelo de Cliente/Servidor, creando un Socket que pueda conectarse mediante
una red TCP/IP. Se busca que este software pueda ser multi-clientes, es decir, que soporte mas de un cliente a la vez conectado al servidor y que pueda jugar una
partida independiente a otro cliente.

## Como funciona el juego

Para poder empezar a jugar Batalla Naval o BattleShip por su nombre en ingles, se posicionan tus 4 barcos en el tablero con la tecla X y los podremos rotar con la 
tecla C, los barcos del enemigo se posicionan aleatoriamente. Para poder disparar debemos apretar la tecla z y elegir la posicion con las teclas W,A,S,D; para movernos 
por el tablero. Solo se podra seguir atacando hasta que ya no queden mas barcos.
