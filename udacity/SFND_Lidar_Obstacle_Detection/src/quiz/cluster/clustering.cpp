#include "kdtree.h"

void proximity(KdTree* tree, const std::vector<std::vector<float>>& points, std::vector<int> &cluster, std::vector<int> &processed, int id, float distanceTol)
{
	if(std::find(processed.begin(), processed.end(), id)==processed.end())
	{
		processed.push_back(id);
		cluster.push_back(id);
		std::vector<int> nearby_ids = tree->search(points[id], distanceTol);
		for(int nearby_id: nearby_ids)
		{
			proximity(tree, points, cluster, processed, nearby_id, distanceTol);
		}
	}
}

std::vector<std::vector<int>> euclideanCluster(const std::vector<std::vector<float>>& points, KdTree* tree, float distanceTol)
{

	// TODO: Fill out this function to return list of indices for each cluster
	std::vector<std::vector<int>> clusters;
	std::vector<int> processed;
	std::vector<int> cluster;
	while(processed.size()!=points.size())
	{	
		std::cout<<processed.size()<<std::endl;
		for(int id=0; id<points.size(); id++)
		{
			if(std::find(processed.begin(), processed.end(), id)==processed.end())
			{
				cluster.clear();
				proximity(tree, points, cluster, processed, id, distanceTol);
				clusters.push_back(cluster);
			}
		}
		
	}
	return clusters;

}