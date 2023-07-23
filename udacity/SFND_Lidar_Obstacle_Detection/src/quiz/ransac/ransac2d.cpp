/* \author Aaron Brown */
// Quiz on implementing simple RANSAC line fitting

#include "../../render/render.h"
#include <unordered_set>
#include "../../processPointClouds.h"
// using templates for processPointClouds so also include .cpp to help linker
#include "../../processPointClouds.cpp"

pcl::PointCloud<pcl::PointXYZ>::Ptr CreateData()
{
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>());
  	// Add inliers
  	float scatter = 0.6;
  	for(int i = -5; i < 5; i++)
  	{
  		double rx = 2*(((double) rand() / (RAND_MAX))-0.5);
  		double ry = 2*(((double) rand() / (RAND_MAX))-0.5);
  		pcl::PointXYZ point;
  		point.x = i+scatter*rx;
  		point.y = i+scatter*ry;
  		point.z = 0;

  		cloud->points.push_back(point);
  	}
  	// Add outliers
  	int numOutliers = 10;
  	while(numOutliers--)
  	{
  		double rx = 2*(((double) rand() / (RAND_MAX))-0.5);
  		double ry = 2*(((double) rand() / (RAND_MAX))-0.5);
  		pcl::PointXYZ point;
  		point.x = 5*rx;
  		point.y = 5*ry;
  		point.z = 0;

  		cloud->points.push_back(point);

  	}
  	cloud->width = cloud->points.size();
  	cloud->height = 1;

  	return cloud;

}

pcl::PointCloud<pcl::PointXYZ>::Ptr CreateData3D()
{
	ProcessPointClouds<pcl::PointXYZ> pointProcessor;
	return pointProcessor.loadPcd("../../sensors/data/pcd/simpleHighway.pcd");
}


pcl::visualization::PCLVisualizer::Ptr initScene()
{
	pcl::visualization::PCLVisualizer::Ptr viewer(new pcl::visualization::PCLVisualizer ("2D Viewer"));
	viewer->setBackgroundColor (0, 0, 0);
  	viewer->initCameraParameters();
  	viewer->setCameraPosition(0, 0, 15, 0, 1, 0);
  	viewer->addCoordinateSystem (1.0);
  	return viewer;
}

std::unordered_set<int> Ransac(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud, int maxIterations, float distanceTol)
{
	std::unordered_set<int> inliersResult;
	srand(time(NULL));
	
	// TODO: Fill in this function
	std::unordered_set<int> inliers;
	int size = cloud->points.size();
	if(size<=2)
	{
		for(int index=0; index<size; index++)
		{
			inliersResult.insert(index);
		}
		return inliersResult;
	}
	for(int index=0; index<maxIterations; index++)
	{
        int i1=0, i2=0;
        while(i1==i2)
        {
            i1 = rand()%size;
            i2 = rand()%size;
        }
		double slope = (cloud->points[i1].y-cloud->points[i2].y)/(cloud->points[i1].x-cloud->points[i2].x);
		double residuals = cloud->points[i1].y-slope*cloud->points[i1].x;
		for(int i=0; i<size; i++)
		{
			double distance = fabs(cloud->points[i].y-slope*cloud->points[i].x-residuals)/sqrt(1+pow(slope, 2));
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

std::unordered_set<int> Ransac3D(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud, int maxIterations, float distanceTol)
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

int main ()
{

	// Create viewer
	pcl::visualization::PCLVisualizer::Ptr viewer = initScene();

	// Create data
	//pcl::PointCloud<pcl::PointXYZ>::Ptr cloud = CreateData();
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud = CreateData3D();

	// TODO: Change the max iteration and distance tolerance arguments for Ransac function
	std::unordered_set<int> inliers = Ransac3D(cloud, 10, 1);

	pcl::PointCloud<pcl::PointXYZ>::Ptr  cloudInliers(new pcl::PointCloud<pcl::PointXYZ>());
	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudOutliers(new pcl::PointCloud<pcl::PointXYZ>());

	for(int index = 0; index < cloud->points.size(); index++)
	{
		pcl::PointXYZ point = cloud->points[index];
		if(inliers.count(index))
			cloudInliers->points.push_back(point);
		else
			cloudOutliers->points.push_back(point);
	}


	// Render 2D point cloud with inliers and outliers
	if(inliers.size())
	{
		renderPointCloud(viewer,cloudInliers,"inliers",Color(0,1,0));
  		renderPointCloud(viewer,cloudOutliers,"outliers",Color(1,0,0));
	}
  	else
  	{
  		renderPointCloud(viewer,cloud,"data");
  	}
	
  	while (!viewer->wasStopped ())
  	{
  	  viewer->spinOnce ();
  	}
  	
}
