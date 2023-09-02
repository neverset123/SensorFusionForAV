#ifndef ransac2d_h
#define ransac2d_h
#include <unordered_set>
#include "../../processPointClouds.h"
#include <pcl/point_cloud.h>
#include <pcl/impl/point_types.hpp>

template<typename PointT>
std::unordered_set<int> Ransac3D(typename pcl::PointCloud<PointT>::Ptr cloud, int maxIterations, float distanceTol);
#endif 