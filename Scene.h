#ifndef SCENE
#define SCENE

#include "Vector.h"
#include "Ray.h"
#include "Shapes.h"
#include "Colors.h"
#include "Light.h"

class Camera {
  public:
    DoubleVector position;
    DoubleVector direction;
    Camera (DoubleVector point_start, DoubleVector point_end);
    Camera ();
};

class MyScreen {
  double width;
  double heigth;
  DoubleVector point_center;
  UnitVec vector_up;
  UnitVec vector_right;
  UnitVec vector_normal;
  public:
    MyScreen (int w, int h, Camera camera, double focus);
    MyScreen ();
    DoubleVector get_point (int i, int j);
};

class Scene {
  Camera camera;
  MyScreen screen;
  Sphere sphere;
  public:
    DoubleVector ambient;
    Light light;
    Scene (Camera camera, MyScreen screen, Sphere sphere, DoubleVector ambient, Light light);
    Ray get_ray (int i, int j);
    Color get_color (Ray ray);
    Color get_color_for_coordinates (int i, int j);
    Color get_ambient_color ();
    Color get_diffuse_color (DoubleVector point);
    Color get_specular_color (DoubleVector point);
};

#endif