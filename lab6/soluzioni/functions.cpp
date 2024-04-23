#include "functions.hpp"
#include <cmath>
#include <numeric>

namespace pf {

double norm(Point3D const& p)
{
  return std::hypot(p.x, p.y, p.z);
}

double sum_norms_index(std::vector<Point3D> const& v)
{
  double res{0};
  for (std::size_t i{0}; i != v.size(); ++i) {
    res += norm(v[i]);
  }
  return res;
}

double sum_norms_it(std::vector<Point3D> const& v)
{
  double res{0};
  for (auto it = v.begin(), last = v.end(); it != last; ++it) {
    res += norm(*it);
  }
  return res;
}

double sum_norms_range(std::vector<Point3D> const& v)
{
  double res{0};
  for (auto const& e : v) {
    res += norm(e);
  }
  return res;
}

void sort_by_x(std::vector<Point3D>& v)
{
  std::sort(v.begin(), v.end(),
            [](Point3D const& a, Point3D const& b) { return a.x < b.x; });
}

void sort_by_norm(std::vector<Point3D>& v)
{
  std::sort(v.begin(), v.end(), [](Point3D const& a, Point3D const& b) {
    return norm(a) < norm(b);
  });
}

double sum_norms_algo(std::vector<Point3D> const& v)
{
  return std::accumulate(
      v.begin(), v.end(), 0.,
      [](auto res, Point3D const& c) { return res + norm(c); });
}

Results sum_elems_algo(std::vector<Point3D> const& v)
{
  return std::accumulate(v.begin(), v.end(), Results{0., 0., 0., 0.},
                         [](Results res, Point3D const& c) {
                           res.sum_norms += norm(c);
                           res.sum_x += c.x;
                           res.sum_y += c.y;
                           res.sum_z += c.z;
                           return res;
                         });
}

void remove_basic(std::vector<Point3D>& v, double el)
{
  for (std::size_t i{0}; i != v.size();) {
    if (v[i].x < el) {
      v.erase(v.begin() + static_cast<long int>(i));
    } else {
      ++i;
    }
  }
}

void remove_algo(std::vector<Point3D>& v, double el)
{
  v.erase(std::remove_if(v.begin(), v.end(),
                         [&](Point3D const& c) { return c.x < el; }),
          v.end());
  // alternativamente, a partire da c++20, si potrebbe usare std::erase_if
  // auto erased = std::erase_if(v,[&](Point3D const& c) { return c.x < el; })
  // dove "erased" rappresenta il numero di elementi rimossi
}

} // namespace pf