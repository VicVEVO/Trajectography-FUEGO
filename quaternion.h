#include <Eigen/Dense>

class Quaternion {
public:
    Quaternion(double w, double x, double y, double z);

    // Déclaration de la fonction pour le produit de deux quaternions

private:
    Eigen::VectorXd quat;  // Représentation interne du quaternion
};