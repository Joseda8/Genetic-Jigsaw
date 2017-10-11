#ifndef IMAGEHANDLER_H_
#define IMAGEHANDLER_H_
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include "util.h"

using namespace cv;

struct Data_Container {
	int parts_width;
	int parts_height;
	int total_parts;
	Mat base_image;
	Mat empty;
};

class Image_Handler {
public:
	Image_Handler();
	/**
	 * Corta una pieza de una imagen.
	 * @param image la imagen a cortar.
	 * @param x la posición en x donde se corta.
	 * @param y la posición en y donde se corta.
	 * @param width el ancho del corte.
	 * @param height la altura del corte.
	 * @return la pieza de imagen cortada.
	 */
	Mat crop( Mat image, int x, int y, int width, int height, std::string name = "cropped_img" );
	/**
	 * Une una imagen con otra.
	 * @param m_image la imagen principal.
	 * @param s_image la imagen secundaria.
	 * @param x_pos la posición en x donde se inserta la imagen.
	 * @param y_pos la posición en y donde se inserta la imagen.
	 */
	void join( Mat& m_image, Mat& s_image, int x_pos, int y_pos );
	/**
	 * Descompone una imagen en la cantidad de partes dada.
	 * @param image la imagen a descomponer.
	 * @param parts el número de partes que se quiere.
	 */
	void split_image( Mat& image, int parts );

	/**
	 * Crea una imagen vacía con fondo negro.
	 * @param width el ancho de la imagen.
	 * @param height la altura de la imagen.
	 * @return la imagen vacía construida.
	 */
	Mat create_empty_img( int width, int height, std::string name = "empty" );

	/**
	 * Junta aleatoriamente las partes generadas en una imagen vacía.
	 * @param empty_pic la imagen vacía.
	 * @param part_width el ancho de cada parte.
	 * @param part_height el largo de cada partes.
	 * @param n el número de partes por lado de la imagen.
	 * @return la imagen terminada.
	 */
	Mat join_parts( );

	/**
	 * Asigna la imagen base con la que se trabaja.
	 * @param image la imagen base.
	 */
	void set_base( Mat image );

	void create_img( std::string path, Mat img );

	virtual ~Image_Handler();

private:
	Data_Container d_container;
};

#endif /* IMAGEHANDLER_H_ */
