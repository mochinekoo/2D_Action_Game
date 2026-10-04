#include "Location2D.h"
#include <cmath>

Location2D::Location2D() {
    x_ = 0;
    y_ = 0;
}

Location2D::Location2D(float x, float y) {
    x_ = x;
    y_ = y;
}

float Location2D::GetX() {
    return x_;
}

void Location2D::SetX(float x) {
    x_ = x;
}

float Location2D::GetY() {
    return y_;
}

void Location2D::SetY(float y) {
    y_ = y;
}

Location2D Location2D::Add(float x, float y) {
    float newX = x_ + x;
    float newY = y_ + y;
    return Location2D(newX, newY);
}

Location2D Location2D::Subtract(float x, float y) {
    float newX = x_ - x;
    float newY = y_ - y;
    return Location2D(newX, newY);
}

Location2D Location2D::Multiply(float x, float y) {
    float newX = x_ * x;
    float newY = y_ * y;
    return Location2D(newX, newY);
}

float Location2D::Distance(Location2D location) {
    return sqrt((x_ - location.x_) * (x_ - location.x_) +
                (y_ - location.y_) * (y_ - location.y_));
}


