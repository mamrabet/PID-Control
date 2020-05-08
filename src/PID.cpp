#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
Kp = Kp_;
Ki = Ki_; 
Kd = Kd_;

 p_error = 0.0;
 i_error = 0.0;
 d_error = 0.0;
 last_cte =0.0;
 sum_cte = 0.0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  p_error = Kp * cte;
  sum_cte += cte;
  i_error = Ki * sum_cte;
  d_error = Kd*(cte-last_cte);
  last_cte = cte;
  tot_error = -(p_error+i_error+d_error);

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  if (tot_error > -1.0 && tot_error< 1.0)
  	return tot_error;
  else if (tot_error <= -1.0)
    return -1.0;
  else if (tot_error >= 1.0)
    return 1.0; 
    
  // TODO: Add your total error calc here!
}