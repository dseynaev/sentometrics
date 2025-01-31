// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// compute_df
Rcpp::NumericVector compute_df(double alpha, Rcpp::NumericVector lambda, Rcpp::List xA);
RcppExport SEXP _sentometrics_compute_df(SEXP alphaSEXP, SEXP lambdaSEXP, SEXP xASEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type lambda(lambdaSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type xA(xASEXP);
    rcpp_result_gen = Rcpp::wrap(compute_df(alpha, lambda, xA));
    return rcpp_result_gen;
END_RCPP
}
// compute_sentiment_onegrams
Rcpp::NumericMatrix compute_sentiment_onegrams(std::vector< std::vector<std::string>> texts, Rcpp::List lexicons, std::string how);
RcppExport SEXP _sentometrics_compute_sentiment_onegrams(SEXP textsSEXP, SEXP lexiconsSEXP, SEXP howSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector< std::vector<std::string>> >::type texts(textsSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type lexicons(lexiconsSEXP);
    Rcpp::traits::input_parameter< std::string >::type how(howSEXP);
    rcpp_result_gen = Rcpp::wrap(compute_sentiment_onegrams(texts, lexicons, how));
    return rcpp_result_gen;
END_RCPP
}
// compute_sentiment_sentences
Rcpp::NumericMatrix compute_sentiment_sentences(std::vector<std::vector<std::string>> texts, Rcpp::List lexicons, std::string how, bool hasValenceShifters);
RcppExport SEXP _sentometrics_compute_sentiment_sentences(SEXP textsSEXP, SEXP lexiconsSEXP, SEXP howSEXP, SEXP hasValenceShiftersSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<std::vector<std::string>> >::type texts(textsSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type lexicons(lexiconsSEXP);
    Rcpp::traits::input_parameter< std::string >::type how(howSEXP);
    Rcpp::traits::input_parameter< bool >::type hasValenceShifters(hasValenceShiftersSEXP);
    rcpp_result_gen = Rcpp::wrap(compute_sentiment_sentences(texts, lexicons, how, hasValenceShifters));
    return rcpp_result_gen;
END_RCPP
}
// compute_sentiment_valence
Rcpp::NumericMatrix compute_sentiment_valence(std::vector< std::vector<std::string> > texts, Rcpp::List lexicons, std::string how);
RcppExport SEXP _sentometrics_compute_sentiment_valence(SEXP textsSEXP, SEXP lexiconsSEXP, SEXP howSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector< std::vector<std::string> > >::type texts(textsSEXP);
    Rcpp::traits::input_parameter< Rcpp::List >::type lexicons(lexiconsSEXP);
    Rcpp::traits::input_parameter< std::string >::type how(howSEXP);
    rcpp_result_gen = Rcpp::wrap(compute_sentiment_valence(texts, lexicons, how));
    return rcpp_result_gen;
END_RCPP
}
// fill_NAs
Rcpp::NumericMatrix fill_NAs(Rcpp::NumericMatrix x);
RcppExport SEXP _sentometrics_fill_NAs(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(fill_NAs(x));
    return rcpp_result_gen;
END_RCPP
}
// make_frequency_maps
List make_frequency_maps(std::vector< std::vector<std::string>> texts, std::vector<std::string> ids, bool byText);
RcppExport SEXP _sentometrics_make_frequency_maps(SEXP textsSEXP, SEXP idsSEXP, SEXP byTextSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector< std::vector<std::string>> >::type texts(textsSEXP);
    Rcpp::traits::input_parameter< std::vector<std::string> >::type ids(idsSEXP);
    Rcpp::traits::input_parameter< bool >::type byText(byTextSEXP);
    rcpp_result_gen = Rcpp::wrap(make_frequency_maps(texts, ids, byText));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_sentometrics_compute_df", (DL_FUNC) &_sentometrics_compute_df, 3},
    {"_sentometrics_compute_sentiment_onegrams", (DL_FUNC) &_sentometrics_compute_sentiment_onegrams, 3},
    {"_sentometrics_compute_sentiment_sentences", (DL_FUNC) &_sentometrics_compute_sentiment_sentences, 4},
    {"_sentometrics_compute_sentiment_valence", (DL_FUNC) &_sentometrics_compute_sentiment_valence, 3},
    {"_sentometrics_fill_NAs", (DL_FUNC) &_sentometrics_fill_NAs, 1},
    {"_sentometrics_make_frequency_maps", (DL_FUNC) &_sentometrics_make_frequency_maps, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_sentometrics(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
