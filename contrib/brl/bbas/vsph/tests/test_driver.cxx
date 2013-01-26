#include <testlib/testlib_register.h>


DECLARE( test_view_sphere );
DECLARE( test_spherical_coord );
DECLARE( test_camera_bounds );
DECLARE( test_sph_geom );

void
register_tests()
{
  REGISTER( test_view_sphere );
  REGISTER( test_spherical_coord );
  REGISTER( test_camera_bounds );
  REGISTER( test_sph_geom );
}

DEFINE_MAIN;


