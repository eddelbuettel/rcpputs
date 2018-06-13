#include <Rcpp.h>

extern "C" {
#include "ema.h"
}

//' The UTS library by Andreas Eckner provides algorithms for unevenly
//' spaced time-series data.  This package brings a few of them to R.
//' The functions describe here offer exponentially-decaying weighted moving
//' average, or EMA, for short. Three variants are provides considering
//' the last or next observation relative to time \sQuote{t}, as well as
//' linear interpolation between them.
//' @title EMA functions for unevenly spaced time series
//' @param times A Datetime vector
//' @param values A numeric vector
//' @param tau A double with the decay factor
//' @return A numeric vector with EMA-weighted values.
//' package at the given position is available.
//' @author Dirk Eddelbuettel for the package, Andreas Eckner for the
//' underlying code.
//' @examples
//' if (requireNamespace("xts", quietly=TRUE)) {
//'     suppressMessages(library(xts))
//'     times <- ISOdatetime(2010, 1, 2, 8, 30, 0) + c(0, 1.0, 1.2, 2.3, 2.9, 5.0)
//'     values <- seq(0, 10, by=2)
//'     plot(xts(values, order.by=times), type="b",
//'          main="Series and last/next/linear EMAs",
//'          major.ticks="auto", grid.ticks.on="auto")
//'     lines(xts(EMAlast(times,values, 1),  values, order.by=times),
//'           type="b", col="lightblue")
//'     lines(xts(EMAnext(times,values, 1),  values, order.by=times),
//'           type="b", col="darkblue")
//'     lines(xts(EMAlinear(times,values, 1),  values, order.by=times),
//'           type="b", col="mediumblue")
//'     addLegend("topleft", legend.names=c("series", "EMAlast", "EMAnext", "EMAlinear"),
//'               lty=rep(1,4), lwd=rep(1,4),
//'               col=c("black", "lightblue", "darkblue", "mediumblue"))
//' }
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
