#include "cle.hpp"

#include <array>
#include <gtest/gtest.h>

class TestOnlyzeroOverwriteMaximumDiamond : public ::testing::TestWithParam<std::string>
{
protected:
  std::array<float, 5 * 5 * 2> output;
  std::array<float, 5 * 5 * 2> input = { 0, 0, 0, 0, 0, 0, 1, 2, 3, 0, 0, 2, 3, 4, 0, 0, 4, 4, 5, 0, 0, 0, 0, 0, 0,
                                         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  std::array<float, 5 * 5 * 2> valid = { 0, 1, 2, 3, 0, 1, 1, 2, 3, 3, 2, 2, 3, 4, 4, 4, 4, 4, 5, 5, 0, 4, 4, 5, 0,
                                         0, 0, 0, 0, 0, 0, 1, 2, 3, 0, 0, 2, 3, 4, 0, 0, 4, 4, 5, 0, 0, 0, 0, 0, 0 };
};

TEST_P(TestOnlyzeroOverwriteMaximumDiamond, execute)
{
  std::string param = GetParam();
  cle::BackendManager::getInstance().setBackend(param);
  auto device = cle::BackendManager::getInstance().getBackend().getDevice("", "all");

  auto gpu_input = cle::Array::create(5, 5, 2, cle::dType::FLOAT, cle::mType::BUFFER, device);
  gpu_input->write(input.data());
  auto flag = cle::Array::create(1, 1, 1, cle::dType::FLOAT, cle::mType::BUFFER, device);
  flag->fill(0);

  auto gpu_output = cle::tier1::onlyzero_overwrite_maximum_diamond_func(device, gpu_input, flag, nullptr);

  gpu_output->read(output.data());
  for (int i = 0; i < output.size(); i++)
  {
    EXPECT_EQ(output[i], valid[i]);
  }
}

std::vector<std::string>
getParameters()
{
  std::vector<std::string> parameters;

#ifdef USE_OPENCL
  parameters.push_back("opencl");
#endif

#ifdef USE_CUDA
  parameters.push_back("cuda");
#endif

  return parameters;
}

INSTANTIATE_TEST_CASE_P(InstantiationName, TestOnlyzeroOverwriteMaximumDiamond, ::testing::ValuesIn(getParameters()));