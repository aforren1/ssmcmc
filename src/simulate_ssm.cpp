#include <Rcpp.h>
using namespace Rcpp;

//' Simulate a state space model for visuomotor rotation.
//' 
//' @param optimal A numeric vector containing the optimal reach direction.
//' @param learn_rate Learning rate.
//' @param forget_rate Forgetting rate.
//' @param process_variance State noise.
//' @param execution_variance Execution noise.
//' 
//' @examples
//' optimal <- c(rep(0, 8), rep(30, 72))
//' sims <- simulate_ssm(optimal = optimal, 
//'                      learn_rate = 0.15,
//'                      forget_rate = 0.94,
//'                      process_variance = 1,
//'                      execution_variance = 5)
//' plot(optimal, type = 'l')
//' lines(sims, col = 'red')
//' @export
// [[Rcpp::export]]
NumericVector simulate_ssm(NumericVector optimal, double learn_rate, 
                           double forget_rate, double process_variance,
                           double execution_variance) {
    
    int n = optimal.size();
    NumericVector observed(n);
    NumericVector state(n);
    double error;
    
    state(0) = R::rnorm(0, process_variance);
    observed(0) = R::rnorm(state(0), execution_variance);
    
    for (int ii = 1; ii < n; ii++) {
        error = observed(ii - 1) - optimal(ii - 1);
        state(ii) = forget_rate * state(ii - 1) - learn_rate * error + R::rnorm(0, process_variance);
        observed(ii) = R::rnorm(state(ii), execution_variance);
    }
    return observed;
}

/*** R
simulate_ssm(optimal = c(rep(0, 8), rep(30, 72)), 
              learn_rate = 0.15,
              forget_rate = 0.94,
              process_variance = 1,
              execution_variance = 5)
*/
