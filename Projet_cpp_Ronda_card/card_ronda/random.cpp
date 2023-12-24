#include "random.h"
#include <QRandomGenerator>
#include <QStringList>
#include <unordered_set>
#include <QDebug>

// Constructor for the random class
random::random() {}

// Function to create a tableau (but currently empty, needs implementation)
QString createtableau() {
    // Placeholder, to be implemented
    return QString();
}

// Function to get a random string from a given QStringList
QString random::getRandomString(const QStringList tableau) {
    // Generate a random index within the bounds of the tableau size
    int randomIndex = QRandomGenerator::global()->bounded(tableau.size());

    // Output the randomly selected string to the console
    qDebug() << tableau[randomIndex];

    // Return the randomly selected string
    return tableau[randomIndex];
}
