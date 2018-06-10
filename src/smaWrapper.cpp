#include <Rcpp.h>

extern "C" {
#include "sma.h"
}

//' The UTS library by Andreas Eckner provides algorithms for unevenly
//' spaced time-series data.  This package brings a few of them to R.
//' The functions describe here offer simple moving
//' average, or SMA, for short. Three variants are provides considering
//' the last or next observation relative to time \sQuote{t}, as well as
//' linear interpolation between them.
//' @title SMA functions for unevenly spaced time series
//' @param times A Datetime vector
//' @param values A numeric vector
//' @param widthbefore A double with the preceding observation width
//' @param widthafter gvA double with the subsequent observation width
//' @return A numeric vector with SMA-weighted values.
//' package at the given position is available.
//' @author Dirk Eddelbuettel for the package, Andreas Eckner for the
//' underlying code.
//' @examples
//' if (requireNamespace("xts", quietly=TRUE)) {
//'     suppressMessages(library(xts))
//'     times <- ISOdatetime(2018, 6, 7, 8, 30, 0) + c(0, 1.0, 1.2, 2.3, 2.9, 5.0)
//'     values <- seq(0, 10, by=2)
//'     plot(xts(values, order.by=times), type="b",
//'          main="Series and last/next/linear SMAs")
//'     lines(xts(SMAlast(times,values, 2.5, 1), values, order.by=times), 
//'          type="b", col="lightblue")
//'     lines(xts(SMAnext(times,values, 2.5, 1),  values, order.by=times),
//'          type="b", col="darkblue")
//'     lines(xts(SMAlinear(times,values, 2.5, 1),  values, order.by=times),
//'          type="b", col="mediumblue")
//'     addLegend("topleft", legend.names=c("series", "SMAlast", "SMAnext", "SMAlinear"),
//'               lty=rep(1,4), lwd=rep(1,4),
//'               col=c("black", "lightblue", "darkblue", "mediumblue"))
//' }
// [[Rcpp::export]]
Rcpp::NumericVector SMAnext(Rcpp::DatetimeVector times,
                            Rcpp::NumericVector values,
                            const double widthbefore,
                            const double widthafter) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  sma_next(values.begin(), times.begin(), &n, res.begin(),
           const_cast<double*>(&widthbefore), const_cast<double*>(&widthafter));
  return res;
}

//' @rdname SMAnext
// [[Rcpp::export]]
Rcpp::NumericVector SMAlast(Rcpp::DatetimeVector times,
                            Rcpp::NumericVector values,
                            const double widthbefore,
                            const double widthafter) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  sma_last(values.begin(), times.begin(), &n, res.begin(), 
           const_cast<double*>(&widthbefore), const_cast<double*>(&widthafter));
  return res;
}

//' @rdname SMAnext
// [[Rcpp::export]]
Rcpp::NumericVector SMAlinear(Rcpp::DatetimeVector times,
                              Rcpp::NumericVector values,
                              const double widthbefore,
                              const double widthafter) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  sma_linear(values.begin(), times.begin(), &n, res.begin(), 
           const_cast<double*>(&widthbefore), const_cast<double*>(&widthafter));
  return res;
}
