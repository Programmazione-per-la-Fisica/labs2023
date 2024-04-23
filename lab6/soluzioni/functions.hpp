#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>

namespace pf {

struct Point3D
{
  double x;
  double y;
  double z;
};

struct Results
{
  double sum_norms;
  double sum_x;
  double sum_y;
  double sum_z;
};

double norm(Point3D const&);
double sum_norms_index(std::vector<Point3D> const&);
double sum_norms_it(std::vector<Point3D> const&);
double sum_norms_range(std::vector<Point3D> const&);

void sort_by_x(std::vector<Point3D>&);
void sort_by_norm(std::vector<Point3D>&);

double sum_norms_algo(std::vector<Point3D> const&);
Results sum_elems_algo(std::vector<Point3D> const&);

void remove_basic(std::vector<Point3D>&, double);
void remove_algo(std::vector<Point3D>&, double);

} // namespace pf

#endif