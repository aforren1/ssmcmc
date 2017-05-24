<!-- README.md is generated from README.Rmd. Please edit that file -->
[![Travis-CI Build Status](https://travis-ci.org/aforren1/ssmcmc.svg?branch=master)](https://travis-ci.org/aforren1/ssmcmc) [![AppVeyor Build Status](https://ci.appveyor.com/api/projects/status/github/aforren1/ssmcmc?branch=master&svg=true)](https://ci.appveyor.com/project/aforren1/ssmcmc)

ssmcmc
======

The goal of ssmcmc is to ...

Example
-------

This is a basic example which shows you how to solve a common problem:

``` r
set.seed(1)
data_mean <- rowMeans(rotation, na.rm = TRUE)
mcmc_sims <- replicate(n = 40,
                       expr = simulate_mcmc(optimal = c(rep(0, 8), rep(30, 72)), 
                                            cost_width = 6,
                                            forget_rate = 0.85,
                                            proposal_variance = 4))
ssm_sims <- replicate(n = 40,
                      expr = simulate_ssm(optimal = c(rep(0, 8), rep(30, 72)), 
                                          learn_rate = 0.15,
                                          forget_rate = 0.94,
                                          process_variance = 1,
                                          execution_variance = 5))
```

``` r
plot(data_mean, ylim = c(-10, 40))
lines(rowMeans(mcmc_sims), col = 'red')
lines(rowMeans(ssm_sims), col = 'blue')
```

![](README-plot1-1.png)

``` r
par(mfrow = c(3, 1))

matplot(rotation, type = 'l', ylim = c(-10, 40))
matplot(mcmc_sims, type = 'l', ylim = c(-10, 40))
matplot(ssm_sims, type = 'l', ylim = c(-10, 40))
```

![](README-plot2-1.png)

``` r
par(mfrow = c(1, 1))
```

``` r
long_mcmc <- reshape2::melt(mcmc_sims)
long_ssm <- reshape2::melt(ssm_sims)
long_data <- reshape2::melt(rotation)

ggplot(long_mcmc, aes(x = Var1, y = value)) + stat_binhex(binwidth = c(2, 3)) + ylim(c(-20, 50))
```

![](README-unnamed-chunk-2-1.png)

``` r
ggplot(long_ssm, aes(x = Var1, y = value)) + stat_binhex(binwidth = c(2, 3)) + ylim(c(-20, 50))
```

![](README-unnamed-chunk-2-2.png)

``` r
ggplot(long_data, aes(x = obs, y = value)) + stat_binhex(binwidth = c(2, 3)) + ylim(c(-20, 50))
#> Warning: Removed 101 rows containing non-finite values (stat_binhex).
```

![](README-unnamed-chunk-2-3.png)
