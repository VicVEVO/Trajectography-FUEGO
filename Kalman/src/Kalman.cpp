/*
Regarder différence entre static et non static
Askip pas besoin changer pointeurs vu qu'on change x et on le fait dans la classe 
*/
#include <iostream>
#include <Eigen/Dense>
#include "Kalman.h"


MEKF::MEKF(){
    //mettre toutes les fonctions
    
};


// Initialiser l'état du filtre
void initializeState(const Eigen::Vector3d& acc, const Eigen::Vector3d& mag, Eigen::VectorXf& q) {
    // Méthode pour initialiser l'état du filtre en utilisant les mesures d'accéléromètre et de magnétomètre
    if (mag.norm() != 0) {
        nedTriad(acc, mag, q);  // Calcul du quaternion initial en utilisant les mesures d'accéléromètre et de magnétomètre
        // Initialisation du vecteur d'état
        _x << 0,0,_altitude0,0, 0, 0, q(0), q(1), q(2), q(3), 0, 0, 0;
        
    }
};

void nedTriad(const Eigen::Vector3d& acc, const Eigen::Vector3d& mag, Eigen::VectorXf& q) {
    Eigen::Vector3d acc_normalise = acc.normalized();
    Eigen::Vector3d mag_normalise = mag.normalized();
    int R1 = _g

};


void predict(const Eigen::Vector3d& accelerometers, const Eigen::Vector3d& gyroscopes);

void correctBaro(double barometer);

void correctGPS(const Eigen::Vector3d& GPS, bool fix);

void correctMag(const Eigen::Vector3d& mag);

int main() {
    MEKF myFilter;
        std::cout << "Initial Latitude: " << myFilter.iPos << std::endl;
    return 0;
}