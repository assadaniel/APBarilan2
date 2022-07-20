//
// Created by User on 19/07/2022.
//

#include "Iris.hpp"
#include <cmath>
#include <iostream>

/**
 * @brief Default constructor for Iris.
 */
Iris::Iris() {}

/****
 * @brief Construct a new unclassified Iris.
 * 
 * @param width A double representing the width of the Iris.
 * @param sepalLength A double representing the length of the sepal of the Iris.
 * @param sepalWidth A double representing the width of the sepal of the Iris
 * @param petalLength A double representing the length of the petal of the Iris
 ****/
Iris::Iris(double width, double sepalLength, double sepalWidth, double petalLength)
        : width(width), sepalLength(sepalLength), sepalWidth(sepalWidth), petalLength(petalLength), type(UNKNOWN) {}

/****
 * @brief Construct a new classified Iris.
 * 
 * @param width A double representing the width of the Iris.
 * @param sepalLength A double representing the length of the sepal of the Iris.
 * @param sepalWidth A double representing the width of the sepal of the Iris
 * @param petalLength A double representing the length of the petal of the Iris
 * @param type An enum representing the type of the Iris.
 ****/
Iris::Iris(double width, double sepalLength, double sepalWidth, double petalLength, irisType type)
        : width(width), sepalLength(sepalLength), sepalWidth(sepalWidth), petalLength(petalLength), type(type) {}

//Iris::Iris(const Iris &iris) {
//    this->width = iris.width;
//    this->sepalLength = iris.sepalLength;
//    this->sepalWidth = iris.sepalWidth;
//    this->petalLength = iris.sepalLength;
//    this->type = iris.type;
//}

/**
 * @brief Function calculating the euclidian distance (difference) between two flowers.
 * 
 * @param iris The other iris we compare.
 * @return double The distance (difference) between the flowers.
 */
double Iris::eucDistance(const Iris iris) const {
    return sqrtf(pow((this->width - iris.width), 2) +
                 pow((this->sepalLength - iris.sepalLength), 2) +
                 pow((this->sepalWidth - iris.sepalWidth), 2) +
                 pow((this->petalLength - iris.petalLength), 2));
}

/**
 * @brief Function calculating the chebyshev distance (difference) between two flowers.
 * 
 * @param iris The other iris we compare.
 * @return double The distance (difference) between the flowers.
 */
double Iris::chebDistance(const Iris iris) const {
    double m1 = fmax(fabs(this->width - iris.width), fabs(this->sepalLength - iris.sepalLength));
    double m2 = fmax(fabs(this->sepalWidth - iris.sepalWidth), fabs(this->petalLength - iris.petalLength));
    return fmax(m1, m2);
}

/**
 * @brief Function calculating the manhattan distance (difference) between two flowers.
 * 
 * @param iris The other iris we compare.
 * @return double The distance (difference) between the flowers.
 */
double Iris::manDistance(const Iris iris) const {
    return fabs(this->width - iris.width) + fabs(this->sepalLength - iris.sepalLength) +
           fabs(this->sepalWidth - iris.sepalWidth)
           + fabs(this->petalLength - iris.petalLength);
}

/**
 * @brief Width getter.
 * 
 * @return double The width of the iris.
 */
double Iris::getWidth() const {
    return width;
}

/**
 * @brief Sepal length getter.
 * 
 * @return double The sepal length of the iris.
 */
double Iris::getSepalLength() const {
    return sepalLength;
}

/**
 * @brief Sepal width getter.
 * 
 * @return double The sepal width of the iris.
 */

double Iris::getSepalWidth() const {
    return sepalWidth;
}

/**
 * @brief Petal length getter.
 * 
 * @return double The petal length of the iris.
 */

double Iris::getPetalLength() const {
    return petalLength;
}

/**
 * @brief Iris getter.
 * 
 * @return irisType The iris type (enum).
 */
irisType Iris::getType() const {
    return type;
}

/**
 * Make an Iris from a vector of the fields given in strings.
 * @param v The vector.
 */
void Iris::setFromVector(std::vector<std::string> v) {
    //THIS CODE MAY CHANGE WHEN WE GET TO SEE THE CSV FILES (mainly the order).
    this->width = std::stod(v[0]);
    this->sepalLength = std::stod(v[1]);
    this->sepalWidth = std::stod(v[2]);
    this->petalLength = std::stod(v[3]);
    //this->type = std::stod(v[4]);
    //This won't work, need to see how the type is given in the actual files.
}
/**
 * << operator for Iris.
 * @param os The out stream
 * @param iris Iris object
 * @return Out stream.
 */
std::ostream& operator<<(std::ostream &os, const Iris &iris) {
    return os << iris.getWidth() << "," << iris.getSepalLength() << ","
              << iris.getSepalWidth() << "," << iris.getPetalLength() << "," << iris.getType();
}