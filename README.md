# Simulador-de-sonda
Este proyecto consiste en implementar un simulador de sonda básico en C++ con Qt Creator. El simulador de sonda tiene la posibilidad de modificar el nivel de producto, nivel de agua, temperatura, su longitud o simular un error de sonda mediante una aplicación. Además, permite consultar el estado de los atributos de la sonda mediante un protocolo básico por el puerto serial.

Clase principal: Sonda

Atributos:
			Nivel de Producto
			Nivel de Agua
			Temperatura
			Error de Sonda
			Longitud de sonda
			Tipo de sonda (Puede Ser Master o Slave)

Sonda Master: Envia por el puerto serie el status de sus atributos cada un tiempo default.
Sonda Slave: Envia por el puerto serie el status de sus atributos luego de ser consultado por el puerto serie.


Desarrollo

En progreso: Modificación de los atributos por la aplicación.

Falta      : Consulta de los atributos por el puerto serie.