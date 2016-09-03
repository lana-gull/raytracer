#pragma once
#include <cmath>
#include <iostream>

template <typename T> class ray_vector {
public:
  ray_vector(T a, T b, T c);
  ray_vector();
  void print_coordinates();
  T x() const;
  T y() const;
  T z() const;
  ray_vector operator+(ray_vector another);
  ray_vector operator-(ray_vector another);
  T operator&(ray_vector another);
  ray_vector operator%(ray_vector another);
  ray_vector operator*(T number);
  ray_vector operator^(ray_vector another);
  bool operator==(ray_vector another);
  double find_length();
  ray_vector get_unit_vector();

private:
  T x_;
  T y_;
  T z_;
};

typedef ray_vector<double> double_vector;
typedef double_vector unit_vector;

template <typename T>
ray_vector<T>::ray_vector(T a, T b, T c) : x_(a), y_(b), z_(c) {}

template <typename T> ray_vector<T>::ray_vector() : x_(0), y_(0), z_(0) {}

template <typename T> void ray_vector<T>::print_coordinates() {
  std::cout << "X: " << x_ << "\n"
            << "Y: " << y_ << "\n"
            << "Z: " << z_ << "\n";
  std::cout << std::endl;
}

template <typename T> T ray_vector<T>::x() const { return x_; }

template <typename T> T ray_vector<T>::y() const { return y_; }

template <typename T> T ray_vector<T>::z() const { return z_; }

template <typename T>
ray_vector<T> ray_vector<T>::operator+(ray_vector<T> another) {
  return ray_vector<T>(x_ + another.x_, y_ + another.y_, z_ + another.z_);
}

template <typename T>
ray_vector<T> ray_vector<T>::operator-(ray_vector<T> another) {
  return ray_vector<T>(x_ - another.x_, y_ - another.y_, z_ - another.z_);
}

template <typename T> T ray_vector<T>::operator&(ray_vector<T> another) {
  return x_ * another.x_ + y_ * another.y_ + z_ * another.z_;
}

template <typename T>
ray_vector<T> ray_vector<T>::operator%(ray_vector<T> another) {
  return ray_vector<T>(y_ * another.z_ - z_ * another.y_,
                       z_ * another.x_ - x_ * another.z_,
                       x_ * another.y_ - y_ * another.x_);
}

template <typename T>
ray_vector<T> ray_vector<T>::operator^(ray_vector<T> another) {
  return ray_vector<T>(x_ * another.x_, y_ * another.y_, z_ * another.z_);
}

template <typename T> bool ray_vector<T>::operator==(ray_vector<T> another) {
  return (std::abs(x_ - another.x_) < 1e-6) &&
         (std::abs(y_ - another.y_) < 1e-6) &&
         (std::abs(z_ - another.z_) < 1e-6);
}

template <typename T> ray_vector<T> ray_vector<T>::operator*(T number) {
  return ray_vector<T>(x_ * number, y_ * number, z_ * number);
}

template <typename T> double ray_vector<T>::find_length() {
  return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
}

template <typename T> ray_vector<T> ray_vector<T>::get_unit_vector() {
  double length = find_length();
  return ray_vector<T>(x_ / length, y_ / length, z_ / length);
}
