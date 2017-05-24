// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// simulate_mcmc
NumericVector simulate_mcmc(NumericVector optimal, double cost_width, double forget_rate, double proposal_variance);
RcppExport SEXP ssmcmc_simulate_mcmc(SEXP optimalSEXP, SEXP cost_widthSEXP, SEXP forget_rateSEXP, SEXP proposal_varianceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type optimal(optimalSEXP);
    Rcpp::traits::input_parameter< double >::type cost_width(cost_widthSEXP);
    Rcpp::traits::input_parameter< double >::type forget_rate(forget_rateSEXP);
    Rcpp::traits::input_parameter< double >::type proposal_variance(proposal_varianceSEXP);
    rcpp_result_gen = Rcpp::wrap(simulate_mcmc(optimal, cost_width, forget_rate, proposal_variance));
    return rcpp_result_gen;
END_RCPP
}
// simulate_ssm
NumericVector simulate_ssm(NumericVector optimal, double learn_rate, double forget_rate, double process_variance, double execution_variance);
RcppExport SEXP ssmcmc_simulate_ssm(SEXP optimalSEXP, SEXP learn_rateSEXP, SEXP forget_rateSEXP, SEXP process_varianceSEXP, SEXP execution_varianceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type optimal(optimalSEXP);
    Rcpp::traits::input_parameter< double >::type learn_rate(learn_rateSEXP);
    Rcpp::traits::input_parameter< double >::type forget_rate(forget_rateSEXP);
    Rcpp::traits::input_parameter< double >::type process_variance(process_varianceSEXP);
    Rcpp::traits::input_parameter< double >::type execution_variance(execution_varianceSEXP);
    rcpp_result_gen = Rcpp::wrap(simulate_ssm(optimal, learn_rate, forget_rate, process_variance, execution_variance));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"ssmcmc_simulate_mcmc", (DL_FUNC) &ssmcmc_simulate_mcmc, 4},
    {"ssmcmc_simulate_ssm", (DL_FUNC) &ssmcmc_simulate_ssm, 5},
    {NULL, NULL, 0}
};

RcppExport void R_init_ssmcmc(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}