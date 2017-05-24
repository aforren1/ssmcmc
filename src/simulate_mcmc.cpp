#include <Rcpp.h>
using namespace Rcpp;

//' Simulate an MCMC-based model for visuomotor rotation.
//' 
//' @param optimal A numeric vector containing the optimal reach direction.
//' @param cost_width Width of the cost function.
//' @param forget_rate Forgetting rate.
//' @param proposal_variance Width of the proposal distribution.
//' 
//' @examples
//' optimal <- c(rep(0, 8), rep(30, 80))
//' sims <- simulate_mcmc(optimal = optimal, 
//'                       cost_width = 5,
//'                       forget_rate = 0.9,
//'                       proposal_variance = 4.5)
//' plot(optimal, type = 'l')
//' lines(sims, col = 'red')
//' @export
// [[Rcpp::export]]
NumericVector simulate_mcmc(NumericVector optimal, double cost_width, 
                       double forget_rate, double proposal_variance) {
    
    int n = optimal.size();
    NumericVector observed(n);
    double metro;

    observed(0) = R::rnorm(0, proposal_variance);
    double sampled = observed(0);
    
    double vc = pow(((observed(0) - optimal(0))/cost_width), 2.0);
    
    for (int ii = 1; ii < n; ii++) {
        if (optimal(ii) != optimal(ii - 1)) {
            vc = 100.0;
        }
        
        observed(ii) = forget_rate * sampled + R::rnorm(0, proposal_variance);
        metro = std::min(exp(-pow(((observed(ii) - optimal(ii))/cost_width), 2.0) + vc), 1.0);
        if (R::runif(0, 1) < metro) {
            vc = pow(((observed(ii) - optimal(ii))/cost_width), 2.0);
            sampled = observed(ii);
        }
    }
    return observed;
}

/*** R
simulate_mcmc(optimal = c(rep(0, 8), rep(30, 80)), 
              cost_width = 5,
              forget_rate = 0.9,
              proposal_variance = 4.5)
*/
