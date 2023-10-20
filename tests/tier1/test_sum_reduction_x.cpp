#include "cle.hpp"

#include <array>
#include <gtest/gtest.h>

class TestSumReductionX : public ::testing::TestWithParam<std::string>
{
protected:
  std::array<float, 3 * 1 * 1>  output;
  std::array<float, 12 * 1 * 1> input = { 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0 };
  std::array<float, 3 * 1 * 1>  valid = { 2.0, 2.0, 1.0 };
};

TEST_P(TestSumReductionX, execute)
{
  std::string param = GetParam();
  cle::BackendManager::getInstance().setBackend(param);
  auto device = cle::BackendManager::getInstance().getBackend().getDevice("", "all");

  auto gpu_input = cle::Array::create(12, 1, 1, cle::dType::FLOAT, cle::mType::BUFFER, device);
  gpu_input->write(input.data());

  auto gpu_output = cle::tier1::sum_reduction_x_func(device, gpu_input, nullptr, 4);

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
#if USE_OPENCL
  parameters.push_back("opencl");
#endif
#if USE_CUDA
  parameters.push_back("cuda");
#endif
  return parameters;
}

INSTANTIATE_TEST_CASE_P(InstantiationName, TestSumReductionX, ::testing::ValuesIn(getParameters()));
