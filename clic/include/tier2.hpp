#ifndef __INCLUDE_TIER2_HPP
#define __INCLUDE_TIER2_HPP

#include "array.hpp"
#include "device.hpp"
#include "execution.hpp"


namespace cle::tier2
{

auto
absolute_difference_func(const Device::Pointer & device,
                         const Array::Pointer &  src0,
                         const Array::Pointer &  src1,
                         Array::Pointer          dst) -> Array::Pointer;

auto
add_images_func(const Device::Pointer & device,
                const Array::Pointer &  src0,
                const Array::Pointer &  src1,
                Array::Pointer          dst) -> Array::Pointer;

auto
bottom_hat_box_func(const Device::Pointer & device,
                    const Array::Pointer &  src,
                    Array::Pointer          dst,
                    int                     radius_x,
                    int                     radius_y,
                    int                     radius_z) -> Array::Pointer;

auto
bottom_hat_sphere_func(const Device::Pointer & device,
                       const Array::Pointer &  src,
                       Array::Pointer          dst,
                       float                   radius_x,
                       float                   radius_y,
                       float                   radius_z) -> Array::Pointer;

auto
clip_func(const Device::Pointer & device,
          const Array::Pointer &  src,
          Array::Pointer          dst,
          float                   min_intensity,
          float                   max_intensity) -> Array::Pointer;

auto
closing_box_func(const Device::Pointer & device,
                 const Array::Pointer &  src,
                 Array::Pointer          dst,
                 int                     radius_x,
                 int                     radius_y,
                 int                     radius_z) -> Array::Pointer;

auto
closing_sphere_func(const Device::Pointer & device,
                    const Array::Pointer &  src,
                    Array::Pointer          dst,
                    float                   radius_x,
                    float                   radius_y,
                    float                   radius_z) -> Array::Pointer;

auto
concatenate_along_x_func(const Device::Pointer & device,
                         const Array::Pointer &  src0,
                         const Array::Pointer &  src1,
                         Array::Pointer          dst) -> Array::Pointer;

auto
concatenate_along_y_func(const Device::Pointer & device,
                         const Array::Pointer &  src0,
                         const Array::Pointer &  src1,
                         Array::Pointer          dst) -> Array::Pointer;

auto
concatenate_along_z_func(const Device::Pointer & device,
                         const Array::Pointer &  src0,
                         const Array::Pointer &  src1,
                         Array::Pointer          dst) -> Array::Pointer;

auto
count_touching_neighbors_func(const Device::Pointer & device,
                              const Array::Pointer &  src,
                              Array::Pointer          dst,
                              bool                    ignore_background) -> Array::Pointer;

auto
crop_border_func(const Device::Pointer & device, const Array::Pointer & src, Array::Pointer dst, int border_size)
  -> Array::Pointer;

// @StRigaud TODO: auto distance_matrix_to_mesh_func

auto
divide_by_gaussian_background_func(const Device::Pointer & device,
                                   const Array::Pointer &  src,
                                   Array::Pointer          dst,
                                   float                   sigma_x,
                                   float                   sigma_y,
                                   float                   sigma_z) -> Array::Pointer;

auto
degrees_to_radians_func(const Device::Pointer & device, const Array::Pointer & src, Array::Pointer dst)
  -> Array::Pointer;

auto
difference_of_gaussian_func(const Device::Pointer & device,
                            const Array::Pointer &  src,
                            Array::Pointer          dst,
                            float                   sigma1_x,
                            float                   sigma1_y,
                            float                   sigma1_z,
                            float                   sigma2_x,
                            float                   sigma2_y,
                            float                   sigma2_z) -> Array::Pointer;

auto
extend_labeling_via_voronoi_func(const Device::Pointer & device, const Array::Pointer & src, Array::Pointer dst)
  -> Array::Pointer;

// @StRigaud TODO: auto generate_maximum_intensity_between_points_matrix_func
// @StRigaud TODO: auto generate_mean_intensity_between_points_matrix_func
// @StRigaud TODO: auto generate_minimum_intensity_between_points_matrix_func
// @StRigaud TODO: auto generate_standard_deviation_intensity_between_points_matrix_func
// @StRigaud TODO: auto generate_should_touch_matrix_func

auto
invert_func(const Device::Pointer & device, const Array::Pointer & src, Array::Pointer dst) -> Array::Pointer;

auto
label_spots_func(const Device::Pointer & device, const Array::Pointer & src, Array::Pointer dst) -> Array::Pointer;

auto
large_hessian_eigenvalue_func(const Device::Pointer & device, const Array::Pointer & src, Array::Pointer dst)
  -> Array::Pointer;

auto
maximum_of_all_pixels_func(const Device::Pointer & device, const Array::Pointer & src) -> float;

// @StRigaud TODO: auto maximum_of_touching_neighbors_func
// @StRigaud TODO: auto mean_of_touching_neighbors_func
// @StRigaud TODO: auto median_of_touching_neighbors_func

auto
minimum_of_all_pixels_func(const Device::Pointer & device, const Array::Pointer & src) -> float;

auto
minimum_of_masked_pixels_func(const Device::Pointer & device, const Array::Pointer & src, const Array::Pointer & mask)
  -> float;

// @StRigaud TODO: auto minimum_of_touching_neighbors_func
// @StRigaud TODO: auto mode_of_touching_neighbors_func
// @StRigaud TODO: auto neighbors_of_neighbors_func

auto
opening_box_func(const Device::Pointer & device,
                 const Array::Pointer &  src,
                 Array::Pointer          dst,
                 int                     radius_x,
                 int                     radius_y,
                 int                     radius_z) -> Array::Pointer;

auto
opening_sphere_func(const Device::Pointer & device,
                    const Array::Pointer &  src,
                    Array::Pointer          dst,
                    float                   radius_x,
                    float                   radius_y,
                    float                   radius_z) -> Array::Pointer;

// @StRigaud TODO: auto pointlist_to_labelled_spots_func
// @StRigaud TODO: auto prefix_in_x_func

auto
radians_to_degrees_func(const Device::Pointer & device, const Array::Pointer & src, Array::Pointer dst)
  -> Array::Pointer;

// @StRigaud TODO: auto reduce_stack_func

auto
small_hessian_eigenvalue_func(const Device::Pointer & device, const Array::Pointer & src, Array::Pointer dst)
  -> Array::Pointer;

auto
square_func(const Device::Pointer & device, const Array::Pointer & src, Array::Pointer dst) -> Array::Pointer;

auto
squared_difference_func(const Device::Pointer & device,
                        const Array::Pointer &  src0,
                        const Array::Pointer &  src1,
                        Array::Pointer          dst) -> Array::Pointer;


auto
standard_deviation_box_func(const Device::Pointer & device,
                            const Array::Pointer &  src,
                            Array::Pointer          dst,
                            int                     radius_x,
                            int                     radius_y,
                            int                     radius_z) -> Array::Pointer;

// @StRigaud TODO: auto standard_deviation_of_touching_neighbors_func

auto
standard_deviation_sphere_func(const Device::Pointer & device,
                               const Array::Pointer &  src,
                               Array::Pointer          dst,
                               int                     radius_x,
                               int                     radius_y,
                               int                     radius_z) -> Array::Pointer;

// @StRigaud TODO: auto sub_stack_func

auto
subtract_gaussian_background_func(const Device::Pointer & device,
                                  const Array::Pointer &  src,
                                  Array::Pointer          dst,
                                  float                   sigma_x,
                                  float                   sigma_y,
                                  float                   sigma_z) -> Array::Pointer;

auto
subtract_images_func(const Device::Pointer & device,
                     const Array::Pointer &  src0,
                     const Array::Pointer &  src1,
                     Array::Pointer          dst) -> Array::Pointer;

auto
sum_of_all_pixels_func(const Device::Pointer & device, const Array::Pointer & src) -> float;


// @StRigaud TODO: auto symmetric_maximum_matrix_func
// @StRigaud TODO: auto symmetric_mean_matrix_func
// @StRigaud TODO: auto symmetric_minimum_matrix_func
// @StRigaud TODO: auto symmetric_sum_matrix_func

auto
top_hat_box_func(const Device::Pointer & device,
                 const Array::Pointer &  src,
                 Array::Pointer          dst,
                 int                     radius_x,
                 int                     radius_y,
                 int                     radius_z) -> Array::Pointer;

auto
top_hat_sphere_func(const Device::Pointer & device,
                    const Array::Pointer &  src,
                    Array::Pointer          dst,
                    float                   radius_x,
                    float                   radius_y,
                    float                   radius_z) -> Array::Pointer;

// @StRigaud TODO: auto touch_matrix_to_adjacency_matrix_func

// @StRigaud TODO: auto z_coordinate_projection_func

} // namespace cle::tier2

#endif // __INCLUDE_TIER2_HPP
