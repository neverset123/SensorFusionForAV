// PCL lib Functions for processing point clouds 

#include "processPointClouds.h"
#include <unordered_set>
#include "quiz/cluster/clustering.h"
// #include "quiz/ransac/ransac2d.h"

//constructor:
template<typename PointT>
ProcessPointClouds<PointT>::ProcessPointClouds() {}


//de-constructor:
template<typename PointT>
ProcessPointClouds<PointT>::~ProcessPointClouds() {}


template<typename PointT>
void ProcessPointClouds<PointT>::numPoints(typename pcl::PointCloud<PointT>::Ptr cloud)
{
    std::cout << cloud->points.size() << std::endl;
}


template<typename PointT>
typename pcl::PointCloud<PointT>::Ptr ProcessPointClouds<PointT>::FilterCloud(typename pcl::PointCloud<PointT>::Ptr cloud, float filterRes, Eigen::Vector4f minPoint, Eigen::Vector4f maxPoint)
{

    // Time segmentation process
    auto startTime = std::chrono::steady_clock::now();

    // TODO:: Fill in the function to do voxel grid point reduction and region based filtering
    typename pcl::PointCloud<PointT>::Ptr filteredCloud {new pcl::PointCloud<PointT>};
    pcl::VoxelGrid<PointT> vg;
    vg.setInputCloud(cloud);
    vg.setLeafSize(filterRes, filterRes, filterRes);
    vg.filter(*filteredCloud);
    std::cout<<filteredCloud->points.size()<<std::endl;

    typename pcl::PointCloud<PointT>::Ptr cloudRegion {new pcl::PointCloud<PointT>};
    pcl::CropBox<PointT> region(true);
    region.setMin(minPoint);
    region.setMax(maxPoint);
    region.setInputCloud(filteredCloud);
    region.filter(*cloudRegion);
    std::cout<<cloudRegion->points.size()<<std::endl;

    //remove roof points
    std::vector<int> indices;
    pcl::CropBox<PointT> roof(true);
    region.setMin(Eigen::Vector4f (-1.5, 1.7, -1, 1));
    region.setMax(Eigen::Vector4f (2.6, 1.7, 0.4, 1));
    region.setInputCloud(cloudRegion);
    region.filter(indices);


    pcl::PointIndices::Ptr inliers {new pcl::PointIndices};
    for(int id: indices)
    {
        std::cout<<id<<std::endl;
        inliers->indices.push_back(id);
    }

    pcl::ExtractIndices<PointT> extract;
    extract.setInputCloud(cloudRegion);
    extract.setIndices(inliers);
    extract.setNegative(true);
    extract.filter(*cloudRegion);


    auto endTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << "filtering took " << elapsedTime.count() << " milliseconds" << std::endl;

    return cloudRegion;

}


template<typename PointT>
std::pair<typename pcl::PointCloud<PointT>::Ptr, typename pcl::PointCloud<PointT>::Ptr> ProcessPointClouds<PointT>::SeparateClouds(pcl::PointIndices::Ptr inliers, typename pcl::PointCloud<PointT>::Ptr cloud) 
{
    // TODO: Create two new point clouds, one cloud with obstacles and other with segmented plane
    pcl::ExtractIndices<PointT> extract;
    typename pcl::PointCloud<PointT>::Ptr obstCloud {new pcl::PointCloud<PointT>};
    typename pcl::PointCloud<PointT>::Ptr planeCloud {new pcl::PointCloud<PointT>};
    for(int index : inliers->indices)
    {
        planeCloud->points.push_back(cloud->points[index]);
    }

    extract.setInputCloud (cloud);
    extract.setIndices (inliers);
    extract.setNegative (true);
    extract.filter (*obstCloud);
    std::cerr << "PointCloud representing the planar component: " << obstCloud->width * obstCloud->height << " data points." << std::endl;

    std::pair<typename pcl::PointCloud<PointT>::Ptr, typename pcl::PointCloud<PointT>::Ptr> segResult(obstCloud, planeCloud);
    return segResult;
}


template<typename PointT>
std::unordered_set<int> Ransac3D(typename pcl::PointCloud<PointT>::Ptr cloud, int maxIterations, float distanceTol)
{
	std::unordered_set<int> inliersResult;
	srand(time(NULL));
	
	// TODO: Fill in this function
	std::unordered_set<int> inliers;
	int size = cloud->points.size();
	if(size<=3)
	{
		for(int index=0; index<size; index++)
		{
			inliersResult.insert(index);
		}
		return inliersResult;
	}
	for(int index=0; index<maxIterations; index++)
	{
        int i1=0, i2=0, i3=0;
        while(i1==i2 || i1==i3 || i2==i3)
        {
            i1 = rand()%size;
            i2 = rand()%size;
			i3 = rand()%size;
        }
		double a = (cloud->points[i2].y-cloud->points[i1].y)*(cloud->points[i3].z-cloud->points[i1].z)-
					(cloud->points[i2].z-cloud->points[i1].z)*(cloud->points[i3].y-cloud->points[i1].y);
		double b = (cloud->points[i2].z-cloud->points[i1].z)*(cloud->points[i3].x-cloud->points[i1].x)-
					(cloud->points[i2].x-cloud->points[i1].x)*(cloud->points[i3].z-cloud->points[i1].z);
		double c = (cloud->points[i2].x-cloud->points[i1].x)*(cloud->points[i3].y-cloud->points[i1].y)-
					(cloud->points[i2].y-cloud->points[i1].y)*(cloud->points[i3].x-cloud->points[i1].x);
		double d = -(a*cloud->points[i1].x + b*cloud->points[i1].y + c*cloud->points[i1].z);
		for(int i=0; i<size; i++)
		{
			double distance = fabs(a*cloud->points[i].x + b*cloud->points[i].y + c*cloud->points[i].z + d)/sqrt(a*a+b*b+c*c);
			if(distance < distanceTol)
			{
				inliers.insert(i);
			}
		}
		if(inliers.size() > inliersResult.size())
		{
			inliersResult = inliers;
		}
		inliers.clear();
	}
	return inliersResult;
}

template<typename PointT>
std::pair<typename pcl::PointCloud<PointT>::Ptr, typename pcl::PointCloud<PointT>::Ptr> ProcessPointClouds<PointT>::SegmentPlane(typename pcl::PointCloud<PointT>::Ptr cloud, int maxIterations, float distanceThreshold)
{
    // Time segmentation process
    auto startTime = std::chrono::steady_clock::now();
    // TODO:: Fill in this function to find inliers for the cloud.
    // pcl::SACSegmentation<PointT> seg;
    // pcl::PointIndices::Ptr inliers {new pcl::PointIndices};
    // pcl::ModelCoefficients::Ptr coefficients {new pcl::ModelCoefficients};

    // seg.setOptimizeCoefficients(true);
    // seg.setModelType(pcl::SACMODEL_PLANE);
    // seg.setMethodType(pcl::SAC_RANSAC);
    // seg.setMaxIterations(maxIterations);
    // seg.setDistanceThreshold(distanceThreshold);

    // seg.setInputCloud(cloud);
    // seg.segment(*inliers, *coefficients);
    // if (inliers->indices.size() == 0)
    // {
    //     std::cerr << "Could not estimate a planar model for the given dataset." << std::endl;
    // }

	std::unordered_set<int> inliers = Ransac3D<PointT>(cloud, maxIterations, distanceThreshold);

	typename pcl::PointCloud<PointT>::Ptr  cloudInliers(new pcl::PointCloud<PointT>());
	typename pcl::PointCloud<PointT>::Ptr cloudOutliers(new pcl::PointCloud<PointT>());

	for(int index = 0; index < cloud->points.size(); index++)
	{
	    PointT point = cloud->points[index];
		if(inliers.count(index))
			cloudInliers->points.push_back(point);
		else
			cloudOutliers->points.push_back(point);
	}

    std::pair<typename pcl::PointCloud<PointT>::Ptr, typename pcl::PointCloud<PointT>::Ptr> segResult(cloudOutliers, cloudInliers);
    auto endTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << "plane segmentation took " << elapsedTime.count() << " milliseconds" << std::endl;

    return segResult;
}

template<typename PointT>
std::vector<typename pcl::PointCloud<PointT>::Ptr> ProcessPointClouds<PointT>::Clustering(typename pcl::PointCloud<PointT>::Ptr cloud, float clusterTolerance, int minSize, int maxSize)
{

    // Time clustering process
    auto startTime = std::chrono::steady_clock::now();

    std::vector<typename pcl::PointCloud<PointT>::Ptr> clusters;

    // TODO:: Fill in the function to perform euclidean clustering to group detected obstacles
    // typename pcl::search::KdTree<PointT>::Ptr tree (new pcl::search::KdTree<PointT>);
    // tree->setInputCloud(cloud);
    // std::vector<pcl::PointIndices> cluster_indices;
    // pcl::EuclideanClusterExtraction<PointT> ec;
    // ec.setClusterTolerance (clusterTolerance);
    // ec.setMinClusterSize (minSize);
    // ec.setMaxClusterSize (maxSize);
    // ec.setSearchMethod(tree);
    // ec.setInputCloud(cloud);
    // ec.extract(cluster_indices);
    // for (const auto& cluster : cluster_indices)
    // {
    //     typename pcl::PointCloud<PointT>::Ptr cloud_cluster (new pcl::PointCloud<PointT>);
    //     for (const auto& idx : cluster.indices) {
    //         cloud_cluster->push_back((*cloud)[idx]);
    //     }
    //     cloud_cluster->width = cloud_cluster->size();
    //     cloud_cluster->height = 1;
    //     cloud_cluster->is_dense = true;
    //     clusters.push_back(cloud_cluster);
    // }

    KdTree* tree = new KdTree;
    std::vector<float> point;
    std::vector<std::vector<float>> points;
    for (int i=0; i<cloud->points.size(); i++)
    {
        point = {cloud->points[i].x, cloud->points[i].y, cloud->points[i].z};
        points.push_back(point);
        tree->insert(point,i); 
    }
        
    std::vector<std::vector<int>> clusterIdsVec = euclideanCluster(points, tree, clusterTolerance);
  	for(std::vector<int> clusterIds : clusterIdsVec)
  	{
        typename pcl::PointCloud<PointT>::Ptr cloud_cluster (new pcl::PointCloud<PointT>);
        for (const auto& idx : clusterIds) {
            
            cloud_cluster->push_back(cloud->points[idx]);
        }
        cloud_cluster->width = cloud_cluster->size();
        cloud_cluster->height = 1;
        cloud_cluster->is_dense = true;
        clusters.push_back(cloud_cluster);
  	}

    auto endTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
    std::cout << "clustering took " << elapsedTime.count() << " milliseconds and found " << clusters.size() << " clusters" << std::endl;

    return clusters;
}


template<typename PointT>
Box ProcessPointClouds<PointT>::BoundingBox(typename pcl::PointCloud<PointT>::Ptr cluster)
{

    // Find bounding box for one of the clusters
    PointT minPoint, maxPoint;
    pcl::getMinMax3D(*cluster, minPoint, maxPoint);

    Box box;
    box.x_min = minPoint.x;
    box.y_min = minPoint.y;
    box.z_min = minPoint.z;
    box.x_max = maxPoint.x;
    box.y_max = maxPoint.y;
    box.z_max = maxPoint.z;

    return box;
}


template<typename PointT>
void ProcessPointClouds<PointT>::savePcd(typename pcl::PointCloud<PointT>::Ptr cloud, std::string file)
{
    pcl::io::savePCDFileASCII (file, *cloud);
    std::cerr << "Saved " << cloud->points.size () << " data points to "+file << std::endl;
}


template<typename PointT>
typename pcl::PointCloud<PointT>::Ptr ProcessPointClouds<PointT>::loadPcd(std::string file)
{

    typename pcl::PointCloud<PointT>::Ptr cloud (new pcl::PointCloud<PointT>);

    if (pcl::io::loadPCDFile<PointT> (file, *cloud) == -1) //* load the file
    {
        PCL_ERROR ("Couldn't read file \n");
    }
    std::cerr << "Loaded " << cloud->points.size () << " data points from "+file << std::endl;

    return cloud;
}


template<typename PointT>
std::vector<boost::filesystem::path> ProcessPointClouds<PointT>::streamPcd(std::string dataPath)
{

    std::vector<boost::filesystem::path> paths(boost::filesystem::directory_iterator{dataPath}, boost::filesystem::directory_iterator{});

    // sort files in accending order so playback is chronological
    sort(paths.begin(), paths.end());

    return paths;

}