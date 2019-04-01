#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

#include "Interface/Fenetres/FenetreModifier.h"

	class FenetreModifier;

	class Traitement {
		public:
			Traitement();
			virtual ~Traitement() {};


		protected:
			cv::Mat imageTraitee;
			FenetreModifier* fenetre;
	};

#endif // TRAITEMENT_H