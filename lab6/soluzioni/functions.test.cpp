#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "functions.hpp"
#include "doctest.h"

TEST_CASE("Testing sum_norms_index")
{
  const std::vector<pf::Point3D> vals{{3, 1, 2}, {2, 4, 5}};

  REQUIRE(vals.size() == 2);

  const double sum_norms = pf::sum_norms_index(vals);
  CHECK(sum_norms == doctest::Approx(10.44986));
}

TEST_CASE("Testing sum_norms_it")
{
  const std::vector<pf::Point3D> vals{{3, 1, 2}, {2, 4, 5}};

  const double sum_norms = pf::sum_norms_it(vals);
  CHECK(sum_norms == doctest::Approx(10.44986));
}

TEST_CASE("Testing sum_norms_range")
{
  const std::vector<pf::Point3D> vals{{3, 1, 2}, {2, 4, 5}};

  const double sum_norms = pf::sum_norms_range(vals);
  CHECK(sum_norms == doctest::Approx(10.44986));
}


TEST_CASE("Testing sort_by_x")
{
  std::vector<pf::Point3D> vals{{3, 1, 2}, {2, 4, 5}};

  pf::sort_by_x(vals);
  CHECK(vals[0].x == doctest::Approx(2));
  CHECK(vals[0].y == doctest::Approx(4));
  CHECK(vals[0].z == doctest::Approx(5));
  CHECK(vals[1].x == doctest::Approx(3));
  CHECK(vals[1].y == doctest::Approx(1));
  CHECK(vals[1].z == doctest::Approx(2));
}

TEST_CASE("Testing sort_by_norm")
{
  std::vector<pf::Point3D> vals{{3, 1, 2}, {2, 4, 5}};

  pf::sort_by_norm(vals);
  CHECK(vals[0].x == doctest::Approx(3));
  CHECK(vals[0].y == doctest::Approx(1));
  CHECK(vals[0].z == doctest::Approx(2));
  CHECK(vals[1].x == doctest::Approx(2));
  CHECK(vals[1].y == doctest::Approx(4));
  CHECK(vals[1].z == doctest::Approx(5));
}

TEST_CASE("Testing sum_norms_algo")
{
  const std::vector<pf::Point3D> vals{{3, 1, 2}, {2, 4, 5}};

  const double sum_norms = pf::sum_norms_algo(vals);
  CHECK(sum_norms == doctest::Approx(10.44986));
}

TEST_CASE("Testing sum_elems_algo")
{
  const std::vector<pf::Point3D> vals{{3, 1, 2}, {2, 4, 5}};

  const auto res = pf::sum_elems_algo(vals);
  CHECK(res.sum_norms == doctest::Approx(10.44986));
  CHECK(res.sum_x == doctest::Approx(5));
  CHECK(res.sum_y == doctest::Approx(5));
  CHECK(res.sum_z == doctest::Approx(7));
}

TEST_CASE("Testing remove_basic")
{
  std::vector<pf::Point3D> vals{{3, 1, 2},  {2, 4, 5},  {-1, 7, 8},
                                {0, 3, 10}, {5, -2, 1}, {1, -5, -4}};

  REQUIRE(vals.size() == 6);
  pf::remove_basic(vals, 2);
  CHECK(vals.size() == 3);
}

TEST_CASE("Testing remove_algo")
{
  std::vector<pf::Point3D> vals{{3, 1, 2},  {2, 4, 5},  {-1, 7, 8},
                                {0, 3, 10}, {5, -2, 1}, {1, -5, -4}};

  pf::remove_algo(vals, 2);
  CHECK(vals.size() == 3);
}
