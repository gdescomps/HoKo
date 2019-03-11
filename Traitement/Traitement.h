#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

	class Traitement {
		public:
			Traitement() {};
			virtual ~Traitement() {};


		protected:
			cv::Mat imageTraitee;

	};

#endif // TRAITEMENT_H