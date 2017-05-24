library(ssmcmc)
context('Model simulations')

test_that('Model functions do not error', {
    expect_length(simulate_mcmc(optimal = c(rep(0, 8), rep(30, 80)), 
                                cost_width = 5,
                                forget_rate = 0.9,
                                proposal_variance = 4.5), 88)
    expect_length(simulate_ssm(optimal = c(rep(0, 8), rep(30, 80)), 
                               learn_rate = 0.15,
                               forget_rate = 0.94,
                               process_variance = 1,
                               execution_variance = 5), 88)
})