#include <Eigen/Dense>

// définition de la belle classe MEKF
class MEKF {
public:
    // Nombre d'états dans le filtre et taille des sous matrices constantes
    const int numOfStates = 13;
    const int subMatrixSize = 6;

    // Indices des informations dans le vecteur d'état
    const int iPos = 0;
    const int iVel = 3;
    const int iQuat = 6;
    const int iBias = 10;

    const double condThrs = 0 ; // Seuil de conditionnement pour les matrices
    
    MEKF();


private:
    // Références au sol
    double _latitude0;
    double _longitude0;
    double _altitude0;
    double _temperature0;

    Eigen::VectorXd _x; // Vecteur d'état

    Eigen::MatrixXd _Pl; // Matrice de covariance pour la position et la vitesse
    Eigen::MatrixXd _Pq; // Matrice de covariance pour le quaternion d'orientation

    // Bruits
    double sigmaB = 1.0;
    double sigmaW = 0.5;
    double sigmaPre = 0.5;
    double sigmaGPSxy = 0.5;
    double sigmaMag = 0.1;
    double sigmaPosVel = 10.0;

};

MEKF::MEKF() : _latitude0(41.808651),
               _longitude0(14.0542908),
               _altitude0(1416),
               _temperature0(273.15) {

    // Initialisation du vecteur d'état avec le quaternion à [0, 0, 0, 1]
    _x = Eigen::VectorXd::Zero(numOfStates);
    _x(iQuat + 3) = 1;

    // Initialisation des matrices de covariance
    _Pl = Eigen::MatrixXd::Identity(subMatrixSize, subMatrixSize);
    _Pq = 0.01 * Eigen::MatrixXd::Identity(subMatrixSize, subMatrixSize);

    // Initialisation des écarts types de bruit (gyroscopique,acc,pressionAtm,posGPS,mesureMag,PosVitesse)
    sigmaB = 1.0;
    sigmaW = 0.5;
    sigmaPre = 0.5;
    sigmaGPSxy = 0.5;
    sigmaMag = 0.1;
    sigmaPosVel = 10.0;

    void predict(const Eigen::Vector3d& accelerometers, const Eigen::Vector3d& gyroscopes);

    void predict(const Eigen::Vector3d& accelerometers, const Eigen::Vector3d& gyroscopes);

    void correctBaro(double barometer);

    void correctGPS(const Eigen::Vector3d& GPS, bool fix);

    void correctMag(const Eigen::Vector3d& mag);

    void gravityNed();

}


