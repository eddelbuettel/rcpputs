#include <Rcpp.h>

extern "C" {
#include "rolling.h"
}

//' The UTS library by Andreas Eckner provides algorithms for unevenly
//' spaced time-series data.  This package brings a few of them to R.
//' The functions describe here offer various rolling operators.
//' @title Rolling operations functions for irregularly spaced time series
//' @param times A Datetime vector
//' @param values A numeric vector
//' @param widthbefore A double with the preceding observation width
//' @param widthafter A double with the subsequent observation width
//' @param moment A double with the requested moment.
//' @return A numeric vector with the corresponding result.
//' @author Dirk Eddelbuettel for the package, Andreas Eckner for the
//' underlying code.
// [[Rcpp::export]]
Rcpp::NumericVector rollingCentralMoment(Rcpp::DatetimeVector times,
                                         Rcpp::NumericVector values,
                                         const double widthbefore,
                                         const double widthafter,
                                         const double moment) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  rolling_central_moment(values.begin(), times.begin(), &n, res.begin(),
                         const_cast<double*>(&widthbefore),
                         const_cast<double*>(&widthafter),
                         const_cast<double*>(&moment));
  return res;
}

//' @rdname rollingCentralMoment
// [[Rcpp::export]]
Rcpp::NumericVector rollingMax(Rcpp::DatetimeVector times,
                               Rcpp::NumericVector values,
                               const double widthbefore,
                               const double widthafter) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  rolling_max(values.begin(), times.begin(), &n, res.begin(),
              const_cast<double*>(&widthbefore),
              const_cast<double*>(&widthafter));
  return res;
}

//' @rdname rollingCentralMoment
// [[Rcpp::export]]
Rcpp::NumericVector rollingMean(Rcpp::DatetimeVector times,
                                Rcpp::NumericVector values,
                                const double widthbefore,
                                const double widthafter) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  rolling_mean(values.begin(), times.begin(), &n, res.begin(),
               const_cast<double*>(&widthbefore),
               const_cast<double*>(&widthafter));
  return res;
}

//' @rdname rollingCentralMoment
// [[Rcpp::export]]
Rcpp::NumericVector rollingMedian(Rcpp::DatetimeVector times,
                                  Rcpp::NumericVector values,
                                  const double widthbefore,
                                  const double widthafter) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  rolling_median(values.begin(), times.begin(), &n, res.begin(),
                 const_cast<double*>(&widthbefore),
                 const_cast<double*>(&widthafter));
  return res;
}
        
//' @rdname rollingCentralMoment
// [[Rcpp::export]]
Rcpp::NumericVector rollingMin(Rcpp::DatetimeVector times,
                               Rcpp::NumericVector values,
                               const double widthbefore,
                               const double widthafter) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  rolling_min(values.begin(), times.begin(), &n, res.begin(),
              const_cast<double*>(&widthbefore),
              const_cast<double*>(&widthafter));
  return res;
}

//' @rdname rollingCentralMoment
// [[Rcpp::export]]
Rcpp::NumericVector rollingNobs(Rcpp::DatetimeVector times,
                                Rcpp::NumericVector values,
                                const double widthbefore,
                                const double widthafter) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  rolling_num_obs(values.begin(), times.begin(), &n, res.begin(),
                  const_cast<double*>(&widthbefore),
                  const_cast<double*>(&widthafter));
  return res;
}

//' @rdname rollingCentralMoment
// [[Rcpp::export]]
Rcpp::NumericVector rollingProduct(Rcpp::DatetimeVector times,
                                   Rcpp::NumericVector values,
                                   const double widthbefore,
                                   const double widthafter) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  rolling_product(values.begin(), times.begin(), &n, res.begin(),
                  const_cast<double*>(&widthbefore),
                  const_cast<double*>(&widthafter));
  return res;
}

//' @rdname rollingCentralMoment
// [[Rcpp::export]]
Rcpp::NumericVector rollingSD(Rcpp::DatetimeVector times,
                              Rcpp::NumericVector values,
                              const double widthbefore,
                              const double widthafter) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  rolling_sd(values.begin(), times.begin(), &n, res.begin(),
             const_cast<double*>(&widthbefore),
             const_cast<double*>(&widthafter));
  return res;
}

//' @rdname rollingCentralMoment
// [[Rcpp::export]]
Rcpp::NumericVector rollingSum(Rcpp::DatetimeVector times,
                               Rcpp::NumericVector values,
                               const double widthbefore,
                               const double widthafter) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  rolling_sum(values.begin(), times.begin(), &n, res.begin(),
              const_cast<double*>(&widthbefore),
              const_cast<double*>(&widthafter));
  return res;
}

//' @rdname rollingCentralMoment
// [[Rcpp::export]]
Rcpp::NumericVector rollingSumStable(Rcpp::DatetimeVector times,
                                     Rcpp::NumericVector values,
                                     const double widthbefore,
                                     const double widthafter) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  rolling_sum_stable(values.begin(), times.begin(), &n, res.begin(),
                     const_cast<double*>(&widthbefore),
                     const_cast<double*>(&widthafter));
  return res;
}

//' @rdname rollingCentralMoment
// [[Rcpp::export]]
Rcpp::NumericVector rollingVar(Rcpp::DatetimeVector times,
                               Rcpp::NumericVector values,
                               const double widthbefore,
                               const double widthafter) {
  if (times.size() != values.size()) Rcpp::stop("Matching vectors needed.");
  int n = times.size();
  Rcpp::NumericVector res(n);
  rolling_var(values.begin(), times.begin(), &n, res.begin(),
              const_cast<double*>(&widthbefore),
              const_cast<double*>(&widthafter));
  return res;
}
