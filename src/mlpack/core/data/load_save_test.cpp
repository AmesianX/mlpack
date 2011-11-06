/**
 * @file load_save_test.cpp
 * @author Ryan Curtin
 *
 * Tests for data::Load() and data::Save().
 */
#include <sstream>

#include "load.hpp"
#include "save.hpp"

#define BOOST_TEST_MODULE LoadSaveTest
#include <boost/test/unit_test.hpp>

using namespace mlpack;

/**
 * Make sure failure occurs when no extension given.
 */
BOOST_AUTO_TEST_CASE(NoExtensionLoad) {
  arma::mat out;
  BOOST_REQUIRE(data::Load("noextension", out) == false);
}

/**
 * Make sure failure occurs when no extension given.
 */
BOOST_AUTO_TEST_CASE(NoExtensionSave) {
  arma::mat out;
  BOOST_REQUIRE(data::Save("noextension", out) == false);
}

/**
 * Make sure load fails if the file does not exist.
 */
BOOST_AUTO_TEST_CASE(NotExistLoad) {
  arma::mat out;
  BOOST_REQUIRE(data::Load("nonexistentfile_______________.csv", out) == false);
}

/**
 * Make sure a CSV is loaded correctly.
 */
BOOST_AUTO_TEST_CASE(LoadCSVTest) {
  std::fstream f;
  f.open("test_file.csv", std::fstream::out);

  f << "1, 2, 3, 4" << std::endl;
  f << "5, 6, 7, 8" << std::endl;

  f.close();

  arma::mat test;
  BOOST_REQUIRE(data::Load("test_file.csv", test) == true);

  BOOST_REQUIRE_EQUAL(test.n_rows, 4);
  BOOST_REQUIRE_EQUAL(test.n_cols, 2);

  for (int i = 0; i < 8; i++)
    BOOST_REQUIRE_CLOSE(test[i], (double) (i + 1), 1e-5);

  // Remove the file.
  remove("test_file.csv");
}

/**
 * Make sure a CSV is saved correctly.
 */
BOOST_AUTO_TEST_CASE(SaveCSVTest) {
  arma::mat test = "1 5;"
                   "2 6;"
                   "3 7;"
                   "4 8;";

  BOOST_REQUIRE(data::Save("test_file.csv", test) == true);

  // Load it in and make sure it is the same.
  BOOST_REQUIRE(data::Load("test_file.csv", test) == true);

  BOOST_REQUIRE_EQUAL(test.n_rows, 4);
  BOOST_REQUIRE_EQUAL(test.n_cols, 2);

  for (int i = 0; i < 8; i++)
    BOOST_REQUIRE_CLOSE(test[i], (double) (i + 1), 1e-5);

  // Remove the file.
  remove("test_file.csv");
}

/**
 * Make sure arma_ascii is loaded correctly.
 */
BOOST_AUTO_TEST_CASE(LoadArmaASCIITest) {
  arma::mat test = "1 5;"
                   "2 6;"
                   "3 7;"
                   "4 8;";

  arma::mat testTrans = trans(test);
  BOOST_REQUIRE(testTrans.save("test_file.txt", arma::arma_ascii));

  BOOST_REQUIRE(data::Load("test_file.txt", test) == true);

  BOOST_REQUIRE_EQUAL(test.n_rows, 4);
  BOOST_REQUIRE_EQUAL(test.n_cols, 2);

  for (int i = 0; i < 8; i++)
    BOOST_REQUIRE_CLOSE(test[i], (double) (i + 1), 1e-5);

  // Remove the file.
  remove("test_file.txt");
}

/**
 * Make sure a CSV is saved correctly.
 */
BOOST_AUTO_TEST_CASE(SaveArmaASCIITest) {
  arma::mat test = "1 5;"
                   "2 6;"
                   "3 7;"
                   "4 8;";

  BOOST_REQUIRE(data::Save("test_file.txt", test) == true);

  // Load it in and make sure it is the same.
  BOOST_REQUIRE(data::Load("test_file.txt", test) == true);

  BOOST_REQUIRE_EQUAL(test.n_rows, 4);
  BOOST_REQUIRE_EQUAL(test.n_cols, 2);

  for (int i = 0; i < 8; i++)
    BOOST_REQUIRE_CLOSE(test[i], (double) (i + 1), 1e-5);

  // Remove the file.
  remove("test_file.txt");
}

/**
 * Make sure raw_ascii is loaded correctly.
 */
BOOST_AUTO_TEST_CASE(LoadRawASCIITest) {
  std::fstream f;
  f.open("test_file.txt", std::fstream::out);

  f << "1 2 3 4" << std::endl;
  f << "5 6 7 8" << std::endl;

  f.close();

  arma::mat test;
  BOOST_REQUIRE(data::Load("test_file.txt", test) == true);

  BOOST_REQUIRE_EQUAL(test.n_rows, 4);
  BOOST_REQUIRE_EQUAL(test.n_cols, 2);

  for (int i = 0; i < 8; i++)
    BOOST_REQUIRE_CLOSE(test[i], (double) (i + 1), 1e-5);

  // Remove the file.
  remove("test_file.txt");
}

/**
 * Make sure CSV is loaded correctly as .txt.
 */
BOOST_AUTO_TEST_CASE(LoadCSVTxtTest) {
  std::fstream f;
  f.open("test_file.txt", std::fstream::out);

  f << "1, 2, 3, 4" << std::endl;
  f << "5, 6, 7, 8" << std::endl;

  f.close();

  arma::mat test;
  BOOST_REQUIRE(data::Load("test_file.txt", test) == true);

  BOOST_REQUIRE_EQUAL(test.n_rows, 4);
  BOOST_REQUIRE_EQUAL(test.n_cols, 2);

  for (int i = 0; i < 8; i++)
    BOOST_REQUIRE_CLOSE(test[i], (double) (i + 1), 1e-5);

  // Remove the file.
  remove("test_file.txt");
}

/**
 * Make sure arma_binary is loaded correctly.
 */
BOOST_AUTO_TEST_CASE(LoadArmaBinaryTest) {
  arma::mat test = "1 5;"
                   "2 6;"
                   "3 7;"
                   "4 8;";

  arma::mat testTrans = trans(test);
  BOOST_REQUIRE(testTrans.quiet_save("test_file.bin", arma::arma_binary)
      == true);

  // Now reload through our interface.
  BOOST_REQUIRE(data::Load("test_file.bin", test) == true);

  BOOST_REQUIRE_EQUAL(test.n_rows, 4);
  BOOST_REQUIRE_EQUAL(test.n_cols, 2);

  for (int i = 0; i < 8; i++)
    BOOST_REQUIRE_CLOSE(test[i], (double) (i + 1), 1e-5);

  // Remove the file.
  remove("test_file.bin");
}

/**
 * Make sure arma_binary is saved correctly.
 */
BOOST_AUTO_TEST_CASE(SaveArmaBinaryTest) {
  arma::mat test = "1 5;"
                   "2 6;"
                   "3 7;"
                   "4 8;";

  BOOST_REQUIRE(data::Save("test_file.bin", test) == true);

  BOOST_REQUIRE(data::Load("test_file.bin", test) == true);

  BOOST_REQUIRE_EQUAL(test.n_rows, 4);
  BOOST_REQUIRE_EQUAL(test.n_cols, 2);

  for (int i = 0; i < 8; i++)
    BOOST_REQUIRE_CLOSE(test[i], (double) (i + 1), 1e-5);

  // Remove the file.
  remove("test_file.bin");
}

/**
 * Make sure raw_binary is loaded correctly.
 */
BOOST_AUTO_TEST_CASE(LoadRawBinaryTest) {
  arma::mat test = "1 2;"
                   "3 4;"
                   "5 6;"
                   "7 8;";

  arma::mat testTrans = trans(test);
  BOOST_REQUIRE(testTrans.quiet_save("test_file.bin", arma::raw_binary)
      == true);

  // Now reload through our interface.
  BOOST_REQUIRE(data::Load("test_file.bin", test) == true);

  BOOST_REQUIRE_EQUAL(test.n_rows, 1);
  BOOST_REQUIRE_EQUAL(test.n_cols, 8);

  for (int i = 0; i < 8; i++)
    BOOST_REQUIRE_CLOSE(test[i], (double) (i + 1), 1e-5);

  // Remove the file.
  remove("test_file.bin");
}

/**
 * Make sure load as PGM is successful.
 */
BOOST_AUTO_TEST_CASE(LoadPGMBinaryTest) {
  arma::mat test = "1 5;"
                   "2 6;"
                   "3 7;"
                   "4 8;";

  arma::mat testTrans = trans(test);
  BOOST_REQUIRE(testTrans.quiet_save("test_file.pgm", arma::pgm_binary)
      == true);

  // Now reload through our interface.
  BOOST_REQUIRE(data::Load("test_file.pgm", test) == true);

  BOOST_REQUIRE_EQUAL(test.n_rows, 4);
  BOOST_REQUIRE_EQUAL(test.n_cols, 2);

  for (int i = 0; i < 8; i++)
    BOOST_REQUIRE_CLOSE(test[i], (double) (i + 1), 1e-5);

  // Remove the file.
  remove("test_file.pgm");
}

/**
 * Make sure save as PGM is successful.
 */
BOOST_AUTO_TEST_CASE(SavePGMBinaryTest) {
  arma::mat test = "1 5;"
                   "2 6;"
                   "3 7;"
                   "4 8;";

  BOOST_REQUIRE(data::Save("test_file.pgm", test) == true);

  // Now reload through our interface.
  BOOST_REQUIRE(data::Load("test_file.pgm", test) == true);

  BOOST_REQUIRE_EQUAL(test.n_rows, 4);
  BOOST_REQUIRE_EQUAL(test.n_cols, 2);

  for (int i = 0; i < 8; i++)
    BOOST_REQUIRE_CLOSE(test[i], (double) (i + 1), 1e-5);

  // Remove the file.
  remove("test_file.pgm");
}