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
    double dl = wheel_states.left - last_wheel_states.left;
    double dr = wheel_states.right - last_wheel_states.right;
    last_wheel_states = wheel_states;
    double calc_a = (dl - dr) / -axel_width_cm;
    double calc_r = dl / calc_a;
    double calc_c = calc_r = axel_width_cm / 2;
    double dx = std::cos(calc_a)*calc_c - calc_c;
    double dy = std::sin(calc_a)*calc_c;
    estimated_pose.t = angle; // also equal to current += calc_a;
    estimated_pose.x += dx;
    estimated_pose.y += dy;

}
void OdometryLayer::reset(Pose pose) {
    estimated_pose = pose;
}