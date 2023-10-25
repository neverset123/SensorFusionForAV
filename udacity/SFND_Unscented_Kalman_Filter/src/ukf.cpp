#include "ukf.h"
#include "Eigen/Dense"
#include <iostream>

using Eigen::MatrixXd;
using Eigen::VectorXd;

/**
 * Initializes Unscented Kalman filter
 */
UKF::UKF() {

  is_initialized_ = false;
  // if this is false, laser measurements will be ignored (except during init)
  use_laser_ = true;

  // if this is false, radar measurements will be ignored (except during init)
  use_radar_ = true;

  // state vector dimension
  n_x_ = 5;

  // lambda parameter
  lambda_ = 3-n_x_;

  // augmented stated vector dimension
  n_aug_ = 7;

  // initial state vector
  x_ = VectorXd(n_x_);
  x_.fill(.0);

  // initial covariance matrix
  P_ = MatrixXd(n_x_, n_x_);
  P_ << 1,    0,    0,   0,   0,
        0,    1,    0,   0,   0,
        0,    0,    1,   0,   0,
        0,    0,    0,   1,   0,
        0,    0,    0,   0,   1;

  // sigma points prediction
  Xsig_pred_ = MatrixXd(n_x_, 2 * n_aug_ + 1);
  Xsig_pred_.fill(.0);

  // augmented state
  x_aug_ = VectorXd(n_aug_);
  x_aug_.fill(0);
  P_aug_ = MatrixXd(n_aug_, n_aug_);
  Xsig_aug_ = MatrixXd(n_aug_, 2*n_aug_+1);

  // weights of sigma points
  weights_ = VectorXd(2*n_aug_+1);
  weights_(0) = lambda_/(lambda_+n_aug_);
  for(int i=1; i<2*n_aug_+1; i++)
  {
      weights_(i) = 1/(2*(lambda_+n_aug_));
  }

  // last timestamp
  previous_timestamp_ = 0;

  // Process noise standard deviation longitudinal acceleration in m/s^2
  std_a_ = 2.0;

  // Process noise standard deviation yaw acceleration in rad/s^2
  std_yawdd_ = M_PI;
  
  /**
   * DO NOT MODIFY measurement noise values below.
   * These are provided by the sensor manufacturer.
   */

  // Laser measurement noise standard deviation position1 in m
  std_laspx_ = 0.15;

  // Laser measurement noise standard deviation position2 in m
  std_laspy_ = 0.15;

  // Radar measurement noise standard deviation radius in m
  std_radr_ = 0.3;

  // Radar measurement noise standard deviation angle in rad
  std_radphi_ = 0.03;

  // Radar measurement noise standard deviation radius change in m/s
  std_radrd_ = 0.3;
  
  /**
   * End DO NOT MODIFY section for measurement noise values 
   */
  
  /**
   * TODO: Complete the initialization. See ukf.h for other member properties.
   * Hint: one or more values initialized above might be wildly off...
   */
}

UKF::~UKF() {}

void change_angle_range(double& angle)
{
  if(angle > M_PI)
    angle -= 2 * M_PI;
  else if(angle < -M_PI)
    angle += 2 * M_PI;
}

void UKF::ProcessMeasurement(MeasurementPackage meas_package) {
  /**
   * TODO: Complete this function! Make sure you switch between lidar and radar
   * measurements.
   */

  if (!is_initialized_) {
    if(meas_package.sensor_type_ == MeasurementPackage::LASER)
    {
      x_ << meas_package.raw_measurements_[0], 
            meas_package.raw_measurements_[1], 
            0,
            0, 
            0;
    }
    else if(meas_package.sensor_type_ == MeasurementPackage::RADAR)
    {
      x_ << meas_package.raw_measurements_[0]*cos(meas_package.raw_measurements_[1]), 
            - meas_package.raw_measurements_[0]*sin(meas_package.raw_measurements_[1]), 
            0,
            0, 
            0;
    }
    else
    {
      throw std::invalid_argument("invalid measurement data...");
    }
    previous_timestamp_ = meas_package.timestamp_;
    is_initialized_ = true;
    return;
  }
  double dt = (meas_package.timestamp_ - previous_timestamp_) / 1000000.0;
  previous_timestamp_ = meas_package.timestamp_;

  Prediction(dt);
  // update measurements
  if(meas_package.sensor_type_ == MeasurementPackage::LASER)
  {
    UpdateLidar(meas_package);
  }
  else if(meas_package.sensor_type_ == MeasurementPackage::RADAR)
  {
    UpdateRadar(meas_package);
  }
  else
  {
    throw std::invalid_argument("invalid measurement data...");
  }
}

void UKF::Prediction(double delta_t) {
  /**
   * TODO: Complete this function! Estimate the object's location. 
   * Modify the state vector, x_. Predict sigma points, the state, 
   * and the state covariance matrix.
   */
  // set augmented state
  x_aug_.head(n_x_) = x_;
  for(int i=n_x_; i<n_aug_; i++)
  {
    x_aug_(i) = 0;
  }

  // covariance
  P_aug_.fill(.0);
  P_aug_.topLeftCorner(n_x_, n_x_) = P_;
  P_aug_(n_x_, n_x_) = std_a_ * std_a_;
  P_aug_(n_x_ + 1, n_x_ + 1) = std_yawdd_ * std_yawdd_;
  A = P_aug_.llt().matrixL();

  Xsig_aug_.fill(.0);
  Xsig_aug_.col(0) = x_aug_;
  for(int i=0; i<n_aug_; i++)
  {
    Xsig_aug_.col(i+1) = x_aug_ + sqrt(lambda_+n_aug_) * A.col(i);
    Xsig_aug_.col(i+1+n_aug_) = x_aug_ - sqrt(lambda_+n_aug_) * A.col(i);
  }

  // prediction
  for (int i = 0; i< 2 * n_aug_ + 1; i++) {
    if(abs(Xsig_aug_(4, i))<0.001)
    {
        Xsig_pred_(0, i) = Xsig_aug_(0 ,i) + Xsig_aug_(2, i)*cos(Xsig_aug_(3, i))*delta_t+ \
        0.5*delta_t*delta_t*cos(Xsig_aug_(3, i))*Xsig_aug_(5, i);
        Xsig_pred_(1, i) = Xsig_aug_(1 ,i) + Xsig_aug_(2, i)*sin(Xsig_aug_(3, i))*delta_t+ \
        0.5*delta_t*delta_t*sin(Xsig_aug_(3, i))*Xsig_aug_(5, i);
        Xsig_pred_(2, i) = Xsig_aug_(2 ,i) + Xsig_aug_(5, i)*delta_t;
        Xsig_pred_(3, i) = Xsig_aug_(3 ,i) + Xsig_aug_(4, i)*delta_t + \
        0.5*delta_t*delta_t*Xsig_aug_(6, i);
        Xsig_pred_(4, i) = Xsig_aug_(4, i) + Xsig_aug_(6, i)*delta_t;
    }
    else
    {
        Xsig_pred_(0, i) = Xsig_aug_(0 ,i) + Xsig_aug_(2, i)/Xsig_aug_(4, i)*(sin(Xsig_aug_(3, i)+Xsig_aug_(4, i)*delta_t)-sin(Xsig_aug_(3, i)))+ \
        0.5*delta_t*delta_t*cos(Xsig_aug_(3, i))*Xsig_aug_(5, i);
        Xsig_pred_(1, i) = Xsig_aug_(1 ,i) + Xsig_aug_(2, i)/Xsig_aug_(4, i)*(-cos(Xsig_aug_(3, i)+Xsig_aug_(4, i)*delta_t)+cos(Xsig_aug_.coeff(3, i)))+ \
        0.5*delta_t*delta_t*sin(Xsig_aug_(3, i))*Xsig_aug_(5, i);
        Xsig_pred_(2, i) = Xsig_aug_(2 ,i) + Xsig_aug_(5, i)*delta_t;
        Xsig_pred_(3, i) = Xsig_aug_(3 ,i) + Xsig_aug_(4, i)*delta_t + \
        0.5*delta_t*delta_t*Xsig_aug_(6, i);
        Xsig_pred_(4, i) = Xsig_aug_(4, i) + Xsig_aug_(6, i)*delta_t;
    }
  }

  // get predict mean and variance
  P_.fill(.0);
  x_ = Xsig_pred_ * weights_;
  for(int i=0; i<2 * n_aug_ + 1; i++)
  {
    VectorXd delta_x = Xsig_pred_.col(i)-x_;
    while(!(delta_x(3)>-M_PI && delta_x(3)<M_PI)){
      change_angle_range(delta_x(3));
    }
    P_ += weights_(i) * delta_x * delta_x.transpose();
  }
}

void UKF::UpdateLidar(MeasurementPackage meas_package) {
  /**
   * TODO: Complete this function! Use lidar data to update the belief 
   * about the object's position. Modify the state vector, x_, and 
   * covariance, P_.
   * You can also calculate the lidar NIS, if desired.
   */
  // state to measurement
  n_z_ = 2;
  Zsig_ = MatrixXd(n_z_, 2 * n_aug_ + 1);
  z_pred_ = VectorXd(n_z_);
  z_pred_.fill(.0);
  S_ = MatrixXd(n_z_, n_z_);
  S_.fill(0);
  for(int i=0; i<2 * n_aug_ + 1; i++)
  {
    Zsig_(0,i)= Xsig_pred_(0,i);
    Zsig_(1,i)= Xsig_pred_(1,i);
  }
  S_ << std_laspx_*std_laspx_, 0,
        0, std_laspy_*std_laspy_;

  // calculate mean predicted measurement
  z_pred_ = Zsig_*weights_;
  for(int i=0; i<2 * n_aug_ + 1; i++)
  {
    VectorXd delta_z = Zsig_.col(i)-z_pred_;
    S_ += weights_(i)*delta_z*delta_z.transpose();
     
  }
  
  // update state 
  Tc_ = MatrixXd(n_x_, n_z_);
  Tc_.fill(.0);
  for(int i=0; i<2*n_aug_+1; i++)
  {
    VectorXd delta_z = Zsig_.col(i) - z_pred_;
    VectorXd delta_x = Xsig_pred_.col(i)-x_;
    while(!(delta_x(3)>-M_PI && delta_x(3)<M_PI)){
      change_angle_range(delta_x(3));
    }
    Tc_ += weights_(i)*(delta_x)*(delta_z).transpose();
  }

  // calculate Kalman gain K;
  K = Tc_*S_.inverse(); 
  
  // update state mean and covariance matrix
  z_ = VectorXd(n_z_);
  z_ <<
      meas_package.raw_measurements_[0],
      meas_package.raw_measurements_[1];

  VectorXd delta_z_2 = z_ - z_pred_;
  x_ += K*delta_z_2;
  P_ -= K*S_*K.transpose();
}

void UKF::UpdateRadar(MeasurementPackage meas_package) {
  /**
   * TODO: Complete this function! Use radar data to update the belief 
   * about the object's position. Modify the state vector, x_, and 
   * covariance, P_.
   * You can also calculate the radar NIS, if desired.
   */
  // state to measurement
  n_z_ = 3;
  Zsig_ = MatrixXd(n_z_, 2 * n_aug_ + 1);
  z_pred_ = VectorXd(n_z_);
  z_pred_.fill(.0);
  S_ = MatrixXd(n_z_, n_z_);
  S_.fill(0);
  for(int i=0; i<2 * n_aug_ + 1; i++)
  {
      Zsig_(0,i)=sqrt(Xsig_pred_(0,i)*Xsig_pred_(0,i)+Xsig_pred_(1,i)*Xsig_pred_(1,i));
      Zsig_(1,i)=atan2(Xsig_pred_(1,i), Xsig_pred_(0,i));
      Zsig_(2,i)=(Xsig_pred_(0,i)*cos(Xsig_pred_(3,i))*Xsig_pred_(2,i)+Xsig_pred_(1,i)*sin(Xsig_pred_(3,i))*Xsig_pred_(2,i))/Zsig_(0,i);
  }

  // calculate covariance matrix S
  S_ << std_radr_*std_radr_, 0, 0,
        0, std_radphi_*std_radphi_, 0, 
        0, 0, std_radrd_*std_radrd_;

  // calculate mean predicted measurement
  z_pred_ = Zsig_*weights_;
  for(int i=0; i<2 * n_aug_ + 1; i++)
  {
    VectorXd delta_z = Zsig_.col(i)-z_pred_;
    while(!(delta_z(1)>-M_PI && delta_z(1)<M_PI))
    {
      change_angle_range(delta_z(1));
    }
    S_ += weights_(i)*delta_z*delta_z.transpose();
     
  }

  // update state mean and covariance
  Tc_ = MatrixXd(n_x_, n_z_);
  Tc_.fill(0);
  for(int i=0; i<2*n_aug_+1; i++)
  {
    VectorXd delta_z = Zsig_.col(i) - z_pred_;
    VectorXd delta_x = Xsig_pred_.col(i)-x_;
    while(!(delta_z(1)>-M_PI && delta_z(1)<M_PI)){
      change_angle_range(delta_z(1));
    }
    while(!(delta_x(3)>-M_PI && delta_x(3)<M_PI)){
      change_angle_range(delta_x(3));
    }
    Tc_ += weights_(i)*(delta_x)*(delta_z).transpose();
  }

  // calculate Kalman gain K;
  MatrixXd K = Tc_*S_.inverse(); 
  
  // update state mean and covariance matrix
  VectorXd z_ = VectorXd(n_z_);
  z_ <<
      meas_package.raw_measurements_[0],
      meas_package.raw_measurements_[1],
      meas_package.raw_measurements_[2];

  VectorXd delta_z_2 = z_ - z_pred_;
  while(!(delta_z_2(1)>-M_PI && delta_z_2(1)<M_PI)){
    change_angle_range(delta_z_2(1));
  }
  x_ += K*delta_z_2;
  P_ -= K*S_*K.transpose();
}
