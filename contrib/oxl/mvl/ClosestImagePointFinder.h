#ifndef ClosestImagePointFinder_h_
#define ClosestImagePointFinder_h_
#ifdef __GNUC__
#pragma interface
#endif
//
// .NAME    ClosestImagePointFinder - HomgInterestPointSet closest points
// .LIBRARY MViewBasics
// .HEADER  MultiView Package
// .INCLUDE mvl/ClosestImagePointFinder.h
// .FILE    ClosestImagePointFinder.cxx
//
// .SECTION Description
//    ClosestImagePointFinder allows fast access to closest-point
//    operations on a HomgInterestPointSet.
//
// .SECTION Author
//     Andrew W. Fitzgibbon, Oxford RRG, 21 Jan 97
//
// .SECTION Modifications:
//     <none yet>
//
//-----------------------------------------------------------------------------

#include <vcl_vector.h>

#include <vnl/vnl_vector.h>
#include <vnl/vnl_matlab_print.h>

#include <vgl/vgl_fwd.h> // for vgl_box_2d

class HomgInterestPointSet;
class vcl_multimap_double_int;
class HomgPoint2D;

class ClosestImagePointFinder {
public:
  // Constructors/Destructors--------------------------------------------------

  ClosestImagePointFinder(const HomgInterestPointSet& corners);
  ClosestImagePointFinder(const vcl_vector<HomgPoint2D>& corners);
  ~ClosestImagePointFinder();

  // ClosestImagePointFinder(const ClosestImagePointFinder& that); - use default
  // ClosestImagePointFinder& operator=(const ClosestImagePointFinder& that); - use default

  // Operations----------------------------------------------------------------
  void get_all_within_search_region(double cx, double cy, double w, double h, vcl_vector<int>* out_indices);
  void get_all_within_search_region(vgl_box_2d<double> const& region, vcl_vector<int>* out_indices);

  int get_closest_within_region(double cx, double cy, double w, double h, int* out_index = 0);
  int get_closest_within_distance(double cx, double cy, double r, int* out_index = 0);

  // Computations--------------------------------------------------------------

  // Data Access---------------------------------------------------------------
  double get_last_squared_distance() const { return _last_d2; }
  int get_last_num_candidates() const { return _last_inrange; }
  int get_last_match_index() const { return _last_index; }
  double get_last_x() const { return px_[_last_index]; }
  double get_last_y() const { return py_[_last_index]; }

  // Data Control--------------------------------------------------------------

protected:
  // Data Members--------------------------------------------------------------

  int get_closest_within_region(double cx, double cy, double w, double h, int* out_index, double mindist_sq);

  vnl_vector<double> px_;
  vnl_vector<double> py_;
  vcl_multimap_double_int* y2i_;
  double _last_d2;
  int _last_inrange;
  int _last_index;

private:
  // Helpers-------------------------------------------------------------------
};

#endif // ClosestImagePointFinder_h_
