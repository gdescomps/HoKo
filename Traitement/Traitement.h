#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

#include "Interface/Fenetres/FenetreModifier.h"
#include "Traitement/GestionTraitement.h"

	class FenetreModifier;
	class GestionTraitement;

	class Traitement {
		public:
			Traitement(GestionTraitement* gestionTraitement);
			virtual ~Traitement() {};


		protected:
			cv::Mat imageTraitee;
			FenetreModifier* fenetre;

			GestionTraitement* gestionTraitement;
	};

#endif // TRAITEMENT_H