/**
	\file main.h
	\brief Archivo include del main.
	\details Contiene estruturas y enums varios.
	\author Ing. Jerónimo F. Atencio (jerome5416@gmail.com)
	\date 2010.06.05
	\version 1.0.0
*/
#ifndef MAIN_H
#define MAIN_H

#define SIZE_1	//!< Tamaño del buffer.

/** \struct resultado_S
	\brief Almacena el resultado.
*/
struct resultado_S {
	int suma;	//!< Resultado del producto.
	int producto;//!< Resultado de la suma.
};

/** \enum dias_E
	\brief Días de la semana.
*/
enum dias_E {
	DOMINGO = 0x00,	//!< Domingo.
	LUNES,			//!< Lunes.
	MARTES,			//!< Martes.
	MIERCOLES,		//!< Miercoles.
	JUEVES,			//!< Jueves.
	VIERNES,		//!< Viernes.
	SABADO,			//!< Sabado.
};

#endif
