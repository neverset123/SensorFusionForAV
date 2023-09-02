#ifndef CLUSTERING_H
#define CLUSTERING_H
#include <vector>
#include "kdtree.h"

std::vector<std::vector<int>> euclideanCluster(const std::vector<std::vector<float>>& points, KdTree* tree, float distanceTol);
#endif