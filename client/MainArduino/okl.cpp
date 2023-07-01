#include "okl.h"

#include <math.h>

KinematicsLayer::KinematicsLayer(double axel_width_cm): axel_width_cm(axel_width_cm) {}
WheelStateType KinematicsLayer::to_wheel_speeds(ChasisSpeeds chasis_speeds) {
    return WheelStateType {
        .left = chasis_speeds.delta_x + chasis_speeds.delta_theta * axel_width_cm / 2.0,
        .right = chasis_speeds.delta_x - chasis_speeds.delta_theta * axel_width_cm / 2.0,
    };
}

OdometryLayer::OdometryLayer(double axel_width_cm): axel_width_cm(axel_width_cm) {}
Pose OdometryLayer::get_pose() {return estimated_pose;}
void OdometryLayer::update(WheelStateType wheel_states, double angle) {
    // we should be able to update the estimated a right away
    double dl = wheel_states.left - last_wheel_states.left;
    double dr = wheel_states.right - last_wheel_states.right;
    last_wheel_states = wheel_states;

    
    double avg_dist_moved = (dl + dr) / 2;
    
    estimated_pose.a = angle;
    estimated_pose.x += cos(angle)*avg_dist_moved;
    estimated_pose.y += sin(angle)*avg_dist_moved;
    /*
    double calc_a = (dl - dr) / -axel_width_cm;
    // avoid div by zero if stopped or heading in a perfectly!!! straight line, so its never gonna happen -- ever
    if (calc_a != 0) {
      // we are going in an arc
      double calc_r = dl / calc_a;
      double calc_c = calc_r + axel_width_cm / 2;
      estimated_pose.a = angle;
      double dxrelative = calc_c - cos(calc_a)*calc_c;
      double dyrelative = sin(calc_a)*calc_c;
      double est_dist_moved = sqrt(pow(dxrelative, 2) + pow(dyrelative, 2));
      estimated_pose.x += cos(estimated_pose.a)*est_dist_moved;
      estimated_pose.y += sin(estimated_pose.a)*est_dist_moved;
    }
    */
}
void OdometryLayer::reset(Pose pose) {
    estimated_pose = pose;
}
