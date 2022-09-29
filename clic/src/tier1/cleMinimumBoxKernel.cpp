

#include "cleMinimumBoxKernel.hpp"
#include "cleExecuteSeparableKernel.hpp"

#include <algorithm>

namespace cle
{

MinimumBoxKernel::MinimumBoxKernel(const ProcessorPointer & device)
  : Operation(device, 2)
{
  std::string cl_header = {
#include "cle_minimum_separable.h"
  };
  this->SetSource("minimum_separable", cl_header);
}

std::array<int, 3>
MinimumBoxKernel::Radius2KernelSize() const
{
  std::array<int, 3> kernel_size;
  std::transform(
    this->radius_.begin(), this->radius_.end(), kernel_size.begin(), [](const int & r) { return r * 2 + 1; });
  return kernel_size;
}

auto
MinimumBoxKernel::SetInput(const Image & object) -> void
{
  this->AddParameter("src", object);
}

auto
MinimumBoxKernel::SetOutput(const Image & object) -> void
{
  this->AddParameter("dst", object);
}

auto
MinimumBoxKernel::SetRadius(const int & radius_x, const int & radius_y, const int & radius_z) -> void
{
  this->radius_ = { radius_x, radius_y, radius_z };
}

auto
MinimumBoxKernel::Execute() -> void
{
  auto src = this->GetImage("src");
  auto dst = this->GetImage("dst");

  auto kernel_size = Radius2KernelSize();

  ExecuteSeparableKernel kernel(this->GetDevice());
  kernel.SetSource(this->GetName(), this->GetSource());
  kernel.SetInput(*src);
  kernel.SetOutput(*dst);
  kernel.SetSigma(this->radius_[0], this->radius_[1], this->radius_[2]);
  kernel.SetKernelSize(kernel_size[0], kernel_size[1], kernel_size[2]);
  kernel.Execute();
}

} // namespace cle
