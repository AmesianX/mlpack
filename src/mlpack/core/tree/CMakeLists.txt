# Define the files we need to compile.
# Anything not in this list will not be compiled into mlpack.
set(SOURCES
  ballbound.hpp
  ballbound_impl.hpp
  binary_space_tree.hpp
  binary_space_tree/binary_space_tree.hpp
  binary_space_tree/binary_space_tree_impl.hpp
  binary_space_tree/breadth_first_dual_tree_traverser.hpp
  binary_space_tree/breadth_first_dual_tree_traverser_impl.hpp
  binary_space_tree/dual_tree_traverser.hpp
  binary_space_tree/dual_tree_traverser_impl.hpp
  binary_space_tree/mean_split.hpp
  binary_space_tree/mean_split_impl.hpp
  binary_space_tree/midpoint_split.hpp
  binary_space_tree/midpoint_split_impl.hpp
  binary_space_tree/single_tree_traverser.hpp
  binary_space_tree/single_tree_traverser_impl.hpp
  binary_space_tree/traits.hpp
  binary_space_tree/typedef.hpp
  bounds.hpp
  bound_traits.hpp
  cosine_tree/cosine_tree.hpp
  cosine_tree/cosine_tree.cpp
  cover_tree/cover_tree.hpp
  cover_tree/cover_tree_impl.hpp
  cover_tree/first_point_is_root.hpp
  cover_tree/single_tree_traverser.hpp
  cover_tree/single_tree_traverser_impl.hpp
  cover_tree/dual_tree_traverser.hpp
  cover_tree/dual_tree_traverser_impl.hpp
  cover_tree/traits.hpp
  cover_tree/typedef.hpp
  example_tree.hpp
  hrectbound.hpp
  hrectbound_impl.hpp
  rectangle_tree.hpp
  rectangle_tree/rectangle_tree.hpp
  rectangle_tree/rectangle_tree_impl.hpp
  rectangle_tree/single_tree_traverser.hpp
  rectangle_tree/single_tree_traverser_impl.hpp
  rectangle_tree/dual_tree_traverser.hpp
  rectangle_tree/dual_tree_traverser_impl.hpp
  rectangle_tree/r_tree_split.hpp
  rectangle_tree/r_tree_split_impl.hpp
  rectangle_tree/no_auxiliary_information.hpp
  rectangle_tree/r_tree_descent_heuristic.hpp
  rectangle_tree/r_tree_descent_heuristic_impl.hpp
  rectangle_tree/r_star_tree_descent_heuristic.hpp
  rectangle_tree/r_star_tree_descent_heuristic_impl.hpp
  rectangle_tree/r_star_tree_split.hpp
  rectangle_tree/r_star_tree_split_impl.hpp
  rectangle_tree/x_tree_split.hpp
  rectangle_tree/x_tree_split_impl.hpp
  rectangle_tree/x_tree_auxiliary_information.hpp
  rectangle_tree/hilbert_r_tree_descent_heuristic.hpp
  rectangle_tree/hilbert_r_tree_descent_heuristic_impl.hpp
  rectangle_tree/hilbert_r_tree_split.hpp
  rectangle_tree/hilbert_r_tree_split_impl.hpp
  rectangle_tree/hilbert_r_tree_auxiliary_information.hpp
  rectangle_tree/hilbert_r_tree_auxiliary_information_impl.hpp
  rectangle_tree/discrete_hilbert_value.hpp
  rectangle_tree/discrete_hilbert_value_impl.hpp
  rectangle_tree/r_plus_tree_descent_heuristic.hpp
  rectangle_tree/r_plus_tree_descent_heuristic_impl.hpp
  rectangle_tree/minimal_coverage_sweep.hpp
  rectangle_tree/minimal_coverage_sweep_impl.hpp
  rectangle_tree/minimal_splits_number_sweep.hpp
  rectangle_tree/minimal_splits_number_sweep_impl.hpp
  rectangle_tree/r_plus_tree_split.hpp
  rectangle_tree/r_plus_tree_split_impl.hpp
  rectangle_tree/r_plus_tree_split_policy.hpp
  rectangle_tree/r_plus_plus_tree_descent_heuristic.hpp
  rectangle_tree/r_plus_plus_tree_descent_heuristic_impl.hpp
  rectangle_tree/r_plus_plus_tree_split_policy.hpp
  rectangle_tree/r_plus_plus_tree_auxiliary_information.hpp
  rectangle_tree/r_plus_plus_tree_auxiliary_information_impl.hpp
  statistic.hpp
  traversal_info.hpp
  tree_traits.hpp
)

# add directory name to sources
set(DIR_SRCS)
foreach(file ${SOURCES})
  set(DIR_SRCS ${DIR_SRCS} ${CMAKE_CURRENT_SOURCE_DIR}/${file})
endforeach()
# Append sources (with directory name) to list of all mlpack sources (used at
# the parent scope).
set(MLPACK_SRCS ${MLPACK_SRCS} ${DIR_SRCS} PARENT_SCOPE)
