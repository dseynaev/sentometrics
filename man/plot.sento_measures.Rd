% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/sentomeasures_methods.R
\name{plot.sento_measures}
\alias{plot.sento_measures}
\title{Plot sentiment measures}
\usage{
\method{plot}{sento_measures}(x, group = "all", ...)
}
\arguments{
\item{x}{a \code{sento_measures} object created using \code{\link{sento_measures}}.}

\item{group}{a value from \code{c("lexicons", "features", "time", "all")}. The first three choices display the average of
all measures from the same group, in a different color. The choice \code{"all"} displays every single sentiment measure
in a separate color, but this may look visually overwhelming very fast, and can be quite slow.}

\item{...}{not used.}
}
\value{
Returns a simple \code{\link{ggplot}} object, which can be added onto (or to alter its default elements) by using
the \code{+} operator (see example). By default, a legend is positioned at the top if there are at maximum twelve line
graphs plotted and \code{group} is different from \code{"all"}.
}
\description{
Plotting method that shows all sentiment measures from the provided \code{sento_measures}
object in one plot, or the average along one of the lexicons, features and time weighting dimensions. We suggest to
make use of a \code{measures_xyz} function when you want to plot only a subset of the sentiment measures.
}
\examples{
data("usnews", package = "sentometrics")
data("list_lexicons", package = "sentometrics")
data("list_valence_shifters", package = "sentometrics")

# construct a sento_measures object to start with
corpus <- sento_corpus(corpusdf = usnews)
corpusSample <- quanteda::corpus_sample(corpus, size = 500)
l <- sento_lexicons(list_lexicons[c("LM_en")], list_valence_shifters[["en"]])
ctr <- ctr_agg(howTime = c("equal_weight", "linear"), by = "year", lag = 3)
sento_measures <- sento_measures(corpusSample, l, ctr)

# plot sentiment measures
plot(sento_measures, group = "features")

\dontrun{
# adjust appearance of plot
library("ggplot2")
p <- plot(sento_measures)
p <- p +
  scale_x_date(name = "month-year") +
  scale_y_continuous(name = "newName")
p}

}
\author{
Samuel Borms
}
