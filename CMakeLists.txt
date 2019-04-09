cmake_minimum_required(VERSION 3.1.0)

project(HoKo)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH ~/Qt/5.12.0/gcc_64/lib/cmake/Qt5Widgets/)

# Find the QtWidgets and OpenCV library
find_package(Qt5Widgets CONFIG REQUIRED)
find_package( OpenCV REQUIRED )

add_library(tinyxml2 tinyxml2/tinyxml2.cpp tinyxml2/tinyxml2.h)

include_directories( ${OpenCV_INCLUDE_DIRS} )

# Populate a CMake variable with the sources
set(HoKo_SRCS
	Traitement/Traitement.h
	Traitement/Traitement.cpp
	Traitement/FlouGaussien.h
	Traitement/FlouGaussien.cpp
	Traitement/Masque.cpp
	Traitement/SegmentationTSV.cpp
	Traitement/FiltreCanny.cpp
	Traitement/Contours.cpp
	Traitement/GestionTraitement.h
	Traitement/GestionTraitement.cpp
	Image/GestionImage.cpp
	Image/GestionImage.h
	Interface/Fenetres/FenetreModifier.cpp
	Interface/Fenetres/FenetreModifier.h
	Interface/Fenetres/ui_FenetreModifier.h
	Interface/InterfacePrincipale.cpp
    Interface/InterfacePrincipale.h
    Interface/InterfacePrincipale.ui
    Controleur.h
    Controleur.cpp
    main.cpp
)

# Tell CMake to create the HoKo executable
add_executable(HoKo WIN32 ${HoKo_SRCS} )

# Use the Widgets module from Qt 5 and OpenCV libs
target_link_libraries(HoKo Qt5::Widgets ${OpenCV_LIBS} tinyxml2)
