// This is core/vgl/io/tests/test_homg_line_2d_io.cxx
#include <iostream>
#include <vcl_compiler.h>
#include <vsl/vsl_indent.h>
#include <vgl/io/vgl_io_homg_line_2d.h>
#include <testlib/testlib_test.h>
#include <vpl/vpl.h>

void test_homg_line_2d_double_io()
{
  std::cout << "***********************************\n"
           << "Testing vgl_homg_line_2d<double> io\n"
           << "***********************************\n";

  //// test constructors, accessors
  vgl_homg_line_2d<double> p_out(1.2,3.4,5.6), p_in;

  vsl_b_ofstream bfs_out("vgl_homg_line_2d_test_double_io.bvl.tmp");
  TEST("Created vgl_homg_line_2d_test_double_io.bvl.tmp for writing", (!bfs_out), false);
  vsl_b_write(bfs_out, p_out);
  bfs_out.close();

  vsl_b_ifstream bfs_in("vgl_homg_line_2d_test_double_io.bvl.tmp");
  TEST("Opened vgl_homg_line_2d_test_double_io.bvl.tmp for reading", (!bfs_in), false);
  vsl_b_read(bfs_in, p_in);
  TEST("Finished reading file successfully", (!bfs_in), false);
  bfs_in.close();

  vpl_unlink ("vgl_homg_line_2d_test_double_io.bvl.tmp");

  TEST("p_out == p_in", p_out.a()==p_in.a() &&
                        p_out.b()==p_in.b() &&
                        p_out.c()==p_in.c() , true);

  vsl_print_summary(std::cout, p_out);
  std::cout << std::endl;
  vsl_indent_clear_all_data();
}

void test_homg_line_2d_io()
{
  test_homg_line_2d_double_io();
}

TESTMAIN(test_homg_line_2d_io);
