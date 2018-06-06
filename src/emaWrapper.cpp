#include <Rcpp.h>

extern "C" {
#include "ema.h"
}

//' The UTS library by Andreas Eckner provides algorithms for unevenly
//' spaced time-series data.  This package brings a few of them to R;
//' and these functions offer exponentially-decaying weighted moving
//' average, or EMA, for short. Three variants are provides considering
//' the last or next observation relative to time \sQuote{t}, as well as
//' linear interpolation between them.
//' @title EMA functions for irregularly samples time series
//' @param times A Datetime vector
//' @param values A numeric vector
//' @param tau A double with the decay factor
//' @return A numeric vector with EMA-weighted values.
//' package at the given position is available.
//' @author Dirk Eddelbuettel for the package, Andreas Eckner for the
//' underlying code.
//' @examples
//' tt <- Sys.time() + c(0, 0.2, 1.2, 2.3)
//' vv <- 0:3
//' EMAnext(tt, vv, 1)
//' EMAlast(tt, vv, 1)
//' EMAlinear(tt, vv, 1)
// [[Rcpp::export]]
Rcpp::NumericVector EMAnext(Rcpp::DatetimeVector times,
                            Rcpp::NumericVector values,
                            const double tau) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  ema_next(values.begin(), times.begin(), &n, res.begin(), const_cast<double*>(&tau));
  return res;
}

//' @rdname EMAnext
// [[Rcpp::export]]
Rcpp::NumericVector EMAlast(Rcpp::DatetimeVector times,
                            Rcpp::NumericVector values,
                            const double tau) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  ema_last(values.begin(), times.begin(), &n, res.begin(), const_cast<double*>(&tau));
  return res;
}

//' @rdname EMAnext
// [[Rcpp::export]]
Rcpp::NumericVector EMAlinear(Rcpp::DatetimeVector times,
                              Rcpp::NumericVector values,
                              const double tau) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  ema_linear(values.begin(), times.begin(), &n, res.begin(), const_cast<double*>(&tau));
  return res;
}
