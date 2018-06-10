## RcppUTS [![Build Status](https://travis-ci.org/eddelbuettel/rcpputs.svg)](https://travis-ci.org/eddelbuettel/rcpputs) [![License](https://eddelbuettel.github.io/badges/GPL2+.svg)](http://www.gnu.org/licenses/gpl-2.0.html) 

Rcpp bindings for UTS (Unevenly Spaced Time Series)

### What is UTS?

UTS is a library by [Andreas Eckner](http://eckner.com/index.html) described and made
available via his [research page](http://eckner.com/research.html) which also contains
a [zip archive](http://eckner.com/papers/uts_algorithms.zip). 

### What is RcppUTS?

This package wraps (the older library version of) UTS for use by R via
[Rcpp](http://dirk.eddelbuettel.com/code/rcpp.html).

Some examples are included, based on the example in the UTS library. Below we show the
exponential-moving average operator, available condition on the `last`, `next` (ie 
current) observation, or a linear interpolation.

![EMA](https://eddelbuettel.github.io/rcpputs/figures/emaPlot.png)\

Also available is a standard moving average with a fixed 'before' and 'after' window length.

![SMA](https://eddelbuettel.github.io/rcpputs/figures/smaPlot.png)\

Both figures are also produced by the respective `example()` commands associate with
the corresponding help files.

### What else?

Well once I told Andreas I was putting together a quick package, he got motivated too and
released [an updated GitHUb repo for uts](https://github.com/andreas50/uts) as well
[one for utsOperators](https://github.com/andreas50/utsOperators). You probably want to
watch those spaces.  His [utsOperators](https://github.com/andreas50/utsOperators) is
closer to what we do here with a focus on SMA, EMA and rolling operators.

### Status

The package builds and checks cleanly.  

More functionality could be added, of course. Contributions are welcome.

### Author

Dirk Eddelbuettel for the package and interface, Andreas Eckner for UTS.

### License

GPL (>= 2)


